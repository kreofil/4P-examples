#ifndef __simple_rectangle__
#define __simple_rectangle__

//------------------------------------------------------------------------------
// simple-rectangle.h - содержит описание класса прямоугольника,
// порожденного от класса Rectangle
//------------------------------------------------------------------------------

#include "rectangle.h"

//------------------------------------------------------------------------------
// прямоугольник
class SimpleRectangle: public Rectangle {
  double x, y; // ширина, высота
public:
  // переопределяем интерфейс класса
  virtual void InData(std::ifstream &ifst);  // ввод данных из потока
  virtual void Out(std::ofstream &ofst);    // вывод данных в стандартный поток
  SimpleRectangle() {} // создание без инициализации.
};

#endif // __simple_rectangle__
