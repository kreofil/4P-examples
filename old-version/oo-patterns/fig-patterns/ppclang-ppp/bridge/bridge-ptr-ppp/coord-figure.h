#ifndef __coord_figure__
#define __coord_figure__

//------------------------------------------------------------------------------
// coord-figure.h - содержит описание обобщающей геометрической фигуры,
// задаваемой координатами и объединяющей воедино фигуры координатные фигуры.
//------------------------------------------------------------------------------

#include "coord-rectangle.h"
#include "coord-triangle.h"

//------------------------------------------------------------------------------
// Фигура
typedef struct CoordFigure {}<> CoordFigure;
CoordFigure + <rect: CoordRectangle;>;
CoordFigure + <trian: CoordTriangle;>;

#endif // __coord_figure__