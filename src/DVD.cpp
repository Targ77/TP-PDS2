#include <iostream>
#include "DVD.hpp"
#include <algorithm>

DVD::DVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria) {
    this->codigo = codigo;
    this->titulo = titulo;
    this->quantidadeDisponivel = quantidade;
    this->quantidadeEstoque = quantidade;
    this->categoria = getCategoria(categoria);
}

double DVD::calcularPreco(int diasLocacao) const {
    double precoBase = 0.0;

    switch (categoria) {
    case Lancamento:
        precoBase = 20.0;
        break;
    case Estoque:
        precoBase = 10.0;
        break;
    case Promocao:
        std::cout << "Codigo: " << getCodigo() << " | Valor: 10" << std::endl;
        return 10.0;
        break;
    }

    double valor = precoBase * diasLocacao;
    std::cout << "Codigo: " << getCodigo() << " | Valor: " << valor << std::endl;
    return valor;
}

bool DVD::validaCategoria(){
    if(this->categoria == DVD::Erro){
        return false;
    }else{
        return true;
    }
}

void DVD::imprimir() const {
    std::cout << "Titulo: " << titulo << std::endl;
    std::cout << "Codigo: " << getCodigo() << ", Quantidade: " << this->quantidadeDisponivel << ", Categoria: ";

    switch (categoria) {
    case Lancamento:
        std::cout << "Lancamento";
        break;
    case Estoque:
        std::cout << "Estoque";
        break;
    case Promocao:
        std::cout << "Promocao";
        break;
    }
    std::cout << std::endl;
    std::cout << "---------------" << std::endl;
}

int DVD::getCodigo() const {
    return this->codigo;
}

DVD::Categoria DVD::getCategoria(const std::string& categoria) {
    std::string categoriaLowerCase = categoria;
    std::transform(categoriaLowerCase.begin(), categoriaLowerCase.end(), categoriaLowerCase.begin(), ::tolower);

    if (categoriaLowerCase == "lancamento") {
        return Categoria::Lancamento;
    } else if (categoriaLowerCase == "estoque") {
        return Categoria::Estoque;
    } else if (categoriaLowerCase == "promocao") {
        return Categoria::Promocao;
    } else {

        return Categoria::Erro;
    }
}
