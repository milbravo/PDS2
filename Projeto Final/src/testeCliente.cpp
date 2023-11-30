
#include "doctest.h"
#include "Cliente.hpp"

TEST_CASE("Teste Cliente")
{
    Cliente teste = Cliente("12590359640", "Milton");
    CHECK(teste.getCPF() == "12590359640");
    CHECK(teste.getNome() == "Milton");
}