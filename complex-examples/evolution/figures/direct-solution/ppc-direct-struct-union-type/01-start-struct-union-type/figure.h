#ifndef __figure__
#define __figure__

//==============================================================================
// figure.h - содержит описание обобщающей геометрической фигуры,
//==============================================================================

#include "rectangle.h"
#include "triangle.h"

//------------------------------------------------------------------------------
// структура, обобщающая фигуры
typedef struct Figure {} union sizeof(Triangle) {} Figure;
// typedef struct Figure {} union sizeof(struct{int a,b,c,d;}) {} Figure;

Figure + {Rectangle rect;};
Figure + {Triangle  trian;};

#endif // __figure__