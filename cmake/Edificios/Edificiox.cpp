//
// Created by sandr on 23/12/2021.
//

#include "Edificiox.h"
#include <cstring>

int Edificiox::podeconstroir(Recursos **pRecursos, int dinheiro, string tipo) {
    //para construir o edificiox é preciso dinheiro: "custo" do edificiox

    //verifica se estao reunidas condicoes para construir o edificiox
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

    //passou para aqui entao estao reunidas as condicoes para construir o edificiox
    //devolve o dinheiro a descontar
    if (strcmp(tipo.c_str(), "mnt") == 0) {
        return custo * 2; //numa montanha o custo de construcao é o dobro
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        return custo / 2;
    } else
        return custo;
}