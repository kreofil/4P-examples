//------------------------------------------------------------------------------
// container-mm-out.cpp - содержит процедуру
// вывода содержимого контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Вывод содержимого контейнера
void Container::MultimethodOut(std::ofstream &ofst) {
    ofst << "Container contents " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            ofst << "[" << i << "," << j << "]:" ;
            cont[i]->Multimethod(*cont[j], ofst);
        }
    }
}

//------------------------------------------------------------------------------
// Вычисление периметров в мультиметоде
double Container::MultimethodPerimeter() {
    double p = 0.0;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            p += cont[i]->MultimethodPerimeter(*cont[j]);
        }
    }
    return p;
}
