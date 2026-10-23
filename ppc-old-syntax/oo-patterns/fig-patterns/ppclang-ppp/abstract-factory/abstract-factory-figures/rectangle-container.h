#ifndef __rectangle_container__
#define __rectangle_container__

//==============================================================================
// rectangle-container.h - содержит тип данных, представляющий простейший контейнер
//==============================================================================

#include "rectangle.h"

enum {rectangle_max_len = 100}; // максимальная длина

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
typedef struct RectangleContainer {
  int len; // текущая длина
  Rectangle *cont[rectangle_max_len];
} RectangleContainer;

#endif // __rectangle_container__