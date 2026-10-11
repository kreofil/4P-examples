#ifndef __simple_triangle__
#define __simple_triangle__

//------------------------------------------------------------------------------
// simple-triangle.h - содержит описание класса треугольника,
// порожденного от базового класса shape
//------------------------------------------------------------------------------

// Требуется описание класса SimpleFigure
#include "simple-figure.h"

//------------------------------------------------------------------------------
// треугольник
class SimpleTriangle: public SimpleFigure
{
  double a, b, c; // стороны
public:
  // переопределяем интерфейс класса
  void InData(std::ifstream &ifst);  // ввод данных из потока
  void Out(std::ofstream &ofst);     // вывод данных в стандартный поток
  SimpleTriangle() {} // создание без инициализации.
};

#endif // __simple_triangle__