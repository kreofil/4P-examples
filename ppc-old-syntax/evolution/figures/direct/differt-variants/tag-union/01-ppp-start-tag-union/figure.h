#ifndef __figure__
#define __figure__

//==============================================================================
// figure.h - содержит описание обобщающей геометрической фигуры,
//==============================================================================

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// структура, обобщающая фигуры
typedef struct Figure {} <> Figure;

typedef struct FigureMix  {
    union {
        Rectangle r;
        Triangle  t;
    };
} FigureMix;

// Figure + <mix:FigureMix;>;
Figure + <rect:FigureMix;>;
Figure + <trian:FigureMix;>;

#endif // __figure__