#ifndef UNTER_ALIMENTOVIEW_H
#define UNTER_ALIMENTOVIEW_H
#include <iostream>
#include <string>
#include <vector>
#include "../model/Alimento.h"

class alimentoView {
public:
    static void readNome(std::string &name);
    static void readNewValCalorico(float &valCalorico);
    static void readNewPreco(float &preco);
    static void readNewMarca(std::string &marca);
    static int getAlimentoId();
    static void printAllAlimentosView(std::ostream &dst);
};


#endif //UNTER_ALIMENTOVIEW_H