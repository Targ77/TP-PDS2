#ifndef ESTOQUE_HPP
#define ESTOQUE_HPP

#include <map>
#include "Produto.hpp"
#include <memory>

class Estoque {
public:
    void adicionarProduto(std::unique_ptr<Produto> produto );
    void removerProduto(int codigo);
    Produto* buscarProduto(int codigo);
    void imprimirRelatorio() const;
    int quantidadeTitulo(const std::string& titulo);
    void lerArquivoCadastro(const std::string& nomeArquivo);
private:
    std::map<int, std::unique_ptr<Produto>> produtos;
};
#endif