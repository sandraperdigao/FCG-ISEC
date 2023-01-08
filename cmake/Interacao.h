//
// Created by sandr on 18/11/2021.
//

#ifndef TRB_INTERACAO_H
#define TRB_INTERACAO_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include "Zona.h"
#include "Zonas/Deserto.h"
#include "Ilha.h"

using namespace std;

class Interacao {
    Ilha ilha= Ilha(); //construtor da ilha
    string trim(string str); //funcao para remover os espaços em branco
    bool terminar = false;
public:
    Ilha getilha(){return ilha;} //obter a ilha
    void lecomandos(istream& in); //ler comandos
    void executaficheiro(string nomeficheiro); //ler ficheiro txt
    bool getflag(){return terminar;} //para o main saber quando sair
    void efeitoszonas(); //ainda nao esta a funcionar
    void recolharecursos(); //ainda nao esta a funcionar
};


#endif //TRB_INTERACAO_H
