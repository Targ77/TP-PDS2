#ifndef CONTROLECLIENTE_HPP
#define CONTROLECLIENTE_HPP

#include "Cliente.hpp"
#include <map>

class ControleCliente {
private:
    std::map<std::string, Cliente*> clientes;

public:
    void adicionarCliente(const std::string& cpf, const std::string& nome);
    void removerCliente(const std::string& cpf);
    void imprimirRelatorio() const;
    Cliente* encontrarCliente(const std::string& cpf);
    void alugarFilme(const std::string& cpf, int codigo);
    void devolverFilmes(const std::string& cpf);
    bool validaCliente(const std::string& cpf);
};

#endif