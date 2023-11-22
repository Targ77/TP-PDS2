#ifndef DVD_HPP
#define DVD_HPP
#pragma once
#include "Produto.hpp"
#include "string";

class DVD : public Produto {
public:
    enum Categoria { Lancamento, Estoque, Promocao };

    DVD(int codigo, const std::string& titulo, Categoria categoria);
    double calcularPreco(int diasLocacao) const override;
    void imprimir() const override;
    int getCodigo() const override;

private:
    Categoria categoria;
};

#endif 