//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_BATERIA_H
#define TRB_BATERIA_H
#include "../Edificio.h"

using namespace std;

class Bateria:public Edificio{
    int madeira = 10; //nr de vigas de madeira necessarias para construir a bateria
    int custo = 10; //custo de construir uma bateria
public:
    Bateria(): Edificio(0,1,5,1,5,0,100,10,1){} //construtor.
    string gettipoedificio() const override{return "bat";}
    int podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) override;
    void sobeNivel(int *dinheiroilha, Recursos **recursosdazona, bool *resultado) override {

        Edificio::sobeNivel(dinheiroilha, recursosdazona, resultado);

        if (getNivelatual() < getNivelmax()) {

            bool podeSubir = false;

            if (*dinheiroilha >= getPreco() && recursosdazona[4]->getquantidade() >= getQntvigas())
                podeSubir = true;

            if (podeSubir) {
                *dinheiroilha -= getPreco();

                setNivelatual(); // incrementa uma vez
                setCapmax(); // incrementa a capacidade maxima

                *resultado = true;

            }else{

                *resultado = false;

            }

        } else {

            *resultado = false;

        }

    }
};
#endif //TRB_BATERIA_H
