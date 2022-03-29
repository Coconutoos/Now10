#include <iostream>
#include "Cliente.h"
#include "stdio.h"
#include <ctime>

Cliente::Cliente(int newId, std::string newNome, int newQtdviagens ,std::vector<int> newHistoricoProduto) : id(newId), nome(newNome), qtdViagens(newQtdviagens),historicoProduto(std::move(newHistoricoProduto)){}

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

void Cliente::erroNomeLog(int id){
    std::ofstream log("../log.txt", std::fstream::app);
    time_t now = time(0);
    std::string dt = ctime(&now);
    dt.pop_back();
    if(log.is_open()){
        log << dt << " Erro (id: "<< id << ") : nome nao cadastrado" << std::endl;
    }
}

int Cliente::salvarCliente(std::string newNome, int newQtdviagens,std::vector<int> newHistoricoProduto){
    int newId = Cliente::generateId();
    if(!Cliente::verificaNome(newNome)){
        erroNomeLog(newId);
        return 0;
    }
    Cliente cliente(newId, newNome, newQtdviagens, std::move(newHistoricoProduto));
    cliente.guardaCliente();
    return 1;
}

void Cliente::guardaCliente(){
    std::vector<int>::iterator it;
    std::ofstream dataBase("../clientesBase.txt", std::fstream::app);
    if(dataBase.is_open()){
        dataBase << id << ',' <<nome << ',' << qtdViagens;
        for(it = historicoProduto.begin(); it < historicoProduto.end(); it++)
            dataBase << "," << *it;
    }
    dataBase << std::endl;
    dataBase.close();
}

int Cliente::verificaNome(std::string nome){
    if(!nome.empty()) return 1;
    return 0;
}

int Cliente::removeCliente(int idSearch){
    std::ifstream dataBase("../clientesBase.txt");
    std::ofstream temp("../temp.txt");
    std::string line;
    int aux = 0;
    char buffer[100];
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d%*c", &aux);
        if(aux != idSearch) temp << line << std::endl;
    };
    dataBase.close();
    temp.close();
    remove("../clientesBase.txt");
    rename("../temp.txt", "../clientesBase.txt");
    return 0;
}

int Cliente::generateId(){
    std::ifstream dataBase("../clientesBase.txt");
    std::string line;
    int aux = 0;
    char buffer[100];
    if(dataBase.peek() == EOF) return 1;
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d%*c", &aux);
    };
    return aux+1;
}
