//
// Created by sandr on 01/11/2021.
//

#ifndef TRB_VIGASMADEIRA_H
#define TRB_VIGASMADEIRA_H
#include "../Recursos.h"
using namespace std;

class VigasMadeira:public Recursos{
public:
    VigasMadeira() : Recursos(2.0){};
    // Funcoes
    string gettipo() const override{return "vigas madeira";}
    double getprecounidade() override{return 2;}
};

#endif //TRB_VIGASMADEIRA_H
