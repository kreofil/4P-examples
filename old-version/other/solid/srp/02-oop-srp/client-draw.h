#ifndef __client_draw__
#define __client_draw__

// Интерфейс клиентского кода, осуществляющего вывод (рисование) фигур
#include "container.h"

class ClientDraw {
public:
  ClientDraw(Container& c): container{c} {}
  // Вывод содержимого контейнера
  void DrawContainer(std::ofstream &ofst);

private:
  // Вывод содержимого фигуры
  void DrawFigure(Figure* f, std::ofstream &ofst);
  // Ссылка на используемый внешний контейнер
  Container& container;
};

#endif // __client_draw__