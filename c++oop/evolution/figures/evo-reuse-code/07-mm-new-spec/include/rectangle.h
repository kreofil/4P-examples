#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание класса прямоугольника,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "figure.h"

//------------------------------------------------------------------------------
// прямоугольник
class Rectangle: public Figure {
  int x, y; // ширина, высота
public:
  // переопределяем интерфейс класса
  virtual void In(std::ifstream &ifst);  // ввод данных из потока
  virtual void Out(std::ofstream &ofst);    // вывод данных в файл
  virtual void Out();                       // вывод данных в cout
  virtual std::string Multimethod(Figure& fig2); // мультиметод
  virtual std::string FirstRectangle(Rectangle& rect);
  virtual std::string FirstTriangle(Triangle& trian);
  virtual std::string FirstCircle(Circle& circ);
  Rectangle(): x{0}, y{0} {} // создание без инициализации.
};

#endif // __rectangle__