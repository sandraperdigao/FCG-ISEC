//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_CENTRALELETRICA_H
#define TRB_CENTRALELETRICA_H

#include "../Edificio.h"

using namespace std;

class Centraleletrica : public Edificio {
    int madeira = 1; //nr de madeira necessarias para queimar (materia prima)
    int prodcarvao = 1; // nr de carvao que a central produz por dia
    int eletricidade = 1; // nr de eletricidade que a central produz por dia
    int custo = 15; // preco para construir a central
    int cap_max_carvao = 100; // capacidade de armazenamento de carvao
public:
    Centraleletrica() : Edificio(0, 0, 0, 0, 0, 0, 0, 0, 1) {} //construtor.
    string gettipoedificio() const override { return "elec"; }

    int podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) override;

    void
    produzEdf(vector<Trabalhadores *> trabalhadores, vector<string> zonasdailha, Recursos **recursosdazona,
              Edificio *bateria, string tipoZonaatual,Recursos** floresta) override {

        // recebe os trabalhadores da zona em que está o edf
        // recebe o tipo de zonas adjacentes
        // recebe os recursos (apenas da zona) da zona em que esta o edf

        Edificio::produzEdf(trabalhadores, zonasdailha, recursosdazona, bateria, tipoZonaatual,floresta);

        // obtemos os recursos do edf
        Recursos **recursosdoEdf;
        recursosdoEdf = getrecursos();

        bool existeTrabalhador = false;
        bool trocouosrecursos = false;
        //int stock = recursosdoEdf[0]->getquantidade(); // o stock passa a ser o numero de recursos do edf (ferro)
        //stock < this->getCapmax() ---- nao ha capacidade maxima na central eletrica

        // procuramos pelo operario
        for (int i = 0; i < trabalhadores.size(); i++)
            if (strcmp(trabalhadores[i]->gettipotrabalhador().c_str(), "operario") == 0) { // se for encontrado
                existeTrabalhador = true; // alteramos a flag
                break; // nao precisamos de procurar mais
            }

        // se o stock da central for inferior a 100 e existir um operario e existir madeira
        if (existeTrabalhador && recursosdazona[3]->getquantidade() > 0 && floresta != nullptr) {
            //recursosdazona[3]->incrementaquantidade(-1); // removemos madeira
            floresta[3]->incrementaquantidade(-1); // removemos madeira da floresta
            tiposrecursos[2]->incrementaquantidade(prodcarvao); // adicionamos carvao
            trocouosrecursos = true;
        }

        if (bateria != nullptr && trocouosrecursos == true) {
            Recursos **recursosBateria = bateria->getrecursos();
            recursosBateria[5]->incrementaquantidade(eletricidade);
        }

    }

    void sobeNivel(int *dinheiroilha, Recursos **recursosdazona, bool *resultado) override { *resultado = false; }
};

#endif //TRB_CENTRALELETRICA_H
