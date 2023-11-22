#include <iostream>
#include "DVD.hpp"
#include "Fita.hpp"

int main() {
    Produto* dvd = new DVD(1, 10, "Meu DVD", DVD::Lancamento);
    dvd->imprimir();

    Produto* fita = new Fita(2, 10, "Minha Fita");
    fita->imprimir();

    return 0;
}