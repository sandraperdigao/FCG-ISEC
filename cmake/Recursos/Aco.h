//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_ACO_H
#define TRB_ACO_H
#include "../Recursos.h"
using namespace std;

class Aco:public Recursos{
public:
    Aco() : Recursos(2){};
    string gettipo() const override{return "aco";}
    double getprecounidade() override{return 2;}
};
#endif //TRB_ACO_H
