#include <iostream>
#include <vector>
#include "cmake-build-debug/Zona.h"
#include "cmake-build-debug/Ilha.h"
#include "cmake-build-debug/Interacao.h"

int Zona::count=998; //NAO ESTA A SER USADA

int main() {
    srand(time(NULL)); //geracao de numeros aleatorios

    /*--------------------------  START ---------------------------*/

    Interacao jogo; // criar objeto do tipo "Interacao" chamado jogo
    cout<<jogo.getilha().getAsString(); // imprimir a ilha

    //FASES DO JOGO
    while(!jogo.getflag()){
        //Amanhecer
        jogo.efeitoszonas(); //ainda nao esta a funcionar

        //Meio Dia
        jogo.lecomandos(cin); //ler comandos

        //Anoitecer
        jogo.recolharecursos(); //ainda nao esta a funcionar
    }

    cout << "\nPrograma terminado!\n";

    return 0;
}
