#ifndef UNTER_ALIMENTO_H
#define UNTER_ALIMENTO_H
#include <string>
#include <fstream>
#include "../view/alimentoView.h"

class Alimento {
private:
    int id;
    std::string nome;
    float valCalorico;
    float preco;
    std::string marca;
    int isDeleted;
    void guardaCliente();
    static int generateId();
    static bool validaAlimento(int id, std::string nome, float valorCalorico, float preco);
    void guardaAlimento();
    static void errorLog(int id, std::string msg);

public:
    Alimento(int newId, std::string newNome, float newValCalorico, float newPreco ,std::string newMarca);
    static int isDeletedAlimento(int id);
    static int salvarAlimento(std::string newNome, float newValCalorico, float newPreco ,std::string newMarca);
    static int removerAlimento(int id);
    static int alterarAlimento(int id);
    static bool consultarAlimento(int id);
};


#endif //UNTER_ALIMENTO_H
