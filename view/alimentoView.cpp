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
}

int alimentoView::getAlimentoId() {
    int aux;
    std::cout << "Digite o id do alimento:" << std::endl;
    std::cin >> aux;
    return aux;
}
