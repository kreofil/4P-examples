//------------------------------------------------------------------------------
// builder.h - обобщенные функции строителя и обработчики специализаций,
// собранные для упрощения в один файл. Но можно и разделить.
//------------------------------------------------------------------------------

#include "builder.h"

//------------------------------------------------------------------------------
// Прототипы используемых функций
void FigureContainerAppend(FigureContainer* c, Figure* figure);

//------------------------------------------------------------------------------
// Обобщающий Строитель прямоугольников.
// По умолчанию ничего не делает, но имеет реализацию
void BuildRectangle<Builder *f>(double x, double y) {}

//------------------------------------------------------------------------------
// Обобщающий Строитель треугольников
void BuildTriangle<Builder *f>(double a, double b, double c) {}

//------------------------------------------------------------------------------
// Строитель прямоугольников для обобщения и существующих специализаций.
void BuildCircle<Builder *f>(double a, double b, double c) {}; // Вдруг будет?

//------------------------------------------------------------------------------
// Формирование результата работы строителя. Нужно переопределять
void ResultOut<Builder *f>(FILE* ofst) {} //= 0;

//==============================================================================
//  Обработчики специализаций для построения аппликаций из простых фигур
//==============================================================================

//------------------------------------------------------------------------------
// Строитель для формирования простых прямоугольников
void BuildRectangle<Builder.SimpleBuilder *f>(double x, double y) {
  struct Figure.SimpleRectangle *rectangle =
                                  create_spec(Figure.SimpleRectangle);
  rectangle->@.x = x;
  rectangle->@.y = y;
  FigureContainerAppend(f->@container, (Figure*)rectangle);
}


//------------------------------------------------------------------------------
// Строитель для формирования простых треугольников
void BuildTriangle<Builder.SimpleBuilder *f>(double a, double b, double c) {
  struct Figure.SimpleTriangle *triangle =
                                  create_spec(Figure.SimpleTriangle);
  triangle->@.a = a;
  triangle->@.b = b;
  triangle->@.c = c;
  FigureContainerAppend(f->@container, (Figure*)triangle);
}

//------------------------------------------------------------------------------
// Формирование результата работы строителя простых фигур.
void ResultOut<Builder.SimpleBuilder *f>(FILE* ofst) {
  fprintf(ofst, "Result of building from Simple figures:\n");
  FigureContainerOut(f->@container, ofst);
}

//==============================================================================
//  Обработчики специализаций для подсчета фигур
//==============================================================================

//------------------------------------------------------------------------------
// Строитель для формирования простых прямоугольников
void BuildRectangle<Builder.CounterBuilder *f>(double x, double y) {
  ++(f->@rectanglesCounter);
}


//------------------------------------------------------------------------------
// Строитель для формирования простых треугольников
void BuildTriangle<Builder.CounterBuilder *f>(double a, double b, double c) {
  ++(f->@trianglesCounter);
}

//------------------------------------------------------------------------------
// Формирование результата работы строителя простых фигур.
void ResultOut<Builder.CounterBuilder *f>(FILE* ofst) {
  fprintf(ofst, "Result of figures counting:\n");
  fprintf(ofst, "    number of rectangles: %d", f->@rectanglesCounter);
  fprintf(ofst, "    number of triangles: %d", f->@trianglesCounter);
}
