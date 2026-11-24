#ifndef __client_geometry__
#define __client_geometry__

#include "container.h"

//------------------------------------------------------------------------------
// Интерфейс клиентского кода, осуществляющего геометрические вычисления
class ClientGeometry {
public:
  ClientGeometry(Container& c): container{c} {}
  // Вычисление и вывод периметров
  void CalcPerimeters(std::ofstream &ofst);
  // Вычисление и вывод площадей
  void CalcAreas(std::ofstream &ofst);
private:
  // Ссылка на используемый внешний контейнер
  Container& container;
};

#endif // __client_geometry__