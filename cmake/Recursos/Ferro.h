//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_FERRO_H
#define TRB_FERRO_H
#include "../Recursos.h"
using namespace std;

class Ferro:public Recursos{
public:
    Ferro() : Recursos(1){};
    string gettipo() const override{return "ferro";}
    double getprecounidade() override{return 1;}
};
#endif //TRB_FERRO_H
