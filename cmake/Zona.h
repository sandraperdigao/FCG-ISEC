//
// Created by sandr on 04/11/2021.
//

#ifndef TRB_ZONA_H
#define TRB_ZONA_H

#include <string>
#include <sstream>
#include <vector>
#include <cstring>
#include "Edificios/Minaferro.h"
#include "Edificios/Minacarvao.h"
#include "Edificios/Bateria.h"
#include "Edificios/Centraleletrica.h"
#include "Edificios/Edificiox.h"
#include "Edificios/Fundicao.h"
#include "Recursos.h"
#include "Recursos/Aco.h"
#include "Recursos/Carvao.h"
#include "Recursos/Eletricidade.h"
#include "Recursos/Ferro.h"
#include "Recursos/Madeira.h"
#include "Recursos/VigasMadeira.h"

using namespace std;

class Zona {
    Edificio *edificio = nullptr; //a zona contem ponteiro do tipo Edificio chamado "edificio",
    // que aponta para null caso a zona nao tenha edificio

    Zona *proximazona = nullptr; // ponteiro para a próxima zona
    Zona *primeiraproxzona = nullptr; // ponteiro para a primeira posição da próxima linha

protected:
//Meta 2
    vector<Trabalhadores *> trabalhadores;
//a zona contem um vetor de ponteiros do tipo trabalhadores.
//a zona contem recursos
//a classe zona tem um ponteiro "tiposrecursos" que aponta para um vetor de recursos
//cada uma das 6 celulas do vetor aponta para um tipo de recurso (ferro, aço, carvão, madeira, vigas de madeira, eletricidade)
    Recursos *tiposrecursos[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(),
                                  new Eletricidade()};
public:
    Zona(); //construtor da zona
    static int count; //variavel estatica para contar as zonas. Nao esta a ser usada
    string teste; // para imprimir a ilha no ecra. Nao esta a ser usada
    //get
    string gettipoedificio() const; //obter o tipo de edificio existente na zona
    //funcoes
    string contratatrabalhador(string tipo, int dia); // funcao para contratar trabalhador.
    //tem como argumentos o tipo de trabalhador(operario, mineiro,lenhador)
    //e o dia do jogo,  que sera necessario para o id do trabalhador
    int verificacondicoescontratacao(string tipo, int dia, int dinheiroilha);

    int
    obtemnumerotrabalhadores() const { return trabalhadores.size(); } //funcao para obter o numero de trabalhadores. corresponde ao tamanho do vetor de trabalhadores
    string getasstring(); //funcao para representar o detalhe de cada zona
    string obtemtipotrabalhadores() const; //funcao para obter a inicial do tipo de trabalhadores
    string constroiedificio(string tipoedif); //funcao para construir edificio na zona
    Trabalhadores *
    retornatrabalhador(string id); //funcao para devolver um ponteiro para o trabalhador com determinado ID
    virtual string
    gettipozona() const = 0; // esta funcao existe em todos os "filhos" de zona: deserto, pastagem, etc. Devolve o tipo de zona
    void getrecursoszonaapenas(Recursos **a) const; // devolve os recursos apenas da zona
    void getrecursos(Recursos **a) const; //esta funcao obtem os recursos existentes numa zona
    //os recursos de uma zona são o resultado da soma dos recursos existentes nessa zona
    //com os recursos do edificio da zona, se aplicavel
    //esta funcao recebe um ponteiro de ponteiros de recursos,
    // semelhante ao ponteiro *tiposrecursos, que provém do edificio
    string getrecursosss() const; // esta funcao vai chamar a funcao acima
    //vai permitir obter a quantidade total de recursos da zona e passa-los para uma string
    string gettrabalhadores() const; //funcao para representar os trabalhadores de uma zona
    void adicionatrabalhador(
            Trabalhadores *pTrabalhadores); //funcao para adicionar um trabalhador a uma zona (acrescenta ao vetor de trabalhadores dessa zona)
    void apagatrabalhador(
            Trabalhadores *pTrabalhadores); //funcao para apagar um trabalhador de uma zona (apaga do vetor de trabalhadores da zona)
    int despedimentos(
            int diaatual); //funcao para despedir trabalhadores, baseando se na probabilidade. Precisa do dia atual
    void mudaflags(); // as flags dos trabalhadores passam todas a FALSE
    Zona *getproximazona() { return proximazona; } // devolve a proxima zona
    Zona *getprimeriaproxzona() { return primeiraproxzona; } // devolve a primeira proxima zona
    void setproximazona(Zona *prox) { this->proximazona = prox; } // altera a proxima zona
    void setprimeiraproxzona(Zona *prox) { this->primeiraproxzona = prox; } // altera a primeira proxima zona
    void descontarecursoszona(Recursos **pRecursos);

    Edificio *getponteiroedificio() { return edificio; } //devolve o ponteiro de edificio da zona
    int
    desabamentos(string tipozona, int linha, int coluna); //funcao para desabar edificios, baseando se na probabilidade
    string getEstadoEdificio(); // função que recebe o estado do edificio e devolve uma string com ligado ou desligado
    bool despedimentosDebug(string id); // função para despedir um trabalhador em específico
    virtual void produzir(int i) {}; // produzir recursos numa zona
    virtual void
    produzirnosEdfs(vector<string> zonasdailha, Edificio *bateria,
                    Recursos **auxZona); // produzir recursos num edificio
    bool existeEdificio(); // retorna tru/false dependendo do ponteiro para edificio

    virtual int getarvores() const { return getarvores(); }; // retorna o numero de arvores da floresta

    int venderEdf(Edificio *tipoEdf); // função para vender um edificio
    void
    setEdfNull() { this->edificio = nullptr; } // coloca o edificio novamente a nullptr (usada quando se vende um edf)
    int venderRec(string tipoRec, int *qnt); // função para vender recursos
    Recursos **getRecursosZona() { return tiposrecursos; }

    void incrementadiasedificio();

    void incrementaDiastrabalho();

};

#endif //TRB_ZONA_H
