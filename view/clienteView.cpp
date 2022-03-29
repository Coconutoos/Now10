#include "clienteView.h"

void clienteView::readName(std::string &name){
    std::cout << "Digite o nome do cliente" << std::endl;
    std::cin.ignore();
    std::getline(std::cin, name);

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

int clienteView::removerCliente(){
    int aux;
    std::cout << "Digite o nome do id a ser removido" << std::endl;
    std::cin >> aux;
    return aux;
}