#include "Estoque.hpp"
#include "DVD.hpp"
#include "Fita.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Estoque::adicionarProduto(std::unique_ptr<Produto> produto) {
    produtos[produto->getCodigo()] = std::move(produto);
}

void Estoque::removerProduto(int codigo) {
    produtos.erase(codigo);
}

Produto* Estoque::buscarProduto(int codigo) {
    auto it = produtos.find(codigo);
    if (it != produtos.end()) {
        return it->second.get();
    }
    return nullptr;
}

void Estoque::imprimirRelatorio() const {
    for (const auto& pair : produtos) {
        std::cout << "Codigo: " << pair.first << ", ";
        pair.second->imprimir();
    }
}

int Estoque::quantidadeTitulo(const std::string& titulo){
    int quant = 0;
    for (const auto& elemento : produtos) {
        if (elemento.second->getTitulo() == titulo) {
            quant++;
        }
    }
    return quant;
}

void Estoque::lerArquivoCadastro(const std::string& nomeArquivo) {
    std::ifstream arquivo(nomeArquivo);

    if (!arquivo.is_open()) {
        std::cout << "ERRO: arquivo inexistente" << std::endl;
        return;
    }

    std::string linha;
    int numProdutosCadastrados = 0;

    while (std::getline(arquivo, linha)) {
        std::istringstream iss(linha);
        std::string comando;
        iss >> comando;

        if (comando == "CF") {
            char tipo;
            int codigo, categoria;
            std::string titulo;

            iss >> tipo >> codigo >> titulo;

            if (tipo == 'F') {
                // Filme
                std::unique_ptr<Produto> fita = std::make_unique<Fita>(codigo, titulo);
                adicionarProduto(std::move(fita));
                numProdutosCadastrados++;
                std::cout << "Fita " << codigo << " cadastrado com sucesso" << std::endl;
            }
            else if (tipo == 'D') {
                // DVD
                iss >> categoria;
                DVD::Categoria categoriaConstrutor;

                switch (categoria) {
                case 1:
                    categoriaConstrutor = DVD::Lancamento;
                    break;
                case 2:
                    categoriaConstrutor = DVD::Estoque;
                    break;
                case 3:
                    categoriaConstrutor = DVD::Promocao;
                    break;
                }

                std::unique_ptr<Produto> dvd = std::make_unique<DVD>(codigo, titulo, categoriaConstrutor);
                adicionarProduto(std::move(dvd));
                numProdutosCadastrados++;
                std::cout << "DVD " << codigo << " cadastrado com sucesso" << std::endl;
            }
            else {
                std::cout << "ERRO: dados incorretos" << std::endl;
            }
        }
        else {
            std::cout << "ERRO: comando desconhecido" << std::endl;
        }
    }

    arquivo.close();

    std::cout << "[" << numProdutosCadastrados << "] Filmes cadastrados com sucesso" << std::endl;
}