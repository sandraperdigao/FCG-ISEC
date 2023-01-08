//
// Created by sandr on 27/12/2021.
//
#include "iostream"
#include <sstream>
#ifndef TRB_TRABALHADORES_H
#define TRB_TRABALHADORES_H

using namespace std;
static int contador = 0; //contador de trabalhadores

class Trabalhadores{
    int preco; //preco de contratar
    float prob_despedir; //probabilidade de se despedir
    int dia_despedir; // dia em que comeca a probabilidade de se despedir
    int id [2]; //id do trabalhador n.d -> n é o nr de trabalhador e d é o dia que foi contratado
    bool movido = false; //flag para saber se o trabalhador ja foi movido nesse dia
    int contaDias; // serve para contar o numero de dias a que o trabalhador existe, vai ser importante para o lenhador
public:
    Trabalhadores(int preco, float prob_despedir, int dia_despedir, int dia, int contaDias); //construtor
    Trabalhadores(){}
    virtual string gettipotrabalhador() const = 0; //funcao necessaria para os "filhos" de Trabalhador: Operario, Mineiro, Lenhador
    virtual string getinicial() const = 0; //funcao necessaria para os "filhos" de Trabalhador: Operario, Mineiro, Lenhador
    virtual int getprecotrabalhador() const = 0; //funcao necessaria para os "filhos" de Trabalhador: Operario, Mineiro, Lenhador
    string getid() const{
        ostringstream oss;
        oss<<(id[0])<<"."<<(id[1]);
        return oss.str();
    } //funcao para obter o id dos trabalhadores no formato n.d -> n é o nr de trabalhador e d é o dia que foi contratado
    string getasstring() const {return gettipotrabalhador()+" "+getinicial()+ " ID: "+ getid();} //funcao para representar como string o trabalhador
    bool getmovido() const {return movido;} //condicao para ser movido apenas uma vez por dia
    void alteramovido(){movido = true;} //condicao para ser movido apenas uma vez por dia
    bool despedetrabalhador(int diaatual, string tipozona); //funcao para despedir o trabalhador
    void alteraflagamanhecer() {movido = false;} //funcao para alterar a flag no trabalhador ao amanhecer. Assim pode ser movido novamente
    void setContadias(){contaDias++;} // incrementa o numero de dias a que o trabalhador esta a trabalhar
    int getContadias() {return contaDias;} // devolve o numero de dias a que o trabalhador esta a trabalhar
};
#endif //TRB_TRABALHADORES_H
