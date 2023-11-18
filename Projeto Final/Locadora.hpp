#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include <vector>
#include <unordered_map>
#include "Cliente.hpp"
#include "Filme.hpp"

class Locadora {
public:
    Locadora();
    ~Locadora() = default;

    void lerArquivoCadastro(const std::string &nomeArquivo);
    void cadastrarFilmeFita(int quantidade, int codigo, const std::string &titulo);
    void cadastrarFilmeDVD(int quantidade, int codigo, const std::string &titulo, const std::string &categoria);
    void removerFilme(int codigo);
    void listarFilmes(char ordenacao) const;
    void cadastrarCliente(const std::string &cpf, const std::string &nome);
    void removerCliente(const std::string &cpf);
    void listarClientes(char ordenacao) const;
    void alugarFilme(const std::string &cpf);
    void devolverFilme(const std::string &cpf, int dias);
    double calcularTotalPagar(const std::vector<int> &locacoes, int dias) const;
  
    
private:
    std::vector<Filme *> estoqueFilmes;
    std::vector<Cliente> clientes;
    std::unordered_map<std::string, std::vector<int>> locacoesEmCurso;

    Filme* buscarFilme(int codigo) const;
    Cliente* buscarCliente(const std::string &cpf) const;
    bool clientePossuiLocacao(const std::string &cpf) const;
    bool validarCPF(const std::string& cpf);
    
};

#endif // LOCADORA_HPP
