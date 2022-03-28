#include "clienteController.h"

void clienteController::cadastrarCliente() {
    std::string newName;
    int newQtdViagens;
    std::vector<int> newHistoricoProduto;
    view.readName(newName);
    view.readQtdViagens(newQtdViagens);
    view.readHistorico(newHistoricoProduto);
    std::cout << newName << std::endl;
    std::cout << newQtdViagens << std::endl;

    for(int i = 0; i < newHistoricoProduto.size(); i++){
        std::cout << newHistoricoProduto[i] << std::endl;
    }
}