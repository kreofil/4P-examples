#ifndef __figure__
#define __figure__

//==============================================================================
// figure.h - содержит описание обобщающей геометрической фигуры,
//==============================================================================

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// структура, обобщающая фигуры
typedef struct Figure {} case{} Figure;

typedef struct FigureMix  {
    union {
        Rectangle r;
        Triangle  t;
    };
} FigureMix;

// Figure + <mix:FigureMix;>;
Figure + {FigureMix rect;};
Figure + {FigureMix trian;};

#endif // __figure__