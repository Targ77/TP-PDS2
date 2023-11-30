#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include "string"
#include <stdbool.h>


class Produto {
protected:
    int codigo;
    int quantidadeEstoque;
    int quantidadeDisponivel;
    std::string titulo;

public:
    virtual ~Produto() = default;
    virtual double calcularPreco(int diasLocacao) const = 0;
    virtual void imprimir() const = 0;
    virtual int getCodigo() const = 0;

    std::string getTitulo() const {
        return titulo;
    }

    void alugaFilme(){
        quantidadeDisponivel--;
    }

    bool validaEstoque(){
        if(quantidadeDisponivel > 0){
            return true;
        }else{
            return false;
        }
    }

    void devolverFilme(){
        quantidadeDisponivel++;
    }
};

#endif