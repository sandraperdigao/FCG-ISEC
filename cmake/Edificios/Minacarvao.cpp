//
// Created by sandr on 23/12/2021.
//

#include "Minacarvao.h"
#include <cstring>

int Minacarvao::podeconstroir(Recursos **pRecursos, int dinheiro, string tipo) {
    //Recursos *a[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    int obtem_madeiras = pRecursos[4]->getquantidade();

    //para construir a mina sao precisas "madeira" nº vigas de madeira
    // cada viga pode ser substituida por "troca_madeira_por_dinheiro" euros

    int descontomadeiras = obtem_madeiras > madeira ? madeira
                                                    : obtem_madeiras; // quantidade de vigas de madeira disponiveis para descontar
    int descontodinheiro = (madeira - descontomadeiras) *
                           troca_madeira_por_dinheiro; //quantidade de dinheiro necessaria para descontar

    //verifica se nao estao reunidas condicoes para construir a mina
    if (strcmp(tipo.c_str(), "mnt") == 0) {
        if (descontodinheiro * 2 > dinheiro) {
            return -1;
        }
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        if (descontodinheiro / 2 > dinheiro) {
            return -1;
        }
    } else {
        if (descontodinheiro > dinheiro) {
            return -1;
        }
    }

    //passou para aqui entao estao reunidas as condicoes para construir a mina
    //decrementa madeiras
    pRecursos[4]->incrementaquantidade(-descontomadeiras);

    //devolve o dinheiro a descontar
    if (strcmp(tipo.c_str(), "mnt") == 0) {
        return descontodinheiro * 2; //numa montanha o custo de construcao é o dobro
    } else if (strcmp(tipo.c_str(), "znX") == 0) {
        return descontodinheiro / 2;
    } else
        return descontodinheiro;
}

/*bool Minacarvao::sobeNivel(int *dinheiroilha, Recursos **recursosdazona)  {

    Edificio::sobeNivel(dinheiroilha, recursosdazona);

    if (getNivelatual() < getNivelmax()) {

        bool podeSubir = false;

        if (*dinheiroilha >= getPreco() && recursosdazona[4]->getquantidade() >= getQntvigas())
            podeSubir = true;

        if (podeSubir) {
            recursosdazona[4]->incrementaquantidade(-getQntvigas());
            *dinheiroilha -= getPreco();

            setNivelatual(); // incrementa uma vez
            setCapmax(); // incrementa a capacidade maxima

            return true;

        }

        return false;

    }

    return false;

}*/