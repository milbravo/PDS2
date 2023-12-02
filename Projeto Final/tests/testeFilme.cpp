#include "doctest.h"
#include "Fita.hpp"

TEST_CASE("Teste Filme - Geral")
{
    Fita teste = Fita(99, "FilmeTeste", 3, true);
    CHECK(teste.getCodigo() == 99);
    CHECK(teste.getTitulo() == "FilmeTeste");
    CHECK(teste.getQuantidade() == 3);
    teste.diminuirQuantidade();
    teste.diminuirQuantidade();
    CHECK(teste.getQuantidade() == 1);
    teste.aumentarQuantidade();
    CHECK(teste.getQuantidade() == 2);
}