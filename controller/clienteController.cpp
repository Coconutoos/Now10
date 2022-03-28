#include "clienteController.h"

void clienteController::cadastrarCliente() {
    std::string newName;
    int newQtdViagens;
    std::vector<int> newHistoricoProduto;
    view.readName(newName);
    view.readQtdViagens(newQtdViagens);
    view.readHistorico(newHistoricoProduto);
    std::cout << newName;
    std::cout << newQtdViagens;


    for(int i; i <= newHistoricoProduto.size(); i++){
        std::cout << newHistoricoProduto[i] << std::endl;
    }
}