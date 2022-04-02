#include "alimentoController.h"

int alimentoController::cadastrarAlimentoController() {
    std::string newNome;
    float newValCalorico;
    float newPreco;
    std::string newMarca;
    alimentoView::readNome(newNome);
    alimentoView::readNewValCalorico(newValCalorico);
    alimentoView::readNewPreco(newPreco);
    alimentoView::readNewMarca(newMarca);
    if(!Alimento::salvarAlimento(newNome, newValCalorico, newPreco, newMarca)) return 0;
    return 1;
}

int alimentoController::removerAlimentoController(){
    int id;
    id = alimentoView::getAlimentoId();
    return Alimento::removerAlimento(id);
}

int alimentoController::alterarAlimentoController() {
    int id;
    id = alimentoView::getAlimentoId();
    return Alimento::alterarAlimento(id);
}

bool alimentoController::consultarAlimentoController() {
    int id;
    id = alimentoView::getAlimentoId();
    return Alimento::consultarAlimento(id, std::cout);
}

void alimentoController::printAllAlimentosController(std::ostream &dst) {
        alimentoView::printAllAlimentosView(dst);
}

