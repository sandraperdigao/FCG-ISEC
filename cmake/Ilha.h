//
// Created by sandr on 04/11/2021.
//

#ifndef TRB_ILHA_H
#define TRB_ILHA_H

#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cstring>
#include "Zona.h"
#include "string.h"

//construcao dinamica da ilha
//a ilha é um conjunto de zonas
static string a[] = {"dsr", "pas", "flr", "mnt", "pnt", "znX"};
//vetor de strings com os 6 tipos de zonas (deserto, pasto, floresta, montanha, pantano, zona x)

class Ilha {
    Zona *pasto = nullptr; // ponteiro para zona que inicialmente aponta para null.
    // vai apontar para a zona pasto onde vão estar os trabalhadores inicialmente.
    // Esta zona pasto é escolhida aleatoriamente
    int altura; // a ilha tem uma altura que corresponde ao nr de linhas
    int largura;    // a ilha tem uma largura que corresponde ao nr de colunas
    string ocupaquatro(string palavra) const; //função que recebe uma string e vai faze la ocupar
    // "nrespacos" espacos (para a representacao da ilha ficar sempre bem no ecrã)
    int nrespacos = 4; // nr de espaços que a palavra pode apresentar (representacao da ilha)
    //vector <vector <Zona*>> zonas; // a ilha é um vetor de vetores de zonas
    Zona *zona; // ponteiro para uma zona (deixamos de ter um vetor de vetores de zonas)
    int diaatual = 0; //dia atual
    int dinheiroilha = 100; //dinheiro existente na ilha
    int despedidos = 0;
public:
    Ilha(); // construtor da ilha
    string getAsString() const; // função que imprime a ilha no ecrã
    Zona *obtemtipozonaleatorio(int a[]) const; //funcao para obter aleatoriamente o tipo de zona
    Zona *procurapastoaleatorio(); //funcao que devolve um pasto aleatorio para meter os trabalhadores
    string contratatrabalhador(string tipotrab);// funcao para contratar um tipo de trabalhador
    string representa(int i, int j); // funcao para representar apenas uma zona detalhada com o comando list
    //Meta 2
    string constroi(string tipoedif, int i, int j); // funcao para construir um edifício numa zona.
    void getrecursos(Recursos **pRecursos) const; //Funcao para obter os recursos totais da ilha inteira
    //recebe como argumento um ponteiro para ponteiro de recursos "pRecursos"
    string transferetrabalhador(string id, int linha,int coluna); //Funca para transferir um trabalhador para uma determinada zona
    void avancadias(); //Funcao para avancar o dia da simulacao e dos edificios
    void despedimentos(); //Funcao necessaria para os efeitos das zonas, vai atuar nos despedimentos dos trabalhadores
    void mudaflagsmovidos(); //Funcao necessaria para mudar as flags dos trabalhadores para poderem voltar a ser movidos no novo dia
    Zona *constroilinha(int tamanho, int a[]); // controi uma linha (é usada no construtor da Ilha)
    Zona *acessoilha(int altura, int largura) const; // aceder a uma posição da ilha
    void descontarecursosilha(Recursos *pRecursos[6]);
    string ligarEdfs(int linha, int coluna); // função para tentar ligar um edificio
    string desligarEdfs(int linha, int coluna); // função para tentar desligar um edificio
    string despedetrabalhadorDebug(string id); // funçao para remover trabalhadores
    void desabamentos(); //Funcao necessaria para os efeitos das zonas, vai atuar nos desabamentos de edificios
    string incrementaDinheiro(int qnt); // incrementa o dinheiro da ilha
    void produz(); // faz com que todos os edificios produzam recursos
    string constroiDebug(string tipoedif, int i, int j); // funçao para construir um edificio sem custos
    string vende(string a, string b); // funçao para vender edificios/recursos
    string subirnivel(int linha, int coluna); // função para subir de nivel numa determinada celula
    void zerarnumerodespedimentos(){despedidos = 0;}
    int getnumerodespedimentos(){return despedidos;}
    void diasTrabalho(); // vai incrementar os dias de trabalho dos trabalhadores de cada zona
};

#endif //TRB_ILHA_H
