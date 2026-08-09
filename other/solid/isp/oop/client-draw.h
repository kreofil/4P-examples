#ifndef __client_draw__
#define __client_draw__

#include "container.h"

//------------------------------------------------------------------------------
// Интерфейс клиентского кода, осуществляющего вывод (рисование) фигур
class ClientDraw {
public:
  ClientDraw(Container& c): container{c} {}
  // Вывод содержимого контейнера
  void DrawContainer(std::ofstream &ofst);
private:
  // Ссылка на используемый внешний контейнер
  Container& container;
};

#endif // __client_draw__