//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_CARVAO_H
#define TRB_CARVAO_H
#include "../Recursos.h"
using namespace std;
class Carvao:public Recursos{
public:
    Carvao() : Recursos(1){};
    string gettipo() const override{return "carvao";}
    double getprecounidade() override{return 1;}
};
#endif //TRB_CARVAO_H
