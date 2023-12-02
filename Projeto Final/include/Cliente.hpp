// Cliente.hpp

#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <string>
#include <vector>

class Cliente
{
public:
    Cliente(std::string cpf, std::string nome);

    std::string getCPF();
    std::string getNome();

private:
    std::string cpf;
    std::string nome;
    std::vector<int> locacoes;
};

#endif // CLIENTE_HPP
