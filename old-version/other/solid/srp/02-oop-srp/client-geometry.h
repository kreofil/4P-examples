#ifndef __client_geometry__
#define __client_geometry__

// Интерфейс клиентского кода, осуществляющего геометрические вычисления
#include "container.h"

class ClientGeometry {
public:
  ClientGeometry(Container& c): container{c} {}
  // Вычисление и вывод периметров
  void CalcPerimeters(std::ofstream &ofst);
  // Вычисление и вывод площадей
  void CalcAreas(std::ofstream &ofst);

private:
  // Вычиcление периметра фигуры
  double CalcFigurePerimeter(Figure* f, std::ofstream &ofst);
  // Вычиcление площади фигуры
  double CalcFigureArea(Figure* f, std::ofstream &ofst);
  // Ссылка на используемый внешний контейнер
  Container& container;
};

#endif // __client_geometry__