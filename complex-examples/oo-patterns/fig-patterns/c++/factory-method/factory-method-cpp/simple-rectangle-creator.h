#ifndef __simple_rectangle_creator__
#define __simple_rectangle_creator__

//------------------------------------------------------------------------------
// simple-rectangle-creator.h - класс, определяющий фабричного метод
// для создания прямоугольника
//------------------------------------------------------------------------------

#include <fstream>
#include "figure-creator.h"

//------------------------------------------------------------------------------
// Фабричный метод создания прямоугольника
class SimpleRectangleCreator: public FigureCreator {
public:
  // Создание прямоугольника
  virtual Figure* CreateFigure();
};

//------------------------------------------------------------------------------

#endif // __simple_rectangle_creator__