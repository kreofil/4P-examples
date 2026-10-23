//------------------------------------------------------------------------------
// figure-container.cpp - реализация методов контейнера
//------------------------------------------------------------------------------

#include <iostream>
#include "figure-container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
FigureContainer::FigureContainer(): len(0) { }

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void FigureContainer::Clear() {
  for(int i = 0; i < len; i++) {
    delete cont[i];
  }
  len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера
void FigureContainer::In(std::ifstream &ifst) {
  while(!ifst.eof()) {
    // std::cout << "FigureContainer::In\n";
    if((cont[len] = FigureCreator::In(ifst)) != nullptr)
    {
      len++;
    }
  }
}

//------------------------------------------------------------------------------
// Занесение фигуры в контейнер
void FigureContainer::Append(Figure* figure) {
  if(len < max_len) {
    cont[len++] = figure;
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера
void FigureContainer::Out(std::ofstream &ofst) {
  ofst << "Container contents " << len << " elements.\n";
  for(int i = 0; i < len; i++) {
    ofst << i << ": ";
    cont[i]->Out(ofst);
  }
}
