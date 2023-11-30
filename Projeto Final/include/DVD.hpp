#ifndef DVD_HPP
#define DVD_HPP

#include "Filme.hpp"

class DVD : public Filme
{
public:
    DVD(int codigo, std::string titulo, int quantidade, std::string categoria);

    virtual std::string getTipo() override;
    virtual double calcularValorLocacao(int dias) override;

private:
    std::string categoria;
};

#endif // DVD_HPP
