#ifndef UNTER_CLIENTECONTROLLER_H
#define UNTER_CLIENTECONTROLLER_H
#include "../model/Cliente.h"
#include "../view/clienteView.h"

class clienteController {
private:
    Cliente model;
    clienteView view;
public:
    void cadastrarCliente();
};


#endif //UNTER_CLIENTECONTROLLER_H
