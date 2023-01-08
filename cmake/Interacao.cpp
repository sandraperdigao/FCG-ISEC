//
// Created by sandr on 18/11/2021.
//

#include "Interacao.h"

//FUNCAO PARA LER COMANDOS
void Interacao::lecomandos(istream &in) {
    string resposta;

    do {

        if (&cin != &in && in.peek() == EOF)//quer dizer que esta a ler do ficheiro e que esta no fim dele
            return;

        cout << "\n\nIntroduza um comando(help):\n--> ";


        getline(in, resposta);

        if (&cin != &in)
            cout << resposta << endl;

        resposta = trim(resposta);

        if (resposta == "help") {   // lista de comandos que podem ser usados

            cout << "\nLista de comandos:" << endl;

            cout << "\nexec <nomeFicheiro> - Executa um conjunto de comandos existentes em <nomeFicheiro>" << endl;

            cout
                    << "\ncons <tipo> <linha> <coluna> - Constroi um edificio de um dado <tipo> na posicao <linha> <coluna>"
                    << endl;

            cout << "\nliga <linha> <coluna> - Liga o edificio (caso exista)" << endl;

            cout << "\ndes <linha> <coluna> - Deslida o edificio (caso exista)" << endl;

            cout << "\nmove <id> <linha> <coluna> - Move o trabalhador <id> para <linha> <coluna>" << endl;

            cout << "\nvende <tipo> <quanto> - Vende <quanto> recursos de um dado <tipo> " << endl;

            cout << "\ncont <tipo> - Contrata um trabalhador de um dado <tipo>" << endl;

            cout << "\nlist <linha> <coluna> - Informacao do jogo (global se nao indicar <linha> e <coluna>" << endl;

            cout << "\nvende <linha> <coluna> - Vende o edificio existente em <linha> <coluna>" << endl;

            cout << "\nnext - Termina a fase de recolha de comandos" << endl;

            cout << "\nsave <nome> - Grava o estado do jogo em memoria, associando-lhe um <nome>" << endl;

            cout << "\nload <nome> - Recupera um dado estado do jogo em memoria" << endl;

            cout << "\napaga <nome> - Apaga um determinado savegame de memoria" << endl;

            cout << "\nconfig <ficheiro> - Le o <ficheiro>, obtem os precos dos trabalhadores e edificios" << endl;

            cout << "\ndebcash <valor> - Adiciona a quantidade de dinheiro especificada em valor" << endl;

            cout << "\ndebed <tipo> <linha> <coluna> - Adiciona um edificio a custo zero" << endl;

            cout << "\ndebkill <id> - Remove o trabalhador com a identificacao id" << endl;

            cout << "\nlvlup <linha> <coluna> - Sobe de nivel o edificio presente nessa célula" << endl;

            cout << "\n---------------------------------------------------------------\n" << endl;

        }

        if (resposta == "next")
            break; //termina a fase de recolha de comandos e desencadeia as acoes necessarias

        // comando list simples
        if (resposta == "list")
            cout << ilha.getAsString();

        if (resposta == "")
            printf("Introduza um comando!!!\n");

        /*-------------------------- Detetar o tipo de comando - START ---------------------------*/

        string primeiroargumento, segundoargumento, terceiroargumento, quartoargumento, w, z, x, b;
        int n_argumentos = 1, n = 1, tam = resposta.size();


        for (auto c: resposta)  // ciclo para contar o número de argumentos de um comando (debcash 400 --> 2 argumentos)
            if (c == ' ')
                n_argumentos++; // não incrementa quando chega ao final de um comando, por isso é que a variável é inicializada com o valor 1

        for (int i = 0; i <= tam; i++) {    // ciclo para separar cada argumento e guardar numa variável

            if (resposta[i] == ' ' && n == 1) { // guarda o primeiro argumento
                primeiroargumento = w;
                n++;
                i++;
            } else
                w += resposta[i];


            if (n == 2) {   // guarda o segundo argumento, se existir
                if (resposta[i] == ' ') {
                    segundoargumento = z;
                    n++;
                    i++;
                } else
                    z += resposta[i];
            }

            if (n == 3) {   // guarda o terceiro argumento, se existir
                if (resposta[i] == ' ') {
                    terceiroargumento = x;
                    n++;
                    i++;

                } else
                    x += resposta[i];
            }

            if (n == 4) {   // guarda o quarto argumento, se existir (se existir é sempre o último)
                if (resposta[i] == '\0') {
                    quartoargumento = b;
                    break;
                } else
                    b += resposta[i];
            }

            if (resposta[i] == '\0') {  // independentemente do número de argumentos, quando chega ao fim da string...
                if (n == 1) {   // guarda o  primeiro argumento se este for o último
                    primeiroargumento = w;
                    n++;
                    i++;
                }

                if (n == 2) {   // guarda o segundo argumento se este for o último
                    segundoargumento = z;
                    n++;
                    i++;
                }

                if (n == 3) {   // guarda o terceiro argumento se este for o último
                    terceiroargumento = x;
                    n++;
                    i++;
                }
            }

        }
//        cout << "n_argumentos = " << n_argumentos << endl; //(debug)
//        primeiroargumento = trim(primeiroargumento);
//        cout << "primeiroargumento = '" << primeiroargumento << "'"<< endl; //(debug)
//        cout << "segundoargumento = '" << segundoargumento << "'"<< endl; //(debug)
//        cout << "terceiroargumento = '" << terceiroargumento << "'"<< endl; //(debug)
//        cout << "quartoargumento = '" << quartoargumento << "'"<< endl; //(debug)

        /*-------------------------- Detetar o tipo de comando - END ---------------------------*/

        /*-------------------------- Resposta por parte do programa (jogo) - START ---------------------------*/

        if (n_argumentos == 2) {    // comandos com 2 argumentos

            /*-------------------------- Procurar erro na introdução de comandos - START ---------------------------*/

            if (primeiroargumento == "cons") {
                cout << "Erro a introduzir o comando! ( cons <tipo> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "move") {
                cout << "Erro a introduzir o comando! ( move <id> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "debed") {
                cout << "Erro a introduzir o comando! ( debed <tipo> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "liga") {
                cout << "Erro a introduzir o comando! ( liga <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "des") {
                cout << "Erro a introduzir o comando! ( des <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "vende") {
                cout << "Erro a introduzir o comando! ( vende <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "lvlup") {
                cout << "Erro a introduzir o comando! ( lvlup <linha> <coluna> )" << endl;
            }


            /*-------------------------- Procurar erro na introdução de comandos - END ---------------------------*/

            if (primeiroargumento == "debcash") {
                cout << ilha.incrementaDinheiro(atoi(segundoargumento.c_str()));
            } else if (primeiroargumento == "exec") {
                executaficheiro(segundoargumento);
            } else if (primeiroargumento == "cont") {
                cout << ilha.contratatrabalhador(segundoargumento);
            } else if (primeiroargumento == "save") {
                printf("Comando em desenvolvimento!\n");
            } else if (primeiroargumento == "load") {
                printf("Comando em desenvolvimento!\n");
            } else if (primeiroargumento == "apaga") {
                printf("Comando em desenvolvimento!\n");
            } else if (primeiroargumento == "config") {
                printf("Comando em desenvolvimento!\n");
            } else if (primeiroargumento == "debkill") {
                cout << ilha.despedetrabalhadorDebug(segundoargumento);
            }


        }

        if (n_argumentos == 3) {    // comandos com 3 argumentos

            /*-------------------------- Procurar erro na introdução de comandos - START ---------------------------*/

            if (primeiroargumento == "cons") {
                cout << "Erro a introduzir o comando! ( cons <tipo> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "move") {
                cout << "Erro a introduzir o comando! ( move <id> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "debed") {
                cout << "Erro a introduzir o comando! ( debed <tipo> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "debcash") {
                cout << "Erro a introduzir o comando! ( debcash <valor> )" << endl;
            } else if (primeiroargumento == "exec") {
                cout << "Erro a introduzir o comando! ( exec <nomedoficheiro> )" << endl;
            } else if (primeiroargumento == "cont") {
                cout << "Erro a introduzir o comando! ( cont <tipo> )" << endl;
            } else if (primeiroargumento == "save") {
                cout << "Erro a introduzir o comando! ( save <nome> )" << endl;
            } else if (primeiroargumento == "load") {
                cout << "Erro a introduzir o comando! ( load <nome> )" << endl;
            } else if (primeiroargumento == "apaga") {
                cout << "Erro a introduzir o comando! ( apaga <nome> )" << endl;
            } else if (primeiroargumento == "config") {
                cout << "Erro a introduzir o comando! ( config <ficheiro> )" << endl;
            } else if (primeiroargumento == "debkill")
                cout << "Erro a introduzir o comando! ( debkill <id> )" << endl;

            /*-------------------------- Procurar erro na introdução de comandos - END ---------------------------*/

            if (primeiroargumento == "liga") {
                cout << ilha.ligarEdfs(atoi(segundoargumento.c_str()), atoi(terceiroargumento.c_str()));
            } else if (primeiroargumento == "des") {
                cout << ilha.desligarEdfs(atoi(segundoargumento.c_str()), atoi(terceiroargumento.c_str()));
            } else if (primeiroargumento == "vende") {
                cout << ilha.vende(segundoargumento, terceiroargumento) << endl;
            } else if (primeiroargumento == "list") {
                cout << ilha.representa(atoi(segundoargumento.c_str()), atoi(terceiroargumento.c_str()));
                //atoi para converter para int
            } else if (primeiroargumento == "lvlup") {
                cout << ilha.subirnivel(atoi(segundoargumento.c_str()), atoi(terceiroargumento.c_str()));
            }

        }

        if (n_argumentos == 4) {    // comandos com 4 argumentos

            /*-------------------------- Procurar erro na introdução de comandos - START ---------------------------*/

            if (primeiroargumento == "debcash") {
                cout << "Erro a introduzir o comando! ( debcash <valor> )" << endl;
            } else if (primeiroargumento == "exec") {
                cout << "Erro a introduzir o comando! ( exec <nomedoficheiro> )" << endl;
            } else if (primeiroargumento == "cont") {
                cout << "Erro a introduzir o comando! ( cont <tipo> )" << endl;
            } else if (primeiroargumento == "save") {
                cout << "Erro a introduzir o comando! ( save <nome> )" << endl;
            } else if (primeiroargumento == "load") {
                cout << "Erro a introduzir o comando! ( load <nome> )" << endl;
            } else if (primeiroargumento == "apaga") {
                cout << "Erro a introduzir o comando! ( apaga <nome> )" << endl;
            } else if (primeiroargumento == "config") {
                cout << "Erro a introduzir o comando! ( config <ficheiro> )" << endl;
            } else if (primeiroargumento == "debkill") {
                cout << "Erro a introduzir o comando! ( debkill <id> )" << endl;
            } else if (primeiroargumento == "liga") {
                cout << "Erro a introduzir o comando! ( liga <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "des") {
                cout << "Erro a introduzir o comando! ( des <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "vende") {
                cout << "Erro a introduzir o comando! ( vende <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "lvlup") {
                cout << "Erro a introduzir o comando! ( lvlup <linha> <coluna> )" << endl;
            }

            /*-------------------------- Procurar erro na introdução de comandos - END ---------------------------*/

            if (primeiroargumento == "cons") {
                cout << ilha.constroi(segundoargumento, atoi(terceiroargumento.c_str()), atoi(quartoargumento.c_str()));
            } else if (primeiroargumento == "move") {
                cout << ilha.transferetrabalhador(segundoargumento, atoi(terceiroargumento.c_str()),
                                                  atoi(quartoargumento.c_str()));
            } else if (primeiroargumento == "debed") {
                cout << ilha.constroiDebug(segundoargumento, atoi(terceiroargumento.c_str()),
                                           atoi(quartoargumento.c_str()));
            }

        }

        if (n_argumentos > 4 || n_argumentos == 1) {

            if (n_argumentos > 4)
                cout << "Nao existem comandos com 5 ou mais argumentos!\n" << endl;

            if (primeiroargumento == "debcash" || resposta == "debcash") {
                cout << "Erro a introduzir o comando! ( debcash <valor> )" << endl;
            } else if (primeiroargumento == "exec" || resposta == "exec") {
                cout << "Erro a introduzir o comando! ( exec <nomedoficheiro> )" << endl;
            } else if (primeiroargumento == "cont" || resposta == "cont") {
                cout << "Erro a introduzir o comando! ( cont <tipo> )" << endl;
            } else if (primeiroargumento == "save" || resposta == "save") {
                cout << "Erro a introduzir o comando! ( save <nome> )" << endl;
            } else if (primeiroargumento == "load" || resposta == "load") {
                cout << "Erro a introduzir o comando! ( load <nome> )" << endl;
            } else if (primeiroargumento == "apaga" || resposta == "apaga") {
                cout << "Erro a introduzir o comando! ( apaga <nome> )" << endl;
            } else if (primeiroargumento == "config" || resposta == "config") {
                cout << "Erro a introduzir o comando! ( config <ficheiro> )" << endl;
            } else if (primeiroargumento == "debkill" || resposta == "debkill") {
                cout << "Erro a introduzir o comando! ( debkill <id> )" << endl;
            } else if (primeiroargumento == "liga" || resposta == "liga") {
                cout << "Erro a introduzir o comando! ( liga <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "des" || resposta == "des") {
                cout << "Erro a introduzir o comando! ( des <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "vende" || resposta == "vende") {
                cout << "Erro a introduzir o comando! ( vende <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "cons" || resposta == "cons") {
                cout << "Erro a introduzir o comando! ( cons <tipo> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "move" || resposta == "move") {
                cout << "Erro a introduzir o comando! ( move <id> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "debed" || resposta == "debed") {
                cout << "Erro a introduzir o comando! ( debed <tipo> <linha> <coluna> )" << endl;
            } else if (primeiroargumento == "lvlup" || resposta == "lvlup") {
                cout << "Erro a introduzir o comando! ( lvlup <linha> <coluna> )" << endl;
            }
        }

        /*-------------------------- Resposta por parte do programa (jogo) - END ---------------------------*/

    } while (resposta != "quit");

    if (strcmp(resposta.c_str(), "quit") == 0)
        terminar = true;
    /*-------------------------- Input do utilizador - END ---------------------------*/
}

//FUNCAO PARA EXECUTAR FICHEIRO TXT
void Interacao::executaficheiro(string nomeficheiro) {
    ifstream f;
    nomeficheiro = trim(nomeficheiro);

    f.open(nomeficheiro, ifstream::in);

    if (!f.is_open()) {
        cout << "\nErro ao abrir o ficheiro!\n";
        return;
    }

    lecomandos(f);

    f.close();
    return;
}

//FUNCAO PARA REMOVER OS ESPACOS EM BRANCO
string Interacao::trim(string str) {
    int pos;
    string str2;
    for (pos = str.size() - 1; str[pos] == ' '; pos--);
    for (int i = 0; i < pos + 1; ++i)
        str2.push_back(str[i]);
    return str2;
}

//FUNCAO DO AMANHECER QUE FAZ OS EFEITOS DAS ZONAS
void Interacao::efeitoszonas() {
    //avancar o dia
    ilha.avancadias();

    //edificios e despedimentos
    ilha.desabamentos();
    ilha.despedimentos();
    cout << "Despediram-se um total de " << ilha.getnumerodespedimentos() << " trabalhadores" << endl;

    //flags mover trabalhadores
    ilha.mudaflagsmovidos();

    //contar os dias a que os trabalhadores estao a trabalhar
    ilha.diasTrabalho();

    //zerar numero de despedimentos
    ilha.zerarnumerodespedimentos();
}

//FUNCAO DO ANOITECER QUE FAZ A RECOLHA DOS RECURSOS
void Interacao::recolharecursos() {
    ilha.produz();
}
