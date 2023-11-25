#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include <vector>
#include <unordered_map>
#include <algorithm>
#include "Cliente.hpp"
#include "Filme.hpp"

class Locadora {
public:
    Locadora();

    void lerArquivoCadastro(std::string nomeArquivo);
    void cadastrarFilmeFita(int quantidade, int codigo, std::string titulo);
    void cadastrarFilmeDVD(int quantidade, int codigo, std::string titulo, std::string categoria);
    void removerFilme(int codigo);
    void listarFilmes(char ordenacao);
    void cadastrarCliente(std::string cpf, std::string nome);
    void removerCliente(std::string cpf);
    void listarClientes(char ordenacao);
    void alugarFilme(std::string cpf);
    void devolverFilme( std::string cpf, int dias);
    double calcularTotalPagar(std::vector<int> locacoes, int dias);
  
    
private:
    std::vector<Filme *> estoqueFilmes;
    std::vector<Cliente> clientes;
    std::unordered_map<std::string, std::vector<int>> locacoesEmCurso;

    Filme* buscarFilme(int codigo);
    Cliente* buscarCliente(std::string cpf);
    bool clientePossuiLocacao(std::string cpf);
    bool validarCPF( std::string cpf);
    
};

#endif // LOCADORA_HPP
