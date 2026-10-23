#ifndef __simple_figures_builder__
#define __simple_figures_builder__

//------------------------------------------------------------------------------
// simple-figures-builder.h - класс, для строительства из простых фигур
//------------------------------------------------------------------------------

#include <fstream>
#include "figure-container.h"
#include "builder.h"
//------------------------------------------------------------------------------
// Строитель из простых фигур
class SimpleBuilder: public Builder {
  FigureContainer* container; // связь с контейнером.
public:
  SimpleBuilder(FigureContainer* _container);
  // Методы, используемые для строительства композиций
  virtual void BuildRectangle(double x, double y);
  virtual void BuildTriangle(double a, double b, double c);
  // Круга нет. Метод по умолчанию пустой
  // Результат строительства сохраняется в файле
  virtual void ResultOut(std::ofstream &ofst);
};

//------------------------------------------------------------------------------

#endif // __simple_figures_builder__