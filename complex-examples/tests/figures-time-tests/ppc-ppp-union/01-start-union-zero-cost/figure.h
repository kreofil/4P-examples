#ifndef __figure__
#define __figure__

//==============================================================================
// figure.h - содержит описание обобщающей геометрической фигуры,
//==============================================================================

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// Объединение альтернатив, включая нулевую в качестве указателя
// максимального размера
typedef struct FigureMix  {
    union {
        struct{char empty[20];} e;
        Rectangle r;
        Triangle  t;
    };
} FigureMix;

//------------------------------------------------------------------------------
// структура, обобщающая фигуры
// typedef struct Figure {} case{default FigureMix empty;} Figure;
typedef struct Figure {} case{} Figure;

Figure + {FigureMix empty;};
Figure + {FigureMix rect;};
Figure + {FigureMix trian;};

#endif // __figure__