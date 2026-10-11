#ifndef __coord_triangle__
#define __coord_triangle__

//------------------------------------------------------------------------------
// coord-triangle.h - содержит описание класса треугольника,
// порожденного от класса AbstractTriangle
//------------------------------------------------------------------------------

// Требуется описание класса Triangle
#include "triangle.h"
#include "coord-point.h"

//------------------------------------------------------------------------------
// треугольник
class CoordTriangle: public Triangle
{
  Point a, b, c; // вершины треугольника
public:
  // переопределяем интерфейс класса
  void InData(std::ifstream &ifst);  // ввод данных из потока
  void Out(std::ofstream &ofst);     // вывод данных в стандартный поток
  CoordTriangle() {} // создание без инициализации.
};

#endif // __coord_triangle__
