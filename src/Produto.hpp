#ifndef PRODUTO_HPP
#define PRODUTO_HPP

#include <iostream>
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

    bool validaEstoque(){
        if(quantidadeDisponivel > 0){
            return true;
        }else{
            return false;
        }
    }

    void alugaFilme(){
        quantidadeDisponivel--;
    }

    void devolverFilme(){
        quantidadeDisponivel++;
    }

    void aumentarEstoque(int qtd) {
        std::cout << "Novo estoque foi de: " << this->quantidadeEstoque << ", sendo " << this->quantidadeDisponivel << " disponiveis" << std::endl;
        this->quantidadeDisponivel += qtd;
        this->quantidadeEstoque += qtd;
        std::cout << "Para: " << this->quantidadeEstoque << ", sendo " << this->quantidadeDisponivel << " disponiveis" << std::endl;
    }

    void diminuirEstoque(int qtd) {

        if (qtd > this->quantidadeEstoque) {
            std::cout << "Nao e possivel retirar mais produtos do que temos" << std::endl;
        }
        else if (qtd > this->quantidadeDisponivel) {
            std::cout << "Produto alugado, nao e possivel diminuir o estoque" << std::endl;
        }
        else {
            std::cout << "Novo estoque foi de: " << this->quantidadeEstoque << ", sendo " << this->quantidadeDisponivel << " disponiveis" << std::endl;
            this->quantidadeDisponivel -= qtd;
            this->quantidadeEstoque -= qtd;
            std::cout << "Para: " << this->quantidadeEstoque << ", sendo " << this->quantidadeDisponivel << " disponiveis" << std::endl;
        }
    }
};

#endif