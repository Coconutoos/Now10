#ifndef UNTER_CLIENTE_H
#define UNTER_CLIENTE_H
#include <string>
#include <vector>

class Cliente {

private:
    int id;
    std::string nome;
    int qtdViagens;
    std::vector<int> historicoProduto;
    void setID(int newId);

public:
    Cliente(int newId, std::string newNome, std::vector<int> newHistoricoProduto);

    int getId() const;

    const std::string &getNome() const;

    int getQtdViagens() const;

    const std::vector<int> &getHistoricoProduto() const;

    void setNome(const std::string &nome);

    void setQtdViagens(int qtdViagens);

    void setHistoricoProduto(const std::vector<int> &historicoProduto);

};

#endif //UNTER_CLIENTE_H
