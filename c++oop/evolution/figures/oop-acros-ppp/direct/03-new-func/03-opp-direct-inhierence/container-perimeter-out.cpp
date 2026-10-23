//==============================================================================
// container-perimeter-out.cpp - метод осуществляющий
// вычисление и тестовый вывод периметров для фигур в контейнере
//==============================================================================

// #include <iostream>
#include "container.h"

//------------------------------------------------------------------------------
// Вывод периметров в поток
void Container::PerimeterOut(std::ofstream &ofst) {
  // std::cout << "Perimeters of figures:\n";
  ofst << "Perimeters of figures:\n";
  for(int i = 0; i < len; i++) {
    ofst << i << ": " << cont[i]->PerimeterFP() << "\n";
  }
}
