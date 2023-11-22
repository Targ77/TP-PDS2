#include <iostream>
#include "DVD.hpp"
#include "Fita.hpp"
#include "Estoque.hpp"

int main() {

    Estoque estoque;

    //estoque.adicionarDVD(1, 10, "Meu DVD", "lancamento");
    //estoque.adicionarFita(2, 10, "Minha Fita");
    estoque.lerArquivoCadastro("cadastro.txt");
    estoque.imprimirRelatorio();

    return 0;
}