//
// Created by sandr on 04/11/2021.
//

#ifndef TRB_DESERTO_H
#define TRB_DESERTO_H


#include "../Zona.h"

class Deserto:public Zona{
public:
    string gettipozona() const override{return "dsr";}
};


#endif //TRB_DESERTO_H
