#ifndef __simple_figure__
#define __simple_figure__

//------------------------------------------------------------------------------
// simple-figure.h - содержит описание обобщающей простой геометрической фигуры,
// объединяющей воедино фигуры семейства простых фигур.
//------------------------------------------------------------------------------

#include "simple-rectangle.h"
#include "simple-triangle.h"

//------------------------------------------------------------------------------
// Фигура
typedef struct SimpleFigure {}<> SimpleFigure;
SimpleFigure + <rect: SimpleRectangle;>;
SimpleFigure + <trian: SimpleTriangle;>;

#endif // __simple_figure__