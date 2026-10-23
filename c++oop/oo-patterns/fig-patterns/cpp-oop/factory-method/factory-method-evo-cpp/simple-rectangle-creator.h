#ifndef __simple_rectangle_creator__
#define __simple_rectangle_creator__

//------------------------------------------------------------------------------
// simple-rectangle-creator.h - класс, определяющий фабричного метод
// для создания прямоугольника
//------------------------------------------------------------------------------

#include <fstream>
#include "figure-creator.h"

//------------------------------------------------------------------------------
// Фабрика, обеспечивающая создание прямоугольников при чтении признака фигуры
class SimpleRectangleCreator: public FigureCreator {
public:
  // Конструктор фабрики, устанавливющий признак прямоугольника (равен 1)
  SimpleRectangleCreator():FigureCreator(1) { }

  // Переопределение метода Create на создание прямоугольников.
  Figure* CreateFigure(int key);
};

#endif // __simple_rectangle_creator__