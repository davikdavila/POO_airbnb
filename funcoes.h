#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include "classes.h"
#include <iostream>
#include <limits> // Para limpar o buffer do cin

using namespace std;

void novo_usuario(ListaUsuarios &lista) {
    Usuario novo;

    // Configura��o do tipo de usu�rio
    cout << "Anfitri�o ou usu�rio? (1 para ANFITRIAO ou 0 para USUARIO)" << endl;
    unsigned tipoUsuario;
    while(true) {
        cin >> tipoUsuario;
        if(cin.fail() || tipoUsuario > 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inv�lida. Digite 0 para USUARIO ou 1 para ANFITRIAO: ";
        } else {
            break;
        }
    }
    novo.setTipoUsuario(tipoUsuario == 1 ? ANFITRIAO : USUARIO);

    // Configura��o do ID
    cout << "Digite o ID do usu�rio: ";
    unsigned id;
    cin >> id;
    novo.setId(id);

    // Configura��o do nome
    cout << "Digite o nome do usu�rio: ";
    string nome;
    cin.ignore(); // Limpa o buffer do \n anterior
    getline(cin, nome);
    novo.setNome(nome);

    // Configura��o da senha
    cout << "Digite a senha: ";
    string senha;
    getline(cin, senha);
    novo.setSenha(senha);

    // Configura��o do telefone
    cout << "Digite o telefone (apenas n�meros): ";
    unsigned telefone;
    cin >> telefone;
    novo.setTelefone(telefone);

    // Inser��o na lista
    lista.insere(novo);

    cout << "Usu�rio criado com sucesso!" << endl;
}

#endif // FUNCOES_H_INCLUDED
