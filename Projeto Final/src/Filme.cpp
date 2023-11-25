#include "Filme.hpp"

Filme::Filme(int codigo, const std::string &titulo, int quantidade)
    : codigo(codigo), titulo(titulo), quantidade(quantidade) {}

int Filme::getCodigo() const {
    return codigo;
}

std::string Filme::getTitulo() const {
    return titulo;
}

int Filme::getQuantidade() const {
    return quantidade;
}

void Filme::diminuirQuantidade() {
    quantidade--;
}

void Filme::aumentarQuantidade() {
    quantidade++;
}