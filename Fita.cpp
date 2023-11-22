#include "Fita.hpp"
#include <iostream>

FitaCassete::FitaCassete(int codigo, const std::string& titulo) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->rebobinada = true;
}

double FitaCassete::calcularPreco(int diasLocacao) const {
    double precoBase = 5.0;
    if (!rebobinada) {
        precoBase += 2.0;
    }
    return precoBase * diasLocacao;
}

void FitaCassete::imprimir() const {
    std::cout << "Titulo: " << titulo << ", Rebobinada: " << (rebobinada ? "Sim" : "Nao") << std::endl;
}

int FitaCassete::getCodigo() const {
    return this->codigo;
}