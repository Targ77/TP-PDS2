#ifndef DVD_HPP
#define DVD_HPP

#include "Produto.hpp"
#include "string"

class DVD : public Produto {
public:
    enum Categoria { Lancamento, Estoque, Promocao };

    DVD(int codigo, int quantidade, const std::string& titulo, Categoria categoria);
    double calcularPreco(int diasLocacao) const override;
    void imprimir() const override;
    int getCodigo() const override;

private:
    Categoria categoria;
};

#endif 