#ifndef UNTER_MENUVIEW_H
#define UNTER_MENUVIEW_H
#include "../controller/clienteController.h"
#include "../controller/alimentoController.h"
class menuView {
public:
    void printMenu();
    void menu();
    void printAllDados();
    static void gerarRelatorio();
};

#endif //UNTER_MENUVIEW_H
