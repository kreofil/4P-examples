#ifndef __spec_builders__
#define __spec_builders__

//------------------------------------------------------------------------------
// spec-builders.h - основы специализаций
// для строительства из простых фигур и подсчета.
// Собраны вмести для упрощения кода.
//------------------------------------------------------------------------------

#include "figure-container.h"

//------------------------------------------------------------------------------
// Строитель из простых фигур
typedef struct SimpleBuilder {
  FigureContainer* container; // связь с контейнером.
} SimpleBuilder;

//------------------------------------------------------------------------------
// Счетчик фигур
typedef struct CounterBuilder {
  int rectanglesCounter;
  int trianglesCounter;
} CounterBuilder;

#endif // __spec_builders__