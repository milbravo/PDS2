#ifndef DVD_HPP
#define DVD_HPP

#include "Filme.hpp"

class DVD : public Filme {
public:
    DVD(int codigo, const std::string &titulo, int quantidade, const std::string &categoria);
    virtual ~DVD() = default;

    std::string getTipo() const override;
    double calcularValorLocacao(int dias) const override;

private:
    std::string categoria;
};

#endif // DVD_HPP

