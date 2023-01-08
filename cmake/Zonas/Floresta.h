//
// Created by sandr on 23/12/2021.
//

#ifndef TRB_FLORESTA_H
#define TRB_FLORESTA_H

#include "../Zona.h"

class Floresta : public Zona {
    int arvores; // numero de árvores da zona
public:
    Floresta() : Zona() { arvores = rand() % 20 + 20; } // construir uma floresta
    string gettipozona() const override { return "flr"; }

    int getarvores() const override { return arvores; }

    void produzir(int i) override {
        Zona::produzir(i);

        bool existeEdf = false;
        if (getponteiroedificio() != nullptr)
            existeEdf = true; // se chegar aqui, significa que existe um edificio construido na floresta

        int nLen = 0;

        for (int i = 0; i < trabalhadores.size(); i++) {
            if (strcmp(trabalhadores[i]->gettipotrabalhador().c_str(), "lenhador") == 0)
                if (trabalhadores[i]->getContadias() % 5 != 0)
                    nLen++;
        }

        int minMadeira = nLen < arvores ? nLen : arvores;

        if (!existeEdf) { // se nao existir edificio

            tiposrecursos[3]->incrementaquantidade(minMadeira);
            arvores -= minMadeira;

            if (arvores < 100 && (i + 1) % 2 == 0) // se nao tiver 100 arvores e for dia par
                arvores++;

        } else { // se existir edificio

            tiposrecursos[3]->incrementaquantidade(minMadeira);
            arvores -= minMadeira;

            if (arvores > 0)
                arvores--; // produziu mandeira anteriormente, mas ainda assim perde uma árvore

        }

    }
};

#endif //TRB_FLORESTA_H
