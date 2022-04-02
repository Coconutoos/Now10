#ifndef UNTER_CLIENTECONTROLLER_H
#define UNTER_CLIENTECONTROLLER_H
#include "../model/Cliente.h"
#include "../view/clienteView.h"

class clienteController {
public:
    static int cadastrarCliente();
    static int removerClienteController();
    static int alterarClienteController();
    static int consultarClienteController();
    static void printAllClientesController(std::ostream &dst);
};


#endif //UNTER_CLIENTECONTROLLER_H
