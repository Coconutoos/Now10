#include <iostream>
#include "Cliente.h"
#include "stdio.h"
#include "../view/clienteView.h"
#include <ctime>
#include <cstring>

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

void Cliente::errorLog(int id, std::string msg){
    std::ofstream log("../log.txt", std::fstream::app);
    time_t now = time(0);
    std::string dt = ctime(&now);
    dt.pop_back();
    if(log.is_open()){
        log << dt << " Erro (id: "<< id << ") : " << msg << std::endl;
    }
    log.close();
}

bool Cliente::validaCliente(int newId,std::string newNome, int newQtdviagens,std::vector<int> newHistoricoProduto){
    std::vector<int>::iterator it;

    if(!Cliente::verificaNome(newNome)){
        errorLog(newId, "Nome nao cadastrado");
        return false;
    }

    if(newQtdviagens < 0){
        errorLog(newId, "Quantidade de viagens invalida");
        return false;
    }

    for(it = newHistoricoProduto.begin(); it < newHistoricoProduto.end(); it++){
        if(*it <= 0){
            errorLog(newId, "Valor do historico invalido");
            return false;
        }

    }
    return true;
}

int Cliente::salvarCliente(std::string newNome, int newQtdviagens,std::vector<int> newHistoricoProduto){
    int newId = Cliente::generateId();


    if(!validaCliente(newId, newNome, newQtdviagens, newHistoricoProduto)) return 0;

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
    dataBase.close();
    return aux+1;
}

int Cliente::exists(int id){
    std::ifstream dataBase("../clientesBase.txt");
    std::string line;
    int aux = 0;
    char buffer[100];
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d%*c", &aux);
        if(aux == id) return 1;
    };
    dataBase.close();
    return 0;
}

int Cliente::alterar(int id){
    std::string newName;
    int newQtdViagens;
    int flag = 0;
    std::vector<int> newHistoricoProduto;
    clienteView::readName(newName);
    clienteView::readQtdViagens(newQtdViagens);
    clienteView::readHistorico(newHistoricoProduto);

    std::vector<int>::iterator it;
    std::ifstream dataBase("../clientesBase.txt");
    std::ofstream temp("../temp.txt");
    std::string line;
    int aux = 0;
    char buffer[100];
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d%*c", &aux);
        if(aux != id) temp << line << std::endl;
        else{
            flag = 1;
            if(!validaCliente(id, newName, newQtdViagens, newHistoricoProduto)) return -1;
            temp << id << ',' << newName << ',' << newQtdViagens;
            for(it = newHistoricoProduto.begin(); it < newHistoricoProduto.end(); it++)
                temp << "," << *it;
            temp << std::endl;
        }
    };
    dataBase.close();
    temp.close();
    remove("../clientesBase.txt");
    rename("../temp.txt", "../clientesBase.txt");
    return flag;
}

void Cliente::lerVetor(std::string line){
        int i = 0;
        int n = line.size();
        char aux[n+1];
        strcpy(aux, line.c_str());
        char *pt;
        pt = strtok(aux, ",");
        for(i = 0; pt; i++){
            if (i > 2)std::cout << "Produto: " << pt << std::endl;
            pt = strtok(nullptr, ",");
        }

}

int Cliente::consultar(int id){
    std::ifstream dataBase("../clientesBase.txt");
    std::string line;
    int flag = 0;
    char name[50];
    int buffer = 0;
    int qtdViagens;
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d%*c", &buffer);
        if(buffer == id) {
            flag = 1;
            sscanf(line.c_str(), "%d,%[^,],%d", &id, name, &qtdViagens);
            std::cout << "===================================" << std::endl;
            std::cout << "Nome: " << name << std::endl;
            std::cout << "Quantidade de viagens: " << qtdViagens << std::endl;
            std::cout << "Historico de produtos:" << std::endl;
            lerVetor(line);
            std::cout << "===================================" << std::endl;
        }
    };
    dataBase.close();
    return flag;
}

