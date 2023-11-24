#include "Locadora.hpp"
#include <iostream>
#include <algorithm>

void Locadora::lerArquivoCadastro(const std::string& nomeArquivo) {
    estoque.lerArquivoCadastro(nomeArquivo);
}

void Locadora::cadastrarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria){
    this->estoque.adicionarDVD(codigo, quantidade, titulo, categoria);
}

void Locadora::cadastrarFita(int codigo, int quantidade, const std::string& titulo){
    this->estoque.adicionarFita(codigo, quantidade, titulo);
}

void Locadora::removerProduto(int codigo) {
    
    this->estoque.removerProduto(codigo);
}

void Locadora::listarProdutosOrdenadosPorCodigo() {
    this->estoque.imprimirRelatorio();
}

void Locadora::listarProdutosOrdenadosPorTitulo() {

}

void Locadora::cadastrarCliente(const std::string& cpf, const std::string& nome) {
    this->controleCliente.adicionarCliente(cpf, nome);
}

void Locadora::removerCliente(const std::string& cpf) {
    this->controleCliente.removerCliente(cpf);
}

void Locadora::listarClientesOrdenadosPorCpf() {
    this->controleCliente.imprimirRelatorio();
}

void Locadora::listarClientesOrdenadosPorNome() {
    // Implemente a lógica para listar clientes ordenados por nome
}

void Locadora::alugarFilme(const std::string& cpf, std::vector<int> filmesAlugados) {
    std::vector<int> filmesIndeisponiveis;

    if(controleCliente.validaCliente(cpf)){

        for (int filme : filmesAlugados) {
            if(estoque.validaProduto(filme)){
                controleCliente.alugarFilme(cpf, filme);
            }else{
                filmesIndeisponiveis.push_back(filme);
            }
        }
    }
    if(!filmesIndeisponiveis.empty()){
        std::cout << "Produtos indisponiveis: ";
        for (int filme : filmesIndeisponiveis) {
            std::cout << filme << " ";
        }
    }

}

void Locadora::devolverFilme(const std::string& cpf, int diasLocacao) {
    // Implemente a lógica para devolver um filme
}
