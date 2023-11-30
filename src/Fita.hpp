#ifndef FITA_HPP
#define FITA_HPP

#include <iostream>
#include "Produto.hpp"
#include "string"


class Fita : public Produto {
public:
    Fita(int codigo, int quantidade, const std::string& titulo);
    double calcularPreco(int diasLocacao) const override;
    void imprimir() const override;
    int getCodigo() const override;
};
#endif