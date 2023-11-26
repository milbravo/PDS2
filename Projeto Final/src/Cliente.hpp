// Cliente.hpp

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>

class Cliente {
public:
    Cliente( std::string cpf, std::string nome);

    const std::string getCPF();
    const std::string getNome();
    const std::vector<int> getLocacoes(); 
    void adicionarLocacao(int codigo); 

private:
    std::string cpf;
    std::string nome;
    std::vector<int> locacoes; 
};

#endif // CLIENTE_HPP

