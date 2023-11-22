#ifndef DVD_HPP
#define DVD_HPP

#include "string"
#include <vector>

class Cliente{
private:
    std::string cpf;
    std::string nome;
    std::vector<int> filmesAlugados;

public:
    void imprimirInformacoes() const;
    std::string getCpf();
    std::string getNome();
    std::vector<int> getFilmes();
    void addFilme(int filme);
    void devolverFilmes();
};

#endif 