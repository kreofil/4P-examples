#ifndef __coord_rectangle__
#define __coord_rectangle__

//------------------------------------------------------------------------------
// coord-rectangle.h - содержит описание класса прямоугольника,
// порожденного от базового класса Rectangle
//------------------------------------------------------------------------------

#include "rectangle.h"
#include "coord-point.h"

//------------------------------------------------------------------------------
// прямоугольник
class CoordRectangle: public Rectangle {
  Point top_left, down_right; // координаты верхнего и нижнего углов
public:
  // переопределяем интерфейс класса
  void InData(std::ifstream &ifst);  // ввод данных из потока
  void Out(std::ofstream &ofst);    // вывод данных в стандартный поток
  CoordRectangle() {} // создание без инициализации.
};

#endif // __coord_rectangle__
