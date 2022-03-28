#include "Cliente.h"

Cliente::Cliente(int newId, std::string newNome, std::vector<int> newHistoricoProduto) :
                    id(newId), nome(newNome), historicoProduto(std::move(newHistoricoProduto)){}

Cliente::Cliente(){
    id = 0;
    nome = "";
    qtdViagens = 0;
}

int Cliente::getId() const {
    return id;
}

const std::string &Cliente::getNome() const {
    return nome;
}

void Cliente::setNome(const std::string &nome) {
    Cliente::nome = nome;
}

int Cliente::getQtdViagens() const {
    return qtdViagens;
}

void Cliente::setQtdViagens(int qtdViagens) {
    Cliente::qtdViagens = qtdViagens;
}

const std::vector<int> &Cliente::getHistoricoProduto() const {
    return historicoProduto;
}

void Cliente::setHistoricoProduto(const std::vector<int> &historicoProduto) {
    Cliente::historicoProduto = historicoProduto;
}

