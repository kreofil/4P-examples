#ifndef __new_generalization__
#define __new_generalization__

//==============================================================================
// new-generalization.h
// Добавление в программу обобщения, содержащего периметры различных фигур,
// подключаемых через указатели на основы специализаций
// в данном примере не будем плодить лишние единицы компиляции, хотя
// специализации можно размазать для большей гибкости.
//==============================================================================

#include "figure.h"

//------------------------------------------------------------------------------
typedef struct FigurePerimeter {
  double perimeter;
  key k;
  union {
    Rectangle* r;
    Triangle*  t;
  };
} FigurePerimeter;

enum {max_len_p = 100};

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
typedef struct ContainerOfPerimeters {
  int len; // текущая длина
  struct FigurePerimeter cont[max_len_p];
} ContainerOfPerimeters;

#endif // __new_generalization__