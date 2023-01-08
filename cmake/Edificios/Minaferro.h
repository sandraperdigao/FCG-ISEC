//
// Created by sandr on 01/11/2021.
//
#include <iostream>

#include "../Recursos/VigasMadeira.h"
#include "../Trabalhadores/Mineiro.h"

#ifndef TRB_MINAFERRO_H
#define TRB_MINAFERRO_H

#include "../Edificio.h"


using namespace std;


class Minaferro : public Edificio {
    int madeira = 10; //nr de vigas de madeira necessarias para construir a mina ferro
    float prodferro = 2; // nr de ferros que a mina ferro produz por dia
    int troca_madeira_por_dinheiro = 10; // preco para trocar vigas de madeira por dinheiro para construir a mina

public:
    Minaferro() : Edificio(0.15, 1, 5, 1, 15, 1, 100, 10,1) {} //construtor.

    string gettipoedificio() const override { return "mnF"; }

    int podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) override;

    void produzEdf(vector<Trabalhadores *> trabalhadores, vector<string> zonasdailha, Recursos **recursosdazona,
                   Edificio *bateria,string tipoZonaatual,Recursos** floresta) override {

        // recebe os trabalhadores da zona em que está o edf
        // recebe o tipo de zonas adjacentes
        // recebe os recursos (apenas da zona) da zona em que esta o edf

        Edificio::produzEdf(trabalhadores, zonasdailha, recursosdazona, bateria,tipoZonaatual,floresta);

        bool existeTrabalhador = false;
        bool reducao = false;
        bool boost = false;

        // o stock passa a ser o numero de recursos do edf
        float stock = tiposrecursos[0]->getquantidade();

        // procuramos pelo mineiro
        for (int i = 0; i < trabalhadores.size(); i++)
            if (strcmp(trabalhadores[i]->gettipotrabalhador().c_str(), "mineiro") == 0) { // se for encontrado
                existeTrabalhador = true; // alteramos a flag
                break; // nao precisamos de procurar mais
            }

        if (tipoZonaatual == "dsr")
            reducao = true;

        if (tipoZonaatual == "mnt")
            boost = true;

        // se o stock da mina for inferior a 100 e existir um mineiro (verifica tb se é uma situaçao normal, de boost ou de reducao)
        if (reducao && stock < getCapmax() && existeTrabalhador)
            tiposrecursos[0]->incrementaquantidade(prodferro / 2); // o stock da mina aumenta
        else if (boost && stock < getCapmax() && existeTrabalhador)
            tiposrecursos[0]->incrementaquantidade(prodferro * 2); // o stock da mina aumenta
        else if (stock < getCapmax() && existeTrabalhador && !reducao && !boost)
            tiposrecursos[0]->incrementaquantidade(prodferro); // o stock da mina aumenta

    }

    void sobeNivel(int *dinheiroilha, Recursos **recursosdazona, bool *resultado) override {

        Edificio::sobeNivel(dinheiroilha, recursosdazona, resultado);

        if (getNivelatual() < getNivelmax()) {

            bool podeSubir = false;

            //float teste1 =this->getPreco();
            //float teste2 =this->getQntvigas();

            if (*dinheiroilha >= this->getPreco() && recursosdazona[4]->getquantidade() >= this->getQntvigas())
                podeSubir = true;

            if (podeSubir) {
                recursosdazona[4]->incrementaquantidade(-getQntvigas());
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

#endif //TRB_MINAFERRO_H
