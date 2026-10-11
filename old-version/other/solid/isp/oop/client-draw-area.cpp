//------------------------------------------------------------------------------
// Реализация клиентского кода, осуществляющего вывод (рисование) фигур
// и вычисление площади

#include "client-draw-area.h"

// Вывод содержимого контейнера
void ClientDrawArea::DrawAndCalcAreas(std::ofstream &ofst) {
  ofst << "\n    ClientDrawArea::DrawAndCalcAreas:\n";
  container.Out(ofst);
  // Вычисление площадей
  container.AreaOut(ofst);
}
