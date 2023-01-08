//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_MADEIRA_H
#define TRB_MADEIRA_H
#include "../Recursos.h"
using namespace std;
class Madeira:public Recursos{
public:
    Madeira() : Recursos(1){};
    string gettipo() const override{return "madeira";}
    double getprecounidade() override{return 1;}
};
#endif //TRB_MADEIRA_H
