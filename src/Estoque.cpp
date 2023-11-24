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
    } else{
        std::cout << "Produto com codigo " << codigo << " já existe." << std::endl;
    }
}

void Estoque::adicionarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria) {

    auto it = produtos.find(codigo);
    if (it == produtos.end()) {
        produtos[codigo] = new DVD(codigo, quantidade, titulo, categoria);
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

bool Estoque::validaProduto(int codigo){
    auto it = produtos.find(codigo);

    if (it != produtos.end()) {
        return true;
    } else {
        std::cout << "Produto com codigo " << codigo << " não encontrado." << std::endl;
        return false;
    }
}