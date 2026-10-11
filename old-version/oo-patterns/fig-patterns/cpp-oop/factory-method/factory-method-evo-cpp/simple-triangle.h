#ifndef __simple_triangle__
#define __simple_triangle__

//------------------------------------------------------------------------------
// simple-triangle.h - содержит описание класса треугольника
//------------------------------------------------------------------------------

#include "figure.h"

//------------------------------------------------------------------------------
// треугольник
class SimpleTriangle: public Figure {
  double a, b, c; // стороны
public:
  // explicit SimpleTriangle(double _a, double _b, double _c);
  // переопределяем интерфейс класса
  void InData(std::ifstream &ifst);  // ввод данных из потока
  void Out(std::ofstream &ofst);     // вывод данных в стандартный поток

  // void SetA(double _a) {a = _a;}
  // void SetB(double _b) {b = _b;}
  // void SetC(double _c) {c = _c;}
};

#endif // __simple_triangle__
