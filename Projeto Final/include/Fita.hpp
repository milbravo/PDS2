#ifndef FITA_HPP
#define FITA_HPP

#include <random>
#include <algorithm>
#include "Filme.hpp"

class Fita : public Filme
{
public:
    Fita(int codigo, std::string titulo, int quantidade, bool rebobinada);

    virtual std::string getTipo() override;
    virtual double calcularValorLocacao(int dias) override;

private:
    bool rebobinada;
};

#endif // FITA_HPP
