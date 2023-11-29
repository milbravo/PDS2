#include <iostream>
#include <stdexcept>
#include "Locadora.hpp"

int main()
{
    Locadora locadora;

    std::string comando;
    std::cout << "------------------------LOCADORA--------------------------" << std::endl;
    std::cout << "Bem vindo!" << std::endl;
    std::cout << "Abaixo está o menu de comandos para a utilizacao da" << std::endl;
    std::cout << "ferramenta:" << std::endl;
    std::cout << std::endl;
    std::cout << "MENU" << std::endl;
    std::cout << "LA: ler arquivo de estoque" << std::endl;
    std::cout << "CF: cadastrar filme no sistema" << std::endl;
    std::cout << "RF: remover filme no sistema" << std::endl;
    std::cout << "LF: listar filmes no sistema" << std::endl;
    std::cout << "CC: cadastrar cliente no sistema" << std::endl;
    std::cout << "RC: remover cliente no sistema" << std::endl;
    std::cout << "LC: listar clientes no sistema" << std::endl;
    std::cout << "AL: registar um aluguel" << std::endl;
    std::cout << "DV: registar uma devolucao" << std::endl;
    std::cout << "RA: exibir relatorio de alugueis" << std::endl;
    std::cout << "HELP: exibe detalhes dos comandos" << std::endl;
    std::cout << "FS: finalizar o sistema" << std::endl;
    std::cout << "---------------------------------------------------" << std::endl;
    std::cout << std::endl;

    int dias;

    while (std::cin >> comando && comando != "FS")
    {
        try
        {
            if (comando == "LA")
            {
                std::string nomeArquivo;
                std::getline(std::cin, nomeArquivo);
                // Remove o espaço (primeiro caractere) da string
                nomeArquivo.erase(0, 1);
                locadora.lerArquivoCadastro(nomeArquivo);
            }
            else if (comando == "CF")
            {
                char tipo;
                int quantidade, codigo;
                std::string titulo, categoria;

                std::cin >> tipo >> quantidade >> codigo >> titulo;
                if (tipo == 'F')
                {
                    locadora.cadastrarFilmeFita(quantidade, codigo, titulo);
                }
                else if (tipo == 'D')
                {
                    std::cin >> categoria;
                    locadora.cadastrarFilmeDVD(quantidade, codigo, titulo, categoria);
                }
            }
            else if (comando == "RF")
            {
                int codigo;
                std::cin >> codigo;
                locadora.removerFilme(codigo);
            }
            else if (comando == "LF")
            {
                char ordenacao;
                std::cin >> ordenacao;
                locadora.listarFilmes(ordenacao);
            }
            else if (comando == "CC")
            {
                std::string cpf, nome;
                std::cin >> cpf >> nome;
                locadora.cadastrarCliente(cpf, nome);
            }
            else if (comando == "RC")
            {
                std::string cpf;
                std::cin >> cpf;
                locadora.removerCliente(cpf);
            }
            else if (comando == "LC")
            {
                char ordenacao;
                std::cin >> ordenacao;
                locadora.listarClientes(ordenacao);
            }
            else if (comando == "AL")
            {
                std::string cpf;
                std::cin >> cpf;
                locadora.alugarFilme(cpf);
            }
            else if (comando == "DV")
            {
                std::string cpf;
                std::cin >> cpf >> dias;
                locadora.devolverFilme(cpf, dias);
            }
            else if (comando == "RA")
            {
                locadora.relatorioAlugueis();
            }
            else if (comando == "HELP")
            {
                std::cout << "MENU HELP--------------------------------------" << std::endl;
                std::cout << "LA <Nome do Arquivo> (caminho de pastas completo)" << std::endl;
                std::cout << "CF <Tipo: F|D> <quantidade> <codigo> <titulo> <categoria no caso de DVD>" << std::endl;
                std::cout << "RF <codigo>" << std::endl;
                std::cout << "LF <Ordenacao: C|T> (C = codigo, T = titulo)" << std::endl;
                std::cout << "CC <CPF> <Nome>" << std::endl;
                std::cout << "RC <CPF>" << std::endl;
                std::cout << "LC <Ordenacao: C|N> (C = CPF, N = nome)" << std::endl;
                std::cout << "AL <CPF> <Codigo1> … <Codigo N> <-1> (-1 atua como flag para indicar o fim dos codigos)" << std::endl;
                std::cout << "DV <CPF>" << std::endl;
                std::cout << "RA  (exibe relatorio de alugueis)" << std::endl;
                std::cout << "HELP (exibe detalhes dos comandos)" << std::endl;
                std::cout << "FS (finalizar o sistema)" << std::endl;
                std::cout << "------------------------------------------------" << std::endl;
            }
            else
            {
                std::cout << "Erro: Comando inválido.\n";
            }
        }
        catch (const std::exception &e)
        {
            std::cerr << "Erro: " << e.what() << "\n";
        }
        std::cout << std::endl;
        std::cout << "Digite um comando (ou 'FS' para sair): " << std::endl;
    }

    return 0;
}
