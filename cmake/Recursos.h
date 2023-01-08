//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_RECURSOS_H
#define TRB_RECURSOS_H

#include "iostream"

using namespace std;

//Os recursos podem ser de 1 zona ou de 1 edificio
class Recursos {
    float preco;
    float quantidade = 0; // quantidade do recurso. Exemplo: quantidade de ferro, quantidade de carvao, etc
public:
    Recursos(float preco); //construtor
    virtual string gettipo() const = 0; //esta informacao é para os filhos dos Recursos (aço, carvao,etc)
    virtual double getprecounidade() = 0; //esta informacao é para os filhos dos Recursos (aço, carvao,etc)
    float getquantidade() { return quantidade; } //função comum para obter a quantidade dos recursos
    void incrementaquantidade(float qtd) {
        //funcao para incrementar a quantidade dos recursos
        //recebe como parametro a quantidade a incrementar (qtd) e acrescenta-a à "quantidade"
        if (qtd + quantidade < 0) quantidade = 0;
        else quantidade += qtd;
    }

    int venderecursos(int *qnt);

    /*void decrementaquantidade(int qnt) {

        if (quantidade - qnt < 0)quantidade = 0;
        else quantidade -= qnt;
    }*/
};

#endif //TRB_RECURSOS_H
