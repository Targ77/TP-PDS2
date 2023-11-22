#ifndef CONTROLECLIENTE_HPP
#define CONTROLECLIENTE_HPP

#include "Cliente.hpp"
#include <map>

class ControleCliente {
private:
    std::map<std::string, Cliente*> clientes;

public:
    void adicionarCliente(Cliente* cliente);
    void removerCliente(const std::string& cpf);
    void imprimirRelatorio() const;
    Cliente* encontrarCliente(const std::string& cpf);
};

#endif