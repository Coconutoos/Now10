#include "clienteController.h"



 int clienteController::cadastrarCliente() {
    std::string newName;
    std::string newDataNasc;
    int newQtdViagens;
    std::vector<int> newHistoricoProduto;
    clienteView::readName(newName);
    clienteView::readDataNasc(newDataNasc);
    clienteView::readQtdViagens(newQtdViagens);
    clienteView::readHistorico(newHistoricoProduto);
    if(!Cliente::salvarCliente(newName, newDataNasc,newQtdViagens, newHistoricoProduto)) return 0;
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
        return Cliente::alterar(alterarId);
    }
    return 0;
}

int clienteController::consultarClienteController(){
    int id = clienteView::viewGetClienteId();
    if(!Cliente::consultar(id, std::cout)) return 0;
    return 1;
}

void clienteController::printAllClientesController(std::ostream &dst){
    clienteView::printAllClientesView(dst);
}