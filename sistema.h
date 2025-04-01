#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Classe base Usuario
class Usuario {
protected:
    string nome;
    string telefone;
    string cep;
public:
    Usuario(string& nome, string& telefone, string& cep)
        : nome(nome), telefone(telefone), cep(cep) {}

    virtual void exibirInfo() = 0;
};

// Subclasse Hospede
class Hospede : public Usuario {
    string cpf;
    int idade;
public:
    Hospede(string& nome, string& telefone, string& cep, string& cpf, int idade)
        : Usuario(nome, telefone, cep), cpf(cpf), idade(idade) {}

    void exibirInfo() override {
        cout << "Hospede - Nome: " << nome << ", Idade: " << idade << endl;
    }
};

// Subclasse Anfitriao
class Anfitriao : public Usuario {
    string cnpj;
public:
    Anfitriao(string& nome, string& telefone, string& cep, string& cnpj)
        : Usuario(nome, telefone, cep), cnpj(cnpj) {}

    void exibirInfo() override {
        cout << "Anfitriao - Nome: " << nome << ", CNPJ: " << cnpj << endl;
    }
};

// Classe base Imovel
class Imovel {
protected:
    string endereco;
    double tamanho;
    int moveis;
    int comodos;
    string cep;
    int capacidade;
    double precoPorDia;
    Anfitriao* responsavel;
public:
    Imovel(string& endereco, double tamanho, int moveis, int comodos,
           string& cep, int capacidade, double precoPorDia, Anfitriao* responsavel)
        : endereco(endereco), tamanho(tamanho), moveis(moveis), comodos(comodos),
          cep(cep), capacidade(capacidade), precoPorDia(precoPorDia), responsavel(responsavel) {}

    virtual void exibirInfo() = 0;
    double getPrecoPorDia() { return precoPorDia; }
};

// Subclasse Casa
class Casa : public Imovel {
public:
    Casa(string& endereco, double tamanho, int moveis, int comodos,
         string& cep, int capacidade, double precoPorDia, Anfitriao* responsavel)
        : Imovel(endereco, tamanho, moveis, comodos, cep, capacidade, precoPorDia, responsavel) {}

    void exibirInfo() override {
        cout << "Casa - Endereco: " << endereco << ", Capacidade: " << capacidade
             << ", Preco: R$" << precoPorDia << endl;
    }
};

// Subclasse Apartamento
class Apartamento : public Imovel {
    int andar;
    double valorCondominio;
public:
    Apartamento(string& endereco, double tamanho, int moveis, int comodos,
                string& cep, int capacidade, double precoPorDia, Anfitriao* responsavel,
                int andar, double valorCondominio)
        : Imovel(endereco, tamanho, moveis, comodos, cep, capacidade, precoPorDia, responsavel),
          andar(andar), valorCondominio(valorCondominio) {}

    void exibirInfo() override {
        cout << "Apartamento - Endereco: " << endereco << ", Andar: " << andar
             << ", Preco: R$" << precoPorDia << ", Condominio: R$" << valorCondominio << endl;
    }
};

// Subclasse Chale
class Chale : public Imovel {
public:
    Chale(string& endereco, double tamanho, int moveis, int comodos,
          string& cep, int capacidade, double precoPorDia, Anfitriao* responsavel)
        : Imovel(endereco, tamanho, moveis, comodos, cep, capacidade, precoPorDia, responsavel) {}

    void exibirInfo() override {
        cout << "Chale - Endereco: " << endereco << ", Capacidade: " << capacidade
             << ", Preco: R$" << precoPorDia << endl;
    }
};

// Classe Reserva
class Reserva {
    double valor;
    Hospede* consumidor;
    Imovel* imovel;
    string dataReserva;
    int notaAvaliacao = 0;
public:
    Reserva(double valor, Hospede* consumidor, Imovel* imovel, string& dataReserva)
        : valor(valor), consumidor(consumidor), imovel(imovel), dataReserva(dataReserva) {}

    void exibirInfo() {
        cout << "Reserva - Valor da Diária: R$" << valor << ", Data: " << dataReserva << endl;
        consumidor->exibirInfo();
        imovel->exibirInfo();
        if (notaAvaliacao > 0)
            cout << "Nota da avaliacao: " << notaAvaliacao << "/5" << endl;
    }

    void avaliar(int nota) {
        notaAvaliacao = nota;
        cout << "Avaliacao registrada: Nota " << nota << "/5" << endl;
    }

    string getDataReserva() { return dataReserva; }
};

// Classe App
class App {
    string nome;
    vector<Usuario*> usuarios;
    vector<Imovel*> imoveis;
    vector<Reserva> reservas;
public:
    App(string& nome) : nome(nome) {}

    void cadastrarUsuario(Usuario* usuario) {
        usuarios.push_back(usuario);
        cout << "Usuario cadastrado com sucesso." << endl;
    }

    void cadastrarImovel(Imovel* imovel) {
        imoveis.push_back(imovel);
        cout << "Imovel cadastrado com sucesso." << endl;
    }

    void listarImoveis() {
        cout << "--- Lista de Imoveis ---" << endl;
        for (auto& imovel : imoveis) {
            imovel->exibirInfo();
        }
    }

    void cadastrarReserva(Reserva& reserva) {
        reservas.push_back(reserva);
        cout << "Reserva cadastrada para o dia " << reserva.getDataReserva() << endl;
    }

    void listarReservas() {
        cout << "--- Lista de Reservas ---" << endl;
        for (auto& reserva : reservas) {
            reserva.exibirInfo();
        }
    }
};

#endif // SISTEMA_H
