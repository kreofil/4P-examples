//==============================================================================
// figures-input.c - функция создания ввода всех альтернативных фигур.
// Реализована с использованием ПП альтернативы шаблонного метода
// и обеспечивающая обход альтернатив для получения нужного значения признака
// Пока без эволюции, но позволяет читать из общего файла.
// Для добавления эволюции наверное имеет смысл ввести в язык функцию, задающую
// число альтернатив и позволяющую делать по ним общей обход?
//==============================================================================

#include <stdio.h>
#include <stdlib.h>

// #include "figure-rectangle.h"
// #include "figure-triangle.h"
#include "action.h"

void FigureIn<Figure *f>(FILE* file);
void FigureOut<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Ввод параметров одноф из фигур из файла
Figure* FigureCreateAndIn(FILE* ifst) {
  // Сформированы два признака для обхода
  // Подумать: может есть вариант формирования массива признаков?
  struct Action.rectangle actRect;
  struct Action.triangle actTrian;
  Figure *pf = NULL;
  int k = 0;
  fscanf(ifst, "%d", &k);
  if(isFigure<(Action*)&actRect>(k)) { // Это признак прямоугольника
    pf = CreateFigure<(Action*)&actRect>();
  } else if(isFigure<(Action*)&actTrian>(k)) { // Это признак треугольника
    pf = CreateFigure<(Action*)&actTrian>();
  } else { // Непонятно что
    exit(13);
    return NULL;
  }
  FigureIn<pf>(ifst);
  // FigureOut<pf>(stdout);
  return pf;
}
