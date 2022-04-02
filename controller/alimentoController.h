#ifndef UNTER_ALIMENTOCONTROLLER_H
#define UNTER_ALIMENTOCONTROLLER_H
#include <string>
#include "../model/Alimento.h"
#include "../view/alimentoView.h"

class alimentoController {
public:
    static int cadastrarAlimentoController();
    static int removerAlimentoController();
    static int alterarAlimentoController();
    static bool consultarAlimentoController();
};


#endif //UNTER_ALIMENTOCONTROLLER_H
