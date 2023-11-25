#include <iostream>
#include <stdexcept>
#include "Locadora.hpp"

int main() {
    Locadora locadora;

    std::string comando;
    std::cout << "Digite um comando (ou 'FS' para sair): "<<std::endl;

    int dias;

    while (std::cin >> comando && comando != "FS") {
        try {
            if (comando == "LA") {
                std::string nomeArquivo;
                std::cin >> nomeArquivo;
                locadora.lerArquivoCadastro(nomeArquivo);
            } else if (comando == "CF") {
                char tipo;
                int quantidade, codigo;
                std::string titulo, categoria;

                std::cin >> tipo >> quantidade >> codigo >> titulo;
                if (tipo == 'F') {
                    locadora.cadastrarFilmeFita(quantidade, codigo, titulo);
                } else if (tipo == 'D') {
                    std::cin >> categoria;
                    locadora.cadastrarFilmeDVD(quantidade, codigo, titulo, categoria);
                }
            } else if (comando == "RF") {
                int codigo;
                std::cin >> codigo;
                locadora.removerFilme(codigo);
            } else if (comando == "LF") {
                char ordenacao;
                std::cin >> ordenacao;
                locadora.listarFilmes(ordenacao);
            } else if (comando == "CC") {
                std::string cpf, nome;
                std::cin >> cpf >> nome;
                locadora.cadastrarCliente(cpf, nome);
            } else if (comando == "RC") {
                std::string cpf;
                std::cin >> cpf;
                locadora.removerCliente(cpf);
            } else if (comando == "LC") {
                char ordenacao;
                std::cin >> ordenacao;
                locadora.listarClientes(ordenacao);
            } else if (comando == "AL") {
                std::string cpf;
                std::cin >> cpf;
                locadora.alugarFilme(cpf);
            } else if (comando == "DV") {
                std::string cpf;
                std::cin >> cpf >> dias; 
                locadora.devolverFilme(cpf, dias);
            } else {
                std::cout << "Erro: Comando inválido.\n";
            }
        } catch (const std::exception &e) {
            std::cerr << "Erro: " << e.what() << "\n";
        }

        std::cout << "Digite um comando (ou 'FS' para sair): "<<std::endl;
    }

    return 0;
}
