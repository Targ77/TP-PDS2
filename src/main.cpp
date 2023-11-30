#include <iostream>
#include "DVD.hpp"
#include "Fita.hpp"
#include "Estoque.hpp"
#include "ControleCliente.hpp"
#include "Cliente.hpp"
#include "Locadora.hpp"
#include <fstream>
#include <sstream>
#include <string>

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
    std::cout << "   AL <CPF> <Codigo1> ... <Codigo N>" << std::endl;

    std::cout << "9. Devolucao Filme:" << std::endl;
    std::cout << "   DV <CPF> <Dias Locacao>" << std::endl;

    std::cout << "10. Aumentar Estoque:" << std::endl;
    std::cout << "   AE <Quantidade> <Codigo>" << std::endl;

    std::cout << "11. Diminuir Estoque:" << std::endl;
    std::cout << "   RE <Quantidade> <Codigo>" << std::endl;

    std::cout << "12. Finalizar Sistema:" << std::endl;
    std::cout << "    FS" << std::endl;
}

bool erroCQ(std::string qtd, std::string codigo) {

    int ver_num = 1;

    for (int i = 0; i < (int)qtd.size(); i++) {
        if(!isdigit(qtd[i])){
            ver_num = 0;
        }
    }

    if (ver_num == 0) {
        std::cout << "A quantidade deve ser um numero inteiro" << std::endl;
            return 0;
    }
    else {
        if (stoi(qtd) <= 0) {
            std::cout << "A quantidade deve ser maior que 0" << std::endl;
                return 0;
        }
    }

    ver_num = 1;

    for (int i = 0; i < (int)codigo.size(); i++) {
        if (!isdigit(codigo[i])){
            ver_num = 0;
        }
    }

    if (ver_num == 0) {
        std::cout << "Codigo deve ser um numero inteiro" << std::endl;
            return 0;
    }
    else {
        if (stoi(codigo) <= 0) {
            std::cout << "Codigo deve ser maior que 0" << std::endl;
            return 0;
        }
    }
        return 1;
}

bool erroCC(std::string cpf) {

    for (int i = 0; i < (int)cpf.size(); i++) {
        if (!isdigit(cpf[i]) || (int)cpf[i] < 0) {
            std::cout << "CPF deve possuir apenas numeros entre 0 e 9" << std::endl;
            return 0;
        }
    }

    return 1;
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

            std::string titulo, categoria, qtd_string, codigo_string;
            // Lógica para Cadastrar Filme
            iss >> tipo;
            iss >> qtd_string >> codigo_string;
            iss >> titulo;

                if (tipo == 'D') {
                    iss >> categoria;
                    if(erroCQ(qtd_string, codigo_string)){
                        quantidade = stoi(qtd_string);
                        codigo = stoi(codigo_string);
                        locadora.cadastrarDVD(codigo, quantidade, titulo, categoria);
                    }
                }
                else if (tipo == 'F') {
                    if (erroCQ(qtd_string, codigo_string)) {
                        quantidade = stoi(qtd_string);
                        codigo = stoi(codigo_string);
                        locadora.cadastrarFita(codigo, quantidade, titulo);
                    }
                }
                else {
                    std::cerr << "ERRO: Tipo de filme invalido." << std::endl;
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
                std::cerr << "ERRO: Tipo de listagem invalido." << std::endl;
            }

        } else if (operacao == "CC") {
            std::string cpf, nome;
            iss >> cpf >> nome;

            // Lógica para Cadastrar Cliente
            if(erroCC(cpf)){
                locadora.cadastrarCliente(cpf, nome);
            }


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
                std::cerr << "ERRO: Tipo de listagem invalido." << std::endl;
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

        }
        else if (operacao == "AE") {

        std::string qtd_string, codigo_string;
        int codigo, quantidade;

        iss >> qtd_string >> codigo_string;
            
        if (erroCQ(qtd_string, codigo_string)) {

            quantidade = stoi(qtd_string);
            codigo = stoi(codigo_string);

            locadora.aumentarEstoque(codigo, quantidade);
            }
        }
        else if (operacao == "RE") {

            std::string qtd_string, codigo_string;
        int codigo, quantidade;

        iss >> qtd_string >> codigo_string;

            if (erroCQ(qtd_string, codigo_string)) {

                quantidade = stoi(qtd_string);
                codigo = stoi(codigo_string);

                locadora.diminuirEstoque(codigo, quantidade);
            }

        }
        else if (operacao == "FS") {
            std::cout << "Sistema finalizado." << std::endl;
            break;
        } else {
            std::cerr << "Comando invalido." << std::endl;
        }
    }

    return 0;
}