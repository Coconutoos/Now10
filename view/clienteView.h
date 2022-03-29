#ifndef UNTER_CLIENTEVIEW_H
#define UNTER_CLIENTEVIEW_H
#include <string>
#include <vector>
#include <iostream>

class clienteView{
public:
    static void readName(std::string &name);
    static void readQtdViagens(int &qtdViagens);
    static void readHistorico(std::vector<int> &historicoProduto);
    static int viewGetClienteId();
};


#endif //UNTER_CLIENTEVIEW_H
