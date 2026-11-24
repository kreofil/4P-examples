// Реализация клиентского кода, осуществляющего геометрические вычисления

#include "client-geometry.h"

// Вычисление периметров
void ClientGeometry::CalcPerimeters(std::ofstream &ofst) {
  container.PerimeterOut(ofst);
}

// Вычисление площадей
void ClientGeometry::CalcAreas(std::ofstream &ofst) {
  container.AreaOut(ofst);
}
