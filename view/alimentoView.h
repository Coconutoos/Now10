#ifndef UNTER_ALIMENTOVIEW_H
#define UNTER_ALIMENTOVIEW_H
#include <iostream>
#include <string>

class alimentoView {
public:
    static void readNome(std::string &name);
    static void readNewValCalorico(float &valCalorico);
    static void readNewPreco(float &preco);
    static void readNewMarca(std::string &marca);
    static int getAlimentoId();
};


#endif //UNTER_ALIMENTOVIEW_H
