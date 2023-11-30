#include "Estoque.hpp"
#include "DVD.hpp"
#include "Fita.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Estoque::adicionarFita(int codigo, int quantidade, const std::string& titulo) {

    auto it = produtos.find(codigo);
    if (it == produtos.end()) {
        produtos[codigo] = new Fita(codigo, quantidade, titulo);
        std::cout << "Produto com codigo " << codigo << " cadastrado com sucesso." << std::endl;
    } else{
        std::cout << "Produto com codigo " << codigo << " já existe." << std::endl;
    }
}

void Estoque::adicionarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria) {

    auto it = produtos.find(codigo);
    if (it == produtos.end()) {
        produtos[codigo] = new DVD(codigo, quantidade, titulo, categoria);
        std::cout << "Produto com codigo " << codigo << " cadastrado com sucesso." << std::endl;
    } else{
        std::cout << "Produto com codigo " << codigo << " já existe." << std::endl;
    }
}

void Estoque::removerProduto(int codigo) {
    auto it = produtos.find(codigo);

    if (it != produtos.end()) {
        produtos.erase(it);
        std::cout << "Produto com codigo " << codigo << " removido com sucesso." << std::endl;
    } else {
        std::cout << "Produto com codigo " << codigo << " não encontrado." << std::endl;
    }
}

Produto* Estoque::buscarProduto(int codigo) {
    auto it = produtos.find(codigo);
    if (it != produtos.end()) {
        return it->second;
    }
    return nullptr;
}

void Estoque::imprimirRelatorio() const {

    if(!this->produtos.empty()){
        std::cout << "Relatorio de estoque:" << std::endl;
        std::cout << std::endl;

        for (const auto& pair : produtos) {

            pair.second->imprimir();
        }

    }else{
        std::cout << "Estoque Vazio!!" << std::endl;
    }

}

void Estoque::lerArquivoCadastro(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "ERRO: arquivo inexistente" << std::endl;
        return;
    }

    std::string linha;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "CF") {
            char tipo;
            int codigo, quantidade;
            std::string titulo, categoria;

            iss >> tipo >> quantidade >> codigo >> titulo;

            if (tipo == 'F') {

                adicionarFita(codigo, quantidade, titulo);
                std::cout << "Fita " << codigo << " cadastrado com sucesso" << std::endl;
            }else if (tipo == 'D') {

                iss >> categoria;
                adicionarDVD(codigo, quantidade, titulo, categoria);
                std::cout << "DVD " << codigo << " cadastrado com sucesso" << std::endl;
            }else {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }
            
        }else {
            std::cout << "ERRO: comando desconhecido" << std::endl;
        }
        
    }

    std::cout << std::endl;

    arquivo.close();

}

bool Estoque::validaProdutoLocacao(int codigo){
    auto it = produtos.find(codigo);

    if (it != produtos.end()) {
        return true;    
    } else {
        std::cout << "Produto com codigo " << codigo << " nao encontrado." << std::endl;
        return false;
    }
}

bool Estoque::validaProdutoEstoque(int codigo){
    auto it = produtos.find(codigo);

    if (it != produtos.end() && it->second->validaEstoque()) {
        return true;    
    } else {
        std::cout << "Produto com codigo " << codigo << " sem estoque." << std::endl;
        return false;
    }
}

void Estoque::alugaProduto(int codigo){
    auto it = produtos.find(codigo);
    it->second->alugaFilme();
}

double Estoque::devolveLocacao(int codigo, int dias){
    auto it = produtos.find(codigo);
    it->second->devolverFilme();
    return it->second->calcularPreco(dias);
    
}

void Estoque::imprimirRelatorioOrdenadoPorTitulo() const {
    std::map<std::string, Produto*> produtosPorTitulo;
    if(!this->produtos.empty()){
        std::cout << "Relatorio de estoque:" << std::endl;
        std::cout << std::endl;

        for (auto pair : produtos) {
            produtosPorTitulo[pair.second->getTitulo()] = pair.second;
        }

        for (auto pair : produtosPorTitulo) {
           pair.second->imprimir();
        }

    }else{
        std::cout << "Estoque Vazio!!" << std::endl;
    }
}