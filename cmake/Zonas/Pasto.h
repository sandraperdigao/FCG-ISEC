//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_PASTO_H
#define TRB_PASTO_H

#include "../Zona.h"

class Pasto:public Zona{
public:
    string gettipozona() const override{return "pas";}
};

#endif //TRB_PASTO_H
