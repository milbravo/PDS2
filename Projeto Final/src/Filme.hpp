#ifndef FILME_HPP
#define FILME_HPP

#include <string>

class Filme {
public:
    Filme(int codigo, const std::string &titulo, int quantidade);
    virtual ~Filme() = default;

    int getCodigo() const;
    std::string getTitulo() const;
    int getQuantidade() const;
    virtual std::string getTipo() const = 0;
    virtual double calcularValorLocacao(int dias) const = 0;
    void diminuirQuantidade(); 
    void aumentarQuantidade();
  
private:
    int codigo;
    std::string titulo;
    int quantidade;
};

#endif // FILME_HPP
