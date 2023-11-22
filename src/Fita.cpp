#include "Fita.hpp"
#include <iostream>

Fita::Fita(int codigo, int quantidade, const std::string& titulo) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->quantidadeDisponivel = quantidade;
    this->quantidadeEstoque = quantidade;
}

double Fita::calcularPreco(int diasLocacao) const {
    double precoBase = 5.0;
    return precoBase * diasLocacao;
}

void Fita::imprimir() const {
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Codigo: " << getCodigo() << ", Quantidade: " << this->quantidadeDisponivel << std::endl;
    std::cout << "---------------" << std::endl;
}

int Fita::getCodigo() const {
    return this->codigo;
}