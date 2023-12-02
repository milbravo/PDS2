#include "doctest.h"
#include "FITA.hpp"

TEST_CASE("Teste Fita - Geral")
{
    Fita teste = Fita(99, "FilmeTeste", 3, true);
    Fita teste2 = Fita(98, "FilmeTeste", 3, false);
    CHECK(teste.getTipo() == "FITA");
    CHECK(teste.calcularValorLocacao(0) == 5);
    CHECK(teste2.calcularValorLocacao(3) == 7);
}
