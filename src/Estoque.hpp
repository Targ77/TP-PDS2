#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <map>
#include "Produto.hpp"
#include <memory>

class Estoque {
private:
    std::map<int, Produto*> produtos;

public:
    void adicionarFita(int codigo, int quantidade, const std::string& titulo);
    void adicionarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria);
    void removerProduto(int codigo);
    Produto* buscarProduto(int codigo);
    void imprimirRelatorio() const;
    int quantidadeTitulo(const std::string& titulo);
    void lerArquivoCadastro(const std::string& nomeArquivo);
    bool validaProdutoLocacao(int codigo);
    double devolveLocacao(int codigo, int dias);
    bool alugaProduto(int codigo);
    void imprimirRelatorioOrdenadoPorTitulo() const;
};
#endif