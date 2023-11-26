#include "Fita.hpp"

Fita::Fita(int codigo, std::string titulo, int quantidade, bool rebobinada) : Filme(codigo, titulo, quantidade), rebobinada(rebobinada) {}

std::string Fita::getTipo()
{
    return "FITA";
}

double Fita::calcularValorLocacao(int dias)
{
    double valor = 5.0;

    if (!rebobinada)
    {
        valor += 2.0; // Multa por não rebobinar
    }

    return valor;
}