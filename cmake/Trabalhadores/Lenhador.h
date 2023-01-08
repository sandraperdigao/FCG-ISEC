//
// Created by sandr on 27/12/2021.
//

#ifndef TRB_LENHADOR_H
#define TRB_LENHADOR_H
#include "iostream"
#include "../Trabalhadores.h"

using namespace std;

class Lenhador:public Trabalhadores{
public:
    Lenhador(): Trabalhadores(){}
    Lenhador(int dia) : Trabalhadores(20,0,0,dia,1){} //construtor.
    string getinicial() const override {return "L";} //funcao para obter a inicial dos lenhadores
    string gettipotrabalhador() const override{return "lenhador";}
    int getprecotrabalhador() const override{return 20;}
};
#endif //TRB_LENHADOR_H
