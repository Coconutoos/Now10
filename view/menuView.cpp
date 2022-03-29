#include <iostream>
#include "menuView.h"


void menuView::printMenu(){
    std::cout<<"\nEscolha uma opcao:"<< std::endl;

    std::cout<<"1 - Cadastrar Cliente"<< std::endl;
    std::cout<<"2 - Remover Cliente"<< std::endl;
    std::cout<<"3 - Alterar Cliente"<< std::endl;
    std::cout<<"4 - Consultar Cliente"<< std::endl;

    std::cout<<"5 - Cadastrar Alimento"<< std::endl;
    std::cout<<"6 - Remover Alimento"<< std::endl;
    std::cout<<"7 - Alterar Alimento"<< std::endl;
    std::cout<<"8 - Consultar Alimento"<< std::endl;

    std::cout<<"9 - Gerar Relatorio"<< std::endl;

    std::cout<<"0 - Sair"<< std::endl;
}

void menuView::menu(){
    int op = -1;
    while(op != 0){
        printMenu();
        std::cin >> op;
        switch(op){
            case 1:
                if(clienteController::cadastrarCliente()) std::cout << "Cliente cadastrado!" << std::endl;
                else std::cout << "Erro! o cliente nao foi cadastrado!" << std::endl;
                break;
            case 2:
                clienteController::removerClienteController();
                break;
            case 3:
                if(clienteController::alterarClienteController()) std::cout << "Cliente alterado com sucesso!" << std::endl;
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
            case 8:
                break;
            case 9:
                break;
            case 0:
                break;
            default:
                std::cout << "\nOpcao invalida!\n" << std::endl;
        }
    }
}