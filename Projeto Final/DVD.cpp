#include "DVD.hpp"
#include <stdexcept> 
#include <iostream>

DVD::DVD(int codigo, const std::string &titulo, int quantidade, const std::string &categoria)
    : Filme(codigo, titulo, quantidade), categoria(categoria) {}

std::string DVD::getTipo() const {
    return "DVD";
}


double DVD::calcularValorLocacao(int dias) const {
    double valor = 0.0;

    if (categoria == "Lancamento") {
        valor = 20.0 * dias;
    } else if (categoria == "Estoque" || categoria == "Promocao") {
        valor = 10.0 * dias;
    } else {
        std::cout << "Categoria de DVD inválida.\n";
    }

    return valor;
}
