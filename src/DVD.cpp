#include <iostream>
#include "DVD.hpp"

DVD::DVD(int codigo, int quantidade, const std::string& titulo, Categoria categoria) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->quantidadeDisponivel = quantidade;
    this->quantidadeEstoque = quantidade;
    this->categoria = categoria;
}

double DVD::calcularPreco(int diasLocacao) const {
    double precoBase = 0.0;

    switch (categoria) {
    case Lancamento:
        precoBase = 20.0;
        break;
    case Estoque:
        precoBase = 10.0;
        break;
    case Promocao:
        return 10.0;
        break;
    }

    return precoBase * diasLocacao;
}

void DVD::imprimir() const {
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Codigo: " << getCodigo() << ", Quantidade: " << this->quantidadeDisponivel << ", Categoria: ";

    switch (categoria) {
    case Lancamento:
        std::cout << "Lancamento";
        break;
    case Estoque:
        std::cout << "Estoque";
        break;
    case Promocao:
        std::cout << "Promocao";
        break;
    }
    std::cout << std::endl;
}

int DVD::getCodigo() const {
    return this->codigo;
}