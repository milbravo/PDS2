#ifndef FILME_HPP
#define FILME_HPP

#include <string>

class Filme
{
public:
    Filme(int codigo, std::string titulo, int quantidade);
    virtual ~Filme();
    int getCodigo();
    std::string getTitulo();
    int getQuantidade();
    virtual std::string getTipo() = 0;
    virtual double calcularValorLocacao(int dias) = 0;
    void diminuirQuantidade();
    void aumentarQuantidade();

private:
    int codigo;
    std::string titulo;
    int quantidade;
};

#endif // FILME_HPP
