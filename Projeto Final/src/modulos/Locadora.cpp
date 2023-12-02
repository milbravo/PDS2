#include "Locadora.hpp"
#include "Fita.hpp"
#include "DVD.hpp"
#include <fstream>
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <regex>

Locadora::Locadora() {}

bool Locadora::validarCPF(std::string cpf)
{
    // Verifica se o CPF tem 11 dígitos numéricos
    if (cpf.length() != 11 || !std::all_of(cpf.begin(), cpf.end(), ::isdigit))
    {
        throw std::runtime_error("ERRO: CPF deve ter exatamente 11 dígitos numéricos.");
    }

    // Algoritmo de validação do CPF
    int soma = 0;
    int resto;

    // Primeira etapa: cálculo do primeiro dígito verificador
    for (int i = 0; i < 9; ++i)
    {
        soma += (cpf[i] - '0') * (10 - i);
    }

    resto = 11 - (soma % 11);
    resto = (resto == 10 || resto == 11) ? 0 : resto;

    // Verifica se o primeiro dígito verificador está correto
    if (resto != (cpf[9] - '0'))
    {
        throw std::runtime_error("ERRO: CPF INVALIDO.");
    }

    soma = 0;

    // Segunda etapa: cálculo do segundo dígito verificador
    for (int i = 0; i < 10; ++i)
    {
        soma += (cpf[i] - '0') * (11 - i);
    }

    resto = 11 - (soma % 11);
    resto = (resto == 10 || resto == 11) ? 0 : resto;

    // Verifica se o segundo dígito verificador está correto
    if (resto != (cpf[10] - '0'))
    {
        throw std::runtime_error("ERRO: CPF INVALIDO.");
    }

    // Se passou por todas as verificações, o CPF é considerado válido
    return true;
}

void Locadora::lerArquivoCadastro(std::string nomeArquivo)
{
    // Abre o arquivo
    std::ifstream arquivo(nomeArquivo.c_str(), std::ifstream::in);
    try
    {
        if (!arquivo.is_open())
        {
            throw std::runtime_error("ERRO: arquivo (" + nomeArquivo + ") inexistente.");
        }
        else
        {
            int quantidade, codigo;
            char tipo;
            std::string titulo, categoria;

            while (arquivo >> tipo >> quantidade >> codigo >> titulo)
            {
                if (tipo == 'F')
                {
                    cadastrarFilmeFita(quantidade, codigo, titulo);
                }
                else if (tipo == 'D')
                {
                    arquivo >> categoria;
                    cadastrarFilmeDVD(quantidade, codigo, titulo, categoria);
                }
            }
            arquivo.close();
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::cadastrarFilmeFita(int quantidade, int codigo, std::string titulo)
{
    try
    {
        if (Locadora::buscarFilme(codigo) == nullptr)
        {
            estoqueFilmes.push_back(new Fita(codigo, titulo, quantidade, true));
            std::cout << "Filme " << codigo << " cadastrado com sucesso.\n";
        }
        else
        {
            throw std::runtime_error("ERRO: codigo (" + std::to_string(codigo) + ") repetido");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::cadastrarFilmeDVD(int quantidade, int codigo, std::string titulo, std::string categoria)
{
    try
    {
        if (Locadora::buscarFilme(codigo) == nullptr)
        {
            try
            {
                if (categoria == "Lancamento" || categoria == "Promocao" || categoria == "Estoque")
                {
                    estoqueFilmes.push_back(new DVD(codigo, titulo, quantidade, categoria));
                    std::cout << "Filme " << codigo << " cadastrado com sucesso.\n";
                }
                else
                {
                    throw std::runtime_error("ERRO: categoria (" + categoria + ") invalida.\nCategorias possiveis: Lancamento, Promocao e Estoque.");
                }
            }
            catch (const std::exception &ex)
            {
                std::cerr << ex.what() << std::endl;
            }
        }
        else
        {
            throw std::runtime_error("ERRO: codigo (" + std::to_string(codigo) + ") repetido");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::removerFilme(int codigo)
{
    auto it = std::find_if(estoqueFilmes.begin(), estoqueFilmes.end(), [codigo](Filme *filme)
                           { return filme->getCodigo() == codigo; });
    try
    {
        if (it != estoqueFilmes.end())
        {
            delete *it;
            estoqueFilmes.erase(it);
            std::cout << "Filme " << codigo << " removido com sucesso.\n";
        }
        else
        {
            throw std::runtime_error("ERRO: codigo inexistente.");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::listarFilmes(char ordenacao)
{
    std::vector<Filme *> filmesOrdenados = estoqueFilmes;

    if (ordenacao == 'C')
    {
        std::sort(filmesOrdenados.begin(), filmesOrdenados.end(),
                  [](Filme *a, Filme *b)
                  { return a->getCodigo() < b->getCodigo(); });
    }
    else if (ordenacao == 'T')
    {
        std::sort(filmesOrdenados.begin(), filmesOrdenados.end(),
                  [](Filme *a, Filme *b)
                  { return a->getTitulo() < b->getTitulo(); });
    }

    for (auto filme : filmesOrdenados)
    {
        std::cout << filme->getCodigo() << " " << filme->getTitulo() << " " << filme->getQuantidade()
                  << " " << filme->getTipo() << "\n";
    }
}

void Locadora::cadastrarCliente(std::string cpf, std::string nome)
{
    try
    {
        if (validarCPF(cpf))
        {
            if (buscarCliente(cpf) == nullptr)
            {
                clientes.push_back(new Cliente(cpf, nome));
                std::cout << "Cliente " << cpf << " cadastrado com sucesso.\n";
            }
            else
            {
                throw std::runtime_error("CPF " + cpf + " repetido.");
            }
        }
        else
        {
            throw std::runtime_error("CPF " + cpf + " inválido.");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::removerCliente(std::string cpf)
{
    auto it = std::find_if(clientes.begin(), clientes.end(), [cpf](Cliente *cliente)
                           { return cliente->getCPF() == cpf; });

    try
    {
        if (it != clientes.end())
        {
            delete *it;
            clientes.erase(it);
            std::cout << "Cliente " << cpf << " removido com sucesso.\n";
        }
        else
        {
            throw std::runtime_error("CPF " + cpf + " não encontrado para remoção.");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::listarClientes(char ordenacao)
{
    std::vector<Cliente *> clientesOrdenados = clientes;

    if (ordenacao == 'C')
    {
        std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
                  [](Cliente *a, Cliente *b)
                  { return a->getCPF() < b->getCPF(); });
    }
    else if (ordenacao == 'N')
    {
        std::sort(clientesOrdenados.begin(), clientesOrdenados.end(),
                  [](Cliente *a, Cliente *b)
                  { return a->getNome() < b->getNome(); });
    }

    for (auto cliente : clientesOrdenados)
    {
        std::cout << cliente->getCPF() << " " << cliente->getNome() << "\n";
    }
}

void Locadora::alugarFilme(std::string cpf)
{
    try
    {
        Cliente *cliente = buscarCliente(cpf);
        if (cliente != nullptr)
        {
            if (!clientePossuiLocacao(cpf))
            {
                std::vector<int> codigosFilmes;
                int codigo;

                std::cout << "Cliente " << cpf << " alugou os filmes:\n";

                while (std::cin >> codigo && codigo != -1)
                {
                    Filme *filme = buscarFilme(codigo);
                    if (filme != nullptr)
                    {
                        if (filme->getQuantidade() > 0)
                        { // Verifica se há filmes disponíveis
                            codigosFilmes.push_back(codigo);
                            filme->diminuirQuantidade(); // Reduz o estoque do filme
                            std::cout << filme->getCodigo() << " " << filme->getTitulo() << " " << filme->getTipo() << "\n";
                        }
                        else
                        {
                            throw std::runtime_error("ERRO: Filme " + std::to_string(codigo) + " sem estoque disponível.");
                        }
                    }
                    else
                    {
                        throw std::runtime_error("ERRO: Filme " + std::to_string(codigo) + " inexistente.");
                    }
                }

                locacoesEmCurso[cpf] = codigosFilmes;
            }
            else
            {
                throw std::runtime_error("ERRO: Cliente " + cpf + " já possui uma locação em curso.");
            }
        }
        else
        {
            throw std::runtime_error("ERRO: CPF inexistente.");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

void Locadora::devolverFilme(std::string cpf, int dias)
{
    try
    {
        Cliente *cliente = buscarCliente(cpf);
        if (cliente != nullptr)
        {
            if (clientePossuiLocacao(cpf))
            {
                std::cout << "Cliente " << cpf << " devolveu os filmes:\n";

                for (int codigo : locacoesEmCurso[cpf])
                {
                    Filme *filme = buscarFilme(codigo);
                    if (filme != nullptr)
                    {
                        std::cout << codigo << " [" << filme->calcularValorLocacao(dias) << "]\n";
                    }
                }

                double totalPagar = calcularTotalPagar(locacoesEmCurso[cpf], dias);
                std::cout << "Total a pagar: [" << totalPagar << "]\n";

                // Adiciona os filmes devolvidos de volta ao estoque
                for (int codigo : locacoesEmCurso[cpf])
                {
                    Filme *filme = buscarFilme(codigo);
                    if (filme != nullptr)
                    {
                        filme->aumentarQuantidade();
                    }
                }

                locacoesEmCurso.erase(cpf);
            }
            else
            {
                throw std::runtime_error("ERRO: Cliente " + cpf + " não possui locação em curso.");
            }
        }
        else
        {
            throw std::runtime_error("ERRO: CPF inexistente.");
        }
    }
    catch (const std::exception &ex)
    {
        std::cerr << ex.what() << std::endl;
    }
}

double Locadora::calcularTotalPagar(std::vector<int> locacoes, int dias)
{
    double totalPagar = 0.0;

    for (int codigo : locacoes)
    {
        Filme *filme = buscarFilme(codigo);
        if (filme != nullptr)
        {
            totalPagar += filme->calcularValorLocacao(dias);
        }
    }

    return totalPagar;
}

Filme *Locadora::buscarFilme(int codigo)
{
    auto it = std::find_if(estoqueFilmes.begin(), estoqueFilmes.end(),
                           [codigo](Filme *filme)
                           { return filme->getCodigo() == codigo; });

    return (it != estoqueFilmes.end()) ? *it : nullptr;
}

Cliente *Locadora::buscarCliente(std::string cpf)
{
    auto it = std::find_if(clientes.begin(), clientes.end(),
                           [cpf](Cliente *cliente)
                           { return cliente->getCPF() == cpf; });

    return (it != clientes.end()) ? *it : nullptr;
}

bool Locadora::clientePossuiLocacao(std::string cpf)
{
    return locacoesEmCurso.find(cpf) != locacoesEmCurso.end();
}

void Locadora::relatorioAlugueis()
{
    std::string nome;

    std::unordered_map<std::string, std::vector<int>>::iterator it;
    std::cout << "----------------------------------------------------" << std::endl;
    std::cout << "Relatorio de alugueis" << std::endl;
    std::cout << std::endl;
    for (it = locacoesEmCurso.begin(); it != locacoesEmCurso.end(); it++)
    {
        nome = Locadora::buscarCliente(it->first)->getNome();
        std::cout << it->first << " " << nome << " ";
        for (int codigo : it->second)
        {
            std::cout << codigo << " ";
        }
        std::cout << std::endl;
    }
    std::cout << "----------------------------------------------------" << std::endl;
}
