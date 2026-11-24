#ifndef __client_draw_area__
#define __client_draw_area__

#include "container.h"

//------------------------------------------------------------------------------
// Интерфейс клиентского кода, осуществляющего вывод фигур
// и вычисление площади
class ClientDrawArea {
public:
  ClientDrawArea(Container& c): container{c} {}
  // Вывод содержимого контейнера и вычисление площади
  void DrawAndCalcAreas(std::ofstream &ofst);
private:
  // Ссылка на используемый внешний контейнер
  Container& container;
};

#endif // __client_draw_area__