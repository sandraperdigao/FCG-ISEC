//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_PANTANO_H
#define TRB_PANTANO_H

#include "../Zona.h"

class Pantano:public Zona{
public:
    string gettipozona() const override{return "pnt";}
};

#endif //TRB_PANTANO_H
