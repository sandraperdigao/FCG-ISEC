//
// Created by sandr on 27/12/2021.
//

#include <cstring>
#include "Trabalhadores.h"

//CONSTRUTOR
Trabalhadores::Trabalhadores(int preco, float prob_despedir, int dia_despedir, int dia, int contaDias) {
    this->preco = preco;
    this->prob_despedir = prob_despedir;
    this->dia_despedir = dia_despedir;
    this->id[0] = ++contador;
    this->id[1] = dia; //dia da contratacao
    this->contaDias = contaDias;
}

//FUNCAO QUE DEVOLVE UM BOOL PARA DESPEDIR TRABALHADOR
bool Trabalhadores::despedetrabalhador(int diaatual, string tipozona) {

    // se nao for uma montanha
    if (strcmp(tipozona.c_str(), "mnt") != 0) {
        //se o dia atual do jogo for menor que o dia a partir do qual
        //é possivel despedir o trabalhador, então retorna falso pois nao pode despedir
        if (diaatual < dia_despedir)
            return false;
        //passou para aqui, entao pode despedir
        //vai gerar um numero aleatorio entre 0 e 1
        double aleatorio = ((double) rand() / (RAND_MAX));
        //devolve um bool resultado da avaliação de "aleatorio < prob_despedir"
        return (aleatorio < prob_despedir);
    } else {
        //se for uma montanha a probabilidade de despedir aumenta 5pct e ate os lenhadores sao
        //afetados
        //se o dia atual do jogo for menor que o dia a partir do qual
        //é possivel despedir o trabalhador, então retorna falso pois nao pode despedir
        if (diaatual < dia_despedir)
            return false;
        //vai gerar um numero aleatorio entre 0 e 1
        double aleatorio = ((double) rand() / (RAND_MAX));
        //devolve um bool resultado da avaliação de "aleatorio < prob_despedir"
        return (aleatorio < (prob_despedir + 0.05));
    }

}