#ifndef FITA_HPP
#define FITA_HPP

#include "Filme.hpp"

class Fita : public Filme {
public:
    Fita(int codigo, const std::string &titulo, int quantidade, bool rebobinada);
    virtual ~Fita() = default;

    std::string getTipo() const override;
    double calcularValorLocacao(int dias) const override;

private:
    bool rebobinada;
};

#endif // FITA_HPP
