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
    std::cout << "Instrucoes de Entrada:" << std::endl << std::endl;
    
    std::cout << "1. Ler Arquivo de Cadastro:" << std::endl ;
    std::cout << "   LA <Nome do Arquivo>" << std::endl << std::endl;

    std::cout << "2. Cadastrar Filme:" << std::endl;
    std::cout << "   CF <Tipo: F|D> <quantidade> <codigo> <categoria no caso de DVD> <titulo>" << std::endl << std::endl;

    std::cout << "3. Remover Filme:" << std::endl;
    std::cout << "   RF <codigo>" << std::endl << std::endl;

    std::cout << "4. Listar Filmes ordenados por Codigo ou Titulo:" << std::endl;
    std::cout << "   LF [C|T]" << std::endl << std::endl;

    std::cout << "5. Cadastrar Cliente:" << std::endl;
    std::cout << "   CC <CPF> <Nome>" << std::endl << std::endl;

    std::cout << "6. Remover Cliente:" << std::endl;
    std::cout << "   RC <CPF>" << std::endl << std::endl;

    std::cout << "7. Listar Clientes ordenados por Codigo ou Nome:" << std::endl;
    std::cout << "   LC [C|N]" << std::endl << std::endl;

    std::cout << "8. Aluguel Filme:" << std::endl;
    std::cout << "   AL <CPF> <Codigo1> ... <Codigo N>" << std::endl << std::endl;

    std::cout << "9. Devolucao Filme:" << std::endl;
    std::cout << "   DV <CPF> <Dias Locacao>" << std::endl << std::endl;

    std::cout << "10. Aumentar Estoque:" << std::endl;
    std::cout << "    AE <Quantidade> <Codigo>" << std::endl << std::endl;

    std::cout << "11. Diminuir Estoque:" << std::endl;
    std::cout << "    RE <Quantidade> <Codigo>" << std::endl << std::endl;

    std::cout << "12. Finalizar Sistema:" << std::endl;
    std::cout << "    FS" << std::endl;
}

bool intPos(std::string entrada){
    for (int i = 0; i < (int)entrada.size(); i++) {
        if (!isdigit(entrada[i]) || (int)entrada[i] < 0) {
            std::cout << "ERRO: Entrada " << entrada << " deve ser um numero inteiro positivo" << std::endl;
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
        std::cout << std::endl <<  "Digite um comando (ou 'FS' para finalizar): ";
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

            iss >> tipo;
            iss >> qtd_string >> codigo_string;

                if (tipo == 'D') {
                    iss >> categoria;
                    std::getline(iss >> std::ws, titulo);
                    if(!qtd_string.empty() && !codigo_string.empty() && !titulo.empty() && !categoria.empty()){
                        if(intPos(qtd_string) && intPos(codigo_string)){
                            quantidade = stoi(qtd_string);
                            codigo = stoi(codigo_string);
                            locadora.cadastrarDVD(codigo, quantidade, titulo, categoria);
                        }
                    }
                    else {
                        std::cerr << "ERRO: Campos vazios" << std::endl;
                    }
                }
                else if (tipo == 'F') {
                    std::getline(iss >> std::ws, titulo);

                    if(!qtd_string.empty() && !codigo_string.empty() && !titulo.empty()){
                        if(intPos(qtd_string) && intPos(codigo_string)) {
                            quantidade = stoi(qtd_string);
                            codigo = stoi(codigo_string);
                            locadora.cadastrarFita(codigo, quantidade, titulo);
                        }
                    }
                    else {   
                        std::cerr << "ERRO: Campos vazios" << std::endl;
                    }
                }
                else {
                    std::cerr << "ERRO: Tipo de filme invalido." << std::endl;
                }


        } else if (operacao == "RF") {
            std::string codigo_string;
            int codigo;
            iss >> codigo_string;

            if(!codigo_string.empty()){
                if(intPos(codigo_string)){
                codigo = stoi(codigo_string);
                locadora.removerProduto(codigo);
                }
            } else {
                std::cout<< "ERRO: Campos vazios" <<std::endl;
            }

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
            iss >> cpf;
            std::getline(iss >> std::ws, nome);

            if(!cpf.empty() && !nome.empty()){
                   if(intPos(cpf)){
                    locadora.cadastrarCliente(cpf, nome);
                }
            } else {
                std::cerr << "ERRO: Campos vazios";
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
            std::string cpf, codigoProdutoString;
            iss >> cpf;
            bool vrf = 0;

            std::vector<int> codigosProdutos;
            int codigoProduto;
            while (iss >> codigoProdutoString) {

                if(intPos(codigoProdutoString)){
                    codigoProduto = stoi(codigoProdutoString);
                    codigosProdutos.push_back(codigoProduto);
                } 
                vrf = 1;
            }

            if(vrf){
                locadora.alugarFilme(cpf, codigosProdutos);
            } else{
                std::cerr << "Campos vazios" << std::endl;
            }

        } else if (operacao == "DV") {
            std::string cpf, dias_string;
            int dias;
            iss >> cpf;
            iss >> dias_string;
            if(!cpf.empty() && !dias_string.empty()){
                if(intPos(dias_string)){
                    dias = stoi(dias_string);
                    locadora.devolverFilme(cpf, dias);
                }
            } else {
                std::cerr << "ERRO: Campos vazios" << std::endl;
            }

        }
        else if (operacao == "AE") {

        std::string qtd_string, codigo_string;
        int codigo, quantidade;

        iss >> qtd_string >> codigo_string;
            
            if(!qtd_string.empty() && !codigo_string.empty()){
                if (intPos(qtd_string) && intPos(codigo_string)) {

                quantidade = stoi(qtd_string);
                codigo = stoi(codigo_string);

                locadora.aumentarEstoque(codigo, quantidade);
                }
            } else {
                std::cerr << "ERRO: Campos vazios";
            }
        }
        else if (operacao == "RE") {

        std::string qtd_string, codigo_string;
        int codigo, quantidade;

        iss >> qtd_string >> codigo_string;

            if(!qtd_string.empty() && !codigo_string.empty()){
                if (intPos(qtd_string) && intPos(codigo_string)) {

                    quantidade = stoi(qtd_string);
                    codigo = stoi(codigo_string);

                    locadora.diminuirEstoque(codigo, quantidade);
                }
            } else {
                std::cerr << "ERRO: Campos vazios";
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