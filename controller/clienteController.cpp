#include "clienteController.h"



 int clienteController::cadastrarCliente() {
    std::string newName;
    int newQtdViagens;
    std::vector<int> newHistoricoProduto;
    clienteView::readName(newName);
    clienteView::readQtdViagens(newQtdViagens);
    clienteView::readHistorico(newHistoricoProduto);
    if(!Cliente::salvarCliente(newName, newQtdViagens, newHistoricoProduto)) return 0;
    return 1;
}

int clienteController::removerClienteController(){
    int removeId;
    removeId = clienteView::removerCliente();
    if(Cliente::removeCliente(removeId)) return 1;
    return 0;
}