#ifndef UNTER_MENUVIEW_H
#define UNTER_MENUVIEW_H
#include "../controller/clienteController.h"

class menuView {
private:
    static clienteController controller;
    //static AlimentoController AlimentoController;
public:
    static void printMenu();
    static void menu();
};

#endif //UNTER_MENUVIEW_H
