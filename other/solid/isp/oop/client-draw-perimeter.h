#ifndef __client_draw_perimeter__
#define __client_draw_perimeter__

#include "container.h"

//------------------------------------------------------------------------------
// Интерфейс клиентского кода, осуществляющего вывод фигур
// и вычисление периметра
class ClientDrawPerimeter {
public:
  ClientDrawPerimeter(Container& c): container{c} {}
  // Вывод содержимого контейнера и вычисление периметров с выводом
  void DrawAndCalcPerimeters(std::ofstream &ofst);
private:
  // Ссылка на используемый внешний контейнер
  Container& container;
};

#endif // __client_draw_perimeter__