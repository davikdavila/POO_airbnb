#ifndef CLASSES_H_INCLUDED
#define CLASSES_H_INCLUDED

#include <list>
#include "date.h"

using namespace date;
using namespace std::chrono;

class Usuario;

class Imovel {
    unsigned id;
    std::string endereco;
    std::string tipoimovel;
    unsigned capacidade;
    unsigned precoDiaria;
    Usuario* Anfitriao;
    std::list<unsigned> avaliacao;

public:
    unsigned getId() const {
        return id;
    }

    bool operator==(const Imovel& outro) const {
        return this->id == outro.id;
    }
};

class Reserva {
    unsigned id;
    Imovel* imovel;
    year_month_day inicio;
    year_month_day fim;

public:
    unsigned getId() const {
        return id;
    }

    bool operator==(const Reserva& outro) const {
        return this->id == outro.id;
    }
};

class Usuario {
    unsigned id;
    std::string nome;
    unsigned telefone;
    std::list<Reserva*> minhasReservas;

public:
    unsigned getId() const {
        return id;
    }

    bool operator==(const Usuario& outro) const {
        return this->id == outro.id;
    }
};

template <typename T>
class ListaGenerica{
    std::list<T> lista;

public:
    void insere(T dado){
        lista.push_back(dado);
    }
    void remove(T dado){
        lista.remove(dado);
    }
};

class ListaUsuarios : public ListaGenerica<Usuario>{
public:
    void insere(Usuario novoUser){
        ListaGenerica<Usuario>::insere(novoUser);
    }
    void remove(Usuario usuario){
        ListaGenerica<Usuario>::remove(usuario);
    }
};

class ListaImoveis : public ListaGenerica<Imovel>{
public:
    void insere(Imovel novoImovel){
        ListaGenerica<Imovel>::insere(novoImovel);
    }
    void remove(Imovel imovel){
        ListaGenerica<Imovel>::remove(imovel);
    }
};

class ListaReservas : public ListaGenerica<Reserva>{
public:
    void insere(Reserva novaReserva){
        ListaGenerica<Reserva>::insere(novaReserva);
    }
    void remove(Reserva reserva){
        ListaGenerica<Reserva>::remove(reserva);
    }
};

#endif // CLASSES_H_INCLUDED
