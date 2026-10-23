//------------------------------------------------------------------------------
// figure-factory.c - Реализация обобщенных функций и обработчиков
// специализаций, создающих различные геометрические фигуры посредством
// использования фабрик.
//------------------------------------------------------------------------------

#include <stdio.h>
#include "figure-factory.h"

//------------------------------------------------------------------------------
// Обобщенная функция создания фигуры - прямоугольника
Figure* CreateRectangle<FigureFactory *factory>() {
  return NULL;
} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации, создающий простой прямоугольник
Figure* CreateRectangle<FigureFactory.simple *factory>() {
  struct SimpleFigure.rect *psr = create_spec(SimpleFigure.rect);
  struct Figure.simple *pf = create_spec(Figure.simple);
  pf->@ = (SimpleFigure*)psr;
  return (Figure*)pf;
  // return create_spec(Figure.simple.rect);
}

//------------------------------------------------------------------------------
// Обработчик специализации, прямоугольник, заданный координатами
Figure* CreateRectangle<FigureFactory.coord *factory>() {
  struct CoordFigure.rect *psr = create_spec(CoordFigure.rect);
  struct Figure.coord *pf = create_spec(Figure.coord);
  pf->@ = (CoordFigure*)psr;
  return (Figure*)pf;
  // return create_spec(Figure.coord.rect);
}

//------------------------------------------------------------------------------
// Обобщенная функция создания фигуры - треугольника
Figure* CreateTriangle<FigureFactory *factory>() {
  return NULL;
} //= 0;

//------------------------------------------------------------------------------
// Обработчик специализации, создающий создающий простой треугольник
Figure* CreateTriangle<FigureFactory.simple *factory>() {
  struct SimpleFigure.trian *psr = create_spec(SimpleFigure.trian);
  struct Figure.simple *pf = create_spec(Figure.simple);
  pf->@ = (SimpleFigure*)psr;
  return (Figure*)pf;
  // return create_spec(Figure.simple.trian);
}

//------------------------------------------------------------------------------
// Обработчик специализации, создающий треугольник, заданный координатами
Figure* CreateTriangle<FigureFactory.coord *factory>() {
  struct CoordFigure.trian *psr = create_spec(CoordFigure.trian);
  struct Figure.coord *pf = create_spec(Figure.coord);
  pf->@ = (CoordFigure*)psr;
  return (Figure*)pf;
  // return create_spec(Figure.coord.trian);
}
