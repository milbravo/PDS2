#include "DVD.hpp"
#include <stdexcept>
#include <iostream>

DVD::DVD(int codigo, std::string titulo, int quantidade, std::string categoria)
    : Filme(codigo, titulo, quantidade), categoria(categoria) {}

std::string DVD::getTipo()
{
    return "DVD";
}

double DVD::calcularValorLocacao(int dias)
{
    double valor = 0.0;

    if (categoria == "Lancamento")
    {
        valor = 20.0 * dias;
    }
    else if (categoria == "Estoque" || categoria == "Promocao")
    {
        valor = 10.0 * dias;
    }
    else if (categoria == "Promocao")
    {
        valor = 10.0;
    }

    return valor;
}
