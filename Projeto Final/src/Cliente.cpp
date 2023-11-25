// Cliente.cpp

#include "Cliente.hpp"

Cliente::Cliente(const std::string &cpf, const std::string &nome)
    : cpf(cpf), nome(nome) {}

const std::string& Cliente::getCPF() const {
    return cpf;
}

const std::string& Cliente::getNome() const {
    return nome;
}

const std::vector<int>& Cliente::getLocacoes() const {
    return locacoes;
}

void Cliente::adicionarLocacao(int codigo) {
    locacoes.push_back(codigo);
}

