//------------------------------------------------------------------------------
// Реализация клиентского кода, осуществляющего вывод (рисование) фигур
// и вычисление периметра

#include "client-draw-perimeter.h"

// Вывод содержимого контейнера
void ClientDrawPerimeter::DrawAndCalcPerimeters(std::ofstream &ofst) {
  ofst << "\n    ClientDrawPerimeter::DrawAndCalcPerimeters:\n";
  container.Out(ofst);
  // Вычисление периметров
  container.PerimeterOut(ofst);
}
