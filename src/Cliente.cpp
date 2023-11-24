#include <iostream>
#include "Cliente.hpp"

Cliente::Cliente(const std::string& cpf, const std::string& nome){
    this->cpf = cpf;
    this->nome = nome;
}

void Cliente::imprimirInformacoes() const {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "CPF: " << cpf << std::endl;
    std::cout << "Filmes Alugados: ";
    
    if (filmesAlugados.empty()) {
        std::cout << "Nenhum filme alugado";
    } else {
        for (int codigoFilme : filmesAlugados) {
            std::cout << codigoFilme << " ";
        }
    }
    
    std::cout << std::endl;
}

std::string Cliente::getCpf() {
    return cpf;
}

std::string Cliente::getNome() {
    return nome;
}

std::vector<int> Cliente::getFilmes() {
    return filmesAlugados;
}

void Cliente::addFilme(int filme){
    this->filmesAlugados.push_back(filme);
}

void Cliente::devolverFilmes(){
    this->filmesAlugados.clear();
}