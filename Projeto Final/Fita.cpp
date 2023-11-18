#include "Fita.hpp"

Fita::Fita(int codigo, const std::string &titulo, int quantidade, bool rebobinada)
    : Filme(codigo, titulo, quantidade), rebobinada(rebobinada) {}

std::string Fita::getTipo() const {
    return "FITA";
}


double Fita::calcularValorLocacao(int dias) const {
    double valor = 5.0 * dias;

    if (!rebobinada) {
        valor += 2.0; // Multa por não rebobinar
    }

    return valor;
}