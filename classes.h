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
    // Getters
    unsigned getId() const {
        return id;
    }

    const std::string& getEndereco() const {
        return endereco;
    }

    const std::string& getTipoImovel() const {
        return tipoimovel;
    }

    unsigned getCapacidade() const {
        return capacidade;
    }

    unsigned getPrecoDiaria() const {
        return precoDiaria;
    }

    Usuario* getAnfitriao() const {
        return Anfitriao;
    }

    const std::list<unsigned>& getAvaliacao() const {
        return avaliacao;
    }

    // Setters
    void setId(unsigned novoId) {
        id = novoId;
    }

    void setEndereco(const std::string& novoEndereco) {
        endereco = novoEndereco;
    }

    void setTipoImovel(const std::string& novoTipoImovel) {
        tipoimovel = novoTipoImovel;
    }

    void setCapacidade(unsigned novaCapacidade) {
        capacidade = novaCapacidade;
    }

    void setPrecoDiaria(unsigned novoPreco) {
        precoDiaria = novoPreco;
    }

    void setAnfitriao(Usuario* novoAnfitriao) {
        Anfitriao = novoAnfitriao;
    }

    // Métodos existentes
    void avaliar(unsigned nota){
        avaliacao.push_back(nota);
    }

    unsigned mediaAvaliacoes(){
        unsigned media = 0;
        if (avaliacao.empty()) {
            return 0;
        }
        for (unsigned nota : avaliacao) {
            media += nota;
        }
        return media / avaliacao.size();
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
    // Getters
    unsigned getId() const {
        return id;
    }

    Imovel* getImovel() const {
        return imovel;
    }

    const year_month_day& getInicio() const {
        return inicio;
    }

    const year_month_day& getFim() const {
        return fim;
    }

    // Setters
    void setId(unsigned novoId) {
        id = novoId;
    }

    void setImovel(Imovel* novoImovel) {
        imovel = novoImovel;
    }

    void setInicio(const year_month_day& novaDataInicio) {
        inicio = novaDataInicio;
    }

    void setFim(const year_month_day& novaDataFim) {
        fim = novaDataFim;
    }

    // Métodos existentes
    void avaliar(unsigned nota){
        imovel->avaliar(nota);
    }

    bool operator==(const Reserva& outro) const {
        return this->id == outro.id;
    }
};

enum userType {
    USUARIO,
    ANFITRIAO
};

class Usuario {
    unsigned id;
    userType tipoUsuario;
    std::string senha;
    std::string nome;
    unsigned telefone;
    std::list<Reserva*> minhasReservas;

public:
    // Getters
    unsigned getId() const {
        return id;
    }

    userType getTipoUsuario() const {
        return tipoUsuario;
    }

    const std::string& getSenha() const {
        return senha;
    }

    const std::string& getNome() const {
        return nome;
    }

    unsigned getTelefone() const {
        return telefone;
    }

    const std::list<Reserva*>& getMinhasReservas() const {
        return minhasReservas;
    }

    // Setters
    void setId(unsigned novoId) {
        id = novoId;
    }

    void setTipoUsuario(userType novoTipo) {
        tipoUsuario = novoTipo;
    }

    void setSenha(const std::string& novaSenha) {
        senha = novaSenha;
    }

    void setNome(const std::string& novoNome) {
        nome = novoNome;
    }

    void setTelefone(unsigned novoTelefone) {
        telefone = novoTelefone;
    }

    void setMinhasReservas(const std::list<Reserva*>& novasReservas) {
        minhasReservas = novasReservas;
    }

    // Métodos para manipulação de reservas
    void adicionarReserva(Reserva* reserva) {
        minhasReservas.push_back(reserva);
    }

    void removerReserva(Reserva* reserva) {
        minhasReservas.remove(reserva);
    }

    // Métodos existentes
    void avaliar(Reserva reserva, unsigned nota){
        reserva.avaliar(nota);
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
