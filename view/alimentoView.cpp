#include "alimentoView.h"

void alimentoView::readNome(std::string &name){
    std::cout << "Digite o nome do alimento" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);
}

void alimentoView::readNewValCalorico(float &valCalorico){
    std::cout << "Digite o valor calorico do alimento" << std::endl;
    std::cin >> valCalorico;
}

void alimentoView::readNewPreco(float &preco){
    std::cout << "Digite o valor preco do alimento" << std::endl;
    std::cin >> preco;
}

void alimentoView::readNewMarca(std::string &marca){
    std::cout << "Digite a marca do alimento" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, marca);
    if(marca.empty()) marca = "Nao cadastrado";
}

int alimentoView::getAlimentoId() {
    int aux;
    std::cout << "Digite o id do alimento:" << std::endl;
    std::cin >> aux;
    return aux;
}

void alimentoView::printAllAlimentosView(std::ostream &dst) {
    int idAux = 1;
    std::vector<int> allAlimentos;
    std::vector<int>::iterator it;
    allAlimentos = Alimento::getAllAlimentosId();
    dst << "******************Alimentos******************" << std::endl;
    for(it = allAlimentos.begin(); it < allAlimentos.end(); it++){
        dst << std::endl;
        Alimento::consultarAlimento(*it, dst);
        dst << std::endl;
    }
    dst << "*********************************************" << std::endl;
}
