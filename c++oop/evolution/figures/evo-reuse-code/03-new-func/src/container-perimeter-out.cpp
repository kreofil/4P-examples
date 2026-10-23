//==============================================================================
// container-perimeter-out.cpp - метод осуществляющий
// вычисление и тестовый вывод периметров для фигур в контейнере
//==============================================================================

#include <iostream>
#include "container.h"

//------------------------------------------------------------------------------
// Вывод периметров в файл
void Container::PerimeterOut(std::ofstream &ofst) {
  ofst << "Perimeters of figures:\n";
  for(int i = 0; i < len; i++) {
    ofst << i << ": " << cont[i]->Perimeter() << "\n";
  }
}

//------------------------------------------------------------------------------
// Вывод периметров в cout
void Container::PerimeterOut() {
  std::cout << "Perimeters of figures:\n";
  for(int i = 0; i < len; i++) {
    std::cout << i << ": " << cont[i]->Perimeter() << "\n";
  }
}
