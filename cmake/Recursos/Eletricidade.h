//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_ELETRICIDADE_H
#define TRB_ELETRICIDADE_H
#include "../Recursos.h"
using namespace std;
class Eletricidade:public Recursos{
public:
    Eletricidade() : Recursos(1){};
    string gettipo() const override{return "eletricidade";}
    double getprecounidade() override{return 1.5;}
};
#endif //TRB_ELETRICIDADE_H
