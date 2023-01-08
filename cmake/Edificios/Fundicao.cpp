//
// Created by sandr on 23/12/2021.
//

#include "Fundicao.h"
#include <cstring>

int Fundicao::podeconstroir(Recursos **pRecursos, int dinheiro, string tipo) {
    //para construir a fundicao é preciso dinheiro: "custo" da fundicao

    //verifica se estao reunidas condicoes para construir a fundicao
    if (strcmp(tipo.c_str(), "mnt") == 0) {
        if (custo * 2 > dinheiro) {
            return -1;
        }
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        if (custo / 2 > dinheiro) {
            return -1;
        }
    } else {
        if (custo > dinheiro) {
            return -1;
        }
    }

    //passou para aqui entao estao reunidas as condicoes para construir a fundicao
    //devolve o dinheiro a descontar
    if (strcmp(tipo.c_str(), "mnt") == 0) {
        return custo * 2; //numa montanha o custo de construcao é o dobro
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        return custo / 2;
    } else
        return custo;
}
