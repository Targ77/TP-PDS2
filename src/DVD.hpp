#ifndef DVD_HPP
#define DVD_HPP

#include <iostream>
#include "Produto.hpp"
#include "string"

class DVD : public Produto {
public:
    //1, 2, 3
    enum Categoria { Lancamento, Estoque, Promocao };

    DVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria);
    double calcularPreco(int diasLocacao) const override;
    void imprimir() const override;
    int getCodigo() const override;
    DVD::Categoria getCategoria(const std::string& categoria);

private:
    Categoria categoria;
};

#endif 