// Cliente.hpp

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>

class Cliente {
public:
    Cliente(const std::string &cpf, const std::string &nome);

    const std::string& getCPF() const;
    const std::string& getNome() const;
    const std::vector<int>& getLocacoes() const; 
    void adicionarLocacao(int codigo); 

private:
    std::string cpf;
    std::string nome;
    std::vector<int> locacoes; 
};

#endif // CLIENTE_HPP

