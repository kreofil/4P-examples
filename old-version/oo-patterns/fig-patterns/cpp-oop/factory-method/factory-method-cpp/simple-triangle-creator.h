#ifndef __simple_triangle_creator__
#define __simple_triangle_creator__

//------------------------------------------------------------------------------
// simple-triangle-creator.h - класс, определяющий фабричного метод
// для создания треугольника
//------------------------------------------------------------------------------

#include <fstream>
#include "figure-creator.h"

//------------------------------------------------------------------------------
// Фабричный метод создания треугольника
class SimpleTriangleCreator: public FigureCreator {
public:
  // Создание треугольника
  virtual Figure* CreateFigure();
};

//------------------------------------------------------------------------------

#endif // __simple_triangle_creator__