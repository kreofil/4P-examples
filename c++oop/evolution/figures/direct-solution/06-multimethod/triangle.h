#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание класса треугольника,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "figure.h"

//------------------------------------------------------------------------------
// треугольник
class Triangle: public Figure {
  int a, b, c; // стороны
public:
  // переопределяем интерфейс класса
  void InData(std::ifstream &ifst);  // ввод данных из потока
  void Out(std::ofstream &ofst);     // вывод данных в стандартный поток
  virtual void Multimethod(Figure& fig2, std::ofstream &ofst); // мультиметод
  virtual void FirstRectangle(Rectangle& rect, std::ofstream &ofst);
  virtual void FirstTriangle(Triangle& trian, std::ofstream &ofst);
  Triangle(): a{0}, b{0}, c{0} {} // создание без инициализации.
};

#endif // __triangle__

