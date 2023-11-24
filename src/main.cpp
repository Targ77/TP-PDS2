#include <iostream>
#include "DVD.hpp"
#include "Fita.hpp"
#include "Estoque.hpp"
#include "ControleCliente.hpp"
#include "Cliente.hpp"
#include "Locadora.hpp"

int main() {

    Locadora locadora;  // Crie uma instância direta de Locadora
    locadora.lerArquivoCadastro("cadastro.txt");
    locadora.listarProdutosOrdenadosPorCodigo();

    locadora.cadastrarCliente("55768302644", "Thiago Alves");
    locadora.cadastrarCliente("13768302644", "Caio");
    locadora.cadastrarCliente("03768302644", "Helena");
    std::cout << "------------------------" << std::endl;
    std::vector<int> filmesAlugados = {3, 4, 5};
    std::vector<int> filmesAlugados2 = {1, 2};
    std::vector<int> filmesAlugados3 = {7, 8, 10};
    locadora.alugarFilme("55768302644", filmesAlugados);
    locadora.alugarFilme("13768302644", filmesAlugados2);
    locadora.alugarFilme("03768302644", filmesAlugados3);
    std::cout << "------------------------" << std::endl;
    locadora.listarClientesOrdenadosPorCpf();

    /*controle.adicionarCliente("55768302644", "Thiago Alves");
    controle.adicionarCliente("13768302644", "Lucas Alves");
    controle.adicionarCliente("03768302644", "Manu");

    controle.encontrarCliente("13768302644");
    controle.imprimirRelatorio();
    controle.removerCliente("13768302644");

    controle.alugarFilme("55768302644", 1);
    controle.alugarFilme("55768302644", 66);
    controle.alugarFilme("55768302644", 3);
    controle.imprimirRelatorio();


    estoque.adicionarDVD(1, 10, "Meu DVD", "lancamento");
    estoque.adicionarFita(2, 10, "Minha Fita");
    estoque.lerArquivoCadastro("cadastro.txt");
    estoque.imprimirRelatorio();

    estoque.removerProduto(1);

    estoque.removerProduto(10);

    estoque.imprimirRelatorio();*/

    return 0;
}