// Cliente.cpp

#include "Cliente.hpp"

Cliente::Cliente(std::string cpf, std::string nome)
    : cpf(cpf), nome(nome) {}

const std::string Cliente::getCPF(){
    return cpf;
}

const std::string Cliente::getNome(){
    return nome;
}

const std::vector<int> Cliente::getLocacoes(){
    return locacoes;
}

void Cliente::adicionarLocacao(int codigo) {
    locacoes.push_back(codigo);
}

