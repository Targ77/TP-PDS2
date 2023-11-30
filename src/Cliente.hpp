#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include "string"
#include <vector>

class Cliente{
private:
    std::string cpf;
    std::string nome;
    std::vector<int> filmesAlugados;

public:
    Cliente(const std::string& cpf, const std::string& nome);
    void imprimirInformacoes() const;
    std::string getCpf();
    std::string getNome();
    std::vector<int> getFilmes();
    void addFilme(int filme);
    void devolverFilmes();
};

#endif 