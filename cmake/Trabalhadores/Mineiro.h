//
// Created by sandr on 01/11/2021.
//

#ifndef TRB_MINEIRO_H
#define TRB_MINEIRO_H

#include <string>
#include "../Trabalhadores.h"

using namespace std;

class Mineiro:public Trabalhadores {
public:
    Mineiro(): Trabalhadores(){}
    Mineiro(int dia) :Trabalhadores (10,0.1,dia + 2,dia,1){} //construtor.
    string getinicial() const override {return "M";} //funcao para obter a inicial dos trabalhadores
    string gettipotrabalhador() const override{return "mineiro";}
    int getprecotrabalhador() const override{return 10;}

};

#endif //TRB_MINEIRO_H
