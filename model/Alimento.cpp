#include "Alimento.h"

Alimento::Alimento(int newId, std::string newNome, float newValCalorico, float newPreco ,std::string newMarca)
: id(newId), nome(newNome), valCalorico(newValCalorico),preco(newPreco), marca(std::move(newMarca)){
    isDeleted = 0;
}

bool Alimento::validaAlimento(int id, std::string nome, float valorCalorico, float preco){
    if(nome.empty()) {
        errorLog(id, "Nome do alimento nao cadastrado");
        return false;
    }
    if(valorCalorico < 0) {
        errorLog(id, "Valor calorico invalido");
        return false;
    }

    if(preco < 0) {
        errorLog(id, "Preco invalido");
        return false;
    }
    return true;
}

void Alimento::errorLog(int id, std::string msg){
    std::ofstream log("log.txt", std::fstream::app);
    time_t now = time(0);
    std::string dt = ctime(&now);
    dt.pop_back();
    if(log.is_open()){
        log << dt << " Erro (id: "<< id << ") : " << msg << std::endl;
    }
    log.close();
}


int Alimento::salvarAlimento(std::string newNome, float newValCalorico, float newPreco ,std::string newMarca){
    int newId = Alimento::generateId();


    if(!validaAlimento(newId, newNome, newValCalorico, newPreco)) return 0;

    Alimento alimento(newId, newNome, newValCalorico, newPreco, newMarca);
    alimento.guardaAlimento();
    return 1;
}

void Alimento::guardaAlimento(){
    std::ofstream dataBase("alimentosBase.txt", std::fstream::app);
    if(dataBase.is_open()){
        dataBase << id << ',' << isDeleted << ',' << nome << ',' << valCalorico << ',' << preco << ',' << marca;
    }
    dataBase << std::endl;
    dataBase.close();
}


int Alimento::generateId(){
    std::ifstream dataBase("alimentosBase.txt");
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
#include<iostream>
int Alimento::isDeletedAlimento(int id){
    std::ifstream dataBase("alimentosBase.txt");
    std::string line;
    int searchId, isDeletedAux;
    char buffer[100];
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d,%d%*c", &searchId, &isDeletedAux);
        if(searchId == id){
            //std::cout << searchId << " " << isDeletedAux << std::endl;
            return isDeletedAux;
        }
    };
    dataBase.close();
    return -1;
}

int Alimento::removerAlimento(int id){
    std::ifstream dataBase("alimentosBase.txt");
    std::ofstream temp("temp.txt");
    std::string line;
    int auxId, auxIsDeleted , resultado = 0;
    char buffer[100];
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d,%d,%s", &auxId,&auxIsDeleted,buffer);
        if(auxId != id){
            temp << line << std::endl;
        }
        else if(auxId == id){
            if(!auxIsDeleted){
                temp << auxId << ',' << "1," << buffer << std::endl;
                resultado = 1;
            }
            if(auxIsDeleted){
                temp << line << std::endl;
                resultado = -1;
            }
        }
    };
    dataBase.close();
    temp.close();
    remove("alimentosBase.txt");
    rename("temp.txt", "alimentosBase.txt");
    return resultado;
}
int Alimento::alterarAlimento(int id){
    std::string newName;
    float newValCalorico;
    float newPreco;
    std::string newMarca;
    alimentoView::readNome(newName);
    alimentoView::readNewValCalorico(newValCalorico);
    alimentoView::readNewPreco(newPreco);
    alimentoView::readNewMarca(newMarca);
    if(!validaAlimento(id, newName, newValCalorico, newPreco)) return -1;
    std::ifstream dataBase("alimentosBase.txt");
    std::ofstream temp("temp.txt");
    std::string line;
    int flag = 0;
    int auxId, auxIsDeleted;
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d,%d,%*c", &auxId, &auxIsDeleted);
        if(auxId != id) temp << line << std::endl;
        else if(auxId == id && !auxIsDeleted){
            flag = 1;
            temp << id << ',' << auxIsDeleted << ',' << newName << ',' << newValCalorico << ',' << newPreco << ',' << newMarca <<std::endl;
        }
        else if(auxId == id && !auxIsDeleted)
            flag = -1;
    };
    dataBase.close();
    temp.close();
    remove("alimentosBase.txt");
    rename("temp.txt", "alimentosBase.txt");
    return flag;
}

bool Alimento::consultarAlimento(int id, std::ostream &dst){
    std::ifstream dataBase("alimentosBase.txt");
    std::string line;
    int isDeleted;
    char nome[50];
    float valCalorico;
    float preco;
    char marca[50];
    int auxId, auxIsDeleted;
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d,%d", &auxId, &auxIsDeleted);
        //std::cout << (auxId == id) << std::endl;
        if(auxId == id && !auxIsDeleted) {
            sscanf(line.c_str(), "%d,%d,%[^,],%f,%f,%[^,\n]", &auxId, &auxIsDeleted, nome, &valCalorico, &preco, marca);
            dst << "===================================" << std::endl;
            dst << "Id: " << id << std::endl;
            dst << "Nome: " << nome << std::endl;
            dst << "Valor Calorico: " << valCalorico << std::endl;
            dst << "Preco: " << preco << std::endl;
            dst << "Marca: " << marca << std::endl;
            dst << "===================================" << std::endl;
            dataBase.close();
            return true;
        }
    };
    dataBase.close();
    return false;
}

std::vector<int> Alimento::getAllAlimentosId(){
    std::ifstream dataBase("alimentosBase.txt");
    std::vector<int> temp;
    std::string line;
    int auxId, auxIsDeleted;
    char buffer[100];
    while(getline(dataBase, line)){
        sscanf(line.c_str(),"%d,%d,%*c", &auxId, &auxIsDeleted);

        if(!auxIsDeleted)
            temp.push_back(auxId);
    };
    dataBase.close();
    return temp;
}



