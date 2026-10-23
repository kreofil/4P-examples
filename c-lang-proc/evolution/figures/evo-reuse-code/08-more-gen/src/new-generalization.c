// new-generalization.c - дополнительное обобщение, связывающее используемое
// в нем значение с основами специализаций.

#include <stdio.h>
#include <stdlib.h>
#include "container.h"
#include "new-generalization.h"

//------------------------------------------------------------------------------
// Прототип функции вычисления периметра прямоугольника
double RectanglePerimeter(Rectangle *r);
// Прототип функции вычисления периметра треугольника
double TrianglePerimeter(Triangle *t);
// Прототип функции вывода прямоугольника
void RectangleOut(Rectangle *r, FILE* ifst);
// Прототип функции вывода треугольника
void TriangleOut(Triangle *t, FILE* ifst);

//==============================================================================
// Формирование специализаций нового обобщения и занесение их в контейнер
// специализаций периметров фигур
//==============================================================================

//------------------------------------------------------------------------------
// Формирование конкретной специализации дополнительного обобщения на основе
// известной специализации фигуры. Область памяти под фигуру имеется
void SelectNewPerimeterSpecFromFigure(Figure* f, FigurePerimeter* fp) {
  switch(f->k) {
    case RECTANGLE:
      fp->perimeter = RectanglePerimeter(&(f->r));
      fp->r = &(f->r);
      break;
    case TRIANGLE:
      fp->perimeter = TrianglePerimeter(&(f->t));
      fp->t = &(f->t);
      break;
    default:
      printf("SelectNewPerimeterSpecFromFigure: Incorrect Figure\n");
      exit(15);
  }
  fp->k = f->k;
}

//------------------------------------------------------------------------------
// Добавление основы специализации в массив, состоящий из специализаций
// дополнительного обобщения.
void AddNewGeneralization(ContainerOfPerimeters* fpc, Container* c) {
  fpc->len = c->len;
  for(int i = 0; i < c->len; ++i) {
    SelectNewPerimeterSpecFromFigure(c->cont[i], &fpc->cont[i]);
  }
}

//==============================================================================
// Организация вывода специализаций нового обобщения и вывод содержимог
// контейнера с новыми специализациями периметров фигур
//==============================================================================

//  Функция вывода значения периметра из поля обобщения
void NewFigurePerimeterOut(FigurePerimeter* fp, FILE* ofst) {
  fprintf(ofst, "Perimeter = %lf. ", fp->perimeter);
  switch(fp->k) {
    case RECTANGLE:
      RectangleOut(fp->r, ofst);
      break;
    case TRIANGLE:
      TriangleOut(fp->t, ofst);
      break;
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера периметров фигур в указанный поток
void ContainerNewPerimeterOut(ContainerOfPerimeters* fpc, FILE* ofst) {
  fprintf(ofst, "Container contains %d elements.\n", fpc->len);
  for(int i = 0; i < fpc->len; i++) {
    fprintf(ofst, "%d: " , i);
    NewFigurePerimeterOut(&(fpc->cont[i]), ofst);
  }
}
