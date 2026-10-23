// new-generalization.c - дополнительное обобщение, связывающее используемое
// в нем значение с основами специализаций.

#include <stdio.h>
#include <stdlib.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"
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
void SelectNewPerimeterSpecFromFigure<Figure* f>(FigurePerimeter* fp) {
  printf("SelectNewPerimeterSpecFromFigure: Incorrect Figure\n");
  exit(15);
}

void SelectNewPerimeterSpecFromFigure<Figure.rect* f>(FigurePerimeter* fp) {
  init_spec(FigurePerimeter.rect, fp);
  struct FigurePerimeter.rect* fpr = (struct FigurePerimeter.rect*)fp;
  fpr->@ = &(f->@);
  fpr->perimeter = RectanglePerimeter(&f->@);
}

void SelectNewPerimeterSpecFromFigure<Figure.trian* f>(FigurePerimeter* fp) {
  init_spec(FigurePerimeter.trian, fp);
  struct FigurePerimeter.trian* fpr = (struct FigurePerimeter.trian*)fp;
  fpr->@ = &(f->@);
  fpr->perimeter = TrianglePerimeter(&f->@);
}

//------------------------------------------------------------------------------
// Добавление основы специализации в массив, состоящий из специализаций
// дополнительного обобщения.
void AddNewGeneralization(ContainerOfPerimeters* fpc, struct ppVector.fig* c) {
  unsigned  len = ppVector_size((ppVector*)c);
  fpc->len = len;
  for(int i = 0; i < len; ++i) {
    ppVector_index((ppVector*)c, i);
    SelectNewPerimeterSpecFromFigure<c->@>((FigurePerimeter*)&fpc->cont[i]);
  }
}

//==============================================================================
// Организация вывода специализаций нового обобщения и вывод содержимог
// контейнера с новыми специализациями периметров фигур
//==============================================================================

//  Функция вывода значения периметра из поля обобщения
void FieldPerimeterOut(FigurePerimeter* fp, FILE* ofst) {
  fprintf(ofst, "Perimeter = %lf. ", fp->perimeter);
}

//------------------------------------------------------------------------------
// Обобщающая функция для вывода периметров и параметров связанной фигуры
void NewFigurePerimeterOut<FigurePerimeter *fp>(FILE* ofst) {} //= 0;

//------------------------------------------------------------------------------
// Ввод периметра и связанного с ним прямоугольника
void NewFigurePerimeterOut<FigurePerimeter.rect *fp>(FILE* ofst) {
  FieldPerimeterOut((FigurePerimeter*)fp, ofst);
  RectangleOut(fp->@, ofst);
}

//------------------------------------------------------------------------------
// Ввод периметра и связанного с ним треугольника
void NewFigurePerimeterOut<FigurePerimeter.trian *fp>(FILE* ofst) {
  FieldPerimeterOut((FigurePerimeter*)fp, ofst);
  TriangleOut(fp->@, ofst);
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера периметров фигур в указанный поток
void ContainerNewPerimeterOut(ContainerOfPerimeters* fpc, FILE* ofst) {
  fprintf(ofst, "Container contains %d elements.\n", fpc->len);
  for(int i = 0; i < fpc->len; i++) {
    fprintf(ofst, "%d: " , i);
    NewFigurePerimeterOut<(FigurePerimeter*)&(fpc->cont[i])>(ofst);
  }
}
