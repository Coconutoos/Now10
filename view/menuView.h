#ifndef UNTER_MENUVIEW_H
#define UNTER_MENUVIEW_H
#include "../controller/clienteController.h"

class menuView {
private:
    clienteController controllerCliente;
    //static AlimentoController AlimentoController;
public:
    void printMenu();
    void menu();
};

#endif //UNTER_MENUVIEW_H
