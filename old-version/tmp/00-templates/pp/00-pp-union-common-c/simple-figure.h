#ifndef __simple_figure__
#define __simple_figure__

//==============================================================================
// simple-figure.h - содержит описание обобщающей геометрической фигуры,
//==============================================================================

#include "simple-rectangle.h"
#include "simple-triangle.h"

//------------------------------------------------------------------------------
// значения ключей для каждой из фигур
typedef enum simple_key {SIMPLE_RECTANGLE, SIMPLE_TRIANGLE} simple_key;

//------------------------------------------------------------------------------
// структура, обобщающая все имеющиеся фигуры
typedef struct SimpleFigure {
  simple_key k; // ключ
  // используемые альтернативы
  union { // используем простейшую реализацию
    SimpleRectangle r;
    SimpleTriangle t;
  };
} SimpleFigure;

#endif // __simple_figure__