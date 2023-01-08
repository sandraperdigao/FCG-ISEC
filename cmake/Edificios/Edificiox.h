//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_EDIFICIOX_H
#define TRB_EDIFICIOX_H

#include "../Edificio.h"

using namespace std;

class Edificiox : public Edificio {
    //Parecido com a fundicao
    int ferro = 1; //nr de ferro necessario para materia prima
    int carvao = 1; // nr de carvao necessario para materia prima
    int aco = 1; // nr de aco que o edificiox produz por dia
    int custo = 10; // preco para construir o edificiox
public:
    Edificiox() : Edificio(0, 0, 0, 0, 0, 0, 0, 0, 1) {} //construtor.
    string gettipoedificio() const override { return "edfX"; }

    int podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) override;

    void sobeNivel(int *dinheiroilha, Recursos **recursosdazona, bool *resultado) override { *resultado = false; }

    void
    produzEdf(vector<Trabalhadores *> trabalhadores, vector<string> zonasdailha, Recursos **recursosdazona,
              Edificio *bateria, string tipoZonaatual,Recursos** floresta) override {

        // recebe os trabalhadores da zona em que está o edf
        // recebe o tipo de zonas adjacentes
        // recebe os recursos (apenas da zona) da zona em que esta o edf

        Edificio::produzEdf(trabalhadores, zonasdailha, recursosdazona, bateria, tipoZonaatual,floresta);

        bool existeTrabalhador = false;
        bool temMadeira = false;
        bool estaFloesta = false;

        for (int i = 0; i < trabalhadores.size(); i++) // procura por um operario
            if (strcmp(trabalhadores[i]->gettipotrabalhador().c_str(), "operario") == 0) {
                existeTrabalhador = true;
                break; // se encontra nao precisa de procurar mais
            }

        if (tipoZonaatual == "flr")
            estaFloesta = true;

        if (recursosdazona[3]->getquantidade() > 0)
            temMadeira = true;

        if (temMadeira && existeTrabalhador && estaFloesta) { // transforma madeira em vigas, 1 por 4
            recursosdazona[3]->incrementaquantidade(-1); // remove madeira
            tiposrecursos[4]->incrementaquantidade(4); // adiciona vigas
        }

    }
};

#endif //TRB_EDIFICIOX_H
