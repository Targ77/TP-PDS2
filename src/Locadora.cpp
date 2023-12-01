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
    
    if(controleCliente.estaAlugado(codigo)){
        this->estoque.removerProduto(codigo);
    }else{
        std::cout << "Produto com codigo "<< codigo << " nao pode ser excluido, item ainda esta alugado." << std::endl;
    }

}

void Locadora::listarProdutosOrdenadosPorCodigo() {
    this->estoque.imprimirRelatorio();
}

void Locadora::listarProdutosOrdenadosPorTitulo() {
    this->estoque.imprimirRelatorioOrdenadoPorTitulo();
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
    this->controleCliente.imprimirRelatorioOrdenadoPorNome();
}

void Locadora::alugarFilme(const std::string& cpf, std::vector<int> filmesAlugados) {
    std::vector<int> filmesIndisponiveis;
    int vrf = 0;

    if(controleCliente.validaCliente(cpf)){

        for (int filme : filmesAlugados) {
            if(estoque.validaProdutoLocacao(filme) && estoque.validaProdutoEstoque(filme)){
                controleCliente.alugarFilme(cpf, filme);
                estoque.alugaProduto(filme);
                vrf = 1;
            }else{
                filmesIndisponiveis.push_back(filme);
            }
        }
    }
    
    if(!filmesIndisponiveis.empty()){
        std::cout << "Produtos indisponiveis: ";
        for (int filme : filmesIndisponiveis) {
            std::cout << filme << " ";
        }
        std::cout << std::endl;
    }else if (vrf == 1){
        std::cout << "Todos produtos alugados. " << std::endl;
    }

}

void Locadora::devolverFilme(const std::string& cpf, int diasLocacao) {
    double valorTotal = 0;
    if(controleCliente.validaCliente(cpf)){
        Cliente* cliente = controleCliente.encontrarCliente(cpf);

        if(cliente->getFilmes().empty()){
            std::cout << "Nao ha filmes a serem devolvidos" << std::endl;

        }
        else{
            for (int filme : cliente->getFilmes()) {
                if(estoque.validaProdutoLocacao(filme)){
                valorTotal = valorTotal + estoque.devolveLocacao(filme, diasLocacao);
                }
            }
            cliente->devolverFilmes();
            std::cout << "Valor Total: " << valorTotal << std::endl;
        }
    }
}

void Locadora::aumentarEstoque(int codigo, int qtd) {
    this->estoque.aumentarEstoque(codigo, qtd);

}
void Locadora::diminuirEstoque(int codigo, int qtd) {
    this->estoque.diminuirEstoque(codigo, qtd);

}