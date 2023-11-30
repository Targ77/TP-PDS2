#include <iostream>
#include "DVD.hpp"
#include "Fita.hpp"
#include "Estoque.hpp"
#include "ControleCliente.hpp"
#include "Cliente.hpp"
#include "Locadora.hpp"
#include <fstream>
#include <sstream>

void imprimirInstrucoesEntrada() {
    std::cout << "Bem-Vindo a Nossa Locadora" << std::endl;
    std::cout << std::endl;
    std::cout << "Instrucoes de Entrada:" << std::endl;
    
    std::cout << "1. Ler Arquivo de Cadastro:" << std::endl;
    std::cout << "   LA <Nome do Arquivo>" << std::endl;

    std::cout << "2. Cadastrar Filme:" << std::endl;
    std::cout << "   CF <Tipo: F|D> <quantidade> <codigo> <titulo> <categoria no caso de DVD>" << std::endl;

    std::cout << "3. Remover Filme:" << std::endl;
    std::cout << "   RF <codigo>" << std::endl;

    std::cout << "4. Listar Filmes ordenados por Codigo ou Titulo:" << std::endl;
    std::cout << "   LF [C|T]" << std::endl;

    std::cout << "5. Cadastrar Cliente:" << std::endl;
    std::cout << "   CC <CPF> <Nome>" << std::endl;

    std::cout << "6. Remover Cliente:" << std::endl;
    std::cout << "   RC <CPF>" << std::endl;

    std::cout << "7. Listar Clientes ordenados por Codigo ou Nome:" << std::endl;
    std::cout << "   LC [C|N]" << std::endl;

    std::cout << "8. Aluguel Filme:" << std::endl;
    std::cout << "   AL <CPF> <Codigo1> … <Codigo N>" << std::endl;

    std::cout << "9. Devolucao Filme:" << std::endl;
    std::cout << "   DV <CPF> <Dias Locacao>" << std::endl;

    std::cout << "10. Finalizar Sistema:" << std::endl;
    std::cout << "    FS" << std::endl;
}

int main() {
    Locadora locadora;

    std::string comando;
    imprimirInstrucoesEntrada();

    while (true) {
        std::cout << "Digite um comando (ou 'FS' para finalizar): ";
        std::getline(std::cin, comando);

        std::istringstream iss(comando);
        std::string operacao;
        iss >> operacao;

        if (operacao == "LA") {
            std::string nomeArquivo;
            iss >> nomeArquivo;
            locadora.lerArquivoCadastro(nomeArquivo);

        } else if (operacao == "CF") {
            char tipo;
            int quantidade, codigo;
            std::string titulo, categoria;

            iss >> tipo >> quantidade >> codigo >> titulo;
            if (tipo == 'D') {
                iss >> categoria;
                locadora.cadastrarDVD(codigo, quantidade, titulo, categoria);
            } else if (tipo == 'F') {
                locadora.cadastrarFita(codigo, quantidade, titulo);
            } else {
                std::cerr << "ERRO: Tipo de filme inválido." << std::endl;
            }

        } else if (operacao == "RF") {
            int codigo;
            iss >> codigo;

            locadora.removerProduto(codigo);

        } else if (operacao == "LF") {
            char opcao;
            iss >> opcao;

            if (opcao == 'C') {
                locadora.listarProdutosOrdenadosPorCodigo();
            } else if (opcao == 'T') {
                locadora.listarProdutosOrdenadosPorTitulo();
            } else {
                std::cerr << "ERRO: Tipo de listagem inválido." << std::endl;
            }

        } else if (operacao == "CC") {
            std::string cpf, nome;
            iss >> cpf >> nome;

            locadora.cadastrarCliente(cpf, nome);

        } else if (operacao == "RC") {
            std::string cpf;
            iss >> cpf;

            locadora.removerCliente(cpf);

        } else if (operacao == "LC") {
            char opcao;
            iss >> opcao;

            if (opcao == 'C') {
                locadora.listarClientesOrdenadosPorCpf();
            } else if (opcao == 'N') {
                locadora.listarClientesOrdenadosPorNome();
            } else {
                std::cerr << "ERRO: Tipo de listagem inválido." << std::endl;
            }

        } else if (operacao == "AL") {
            std::string cpf;
            iss >> cpf;

            std::vector<int> codigosProdutos;
            int codigoProduto;
            while (iss >> codigoProduto) {
                codigosProdutos.push_back(codigoProduto);
            }

            locadora.alugarFilme(cpf, codigosProdutos);

        } else if (operacao == "DV") {
            std::string cpf;
            int dias;
            iss >> cpf;
            iss >> dias;

            locadora.devolverFilme(cpf, dias);

        } else if (operacao == "FS") {
            std::cout << "Sistema finalizado." << std::endl;
            break;
        } else {
            std::cerr << "Comando inválido." << std::endl;
        }
    }

    return 0;
}