//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_EDIFICIO_H
#define TRB_EDIFICIO_H

#include "iostream"
#include "Recursos.h"
#include "Recursos/Aco.h"
#include "Recursos/Carvao.h"
#include "Recursos/Eletricidade.h"
#include "Recursos/Ferro.h"
#include "Recursos/Madeira.h"
#include "Recursos/VigasMadeira.h"
#include "Trabalhadores.h"
#include <vector>
#include <cstring>

using namespace std;

class Edificio {
    float prob_desabar;
    bool ligado = false; // flag para saber se um edificio está ligado ou desligado
    int nivel_atual; // nivel atual
    int nivel_maximo; // nivel maximo
    int novo_nivel; // novo nivel
    int preco_nivel; // preco para melhorar de nivel
    float qnt_vigas; // quantidade em vigas para aumentar de nivel
    float cap_max_recursos; // capacidade maxima de armazenamento
    int cap_adicional_nivel; // capacidade adicional de armazendamento por melhoria de nivel
    int contadiasedificio; //contador de dias de existencia do edificio, necessario para o pantano
protected:
//o edificio contem recursos
//a classe edificio tem um ponteiro "tiposrecursos" que aponta para um vetor de recursos
//cada uma das 6 celulas do vetor aponta para um tipo de recurso (ferro, aço, carvão, madeira, vigas de madeira, eletricidade)
    Recursos *tiposrecursos[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(),
                                  new Eletricidade()};
public:
    Edificio(float prob_desabar, int nivel_atual, int nivel_maximo, int novo_nivel, int preco_nivel, int preco_vigas,
             int cap_max_recursos, int cap_adicional_nivel, int contadiasedificio); //construtor
    virtual string
    gettipoedificio() const = 0; //esta funcao existe em todos os "filhos" de edificio (bateria, centraleletrica, etc)
    Recursos **
    getrecursos() { return tiposrecursos; } // a funcao getrecursos devolve o endereço do vetor "tiposrecursos"
    virtual int podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) = 0;

    int decrementa(int qtdadecrementar, int i);

    bool getLigado() { return ligado; } // devolve a flag de um edificio
    void setLigado(bool estado) { ligado = estado; } // liga/desliga um edificio
    bool desabaedificio(); //Funcao para desabar o edificio
    virtual void produzEdf(vector<Trabalhadores *> trabalhadores, vector<string> zonasdailha, Recursos **recursosdazona,
                           Edificio *bateria, string tipoZonaatual, Recursos** floresta) {}; // produzir recursos no edificio
    virtual void sobeNivel(int *dinheiroilha, Recursos **recursosdazona, bool *resultado) {}

    int getPreco() const { return preco_nivel; }

    float getQntvigas() const { return qnt_vigas; }

    int getNivelatual() const { return nivel_atual; }

    void setNivelatual() { nivel_atual++; }

    int getNivelmax() const { return nivel_maximo; }

    float getCapmax() const { return cap_max_recursos; }

    void setCapmax() { cap_max_recursos += getCapadicional(); }

    int getCapadicional() const { return cap_adicional_nivel; }

    void incrementadiasedificio() { contadiasedificio++; }

    int getdiasedificio() { return contadiasedificio; }
};

#endif //TRB_EDIFICIO_H
