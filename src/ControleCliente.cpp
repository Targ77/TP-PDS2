#include "ControleCliente.hpp"
#include <iostream>

void ControleCliente::adicionarCliente(Cliente* cliente) {
    
    if (clientes.find(cliente->getCpf()) == clientes.end()) {
        clientes[cliente->getCpf()] = cliente;
        std::cout << "Cliente adicionado com sucesso." << std::endl;
    } else {
        std::cout << "Cliente com CPF " << cliente->getCpf() << " já existe." << std::endl;
    }
}

void ControleCliente::removerCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {
        clientes.erase(it);
        std::cout << "Cliente com CPF " << cpf << " removido com sucesso." << std::endl;
    } else {
        std::cout << "Cliente com CPF " << cpf << " não encontrado." << std::endl;
    }
}

void ControleCliente::imprimirRelatorio() const {
    for (const auto& pair : clientes) {
        pair.second->imprimirInformacoes();
        std::cout << "------------------------\n";
    }
}

Cliente* ControleCliente::encontrarCliente(const std::string& cpf) {
    auto it = clientes.find(cpf);

    if (it != clientes.end()) {
        return it->second;
    }

    return nullptr;
}