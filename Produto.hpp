#ifndef PRODUTO_HPP
#define PRODUTO_HPP
#pragma once
#include "string"
#include <stdbool.h>


class Produto {
protected:
    int codigo;
    bool hasAlugado = false;
    std::string titulo;

public:
    virtual ~Produto() = default;
    virtual double calcularPreco(int diasLocacao) const = 0;
    virtual void imprimir() const = 0;
    virtual int getCodigo() const = 0;

    std::string getTitulo() const {
        return titulo;
    }

};

#endif