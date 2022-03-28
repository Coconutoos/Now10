#ifndef UNTER_CLIENTEVIEW_H
#define UNTER_CLIENTEVIEW_H
#include <string>
#include <vector>
#include <iostream>

class clienteView{
public:
    void readName(std::string name);
    void readQtdViagens(int &qtdViagens);
    void readHistorico(std::vector<int> &historicoProduto);
};


#endif //UNTER_CLIENTEVIEW_H
