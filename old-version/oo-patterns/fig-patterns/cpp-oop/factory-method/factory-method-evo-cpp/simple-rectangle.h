#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание класса прямоугольника
//------------------------------------------------------------------------------

#include "figure.h"

//------------------------------------------------------------------------------
// прямоугольник
class SimpleRectangle: public Figure {
  double x, y; // ширина, высота
public:
  // explicit SimpleRectangle(double _x, double _y);
  // переопределяем интерфейс класса
  virtual void InData(std::ifstream &ifst);  // ввод данных из потока
  virtual void Out(std::ofstream &ofst);    // вывод данных в стандартный поток

  // void SetX(double _x) {x = _x;}
  // void SetY(double _y) {y = _y;}

};

#endif // __rectangle__
