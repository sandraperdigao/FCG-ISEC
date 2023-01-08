//
// Created by sandr on 04/11/2021.
//

#include "Zona.h"
#include "Trabalhadores/Operario.h"
#include "Trabalhadores/Lenhador.h"
#include "Edificios/Minaferro.h"

#define MINER "miner" // mineiro
#define OPER "oper" // operário
#define LEN "len" // lenhador

#define MINAF "minaf" // mina de ferro
#define MINAC "minac" // mina de carvão
#define CENTRAL "central" // central elétrica
#define BAT "bat" // bateria
#define FUND "fund" // fundição
#define EDX "edx" // edifício x

#define PAS "pas" // pasto

//CONSTRUTOR DA ZONA
Zona::Zona() {
    teste = "z" + to_string((count++)); //funcao para imprimir o nº da zona no ecra. Nao esta a ser usada

    for (int i = 0; i < 6; ++i) {
        tiposrecursos[i]->incrementaquantidade(rand() % 5);
    }
}

//FUNCAO PARA VERIFICAR SE ESTAO REUNIDAS AS CONDICOES DE CONTRATACAO
int Zona::verificacondicoescontratacao(string tipo, int dia, int dinheiroilha) {

    //compara as strings para ver se o trabalhador é um mineiro
    if (strcmp(tipo.c_str(), "miner") == 0) {
        Mineiro a;
        int custo = a.getprecotrabalhador();
        if (custo > dinheiroilha)
            return -1;
        return custo;
    }

    //compara as strings para ver se o trabalhador é um operario
    if (strcmp(tipo.c_str(), "oper") == 0) {
        Operario a;
        int custo = a.getprecotrabalhador();
        if (custo > dinheiroilha)
            return -1;
        return custo;
    }

    //compara as strings para ver se o trabalhador é um lenhador
    if (strcmp(tipo.c_str(), "len") == 0) {
        Lenhador a;
        int custo = a.getprecotrabalhador();
        if (custo > dinheiroilha)
            return -1;
        return custo;
    }

    //nao é um tipo de trabalhador existente no jogo
    if (strcmp(tipo.c_str(), "miner") != 0 && strcmp(tipo.c_str(), "oper") != 0 && strcmp(tipo.c_str(), "len") != 0)
        return 0;
    return 0;
}

//FUNCAO PARA CONTRATAR TRABALHADOR. RECEBE O TIPO DE TRABALHADOR E DIA DA CONTRATACAO
string Zona::contratatrabalhador(string tipo, int dia) {
    //compara as strings para ver se o trabalhador é um mineiro
    if (strcmp(tipo.c_str(), MINER) == 0) {
        trabalhadores.push_back(new Mineiro(
                dia)); //é um mineiro, entao carrega o mineiro para o vetor de trabalhadores da zona pasto inicial
        return "";
    }

    //compara as strings para ver se o trabalhador é um operario
    if (strcmp(tipo.c_str(), OPER) == 0) {
        trabalhadores.push_back(new Operario(
                dia)); //é um operario, entao carrega o operario para o vetor de trabalhadores da zona pasto inicial
        return "";
    }

    //compara as strings para ver se o trabalhador é um lenhador
    if (strcmp(tipo.c_str(), LEN) == 0) {
        trabalhadores.push_back(new Lenhador(
                dia)); //é um lenhador, entao carrega o lenhador para o vetor de trabalhadores da zona pasto inicial
        return "";
    }

    //nao é um tipo de trabalhador existente no jogo
    return "Tipo de trabalhador invalido";
}

//FUNCAO PARA REPRESENTAR O DETALHE DE UMA DETERMINADA ZONA
string Zona::getasstring() {

    ostringstream oss;
    oss << "\nTipo de zona: " << gettipozona() << endl
        << "Edificio construido: " << gettipoedificio() << endl;

    if (strcmp(gettipozona().c_str(), "flr") == 0)
        oss << "Numero de arvores: " << getarvores() << endl;

    if (edificio != nullptr) {
        oss << "Estado do edificio: " << getEstadoEdificio() << endl << "Nivel atual do edificio: "
            << edificio->getNivelatual() << endl
            << "Capacidade maxima de recursos (edificio):" << edificio->getCapmax() << endl << "Nivel maximo:"
            << edificio->getNivelmax() << endl << "Preco para subir de nivel:" << edificio->getPreco() << endl
            << "Quantidade de vigas para subir de nivel: " << edificio->getQntvigas() << endl << "Dias do edificio: "
            << edificio->getdiasedificio() << endl;
    }

    oss << "Tipo de trabalhadores: " << obtemtipotrabalhadores() << endl
        << "Numero de trabalhadores: " << obtemnumerotrabalhadores() << endl
        << getrecursosss() << endl
        << "Trabalhadores: " << gettrabalhadores() << endl;

    return oss.str();
}

//FUNCAO PARA REPRESENTAR O TIPO DE TRABALHADORES DA ZONA (VAI OBTER AS INICIAIS QUE VAO PARA A 3º LINHA DA ILHA)
string Zona::obtemtipotrabalhadores() const {
    ostringstream oss;
    int i;
    //percorre o vetor de trabalhadores da zona, e obtem a inicial de cada tipo de trabalhador
    for (i = 0; i < trabalhadores.size(); i++) {
        oss << trabalhadores[i]->getinicial();
    }
    return oss.str();
}

//FUNCAO PARA CONSTRUIR EDIFICIO
string Zona::constroiedificio(string tipoedif) {
    //Recebe o tipo de edificio a construir
    //Cada zona so pode ter um edificio

    //vai comparar o tipoedif que recebeu como argumento com os edificios possiveis
    if (strcmp(MINAF, tipoedif.c_str()) == 0) {
        edificio = new Minaferro(); //o ponteiro fica a apontar para essa referência MinaFerro
    }

    if (strcmp(MINAC, tipoedif.c_str()) == 0) {
        edificio = new Minacarvao(); //o ponteiro fica a apontar para essa referência MinaCarvao
    }

    if (strcmp(CENTRAL, tipoedif.c_str()) == 0) {
        edificio = new Centraleletrica(); //o ponteiro fica a apontar para essa referência CentralEletrica
    }

    if (strcmp(BAT, tipoedif.c_str()) == 0) {
        edificio = new Bateria(); //o ponteiro fica a apontar para essa referência Bateria
    }

    if (strcmp(FUND, tipoedif.c_str()) == 0) {
        edificio = new Fundicao(); //o ponteiro fica a apontar para essa referência Fundicao
    }

    if (strcmp(EDX, tipoedif.c_str()) == 0) {
        edificio = new Edificiox(); //o ponteiro fica a apontar para essa referência EdificioX
    }
    return "";
}

//FUNCAO PARA OBTER O TIPO DE EDIFICIO EXISTENTE NA ZONA
string Zona::gettipoedificio() const {
    if (edificio != nullptr) {
        return edificio->gettipoedificio();
    }
    return "";
}

//FUNCAO PARA OBTER A QUANTIDADE TOTAL DE RECURSOS DE UMA ZONA
void Zona::getrecursos(Recursos **a) const {
    //a quantidade total de recursos de uma zona corresponde à soma
    //da quantidade de recursos existente na zona com os recursos do edificio da zona
    //caso exista edificio
    //a funcao recebe um ponteiro de ponteiros "a"
    //esse ponteiro aponta para um vetor de ponteiros de recursos
    //Recursos *a[6]={new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()}
    for (int i = 0; i < 6; i++) {
        //ciclo de 0 até 5 (6 é o tamanho do vetor que recebe)
        //esta funcao modifica os valores apontados por o vetor de recursos "a", correspondentes à quantidade dos recursos
        //envia como parametro da funcao incrementaquantidade() o valor i do vetor tiposrecursos da zona
        a[i]->incrementaquantidade(tiposrecursos[i]->getquantidade());

        //caso a zona tenha um edificio também tem que somar os recursos desse edificio ao vetor "a"
        if (edificio != nullptr) {
            Recursos **b; //cria um novo ponteiro de ponteiros Recursos "b"
            b = edificio->getrecursos(); // b recebe o endereço do vetor "tiposrecursos" que está no edificio
            a[i]->incrementaquantidade(
                    b[i]->getquantidade()); //volta a incrementar a[i] com a informação do vetor do efificio
        }
    }
}

void Zona::getrecursoszonaapenas(Recursos **a) const {

    // esta função ignora os recursos existentes no edificio da zona
    // e apenas adiciona os recursos da zona em si

    for (int i = 0; i < 6; i++) {

        a[i]->incrementaquantidade(tiposrecursos[i]->getquantidade());

    }

}

//FUNÇÃO PARA DEVOLVER A INFORMAÇÃO EM FORMATO STRING DA QUANTIDADE DE RECURSOS DA ZONA
string Zona::getrecursosss() const {
    ostringstream oss;
    int i;
    //Cria um ponteiro para vetor de 6 recursos. O recurso 1 do vetor aponta para um Ferro, o 2 para Aço, etc.
    Recursos *a[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    getrecursos(a); //chama a função getrecursos com o ponteiro a como argumento, para obter os recursos da zona
    oss << "Recursos: " << endl;
    for (i = 0; i < 6; i++) {
        oss << a[i]->gettipo() << ' ' << a[i]->getquantidade() << endl;
    }
    return oss.str();
}

//FUNCAO PARA REPRESENTAR OS TRABALHADORES DE UMA ZONA
string Zona::gettrabalhadores() const {
    ostringstream oss;
    int i;
    //ciclo for que percorre o vetor de trabalhadores da zona
    for (i = 0; i < trabalhadores.size(); i++) {
        oss << trabalhadores[i]->getasstring() << endl;
    }
    return oss.str();
}

//FUNCAO PARA DEVOLVER UM PONTEIRO DO TRABALHADOR COM DETERMINADO ID
Trabalhadores *Zona::retornatrabalhador(string id) {
    int i;
    for (i = 0; i < trabalhadores.size(); i++) {
        if (strcmp(id.c_str(), trabalhadores[i]->getid().c_str()) == 0) {
            return trabalhadores[i];
        }
    }
    return nullptr;
}

//FUNCAO PARA ADICIONAR TRABALHADOR NO VETOR DE TRABALHADORES DE UMA ZONA
void Zona::adicionatrabalhador(Trabalhadores *pTrabalhadores) {
    trabalhadores.push_back(pTrabalhadores);
}

//FUNCAO PARA APAGAR TRABALHADOR DO VETOR DE TRABALHADORES DE UMA ZONA
void Zona::apagatrabalhador(Trabalhadores *pTrabalhadores) {
    //deixa de apontar para o trabalhador que foi transferido para outra zona
    //apaga esse trabalhador da zona antiga
    for (int i = 0; i < trabalhadores.size(); i++) {
        //compara os endereços:
        if (trabalhadores[i] == pTrabalhadores) {
            trabalhadores.erase(trabalhadores.begin() + i);
            break; //encontrou o trabalhador, sai do ciclo, nao precisa de continuar à procura
        }
    }
}

//FUNCAO PARA DESPEDIR TRABALHADORES DE UMA ZONA
int Zona::despedimentos(int diaatual) {

    int despedidos = 0; //contador de despedimentos na zona

    //os trabalhadores dos pastos nao se despedem
    if (strcmp(gettipozona().c_str(), PAS) == 0)
        return despedidos;

    //na zona percorre o vetor de trabalhadores e despede-os com base na probabilidade
    for (int i = 0; i < trabalhadores.size(); i++) {
        //chama uma funcao que vai devolver um bool, que depende de um numero aleatorio com base na prob de despedir
        if (trabalhadores[i]->despedetrabalhador(diaatual, gettipozona().c_str())) {
            //se o bool devolvido for true:
            cout << "Eu despedi-me e era o trabalhador com o ID: " << trabalhadores[i]->getid()
                 << endl;
            trabalhadores.erase(trabalhadores.begin() + i); //apaga esse trabalhador do vetor de trabalhadores
            i--; //decrementa o i para nao saltar nenhuma posicao no ciclo for
            despedidos++;
        }
    }

    return despedidos;
}

//FUNCAO DE DESPEDIMENTOS DEBUG
bool Zona::despedimentosDebug(string id) {

    if (!id.empty()) { // apagar o último caracter da string id
        id.pop_back();
    }

    // vamos procurar no vetor de trabalhadores esse ID
    for (int i = 0; i < trabalhadores.size(); i++) {

        if (id == trabalhadores[i]->getid()) {
            trabalhadores.erase(trabalhadores.begin() + i); //apaga esse trabalhador do vetor de trabalhadores
            i--; //decrementa o i para nao saltar nenhuma posicao no ciclo for
            return true;
        }

    }

    // retorna false se nao encontrar
    return false;

}

//FUNCAO COM A PROBABILIDADE DE UM EDIFICIO DESABAR NUMA ZONA
int Zona::desabamentos(string tipozona, int linha, int coluna) {
    string tipo = "a"; //obter tipo de edificio
    int despedidos = 0; //contador de despedimentos na zona

    //na zona acede ao ponteiro de edificio
    if (edificio != nullptr) {
        tipo = edificio->gettipoedificio();

        //Se a zona for um pantano o edificio desaba ao fim de 10 dias e os funcionarios despedem-se
        if (strcmp(tipozona.c_str(), "pnt") == 0) {
            if (edificio->getdiasedificio() == 10) {
                //se o bool devolvido for true:
                cout << "O edificio " + edificio->gettipoedificio() + " desabou na posicao " + to_string(linha + 1) +
                        " " +
                        to_string(coluna + 1) << endl;
                delete edificio; //apaga o espaco alocado em memoria dinamica
                edificio = nullptr; //o ponteiro passa a apontar para null

                //percorre o vetor de trabalhadores da zona e despede os trabalhadores
                for (int i = 0; i < trabalhadores.size(); i++) {
                    cout << "Eu despedi-me e era o trabalhador com o ID: " << trabalhadores[i]->getid() << endl;
                    trabalhadores.erase(trabalhadores.begin() + i); //apaga esse trabalhador do vetor de trabalhadores
                    i--; //decrementa o i para nao saltar nenhuma posicao no ciclo for
                    despedidos++;
                }

                return despedidos; //sai da funcao
            }
        }

        //Independentemente da zona Se o edificio for uma minaferro ou minacarvao tem probabilidade de desabar
        if (strcmp(tipo.c_str(), "mnF") == 0 || strcmp(tipo.c_str(), "mnC") == 0) {
            //obtem a probabilidade de desabar
            if (edificio->desabaedificio()) {
                //se o bool devolvido for true:
                cout << "O edificio " + edificio->gettipoedificio() + " desabou na posicao " + to_string(linha + 1) +
                        " " +
                        to_string(coluna + 1) << endl;
                delete edificio; //apaga o espaco alocado em memoria dinamica
                edificio = nullptr; //o ponteiro passa a apontar para null
            }
        }
    }

    return despedidos;
}


//FUNCAO PARA MUDAR AS FLAGS AO AMANHECER PARA OS TRABALHADORES VOLTAREM A PODER MOVER DE ZONA
void Zona::mudaflags() {
    //na zona percorre o vetor de trabalhadores
    for (int i = 0; i < trabalhadores.size(); i++) {
        trabalhadores[i]->alteraflagamanhecer();
    }
}

//FUNCAO PARA DESCONTAR RECURSOS DA ZONA
void Zona::descontarecursoszona(Recursos **pRecursos) {

    //pRecursos é o que tenho que descontar no total de cada recurso

    //obter recursos da zona e do edificio da zona
    Recursos *a[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    getrecursos(a); //chama a função getrecursos com o ponteiro a como argumento, para obter os recursos da zona

    for (int i = 0; i < 6; i++) {
        //Calcular a diferenca a descontar na zona+edificio
        int diferenca = a[i]->getquantidade() > pRecursos[i]->getquantidade() ? pRecursos[i]->getquantidade()
                                                                              : a[i]->getquantidade();

        //o pRecursos fica ja atualizado com o valor que se tirou aos recursos
        pRecursos[i]->incrementaquantidade(-diferenca);

        //decrementar no edificio
        if (edificio != nullptr) {
            diferenca -= edificio->decrementa(diferenca, i); //atualiza a diferenca com o que decrementou no edificio
        }

        //decrementar na zona
        tiposrecursos[i]->incrementaquantidade(-diferenca);
    }

}

string Zona::getEstadoEdificio() {

    if (edificio->getLigado())
        return "Ligado";
    else
        return "Desligado";

}

void Zona::produzirnosEdfs(vector<string> zonasdailha, Edificio *bateria, Recursos** auxZona) {

    // bateria -> armazena 100kwh de eletricidade

    if (edificio != nullptr) // se existir um edificio
        if (edificio->getLigado() == true) { // se o edificio estiver ligado
            // criamos um array de recursos
            //Recursos *aux[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
            // colocamos nesse array de recursos, todos os recursos existentes nessa zona (apenas da zona)
            //getrecursoszonaapenas(aux);

            Recursos **aux = tiposrecursos; // vamos mandar os recursos da zona para as funções
            string tipoZonaatual = gettipozona(); // vamos mandar o tipo de zona em que o edf se encontra atualmente (importante para o dsr e para a mnt)

            edificio->produzEdf(trabalhadores, zonasdailha, aux, bateria, tipoZonaatual, auxZona); // produzimos num edificio
        }


}

bool Zona::existeEdificio() {
    return edificio != nullptr; // dá return true se for for igual
}

int Zona::venderEdf(Edificio *tipoEdf) {

    // dependendo do tipo de edificio, retorna um valor que vai ser somado ao dinheiro da ilha

    if (strcmp(tipoEdf->gettipoedificio().c_str(), "mnF") == 0) {
        return 10;
    } else if (strcmp(tipoEdf->gettipoedificio().c_str(), "mnC") == 0) {
        return 10;
    } else if (strcmp(tipoEdf->gettipoedificio().c_str(), "fun") == 0) {
        return 10;
    } else if (strcmp(tipoEdf->gettipoedificio().c_str(), "edfX") == 0) {
        return 10;
    } else if (strcmp(tipoEdf->gettipoedificio().c_str(), "elec") == 0) {
        return 15;
    } else if (strcmp(tipoEdf->gettipoedificio().c_str(), "bat") == 0) {
        return 10;
    } else {
        return 0;
    }

}

int Zona::venderRec(string tipoRec, int *qnt) {

    Recursos **recursosdazona = tiposrecursos;
    int recompensa, recompensaFinal;

    if (strcmp(tipoRec.c_str(), "ferro") == 0) {
        recompensa = tiposrecursos[0]->venderecursos(qnt);
        recompensaFinal = recompensa; // ferro é vendido por 1€ ao kg
    } else if (strcmp(tipoRec.c_str(), "aco") == 0) {
        recompensa = tiposrecursos[1]->venderecursos(qnt);
        recompensaFinal = recompensa * 2; // aço é vendido por 2€ ao kg
    } else if (strcmp(tipoRec.c_str(), "carvao") == 0) {
        recompensa = tiposrecursos[2]->venderecursos(qnt);
        recompensaFinal = recompensa; // carvao é vendido por 1€ ao kg
    } else if (strcmp(tipoRec.c_str(), "madeira") == 0) {
        recompensa = tiposrecursos[3]->venderecursos(qnt);
        recompensaFinal = recompensa; // madeira é vendida por 1€ ao kg
    } else if (strcmp(tipoRec.c_str(), "vigas madeira") == 0) {
        recompensa = tiposrecursos[4]->venderecursos(qnt);
        recompensaFinal = recompensa * 2; // vigas são vendidas por 2€ ao kg
    } else if (strcmp(tipoRec.c_str(), "eletricidade") == 0) {
        recompensa = tiposrecursos[5]->venderecursos(qnt);
        recompensaFinal = recompensa * 1.5; // eletro é vendida por 1.5€ ao kg
    }

    return recompensaFinal;

}

void Zona::incrementadiasedificio() {
    if (edificio != nullptr) // se existir um edificio
        edificio->incrementadiasedificio();
}

void Zona::incrementaDiastrabalho() {

    for (int i = 0; i < trabalhadores.size(); i++) { // percorre todos os trabalhadores
        trabalhadores[i]->setContadias(); // incrementa o seu dia de trabalho
        if (trabalhadores[i]->gettipotrabalhador() == "lenhador") { // se for lenhador
            if (trabalhadores[i]->getContadias() % 5 == 0) // trabalha 4 descansa 1 (vai descansar no dia 5,10,15,...)
                cout << "O lenhador " + trabalhadores[i]->getid() + " vai descansar no PROXIMO dia!" << endl;
        }
    }

}

