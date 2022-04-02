#include <iostream>
#include "menuView.h"
#include <algorithm>


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

void menuView::printAllDados(){
    clienteController::printAllClientesController(std::cout);
    alimentoController::printAllAlimentosController(std::cout);
}

void menuView::gerarRelatorio(){
    std::string relatorioPath;
    time_t now = time(0);
    std::string dt = ctime(&now);
    dt.pop_back();
    relatorioPath = "../Relatorio " + dt + ".txt";
    std::replace( relatorioPath.begin(), relatorioPath.end(), ' ', '_');
    std::replace( relatorioPath.begin(), relatorioPath.end(), ':', '_');
    std::ofstream relatorio(relatorioPath, std::ofstream::app);
    clienteController::printAllClientesController(relatorio);
    alimentoController::printAllAlimentosController(relatorio);
    std::cout << relatorioPath << std::endl;
    relatorio.close();
}

void menuView::menu(){
    int op = -1;
    while(op != 0){
        printMenu();
        std::cin >> op;
        switch(op){
            case 1:{
                int flag = clienteController::cadastrarCliente();
                menuView::printAllDados();
                if(flag) std::cout << "Cliente cadastrado!" << std::endl;
                else std::cout << "Erro! o cliente nao foi cadastrado!" << std::endl;}
                break;
            case 2:{
                int flag = clienteController::removerClienteController();
                menuView::printAllDados();
                if(flag) std::cout << "Cliente removido!" << std::endl;
                else std::cout << "Cliente nao encontrado!" << std::endl;
            }
                break;
            case 3:{
                int flag = clienteController::alterarClienteController();
                menuView::printAllDados();
                if(flag == 1) std::cout << "Cliente alterado com sucesso!" << std::endl;
                if(flag == 0) std::cout << "Cliente nao encontrado!" << std::endl;
                if(flag == -1) std::cout << "Erro! O cliente nao pode ser alterado!" << std::endl;}
                break;
            case 4:
                if(!clienteController::consultarClienteController()) std::cout <<  "Cliente nao encontrado!" << std::endl;
                break;
            case 5:{
                int flag = alimentoController::cadastrarAlimentoController();
                menuView::printAllDados();
                if(flag) std::cout << "Alimento Cadastrado!" << std::endl;
                else std::cout << "Erro! O alimento nao foi cadastrado." << std::endl;
            }
                break;
            case 6: {
                int flag = alimentoController::removerAlimentoController();
                menuView::printAllDados();
                if (flag == 0) std::cout << "Erro! alimento nao encontrado" << std::endl;
                else if (flag == 1) std::cout << "Alimento removido com sucesso!" << std::endl;
                else if (flag == -1) std::cout << "Erro! o alimento ja foi removido" << std::endl;}
                break;
            case 7:{
                int flag = alimentoController::alterarAlimentoController();
                menuView::printAllDados();
                if (flag == 0) std::cout << "Erro! alimento nao encontrado" << std::endl;
                else if (flag == 1) std::cout << "Alimento alterado com sucesso!" << std::endl;
                else if (flag == -1) std::cout << "Erro! Dados inseridos invalidos, o alimento nao foi alterado" << std::endl;}
                break;
            case 8:{
                bool flag = alimentoController::consultarAlimentoController();
                if(!flag) std::cout << "Alimento nao encontrado!";}
                break;
            case 9:
                menuView::gerarRelatorio();

                break;
            case 0:
                break;
            default:
                std::cout << "\nOpcao invalida!\n" << std::endl;
        }
    }
}