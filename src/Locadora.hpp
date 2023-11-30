#ifndef LOCADORA_HPP
#define LOCADORA_HPP

#include <iostream>
#include "Estoque.hpp"
#include "ControleCliente.hpp"

class Locadora {
private:
    Estoque estoque;
    ControleCliente controleCliente;

public:
    void lerArquivoCadastro(const std::string& nomeArquivo);
    void cadastrarFita(int codigo, int quantidade, const std::string& titulo);
    void cadastrarDVD(int codigo, int quantidade, const std::string& titulo, const std::string& categoria);
    void removerProduto(int codigo);
    void listarProdutosOrdenadosPorCodigo();
    void listarProdutosOrdenadosPorTitulo();//Falta implementar
    void cadastrarCliente(const std::string& cpf, const std::string& nome);
    void removerCliente(const std::string& cpf);
    void listarClientesOrdenadosPorCpf();
    void listarClientesOrdenadosPorNome();//Falta implementar
    void alugarFilme(const std::string& cpf, std::vector<int> filmesAlugados);
    void devolverFilme(const std::string& cpf, int diasLocacao);
    void aumentarEstoque(int codigo, int qtd);
    void diminuirEstoque(int codigo, int qtd);
};

#endif