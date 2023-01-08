//
// Created by sandr on 23/12/2021.
//

#include "Edificio.h"

Edificio::Edificio(float prob_desabar, int nivel_atual, int nivel_maximo, int novo_nivel, int preco_nivel,
                   int qnt_vigas,
                   int cap_max_recursos, int cap_adicional_nivel, int contadiasedificio) {
    this->prob_desabar = prob_desabar;
    this->nivel_atual = nivel_atual;
    this->nivel_maximo = nivel_maximo;
    this->novo_nivel = novo_nivel;
    this->preco_nivel = preco_nivel;
    this->qnt_vigas = qnt_vigas;
    this->cap_max_recursos = cap_max_recursos;
    this->cap_adicional_nivel = cap_adicional_nivel;
    this->contadiasedificio = contadiasedificio;
}

int Edificio::decrementa(int qtdadecrementar, int i) {

    int g = tiposrecursos[i]->getquantidade();
    int diferenca = g > qtdadecrementar ? qtdadecrementar : g;

    //descontar os recursos ao edificio da zona
    tiposrecursos[i]->incrementaquantidade(-diferenca);

    return diferenca;
}

//FUNCAO QUE DEVOLVE UM BOOL PARA DESABAR EDIFICIO
bool Edificio::desabaedificio() {
    //vai gerar um numero aleatorio entre 0 e 1
    double aleatorio = ((double) rand() / (RAND_MAX));
    //devolve um bool resultado da avaliação de "aleatorio < prob_desabar"
    return (aleatorio < prob_desabar);
}

