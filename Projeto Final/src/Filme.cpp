#include "Filme.hpp"

Filme::Filme(int codigo, std::string titulo, int quantidade): codigo(codigo), titulo(titulo), quantidade(quantidade) {}
Filme::~Filme(){};
int Filme::getCodigo()
{
    return codigo;
}

std::string Filme::getTitulo()
{
    return titulo;
}

int Filme::getQuantidade()
{
    return quantidade;
}

void Filme::diminuirQuantidade()
{
    quantidade--;
}

void Filme::aumentarQuantidade()
{
    quantidade++;
}