#include "clienteView.h"

void clienteView::readName(std::string &name){
    std::cout << "Digite o nome do cliente" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);

}

void clienteView::readDataNasc(std::string &dataNasc){
    std::cout << "Digite a data de nascimento do cliente" << std::endl;
    std::getline(std::cin, dataNasc);
}

void clienteView::readQtdViagens(int &qtdViagens){
    std::cout << "Digite a Quantidade de viagens do cliente. Digite 0 para nao cadastrar" << std::endl;
    std::cin >> qtdViagens;
}

void clienteView::readHistorico(std::vector<int> &historicoProduto){
    int input;
    std::cout << "Digite o Historico de pedidos do cliente. Digite 0 para terminar ou nao cadastrar" << std::endl;
    std::cin >> input;
    while(input != 0){
        historicoProduto.push_back(input);
        std::cin >> input;
    }
}

int clienteView::viewGetClienteId(){
    int aux;
    std::cout << "Digite o id do cliente:" << std::endl;
    std::cin >> aux;
    return aux;
}

void clienteView::printAllClientesView(std::ostream &dst){
    int idAux = 1;
    std::vector<int> allClientes;
    std::vector<int>::iterator it;
    allClientes = Cliente::getAllClientesId();
    dst << "******************Clientes******************" << std::endl;

    for(it = allClientes.begin(); it < allClientes.end(); it++){
        dst << std::endl;
        Cliente::consultar(*it, dst);
        dst << std::endl;
    }
    dst << "********************************************" << std::endl;
}