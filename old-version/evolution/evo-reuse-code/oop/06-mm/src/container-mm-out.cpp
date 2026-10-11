//------------------------------------------------------------------------------
// container-mm-out.cpp - содержит процедуру
// вывода содержимого контейнера
//------------------------------------------------------------------------------

#include "container.h"

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в файл
void Container::MultimethodOut(std::ofstream &ofst) {
    ofst << "Container contents " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            ofst << "[" << i << "," << j << "]:" <<
            cont[i]->Multimethod(*cont[j]);
        }
    }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в консоль
void Container::MultimethodOut() {
    std::cout << "Container contents " << len << " elements.\n";
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            std::cout << "[" << i << "," << j << "]:"
                      << cont[i]->Multimethod(*cont[j]);
        }
    }
}
