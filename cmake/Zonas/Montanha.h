//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_MONTANHA_H
#define TRB_MONTANHA_H

#include "../Zona.h"

class Montanha:public Zona{
public:
    string gettipozona() const override{return "mnt";}

    void produzir(int i) override{
        Zona::produzir(i);

        int nTrab = trabalhadores.size(); // obter o nº de trabalhadores
        float producaoFerro = 0.1 * nTrab; // produz 0.1kg por cada trabalhador nessa zona

        tiposrecursos[0]->incrementaquantidade(producaoFerro); // incrementar os recursos da zona

    }
};

#endif //TRB_MONTANHA_H
