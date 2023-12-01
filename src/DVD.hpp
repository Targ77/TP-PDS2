#ifndef DVD_HPP
#define DVD_HPP

#include <iostream>
#include "Produto.hpp"
#include "string"

class DVD : public Produto {
public:
    
    enum Categoria { Lancamento, Estoque, Promocao, Erro };

    DVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria);
    double calcularPreco(int diasLocacao) const override;
    void imprimir() const override;
    int getCodigo() const override;
    DVD::Categoria getCategoria(const std::string& categoria);
    bool validaCategoria();

private:
    Categoria categoria;
};

#endif 