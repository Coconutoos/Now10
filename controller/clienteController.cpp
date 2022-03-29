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
    removeId = clienteView::viewGetClienteId();
    if(Cliente::removeCliente(removeId)) return 1;
    return 0;
}

int clienteController::alterarClienteController(){
    int alterarId;
    alterarId = clienteView::viewGetClienteId();
    if(Cliente::exists(alterarId)){
        if(Cliente::alterar(alterarId)) return 1;
        else return 0;
    }
}