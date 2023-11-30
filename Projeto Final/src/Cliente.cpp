// Cliente.cpp

#include "Cliente.hpp"

Cliente::Cliente(std::string cpf, std::string nome)
    : cpf(cpf), nome(nome) {}

std::string Cliente::getCPF(){
    return cpf;
}

std::string Cliente::getNome(){
    return nome;
}

/*std::vector<int> Cliente::getLocacoes(){
    return locacoes;
}

void Cliente::adicionarLocacao(int codigo) {
    locacoes.push_back(codigo);
}
*/
