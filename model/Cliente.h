#ifndef UNTER_CLIENTE_H
#define UNTER_CLIENTE_H
#include <string>
#include <vector>
#include <fstream>
#include "Alimento.h"

class Cliente {

private:
    int id;
    std::string nome;
    std::string dataNasc;
    int qtdViagens;
    std::vector<int> historicoProduto;
    static int verificaNome(std::string nome);
    void guardaCliente();
    static int generateId();
    static void errorLog(int id, std::string msg);
    static bool validaCliente( int newId,std::string newNome, std::string newDataNasc,int newQtdviagens,std::vector<int> newHistoricoProduto);
    static void printHistorico(std::string line, bool isAtual, std::ostream &dst);
public:
    Cliente(int newId, std::string newNome, std::string newDataNasc,int newQtdviagens,std::vector<int> newHistoricoProduto);

    int getId() const;

    const std::string &getNome() const;

    int getQtdViagens() const;

    const std::vector<int> &getHistoricoProduto() const;

    void setNome(const std::string &nome);

    void setQtdViagens(int qtdViagens);

    void setHistoricoProduto(const std::vector<int> &historicoProduto);

    static int salvarCliente(std::string newNome, std::string newDataNasc,int newQtdviagens,std::vector<int> newHistoricoProduto);

    static int removeCliente(int idSearch);

    static int exists(int id);

    static int alterar(int id);

    static int consultar(int id, std::ostream &dst);

    static std::vector<int> getAllClientesId();

};

#endif //UNTER_CLIENTE_H
