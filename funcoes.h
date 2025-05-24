#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

#include "classes.h"
#include <iostream>
#include <limits> // Para limpar o buffer do cin

using namespace std;

void novo_usuario(ListaUsuarios &lista) {
    Usuario novo;

    // Configuração do tipo de usuário
    cout << "Anfitrião ou usuário? (1 para ANFITRIAO ou 0 para USUARIO)" << endl;
    unsigned tipoUsuario;
    while(true) {
        cin >> tipoUsuario;
        if(cin.fail() || tipoUsuario > 1) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada inválida. Digite 0 para USUARIO ou 1 para ANFITRIAO: ";
        } else {
            break;
        }
    }
    novo.setTipoUsuario(tipoUsuario == 1 ? ANFITRIAO : USUARIO);

    // Configuração do ID
    cout << "Digite o ID do usuário: ";
    unsigned id;
    cin >> id;
    novo.setId(id);

    // Configuração do nome
    cout << "Digite o nome do usuário: ";
    string nome;
    cin.ignore(); // Limpa o buffer do \n anterior
    getline(cin, nome);
    novo.setNome(nome);

    // Configuração da senha
    cout << "Digite a senha: ";
    string senha;
    getline(cin, senha);
    novo.setSenha(senha);

    // Configuração do telefone
    cout << "Digite o telefone (apenas números): ";
    unsigned telefone;
    cin >> telefone;
    novo.setTelefone(telefone);

    // Inserção na lista
    lista.insere(novo);

    cout << "Usuário criado com sucesso!" << endl;
}

#endif // FUNCOES_H_INCLUDED
