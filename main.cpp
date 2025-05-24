#include <iostream>
#include "classes.h"
#include "funcoes.h"
using namespace std;

void wait_enter(){
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main(){

    setlocale(LC_ALL, "Portuguese");

    ListaUsuarios lista_usuarios;
    ListaImoveis  lista_imoveis;
    ListaReservas lista_reservas;

    bool run = true;
    while (run)
    {

    novo_usuario(lista_usuarios);

    }
    return 0;
}
