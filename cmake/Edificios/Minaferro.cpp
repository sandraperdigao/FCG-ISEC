//
// Created by sandr on 01/11/2021.
//

#include "Minaferro.h"
#include <cstring>

/*bool Minaferro::constroiminaferro() {
//
//    int obtem_madeiras = (*mad).get_qtd_madeiras(); //obter a quantidade de vigas de madeira existentes
//    int obtem_dinheiro = (*money).get_qtd_dinheiro(); //obter a quantidade de dinheiro existente
//
//    //para construir a mina sao precisas "madeira" nº vigas de madeira
//    // cada viga pode ser substituida por "troca_madeira_por_dinheiro" euros
//
//    int descontomadeiras = obtem_madeiras > madeira ? madeira : obtem_madeiras; // quantidade de vigas de madeira disponiveis para descontar
//    int descontodinheiro = (madeira - descontomadeiras) * troca_madeira_por_dinheiro; //quantidade de dinheiro necessaria para descontar
//
//    //verifica se nao estao reunidas condicoes para construir a mina
//    if((obtem_madeiras < madeira) && (descontodinheiro < obtem_dinheiro)){
//        return false;
//    }
//
//    //passou para aqui entao estao reunidas as condicoes para construir a mina
//    (*mad).descontamadeiras(descontomadeiras);
//    (*money).descontadinheiro(descontodinheiro);
//
    return true;
}

bool Minaferro::incrementanivel() {
//
//    //para incrementar nivel precisa de "preco_nivel" euros e "troca_madeira" nº de vigas de madeira
//    int obtem_madeiras = (*mad).get_qtd_madeiras(); //obter a quantidade de vigas de madeira existent
//    int obtem_dinheiro = (*money).get_qtd_dinheiro();//obter a quantidade de dinheiro existente
//
//    int aux = novo_nivel - nivel_atual; //variavel auxiliar que dá a diferença de niveis
//    int descontomadeiras = aux * troca_madeira; // calcula a quantidade de vigas de madeira a descontar
//    int descontodinheiro = aux * preco_nivel; // calcula a quantidade de dinheiro a descontar
//
//    //verifica se nao estao reunidas as condicoes para aumentar de nivel
//    if(obtem_dinheiro < descontodinheiro || (obtem_madeiras < descontomadeiras)){
//        return false;
//    }
//
//    //passou para aqui é pq estao reunidas as condicoes
//    (*mad).descontamadeiras(descontomadeiras); // vai descontar as vigas de madeira
//    (*money).descontadinheiro(descontodinheiro); //vai descontar o dinheiro
//    aumentacapacidademaxima(aux); // tem que aumentar a capacidade maxima de armazenamento de ferro
//    nivel_atual = novo_nivel; // muda o nivel atual para o novo nivel

    return true;
}*/

int Minaferro::podeconstroir(Recursos *pRecursos[6], int dinheiro, string tipo) {

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

/*bool Minaferro::sobeNivel(int *dinheiroilha, Recursos **recursosdazona)  {

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
















