#ifndef __simple_figure_factory__
#define __simple_figure_factory__

//------------------------------------------------------------------------------
// simple-figure-factory.h - содержит описание фабрики,
// порождающей простые фигуры
//------------------------------------------------------------------------------

#include <fstream>
#include "figure-factory.h"

//------------------------------------------------------------------------------

// Класс конкретной фабрики, порождающей конкретные фигуры
class SimpleFigureFactory: public FigureFactory {
public:
  // Методы порождения различный фигур
  virtual Rectangle* CreateRectangle();
  virtual Triangle* CreateTriangle();
};

//------------------------------------------------------------------------------

#endif // __simple_figure_factory__