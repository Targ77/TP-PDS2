#ifndef FITACASSETE_HPP
#define FITACASSETE_HPP
#pragma once
#include "Produto.hpp"
#include "string";

class FitaCassete : public Produto {
public:
    FitaCassete(int codigo, const std::string& titulo);
    double calcularPreco(int diasLocacao) const override;
    void imprimir() const override;
    int getCodigo() const override;

private:
    bool rebobinada;
};
#endif