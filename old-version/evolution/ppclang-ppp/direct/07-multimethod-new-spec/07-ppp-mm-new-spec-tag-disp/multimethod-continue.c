// multimethod-continue.c - содержит функции, опрeделяющие реализацию
// мультиметода для добавленного круга
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "figure-circle.h"


//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и круга
static void MultimethodFirstRect<Figure.circ* c2>(Figure.rect* r1, FILE* ofst) {
  fprintf(ofst, "Rectangle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и круга
static void MultimethodFirstTrian<Figure.circ* c2>(Figure.trian* t1, FILE* ofst) {
  fprintf(ofst, "Triangle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обобщающая функция, задающая вход во вторую фигуру,
// Когда первая фигура уже определена и это круг
static void MultimethodFirstCirc<Figure* f2>(Figure.circ* c1, FILE* ofst) {} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации для круга и прямоугольника
static void MultimethodFirstCirc<Figure.rect* r2>(Figure.circ* c1, FILE* ofst) {
  fprintf(ofst, "Circle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и треугольника
static void MultimethodFirstCirc<Figure.trian* t2>(Figure.circ* c1, FILE* ofst) {
  fprintf(ofst, "Circle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух кругов
static void MultimethodFirstCirc<Figure.circ* c2>(Figure.circ* c1, FILE* ofst) {
  fprintf(ofst, "Circle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации, когда первая фигура - круг
void Multimethod<struct Figure.circ* c1>(Figure* f2, FILE* ofst) {
  MultimethodFirstCirc<f2>(c1, ofst);
}
