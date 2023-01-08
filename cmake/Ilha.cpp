//
// Created by sandr on 04/11/2021.
//

#include "Ilha.h"
#include "Zonas/Deserto.h"
#include "Zonas/Pasto.h"
#include "Zonas/Floresta.h"
#include "Zonas/Pantano.h"
#include "Zonas/Montanha.h"
#include "Zonas/ZonaX.h"

//CONSTRUTOR DA ILHA
Ilha::Ilha() {

    int altura, largura;

    cout << "Dimensoes da ilha: " << endl;

    do {
        cout << "Altura - ";
        cin >> altura;
        cin.clear();
        cin.ignore();
    } while ((altura < 3 || altura > 8) || cin.fail());

    do {
        cout << "Largura - ";
        cin >> largura;
        cin.clear();
        cin.ignore();
    } while ((largura < 3 || largura > 16) || cin.fail());

    //parte do codigo para construir a ilha.
    this->largura = largura; //largura da ilha
    this->altura = altura; //altura da ilha
    int a[6] = {0, 0, 0, 0, 0, 0};
    Zona *aux = nullptr;
    Zona *aux2 = nullptr;

    zona = constroilinha(largura, a); // a zona tem uma linha de zonas diferentes
    aux = constroilinha(largura, a); // aux tem outra linha de zonas diferente
    zona->setprimeiraproxzona(aux); // a primeira proxima zona da Zona vai ser o aux

    for (int i = 0; i < altura - 2; ++i) { //comeca pela altura da ilha com ciclo for

        aux2 = constroilinha(largura, a); // aux2 tem outra linha de zonas diferente
        aux->setprimeiraproxzona(aux2); // a primeira proxima zona do Aux vai ser o Aux2
        aux = aux2; // o aux passa a ser a proxima linha que foi acabada de ser criada

    }

    //funcao para definir aleatoriamente o tipo de zona
    pasto = procurapastoaleatorio(); //funcao para definir o pasto aleatório para onde vao os trabalhadores. inicialmente este ponteiro aponta para null, com a construçao da ilha já fica a apontar para um pasto
}

Zona *Ilha::constroilinha(int tamanho, int a[]) {

    Zona *aux = obtemtipozonaleatorio(a); // vai guardar a primeira posição das linhas
    Zona *aux2 = nullptr;

    aux->setproximazona(obtemtipozonaleatorio(a)); // o ponteiro para a proxima ja tem uma nova Zona
    aux2 = aux->getproximazona(); // o aux2 vai ser o que o aux está a apontar

    for (int j = 0; j < largura - 2; ++j) { //passa para a largura com ciclo for

        aux2->setproximazona(obtemtipozonaleatorio(a)); // o aux2 ja esta a apontar para uma proxima zona
        aux2 = aux2->getproximazona(); // o aux2 vai ser a proxima zona

    }

    return aux;

}

Zona *Ilha::acessoilha(int altura, int largura) const {

    Zona *aux = zona; // o aux vai estar a apontar para a primeira zona de todas


    for (int i = 0; i < altura && i < this->altura; ++i) { // estamos a percorrer as linhas (verticalmente)
        aux = aux->getprimeriaproxzona(); // o aux vai ser a proxima zona da proxima linha
    }

    for (int j = 0; j < largura && j < this->largura; ++j) { // estamos a percorrer as colunas (horizontalmente)
        aux = aux->getproximazona(); // o aux vai ser a proxima zona
    }

    return aux;

}

//FUNCAO PARA IMPRIMIR A ILHA NO ECRA
string Ilha::getAsString() const {

    ostringstream oss;
    oss << "Ilha" << endl;

    //imprime a primeira linha horizontal da ilha no ecra
    oss << "|";
    for (int j = 0; j < largura - 1; ++j)
        oss << "----+";
    oss << "----|\n";

    //este ciclo for imprime as linhas seguintes no ecra
    for (int i = 0; i < altura; ++i) {

        //imprime a primeira frase da zona (tipo de zona)
        for (int j = 0; j < largura; ++j)
            oss << "|" << ocupaquatro(acessoilha(i, j)->gettipozona());
        oss << "|\n";

        //imprime a segunda frase da zona (tipo de edificio)
        for (int j = 0; j < largura; ++j)
            oss << "|" << ocupaquatro(acessoilha(i, j)->gettipoedificio());
        oss << "|\n";

        //imprime a terceira frase da zona (tipo de trabalhadores)
        for (int j = 0; j < largura; ++j)
            oss << "|" << ocupaquatro(acessoilha(i, j)->obtemtipotrabalhadores());
        oss << "|\n";

        //imprime a quarta frase da zona (numero de trabalhadores)
        for (int j = 0; j < largura; ++j)
            oss << "|" << ocupaquatro(to_string(acessoilha(i, j)->obtemnumerotrabalhadores()));
        oss << "|";

        //imprime a linha horizontal que separa as zonas
        oss << "\n|";
        for (int j = 0; j < largura - 1; ++j)
            oss << "----+";
        oss << "----|\n";
    }

    //Imprimir no ecra os Recursos totais da ilha
    oss << "Recursos Totais: " << endl;
    Recursos *a[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    getrecursos(a);
    int i;
    for (i = 0; i < 6; i++) {
        oss << a[i]->gettipo() << ' ' << a[i]->getquantidade() << endl;
    }

    //Imprimir no ecra o Dinheiro total da ilha
    oss << "Dinheiro Total: " << dinheiroilha << " euros" << endl;

    return oss.str();
}

//FUNCAO PARA NA REPRESENTACAO DA ILHA OCUPAR 4 ESPAÇOS INDEPENDENTEMENTE DO TAMANHO DA STRING
string Ilha::ocupaquatro(string palavra) const {
    int tamanhopalavra = palavra.size(); //obter o tamanho da palavra recebida por argumento
    string auxiliar; //variavel string auxiliar
    int i = 0; // variavel int auxiliar

    //ciclo for para carregar para a string auxiliar letra a letra da palavra
    for (; i < tamanhopalavra && i < nrespacos; i++) {
        auxiliar += palavra[i];
    }
    //ciclo for para preencher o resto da string auxiliar com espacos, até ao total de 4 espaços
    for (; i < nrespacos; i++) {
        auxiliar += " ";
    }

    return auxiliar; //devolve a string auxiliar que ocupa 4 espaços
}

//FUNÇAO PARA OBTER ALEATORIAMENTE O TIPO DE ZONA
Zona *Ilha::obtemtipozonaleatorio(int a[]) const {

    int nrcelulas = altura * largura; //obter o numero de zonas que vao ser geradas
    int nrmin = nrcelulas /
                6; // obter o numero minimo de zonas de cada tipo, para haver equilibrio no numero de zonas de cada tipo
    int sobra =
            nrcelulas % 6; // obter o resto da divisao para posteriormente acrescentar ao numero minimo de certas zonas
    int x, y; // variaveis auxiliares
    int aux; //variavel auxiliar

    // gerar o tipo de terreno de forma aleatoria
    do {
        aux = rand() % 6; //gera um numero aleatorio de 0 ate 6 que é o tipo de zonas possiveis (deserto, pastagem, etc)
    } while (a[aux] >= (aux < sobra ? nrmin + 1 : nrmin));

    a[aux]++; //incrementa no vetor a o nr de zonas do tipo
    switch (aux) {
        case 0:
            return new Deserto();
        case 1:
            return new Pasto();
        case 2:
            return new Floresta();
        case 3:
            return new Montanha();
        case 4:
            return new Pantano();
        case 5:
            return new ZonaX();
    }
    return nullptr;
}

//FUNCAO PARA OBTER O PASTO ALEATORIO
Zona *Ilha::procurapastoaleatorio() {

    vector<int> x; //vetor da posicao i
    vector<int> y; //vetor da posicao j

    //ciclo for que percorre a ilha à procura das zonas tipo pasto
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            if (strcmp("pas", acessoilha(i, j)->gettipozona().c_str()) ==
                0) {//usa a funçáo strcmp para comparar os tipos de zona.
                x.push_back(i); //encontrou um pasto, entao carrega a coordenada i da zona para o vetor x
                y.push_back(j); //encontrou um pasto, entao carrega a coordenada j da zona para o vetor y
            }
        }
    }
    //quando sai do ciclo ja percorreu a ilha e encontrou os pastos, cujas coordenadas estao nos vetores x e y

    int nraleatorio = rand() % x.size(); //gera numero aleatorio de 0 até ao tamanho do vetor x

    return acessoilha(x[nraleatorio], y[nraleatorio]);
    //return zonas[x[nraleatorio]][y[nraleatorio]]; //devolve uma referência para uma zona pasto com as coordenadas de x[nraleatorio] e y[nraleatorio]
}

//FUNCAO PARA CONTRATAR UM TIPO DE TRABALHADOR QUE VAI PARA A ZONA PASTO ESCOLHIDA ALEATORIAMENTE
string Ilha::contratatrabalhador(string tipotrab) {
    //verifica se estao reunidas as condicoes para contratacao
    int custo = pasto->verificacondicoescontratacao(tipotrab, diaatual, dinheiroilha);
    if (custo == -1) {
        return "Nao estao reunidas as condicoes de contratacao.";
    };

    if (custo == 0) {
        return "Tipo de trabalhador invalido.";
    };

    //estao reunidas as condicoes de contratacao
    dinheiroilha -= custo;
    return pasto->contratatrabalhador(tipotrab, diaatual);
}

//FUNCAO PARA REPRESENTAR APENAS UMA ZONA DETALHADA COM O COMANDO LIST
string Ilha::representa(int i, int j) {
    //i e j são as coordenadas da zona na ilha
    if (i <= 0 || i > altura || j <= 0 || j > largura)
        return "Posicao invalida";

    //a linha começa em 1 e a coluna começa em 1
    return acessoilha(i - 1, j - 1)->getasstring();
    //return zonas[i - 1][j - 1]->getasstring();
}

//FUNCAO PARA CONSTRUIR UM EDIFÍCIO NUMA DETERMINADA ZONA
string Ilha::constroi(string tipoedif, int i, int j) {

    //i e j são as coordenadas da zona na ilha
    if (i <= 0 || i > altura || j <= 0 || j > largura)
        return "Posicao invalida";

    //Ver se ja tem edificio nessa zona
    Edificio *aux = nullptr;
    aux = acessoilha(i - 1, j - 1)->getponteiroedificio();
    if (aux != nullptr) {
        return "Ja existe edificio na zona";
    }

    //ver se temos recursos suficientes na ilha
    Recursos *a[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    getrecursos(a);
    Edificio *edificio = nullptr;

    if (strcmp("minaf", tipoedif.c_str()) == 0) {
        edificio = new Minaferro(); //o ponteiro fica a apontar para essa referência MinaFerro
    }

    if (strcmp("minac", tipoedif.c_str()) == 0) {
        edificio = new Minacarvao(); //o ponteiro fica a apontar para essa referência MinaCarvao
    }

    if (strcmp("central", tipoedif.c_str()) == 0) {
        edificio = new Centraleletrica(); //o ponteiro fica a apontar para essa referência CentralEletrica
    }

    if (strcmp("bat", tipoedif.c_str()) == 0) {
        edificio = new Bateria(); //o ponteiro fica a apontar para essa referência Bateria
    }

    if (strcmp("fund", tipoedif.c_str()) == 0) {
        edificio = new Fundicao(); //o ponteiro fica a apontar para essa referência Fundicao
    }

    if (strcmp("edx", tipoedif.c_str()) == 0) {
        edificio = new Edificiox(); //o ponteiro fica a apontar para essa referência EdificioX
    }

    if (edificio == nullptr) {
        return "Edificio invalido\n";
    }

    //faz copia para depois comparar
    Recursos *b[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    for (int i = 0; i < 6; i++) {
        b[i]->incrementaquantidade(a[i]->getquantidade());
    }

    //obter o tipo de zona para atualizar o valor a descontar
    string tipo = acessoilha(i - 1, j - 1)->gettipozona();
    int desconta = edificio->podeconstroir(a, dinheiroilha, tipo);
    if (desconta == -1) {
        return "Nao tem recursos suficientes\n";
    }

    //descontar dinheiro para construir o edificio
    dinheiroilha -= desconta;

    //Funcao para descontar recursos da ilha
    Recursos *c[6] = {new Ferro(), new Aco(), new Carvao(), new Madeira(), new VigasMadeira(), new Eletricidade()};
    for (int i = 0; i < 6; i++) {
        c[i]->incrementaquantidade(b[i]->getquantidade() - a[i]->getquantidade());
    }
    descontarecursosilha(c);

    //a linha começa em 1 e a coluna começa em 1
    return acessoilha(i - 1, j - 1)->constroiedificio(tipoedif);
    //return zonas[i - 1][j - 1]->constroiedificio(tipoedif);
}

string Ilha::constroiDebug(string tipoedif, int i, int j) {

    //i e j são as coordenadas da zona na ilha
    if (i <= 0 || i > altura || j <= 0 || j > largura)
        return "Posicao invalida";

    //Ver se ja tem edificio nessa zona (pode ser ignorado? visto este ser um comando de debug?)
    Edificio *aux;
    aux = acessoilha(i - 1, j - 1)->getponteiroedificio();
    if (aux != nullptr) {
        return "Ja existe edificio na zona";
    }

    //a linha começa em 1 e a coluna começa em 1
    // vai recorrer à funçao de construir normalmente
    return acessoilha(i - 1, j - 1)->constroiedificio(tipoedif);
    //return zonas[i - 1][j - 1]->constroiedificio(tipoedif);

}

//FUNÇAO PARA OBTER OS RECURSOS TOTAIS DA ILHA
void Ilha::getrecursos(Recursos **pRecursos) const {

    //percorre zona a zona e obtem a quantidade de recursos existentes na zona
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            acessoilha(i, j)->getrecursos(pRecursos);
        }
    }
}

//FUNCAO PARA TRANSFERIR UM TRABALHADOR PARA OUTRA ZONA
string Ilha::transferetrabalhador(string id, int linha, int coluna) {

    Trabalhadores *aux = nullptr;

    //verifica se a linha e coluna sao validos
    //i e j são as coordenadas da zona na ilha
    if (linha <= 0 || linha > altura || coluna <= 0 || coluna > largura)
        return "Posicao invalida\n";

    //percorre a ilha a procura do trabalhador
    int i, j;
    for (i = 0; i < altura && aux == nullptr; ++i) {
        for (j = 0; j < largura && aux == nullptr; ++j) {
            aux = acessoilha(i, j)->retornatrabalhador(id);
        }
    }

    // verificar se estamos a mover o trabalhador para o mesmo sítio
    if (linha == i && coluna == j)
        return "O Trabalhador ja estava nessa posicao\n";

    //nao encontrou o trabalhador
    if (aux == nullptr) return "Trabalhador com id " + id + " nao encontrado.\n";

    //ver se o trabalhador ja foi movido
    if (aux->getmovido()) {
        return "Trabalhador ja foi movido hoje. So pode ser movido amanha.\n";
    }

    //encontrou o trabalhador. Vai adiciona-lo ao vetor de trabalhadores da zona
    acessoilha(linha - 1, coluna - 1)->adicionatrabalhador(aux);
    //tem que apagar o trabalhador do vetor de trabalhadores da outra zona
    acessoilha(i - 1, j - 1)->apagatrabalhador(aux); //
    aux->alteramovido(); //muda a flag do trabalhador para saber que ja foi movido naquele dia

    return "Trabalhador com id" + id + " transferido para a Zona " + to_string(linha) + " " + to_string(coluna) + ".\n";
}

//FUNCAO PARA AVANCAR OS DIAS DA ILHA E DOS EDIFICIOS
void Ilha::avancadias() {
    diaatual++;
    //percorre a ilha, para cada zona chama a funcao de incrementa dias edificios
    int i, j;

    for (i = 0; i < altura; ++i) {
        for (j = 0; j < largura; ++j) {
            acessoilha(i, j)->incrementadiasedificio();
        }
    }
}

//FUNCAO PARA OS EFEITOS DE DESPEDIMENTOS DA ILHA
void Ilha::despedimentos() {
    //percorre a ilha, para cada zona chama a funcao de despedimentos
    int i, j;
    for (i = 0; i < altura; ++i) {
        for (j = 0; j < largura; ++j) {
            despedidos += acessoilha(i, j)->despedimentos(diaatual);
        }
    }
}

//FUNCAO DESPEDE TRABALHADOR DEBUG
string Ilha::despedetrabalhadorDebug(string id) {

    // flag para saber se ja foi despedido
    bool despedido = false;

    // percorremos a ilha inteira
    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {
            despedido = acessoilha(i, j)->despedimentosDebug(id); // *explicação
            if (despedido) // se alguem foi despedido, nao precisamos de procurar mais
                break;
        }
        if (despedido) // se alguem foi despedido, nao precisamos de procurar mais
            break;
    }

    // *explicação - vamos ver no vetor de trabalhadores, de zona em zona, se
    // conseguimos encontrar um trabalhador com aquele id
    // nessa função, se for encontrado um trabalhador com esse id, ele é despedido e retorna true

    if (despedido) { // se foi despedidos, apresentamos essa info
        ostringstream oss;
        oss << "Foi despedido o trabalhador com o ID: " << id;
        return oss.str();
    } else { // caso contrário, dizemos que nao existe esse ID
        return "Nao existe um trabalhador com esse ID";
    }

}

//FUNCAO PARA OS DESABAMENTOS DE EDIFICIOS DA ILHA
void Ilha::desabamentos() {
    //percorre a ilha, para cada zona chama a funcao de desabamentos
    int i, j;
    for (i = 0; i < altura; ++i) {
        for (j = 0; j < largura; ++j) {
            despedidos += acessoilha(i, j)->desabamentos(acessoilha(i, j)->gettipozona(), i, j);
        }
    }
}

//FUNCAO PARA MUDAR AS FLAGS DE MOVIDO DOS TRABALHADORES, PARA PODEREM VOLTAR A MUDAR DE ZONA NO NOVO DIA
void Ilha::mudaflagsmovidos() {
    //percorre a ilha, para cada zona chama a funcao de mudaflags
    int i, j;
    for (i = 0; i < altura; ++i) {
        for (j = 0; j < largura; ++j) {
            acessoilha(i, j)->mudaflags();
        }
    }
}

void Ilha::descontarecursosilha(Recursos **pRecursos) {
    //percorre a ilha, para cada zona
    int i, j, k, recursosdescontar; //recursos a descontar
    recursosdescontar = 0;
    for (k = 0; k < 6; k++) {
        recursosdescontar += pRecursos[k]->getquantidade();
    }

    for (i = 0; i < altura && recursosdescontar > 0; ++i) {
        for (j = 0; j < largura && recursosdescontar > 0; ++j) {
            acessoilha(i, j)->descontarecursoszona(pRecursos);
            recursosdescontar = 0;
            for (k = 0; k < 6; k++) {
                recursosdescontar += pRecursos[k]->getquantidade();
            }
        }
    }


}

// função para tentar ligar um edificio
string Ilha::ligarEdfs(int linha, int coluna) {

    // verificar se a posição é valida
    if (linha <= 0 || linha > altura || coluna <= 0 || coluna > largura)
        return "Posicao invalida\n";

    // criar um edificio auxiliar que é igual ao que existe na zona em questão
    Edificio *aux;
    aux = acessoilha(linha - 1, coluna - 1)->getponteiroedificio();

    if (aux != nullptr) { // se esse edificio nao for nullptr
        aux->setLigado(true); // vamos ligar o edificio
        return "O edificio foi ligado";
    } else // se esse edificio for nullptr, nao vamos fazer nada
        return "Nao existe nenhum edificio para ligar!";

}

string Ilha::desligarEdfs(int linha, int coluna) {

    // verificar se a posição é valida
    if (linha <= 0 || linha > altura || coluna <= 0 || coluna > largura)
        return "Posicao invalida\n";

    // criar um edificio auxiliar que é igual ao que existe na zona em questão
    Edificio *aux;
    aux = acessoilha(linha - 1, coluna - 1)->getponteiroedificio();

    if (aux != nullptr) { // se esse edificio nao for nullptr
        aux->setLigado(false); // vamos desligar o edificio
        return "O edificio foi desligado";
    } else // se esse edificio for nullptr, nao vamos fazer nada
        return "Nao existe nenhum edificio para desligar!";

}

string Ilha::incrementaDinheiro(int qnt) {

    if (qnt > 0) { // adicionar dinheiro
        dinheiroilha += qnt;
        return "Foram adicionados " + to_string(qnt) + "euros. Saldo atual: " + to_string(dinheiroilha);
    } else if (qnt == 0) // caso para quanndo nao se recebe nenhum valor para aumentar/diminuir
        return "O seu saldo mantem-se igual.";
    else { // remover dinheiro
        if (dinheiroilha + qnt < 0) { // nunca se tem saldo negativo
            dinheiroilha = 0;
            return "O seu saldo passou para 0 euros.";
        } else { // remover dinheiro
            dinheiroilha += qnt;
            return "Foram removidos " + to_string(qnt) + "euros. Saldo atual: " + to_string(dinheiroilha);
        }
    }

}

void Ilha::produz() {

    Edificio *auxEdf = nullptr; // este ponteiro auxiliar vai servir para guardar uma bateria, caso exista nas zonas adjacentes
    // este edf vai ser passado de função em função e se: entrar numa central eletrica + for uma bateria = recebe energia

    Recursos **auxZona = nullptr; // este ponteiro auxiliar vai servir para guardar os recursos de uma floresta, caso exista nas zonas adjacentes
    // este zona vai ser passado de função em função e se: entrar numa central eletrica + for uma floresta = perde madeira

    Recursos **temp = nullptr;

    for (int i = 0; i < altura; ++i) {
        for (int j = 0; j < largura; ++j) {

            vector<string> zonasdailha;

            if (i > 0) { // se existir mais células para a cima, posso add a de cima
                // procura por edificios nas zonas adjacentes
                if (acessoilha(i - 1, j)->existeEdificio()) {

                    // guarda o tipo de edificio na zona adjacente
                    zonasdailha.push_back(acessoilha(i - 1, j)->gettipoedificio());

                    // vai ver se está uma bateria na zona adjacente e se estiver guarda a informação dela
                    auxEdf = acessoilha(i - 1, j)->getponteiroedificio();
                    if (auxEdf->gettipoedificio() != "bat")
                        auxEdf = nullptr;
                    else {
                        Recursos **auxRecursos = auxEdf->getrecursos();
                        if (auxRecursos[5]->getquantidade() == auxEdf->getCapmax())
                            auxEdf = nullptr;
                    }

                }

                // procura por florestas nas zonas adjacentes
                if (acessoilha(i - 1, j)->gettipozona() == "flr") {
                    //Recursos **temp;
                    //acessoilha(i - 1, j)->getrecursoszonaapenas(temp);
                    temp = acessoilha(i - 1, j)->getRecursosZona();
                    // procura se tem madeira nessa floresta
                    if (temp[3]->getquantidade() > 0)
                        auxZona = acessoilha(i - 1, j)->getRecursosZona();
                    else
                        auxZona = nullptr;
                } else
                    auxZona = nullptr;

            }


            if (j > 0) {
                if (acessoilha(i, j - 1)->existeEdificio()) {
                    zonasdailha.push_back(acessoilha(i, j - 1)->gettipoedificio());
                    auxEdf = acessoilha(i, j - 1)->getponteiroedificio();
                    if (auxEdf->gettipoedificio() != "bat")
                        auxEdf = nullptr;
                    else {
                        Recursos **auxRecursos = auxEdf->getrecursos();
                        if (auxRecursos[5]->getquantidade() == auxEdf->getCapmax())
                            auxEdf = nullptr;
                    }
                }

                // procura por florestas nas zonas adjacentes
                if (acessoilha(i, j - 1)->gettipozona() == "flr") {
                    //Recursos **temp;
                    //acessoilha(i, j - 1)->getrecursoszonaapenas(temp);
                    temp = acessoilha(i, j - 1)->getRecursosZona();
                    // procura se tem madeira nessa floresta
                    if (temp[3]->getquantidade() > 0)
                        auxZona = acessoilha(i, j - 1)->getRecursosZona();
                    else
                        auxZona = nullptr;
                } else
                    auxZona = nullptr;
            }


            if (i < altura - 1) {
                if (acessoilha(i + 1, j)->existeEdificio()) {
                    zonasdailha.push_back(acessoilha(i + 1, j)->gettipoedificio());
                    auxEdf = acessoilha(i + 1, j)->getponteiroedificio();
                    if (auxEdf->gettipoedificio() != "bat")
                        auxEdf = nullptr;
                    else {
                        Recursos **auxRecursos = auxEdf->getrecursos();
                        if (auxRecursos[5]->getquantidade() == auxEdf->getCapmax())
                            auxEdf = nullptr;
                    }
                }

                // procura por florestas nas zonas adjacentes
                if (acessoilha(i + 1, j)->gettipozona() == "flr") {
                    //Recursos **temp;
                    //acessoilha(i + 1, j)->getrecursoszonaapenas(temp);
                    temp = acessoilha(i + 1, j)->getRecursosZona();
                    // procura se tem madeira nessa floresta
                    if (temp[3]->getquantidade() > 0)
                        auxZona = acessoilha(i + 1, j)->getRecursosZona();
                    else
                        auxZona = nullptr;
                } else
                    auxZona = nullptr;
            }


            if (j < largura - 1) {
                if (acessoilha(i, j + 1)->existeEdificio()) {
                    zonasdailha.push_back(acessoilha(i, j + 1)->gettipoedificio());
                    auxEdf = acessoilha(i, j + 1)->getponteiroedificio();
                    if (auxEdf->gettipoedificio() != "bat")
                        auxEdf = nullptr;
                    else {
                        Recursos **auxRecursos = auxEdf->getrecursos();
                        if (auxRecursos[5]->getquantidade() == auxEdf->getCapmax())
                            auxEdf = nullptr;
                    }
                }

                // procura por florestas nas zonas adjacentes
                if (acessoilha(i, j + 1)->gettipozona() == "flr") {
                    //Recursos **temp;
                    //acessoilha(i, j + 1)->getrecursoszonaapenas(temp);
                    temp = acessoilha(i, j + 1)->getRecursosZona();
                    // procura se tem madeira nessa floresta
                    if (temp[3]->getquantidade() > 0)
                        auxZona = acessoilha(i, j + 1)->getRecursosZona();
                    else
                        auxZona = nullptr;
                } else
                    auxZona = nullptr;
            }


            acessoilha(i, j)->produzir(diaatual); // PRODUÇÃO DAS ZONAS
            acessoilha(i, j)->produzirnosEdfs(zonasdailha, auxEdf, auxZona); // PRODUÇÃO DOS EDFS

        }
    }

}

string Ilha::vende(string a, string b) {

    // o comando pode ser do tipo:
    // vende <tipo> <quanto>
    string tipo;
    int qnt = 0; // é um ponteiro pq vai andar de zona em zona e nao sabemos em que zona é que chega a zero
    int recompensa = 0;

    // o comando pode ser do tipo:
    // vende <linha> <coluna>
    int Linha;
    int Coluna;

    // descobrir se o utilizador quer vender recursos ou um edificio
    bool venderEdf = false;
    bool venderRecursos = false;

    if (strcmp(a.c_str(), "ferro") == 0) {
        venderRecursos = true;
        qnt = atoi(b.c_str());
        tipo = "ferro";
    } else if (strcmp(a.c_str(), "aco") == 0) {
        venderRecursos = true;
        qnt = atoi(b.c_str());
        tipo = "aco";
    } else if (strcmp(a.c_str(), "carvao") == 0) {
        venderRecursos = true;
        qnt = atoi(b.c_str());
        tipo = "carvao";
    } else if (strcmp(a.c_str(), "mad") == 0) {
        venderRecursos = true;
        qnt = atoi(b.c_str());
        tipo = "madeira";
    } else if (strcmp(a.c_str(), "viga") == 0) {
        venderRecursos = true;
        qnt = atoi(b.c_str());
        tipo = "vigas madeira";
    } else if (strcmp(a.c_str(), "eletr") == 0) {
        venderRecursos = true;
        qnt = atoi(b.c_str());
        tipo = "eletricidade";
    } else {
        Linha = atoi(a.c_str());
        Coluna = atoi(b.c_str());
        venderEdf = true;
    }

    // ciclo para vender um edificio
    // a - altura - linha
    // b - largura - coluna
    if (venderEdf) {
        if (acessoilha(Linha - 1, Coluna - 1)->getponteiroedificio() != nullptr) { // se existir um edificio nessa zona

            Edificio *edf = acessoilha(Linha - 1, Coluna - 1)->getponteiroedificio(); // criamos um edificio auxiliar

            // esta função vai nos dar a recompensa por vender o Edf
            int dinheiro = acessoilha(Linha - 1, Coluna - 1)->venderEdf(edf);

            acessoilha(Linha - 1, Coluna - 1)->setEdfNull(); // colocamos o edf a null

            return "Foi vendido o edificio " + acessoilha(Linha - 1, Coluna - 1)->gettipoedificio() +
                   " na posicao " +
                   to_string(Linha) + " " +
                   to_string(Coluna) + "\n" + incrementaDinheiro(dinheiro);

        } else // se nao existir edificio
            return "Nao existe nenhum edificio para vender!"; // nao fazemos nada
    }

    if (venderRecursos) {
        for (int i = 0; i < altura; ++i) {
            for (int j = 0; j < largura; ++j) {
                if (qnt == 0)
                    break;
                recompensa += acessoilha(i, j)->venderRec(tipo, &qnt);
            }
            if (qnt == 0)
                break;
        }

        dinheiroilha += recompensa;
        return "Foram vendidos " + to_string(recompensa) + " € de " + tipo;

    }

    return "";

}

string Ilha::subirnivel(int linha, int coluna) {

    bool constroi = false;

    // verificar se existe eedificio
    if (acessoilha(linha - 1, coluna - 1)->getponteiroedificio() != nullptr) {
        acessoilha(linha - 1, coluna - 1)->getponteiroedificio()->sobeNivel(&dinheiroilha,
                                                                            acessoilha(linha - 1, coluna -
                                                                                                  1)->getRecursosZona(),
                                                                            &constroi);
    } else
        return "Nao existe nenhum edicio para subir de nivel!";

    if (constroi)
        return "O edificio subiu de nivel!";
    else
        return "Nao e possivel subir de nivel!";

}

void Ilha::diasTrabalho() {
    //percorre a ilha, para cada zona chama a funcao de despedimentos
    int i, j;
    for (i = 0; i < altura; ++i) {
        for (j = 0; j < largura; ++j) {
            acessoilha(i, j)->incrementaDiastrabalho();
        }
    }
}

