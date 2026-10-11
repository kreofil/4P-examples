//------------------------------------------------------------------------------
// figure-factory.c - Реализация обобщенных функций и обработчиков
// специализаций, создающих различные геометрические фигуры посредством
// использования фабрик.
//------------------------------------------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include "figure-factory.h"

// static void test_type_tag_Figure(struct Figure* X) {
//   printf("Figure Tag = %d\n", X->__pp_specialization_type);
// }
//
// static void test_type_tag_SimpleFigure(struct SimpleFigure* X) {
//   printf("SimpleFigure Tag = %d\n", X->__pp_specialization_type);
// }

//------------------------------------------------------------------------------
// Обобщенная функция создания фигуры - прямоугольника
Figure* CreateRectangle<FigureFactory *factory>() {
  return NULL;
} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации, создающий простой прямоугольник
Figure* CreateRectangle<FigureFactory.simple *factory>() {
  struct Figure.simple.rect *pf = create_spec(Figure.simple.rect);
  if(pf == 0) {
    perror("Incorrect Pointer!!!!\n");
    exit(66);
  }
  return (Figure*)pf;
}

//------------------------------------------------------------------------------
// Обработчик специализации, прямоугольник, заданный координатами
Figure* CreateRectangle<FigureFactory.coord *factory>() {
  struct CoordFigure.rect *psr = create_spec(CoordFigure.rect);
  return create_spec(Figure.coord.rect);
}

//------------------------------------------------------------------------------
// Обобщенная функция создания фигуры - треугольника
Figure* CreateTriangle<FigureFactory *factory>() {
  return NULL;
} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации, создающий создающий простой треугольник
Figure* CreateTriangle<FigureFactory.simple *factory>() {
  struct Figure.simple.trian *pf = create_spec(Figure.simple.trian);
  return (Figure*)pf;
}

//------------------------------------------------------------------------------
// Обработчик специализации, создающий треугольник, заданный координатами
Figure* CreateTriangle<FigureFactory.coord *factory>() {
  struct Figure.coord *pf = create_spec(Figure.coord);
  return create_spec(Figure.coord.trian);
}
