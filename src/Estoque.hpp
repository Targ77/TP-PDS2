#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <map>
#include "Produto.hpp"
#include <memory>
#include <iostream>

class Estoque {
private:
    std::map<int, Produto*> produtos;

public:
    void adicionarFita(int codigo, int quantidade, const std::string& titulo);
    void adicionarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria);
    void removerProduto(int codigo);
    Produto* buscarProduto(int codigo);
    void imprimirRelatorio() const;
    void lerArquivoCadastro(const std::string& nomeArquivo);
    bool validaProdutoLocacao(int codigo);
    bool validaProdutoEstoque(int codigo);
    double devolveLocacao(int codigo, int dias);
    void alugaProduto(int codigo);
    void imprimirRelatorioOrdenadoPorTitulo() const;
    void aumentarEstoque(int codigo, int qtd);
    void diminuirEstoque(int codigo, int qtd);
};
#endif