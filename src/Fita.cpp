#include "Fita.hpp"
#include <iostream>
#include <random>

Fita::Fita(int codigo, int quantidade, const std::string& titulo) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->quantidadeDisponivel = quantidade;
    this->quantidadeEstoque = quantidade;
}

double Fita::calcularPreco(int diasLocacao) const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0.0, 1.0);

    double randomValue = dis(gen);
    double precoBase = 5.0;
    double valor = precoBase * diasLocacao;

    if (randomValue < 0.5) {
        valor += 2.0;  
        std::cout << "Codigo: " << getCodigo() << " | Valor: " << valor << " | Fita nao foi rebobinada." << std::endl;
        return valor;
    }else{
        std::cout << "Codigo: " << getCodigo() << " | Valor: " << valor << std::endl;
        return valor;
    }
}

void Fita::imprimir() const {
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Codigo: " << getCodigo() << ", Quantidade: " << this->quantidadeDisponivel << std::endl;
    std::cout << "---------------" << std::endl;
}

int Fita::getCodigo() const {
    return this->codigo;
}