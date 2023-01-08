//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_FUNDICAO_H
#define TRB_FUNDICAO_H

#include "../Edificio.h"

using namespace std;

class Fundicao : public Edificio {
    float ferro = 1.5; //nr de ferro necessario para materia prima
    float carvao = 0.5; // nr de carvao necessario para materia prima
    int aco = 1; // nr de aco que a fundicao produz por dia
    int custo = 10; // preco para construir a fundicao
public:
    Fundicao() : Edificio(0,0,0,0,0,0,0,0,1) {} //construtor.
    string gettipoedificio() const override { return "fun"; }

    int podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) override;

    void
    produzEdf(vector<Trabalhadores *> trabalhadores, vector<string> zonasdailha, Recursos **recursosdazona,Edificio *bateria,string tipoZonaatual,Recursos** floresta) override {

        // recebe os trabalhadores da zona em que está o edf
        // recebe o tipo de zonas adjacentes
        // recebe os recursos (apenas da zona) da zona em que esta o edf

        bool existeTrabalhador = false;
        bool zona1 = false;
        bool zona2 = false;
        bool temFerro = false;
        bool temCarvao = false;

        Edificio::produzEdf(trabalhadores, zonasdailha, recursosdazona,bateria,tipoZonaatual,floresta);

        for (int i = 0; i < trabalhadores.size(); i++) // procura por um operario
            if (strcmp(trabalhadores[i]->gettipotrabalhador().c_str(), "operario") == 0) {
                existeTrabalhador = true;
                break; // se encontra nao precisa de procurar mais
            }

        for (int i = 0; i < zonasdailha.size(); i++) // procura por uma mina de ferro adjacente
            if (strcmp(zonasdailha[i].c_str(), "mnF") == 0) {
                zona1 = true;
                break; // se encontra nao precisa de procurar mais
            }

        for (int i = 0; i < zonasdailha.size(); i++) // procura por uma mina de carvao adjacente
            if (strcmp(zonasdailha[i].c_str(), "mnC") == 0) {
                zona2 = true;
                break; // se encontra nao precisa de procurar mais
            }

        if (recursosdazona[0]->getquantidade() > 0)
            temFerro = true;

        if (recursosdazona[2]->getquantidade() > 0)
            temCarvao = true;

        if (existeTrabalhador && zona1 && zona2 && temFerro && temCarvao) {
            recursosdazona[0]->incrementaquantidade(-ferro);
            recursosdazona[2]->incrementaquantidade(-carvao);
            tiposrecursos[1]->incrementaquantidade(aco);
        }

    }
    void sobeNivel(int *dinheiroilha,Recursos **recursosdazona,bool *resultado) override{*resultado = false;}
};

#endif //TRB_FUNDICAO_H
