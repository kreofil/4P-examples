//==============================================================================
// simple-figure.c - функции, задающие работу с обобщенными фигурами
// и их специализациями
//==============================================================================

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "simple-figure.h"

//------------------------------------------------------------------------------
// Обобщенная функция ввода фигуры
void FigureIn<SimpleFigure *f>(FILE* ifst) {} //= 0;

//------------------------------------------------------------------------------
// Обработчик, осуществляющий ввод фигуры из семейства прямоугольников
void FigureIn<SimpleFigure.SimpleRectangle *f>(FILE* ifst) {
  SimpleRectangleIn(&(f->@), ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий ввод фигуры из семейства треугольников
void FigureIn<SimpleFigure.SimpleTriangle *f>(FILE* ifst) {
  SimpleTriangleIn(&(f->@), ifst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий ввод фигуры из семейства контейнеров
void FigureIn<SimpleFigure.FigureContainer *f>(FILE* ifst) {
  struct FigureContainer* c = &(f->@);
  while(!feof(ifst))  {
    if((c->cont[c->len] = FigureCreateAndIn(ifst)) != 0) {
      c->len++;
    }
  }
}

//------------------------------------------------------------------------------
// Ввод параметров одноЙ из фигур
SimpleFigure* FigureCreateAndIn(FILE* ifst) {
  struct SimpleFigure *sp;
  int k;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    sp = create_spec(SimpleFigure.SimpleRectangle);
    break;
  case 2:
    sp = create_spec(SimpleFigure.SimpleTriangle);
    break;
  default:
    return 0;
  }
  FigureIn<sp>(ifst);
  // FigureOut<sp>(stdout);
  return sp;
}


//------------------------------------------------------------------------------
// Обобщенная функция вывода любой фигуры
void FigureOut<SimpleFigure *f>(FILE* ofst) {} //= 0;

//------------------------------------------------------------------------------
// Обработчик, осуществляющий вывод фигуры из семейства прямоугольников
void FigureOut<SimpleFigure.SimpleRectangle *f>(FILE* ofst) {
  SimpleRectangleOut(&(f->@), ofst);
}

//------------------------------------------------------------------------------
// Обработчик, осуществляющий вывод фигуры из семейства треугольников
void FigureOut<SimpleFigure.SimpleTriangle *f>(FILE* ofst) {
  SimpleTriangleOut(&(f->@), ofst);
}

void FigureOut<SimpleFigure.FigureContainer *f>(FILE* ofst) {
  FigureContainerOut(&(f->@), ofst);
}
//------------------------------------------------------------------------------
// Обобщенная функция клонирования фигуры
SimpleFigure* FigureClone<SimpleFigure *f>() {return NULL;} //= 0

//------------------------------------------------------------------------------
// Обработчик, клонирующий прямоугольник
SimpleFigure* FigureClone<SimpleFigure.SimpleRectangle *f>() {
  struct SimpleFigure.SimpleRectangle *r
        = create_spec(SimpleFigure.SimpleRectangle);
  // memcpy(r, f, sizeof(SimpleFigure<SimpleRectangle>));
  r->@x = f->@x;
  r->@y = f->@y;
  return (SimpleFigure*)r;
}

//------------------------------------------------------------------------------
// Обработчик, клонирующий треугольник
SimpleFigure* FigureClone<SimpleFigure.SimpleTriangle *f>() {
  struct SimpleFigure.SimpleTriangle *t
        = create_spec(SimpleFigure.SimpleTriangle);
  // memcpy(t, f, sizeof(SimpleFigure<SimpleTriangle>));
  t->@a = f->@a;
  t->@b = f->@b;
  t->@c = f->@c;
  return (SimpleFigure*)t;

}

//------------------------------------------------------------------------------
// Обработчик, клонирующий контейнер
SimpleFigure* FigureClone<SimpleFigure.FigureContainer *f>() {
  struct SimpleFigure.FigureContainer* clone =
      create_spec(SimpleFigure.FigureContainer);
  FigureContainer *own_container = &(f->@);
  FigureContainer *clone_container = &(clone->@);
  clone_container->len = own_container->len;
  for(int i = 0; i < own_container->len; i++) {
    clone_container->cont[i] = FigureClone<own_container->cont[i]>();
  }
  return (SimpleFigure*)clone;
}
