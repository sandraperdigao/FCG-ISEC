//
// Created by sandr on 23/12/2021.
//

#include "Recursos.h"

Recursos::Recursos(float preco) {
    this->preco = preco;
}

int Recursos::venderecursos(int *qnt) {

    int recompensa;

    // se a quantidade a vender exceder os limites, coloca os recursos a zero
    if (quantidade - *qnt < 0) {
        recompensa = quantidade; // o dinheiro é igual à quantidade vendida
        *qnt -= quantidade; // a quantidade a vender decrementa consoante aquilo que vendei
        quantidade = 0; // a quantidade desse recurso passa para zero, pq a quantidade a vender é superior
        return recompensa; // vamos devolver como recompensa a quantidade vendida
    } else if (quantidade - *qnt == 0) {
        recompensa = *qnt; // a recompensa é a quantidade que queriamos vender
        *qnt = 0; // a quantidade a vender passa para zero, pq a quantidade existente é igual
        quantidade = 0; // a quantidade desse recurso passa para zero, pq a quantidade a vender é igual
    } else if (quantidade - *qnt > 0) {
        recompensa = *qnt; // a recompensa passa a ser a qnt que queriamos vender
        quantidade -= *qnt; // temos de remover à quantidade existente a que foi vendida
        *qnt = 0; // a quantidade a vender passa a ser 0 pq a quantidade existente é maior
    }

    return recompensa;

}