//
// Created by sandr on 23/12/2021.
//
#include <cstring>
#include "Bateria.h"

int Bateria::podeconstroir(Recursos **pRecursos, int dinheiro, string tipo) {
    //Recursos *a[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    int obtem_madeiras = pRecursos[4]->getquantidade(); //obtem vigas de madeira

    //para construir a bateria sao precisas "madeira" nº vigas de madeira e dinheiro "custo"
    //verifica se nao estao reunidas condicoes para construir a mina

    if (strcmp(tipo.c_str(), "mnt") == 0) {
        if (obtem_madeiras < madeira || custo * 2 > dinheiro) {
            return -1; //nao tem vigas de madeira ou dinheiro suficiente
        }
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        if (obtem_madeiras < madeira || custo / 2 > dinheiro) {
            return -1; //nao tem vigas de madeira ou dinheiro suficiente
        }
    } else {
        if (obtem_madeiras < madeira || custo > dinheiro) {
            return -1; //nao tem vigas de madeira ou dinheiro suficiente
        }
    }

    //passou para aqui entao estao reunidas as condicoes para construir a mina
    //decrementa madeiras
    pRecursos[4]->incrementaquantidade(-madeira);

    //devolve o dinheiro a descontar
    if (strcmp(tipo.c_str(), "mnt") == 0) {
        return custo * 2; //numa montanha o custo de construcao é o dobro
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        return custo / 2;
    } else
        return custo;
}
