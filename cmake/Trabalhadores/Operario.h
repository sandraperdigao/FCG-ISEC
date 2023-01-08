//
// Created by sandr on 27/12/2021.
//

#ifndef TRB_OPERARIO_H
#define TRB_OPERARIO_H
#include "iostream"
#include "../Trabalhadores.h"

using namespace std;

class Operario:public Trabalhadores{
public:
    Operario(): Trabalhadores(){}
    Operario(int dia) : Trabalhadores(15,0.05,dia+10,dia,1){} //construtor.
    string getinicial() const override {return "O";} //funcao para obter a inicial dos operarios
    string gettipotrabalhador() const override{return "operario";}
    int getprecotrabalhador() const override{return 15;}
};
#endif //TRB_OPERARIO_H
