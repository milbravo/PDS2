#include "doctest.h"
#include "DVD.hpp"

TEST_CASE("Teste DVD - Geral")
{
    DVD teste = DVD(99, "FilmeTeste", 3, "Promocao");
    DVD teste2 = DVD(98, "FilmeTeste", 3, "Lancamento");
    DVD teste3 = DVD(97, "FilmeTeste", 3, "Estoque");
    CHECK(teste.getTipo() == "DVD");
    CHECK(teste.calcularValorLocacao(3) == 10);
    CHECK(teste2.calcularValorLocacao(3) == 60);
    CHECK(teste3.calcularValorLocacao(3) == 30);
}
TEST_CASE("Teste DVD - Dia zerado")
{
    DVD teste = DVD(99, "FilmeTeste", 3, "Promocao");
    DVD teste2 = DVD(98, "FilmeTeste", 3, "Lancamento");
    DVD teste3 = DVD(97, "FilmeTeste", 3, "Estoque");
    CHECK(teste.calcularValorLocacao(0) == 10);
    CHECK(teste2.calcularValorLocacao(0) == 20);
    CHECK(teste3.calcularValorLocacao(0) == 10);
}