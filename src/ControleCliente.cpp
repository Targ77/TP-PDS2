#include "ControleCliente.hpp"
#include <iostream>

void ControleCliente::adicionarCliente(const std::string& cpf, const std::string& nome) {
    
    if (clientes.find(cpf) == clientes.end()) {
        clientes[cpf] = new Cliente(cpf, nome);
        std::cout << "Cliente adicionado com sucesso." << std::endl;
    } else {
        std::cout << "Cliente com CPF " << cpf << " ja existe." << std::endl;
    }
}

void ControleCliente::removerCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {

        if(it->second->getFilmes().empty()){
            clientes.erase(it);
            std::cout << "Cliente com CPF " << cpf << " removido com sucesso." << std::endl;
        }else{
            std::cout << "Cliente com CPF " << cpf << " nao pode ser removido pois ainda tem filmes alugados." << std::endl;
        }
        
    } else {
        std::cout << "Cliente com CPF " << cpf << " nao encontrado." << std::endl;
    }
}

void ControleCliente::imprimirRelatorio() const {

    if(!this->clientes.empty()){
        std::cout << "Relatorio de Clientes:" << std::endl;
        std::cout << std::endl;

        for (const auto& pair : clientes) {

            pair.second->imprimirInformacoes();
            std::cout << "------------------------\n";
        }

    }else{
        std::cout << "Nenhum Cliente Cadastrado!!" << std::endl;
    }
}

Cliente* ControleCliente::encontrarCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {
        return it->second;
    }

    return nullptr;
}

void ControleCliente::alugarFilme(const std::string& cpf, int codigo){
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {
        it->second->addFilme(codigo);
    } else {
        std::cout << "Cliente com CPF " << cpf << " nao encontrado." << std::endl;
    }
}

void ControleCliente::devolverFilmes(const std::string& cpf){
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {
        it->second->devolverFilmes();
    } else {
        std::cout << "Cliente com CPF " << cpf << " nao encontrado." << std::endl;
    }
}

bool ControleCliente::validaCliente(const std::string& cpf){
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {
        return true;
    } else {
        std::cout << "Cliente com CPF " << cpf << " nao encontrado." << std::endl;
        return false;
    }
}

void ControleCliente::imprimirRelatorioOrdenadoPorNome() const {
    std::map<std::string, Cliente*> clientesPorNome;

    if(!this->clientes.empty()){
        std::cout << "Relatorio de Clientes:" << std::endl;
        std::cout << std::endl;

        for (auto pair : clientes) {
            clientesPorNome[pair.second->getNome()] = pair.second;
        }

        for (const auto& pair : clientesPorNome) {

            pair.second->imprimirInformacoes();
            std::cout << "------------------------\n";
        }

    }else{
        std::cout << "Nenhum Cliente Cadastrado!!" << std::endl;
    }
}

bool ControleCliente::estaAlugado(int codigo){

    if(!this->clientes.empty()){

        for (auto pair : this->clientes) {

            if(!pair.second->getFilmes().empty()){
                for (int filme : pair.second->getFilmes()) {
                    if(filme == codigo){
                        return false;
                    }
                }
            }
        }

    }

    return true;

}


