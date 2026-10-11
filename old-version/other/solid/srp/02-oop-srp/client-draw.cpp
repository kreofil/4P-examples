//==============================================================================
// Реализация клиентского кода, осуществляющего вывод (рисование) фигур
//==============================================================================

#include "client-draw.h"
#include "rectangle.h"
#include "triangle.h"

// Вывод содержимого контейнера
void ClientDraw::DrawContainer(std::ofstream &ofst) {
  // container.Out(ofst);
  ofst << "Container contents " << container.len << " elements.\n";
  for(int i = 0; i < container.len; i++) {
    ofst << i << ": ";
    DrawFigure(container.cont[i], ofst);
  }
}
//------------------------------------------------------------------------------
// Вывод содержимого фигуры
void ClientDraw::DrawFigure(Figure* f, std::ofstream &ofst) {
  Rectangle* r;
  Triangle* t;
  if((r = dynamic_cast<Rectangle*>(f)) != nullptr) {
    ofst << "It is Rectangle: x = " << r->x << ", y = " << r->y << "\n";
  } else if((t = dynamic_cast<Triangle*>(f)) != nullptr) {
    ofst << "It is Triangle: a = "
    << t->a << ", b = " << t->b
    << ", c = " << t->c << "\n";
  } else {
    ofst << "Unknown Figure\n";
  }
}
