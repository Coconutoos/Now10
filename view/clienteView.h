#ifndef UNTER_CLIENTEVIEW_H
#define UNTER_CLIENTEVIEW_H
#include <string>
#include <vector>
#include <iostream>
#include "../model/Cliente.h"

class clienteView{
public:
    static void readName(std::string &name);
    static void readQtdViagens(int &qtdViagens);
    static void readHistorico(std::vector<int> &historicoProduto);
    static int viewGetClienteId();
    static void readDataNasc(std::string &newDataNasc);
    static void printAllClientesView(std::ostream &dst);
};


#endif //UNTER_CLIENTEVIEW_H
