#ifndef __coord_figure_factory__
#define __coord_figure_factory__

//------------------------------------------------------------------------------
// coord-figure-factory.h - содержит описание фабрики,
// порождающей фигуры, задаваемые координатами
//------------------------------------------------------------------------------

#include <fstream>
#include "figure-factory.h"

//------------------------------------------------------------------------------

// Класс конкретной фабрики, порождающей конкретные фигуры
class CoordFigureFactory: public FigureFactory {
public:
  // Методы порождения различный фигур
  virtual Rectangle* CreateRectangle();
  virtual Triangle* CreateTriangle();
};

//------------------------------------------------------------------------------

#endif // __coord_figure_factory__