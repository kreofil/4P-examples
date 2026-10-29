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
int Container::MultimethodDifFunc() {
    int p = 0;
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            p += cont[i]->MultimethodDifFunc(*cont[j]);
        }
    }
    return p;
}
