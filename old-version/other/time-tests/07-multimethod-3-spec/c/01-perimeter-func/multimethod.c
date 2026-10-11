//==============================================================================
// multimethod.c - содержит функции, опрделяющие реализацию мультиметода
// для чистого процедурного подхода с использованием для фигуры объединения
//==============================================================================

#include <stdio.h>
#include "figure.h"

//------------------------------------------------------------------------------
// Обработчик специализации для двух прямоугольников
void MMRR(Rectangle* r1, Rectangle* r2, FILE* ofst) {
  fprintf(ofst, "Rectangle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и треугольника
void MMRT(Rectangle* r1, Triangle* t2, FILE* ofst) {
  fprintf(ofst, "Rectangle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и круга
void MMRC(Rectangle* r1, Circle* c2, FILE* ofst) {
  fprintf(ofst, "Rectangle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и прямоугольника
void MMTR(Triangle* t1, Rectangle* r2, FILE* ofst) {
  fprintf(ofst, "Triangle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух треугольников
void MMTT(Triangle* t1, Triangle* t2, FILE* ofst) {
  fprintf(ofst, "Triangle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и круга
void MMTC(Triangle* t1, Circle* c2, FILE* ofst) {
  fprintf(ofst, "Triangle - Circle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и прямоугольника
void MMCR(Circle* c1, Rectangle* r2, FILE* ofst) {
  fprintf(ofst, "Circle - Rectangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и треугольника
void MMCT(Circle* c1, Triangle* t2, FILE* ofst) {
  fprintf(ofst, "Circle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух кругов
void MMCC(Circle* c1, Circle* c2, FILE* ofst) {
  fprintf(ofst, "Circle - Triangle Combination\n");
}

//------------------------------------------------------------------------------
void Multimethod(Figure* f1, Figure* f2, FILE* ofst) {
  switch(f1->k) {
    case RECTANGLE:
      switch(f2->k) {
        case RECTANGLE:
          MMRR(&(f1->r), &(f2->r), ofst);
          break;
        case TRIANGLE:
          MMRT(&(f1->r), &(f2->t), ofst);
          break;
        case CIRCLE:
          MMRC(&(f1->r), &(f2->c), ofst);
          break;
        default:
          fprintf(ofst, "1st is RECTANGLE. Incorrect key of figure 2 = %d\n", f2->k);
      }
      break;
    case TRIANGLE:
      switch(f2->k) {
        case RECTANGLE:
          MMTR(&(f1->t), &(f2->r), ofst);
          break;
        case TRIANGLE:
          MMTT(&(f1->t), &(f2->t), ofst);
          break;
        case CIRCLE:
          MMTC(&(f1->t), &(f2->c), ofst);
          break;
        default:
          fprintf(ofst, "1st is TRIANGLE. Incorrect key of figure 2 = %d\n", f2->k);
      }
      break;
    case CIRCLE:
      switch(f2->k) {
        case RECTANGLE:
          MMCR(&(f1->c), &(f2->r), ofst);
          break;
        case TRIANGLE:
          MMCT(&(f1->c), &(f2->t), ofst);
          break;
        case CIRCLE:
          MMCC(&(f1->c), &(f2->c), ofst);
          break;
        default:
          fprintf(ofst, "1st is CIRCLE. Incorrect key of figure 2 = %d\n", f2->k);
      }
      break;
    default:
      fprintf(ofst, "Incorrect key of figure 1 = %d\n", f1->k);
  }
}

//==============================================================================
// Вычисление периметров в качестве нагрузки мультиметода
// Хотя в целом их можно было распознать и без мультиметода.
//==============================================================================

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника
double RectanglePerimeter(Rectangle *r);
// Вычисление периметра треугольника
double TrianglePerimeter(Triangle *t);
// Вычисление периметра круга
double CirclePerimeter(Circle *c);

//------------------------------------------------------------------------------
// Обработчик специализации для двух прямоугольников
double MMRRP(Rectangle* r1, Rectangle* r2) {
  return RectanglePerimeter(r1) * RectanglePerimeter(r2);
}

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и треугольника
double MMRTP(Rectangle* r1, Triangle* t2) {
  return RectanglePerimeter(r1) + TrianglePerimeter(t2);
}

//------------------------------------------------------------------------------
// Обработчик специализации для прямоугольника и круга
double MMRCP(Rectangle* r1, Circle* c2) {
  return (RectanglePerimeter(r1) - CirclePerimeter(c2)) * 10.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и прямоугольника
double MMTRP(Triangle* t1, Rectangle* r2) {
  return TrianglePerimeter(t1) / RectanglePerimeter(r2);
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух треугольников
double MMTTP(Triangle* t1, Triangle* t2) {
  return TrianglePerimeter(t1) * TrianglePerimeter(t2) * 2.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для треугольника и круга
double MMTCP(Triangle* t1, Circle* c2) {
  return TrianglePerimeter(t1) * CirclePerimeter(c2) / 3.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и прямоугольника
double MMCRP(Circle* c1, Rectangle* r2) {
  return (CirclePerimeter(c1) + RectanglePerimeter(r2)) / 5.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для круга и треугольника
double MMCTP(Circle* c1, Triangle* t2) {
  return CirclePerimeter(c1) - TrianglePerimeter(t2) * 7.0;
}

//------------------------------------------------------------------------------
// Обработчик специализации для двух кругов
double MMCCP(Circle* c1, Circle* c2) {
  return CirclePerimeter(c1) * CirclePerimeter(c2) / 13.0;
}

//------------------------------------------------------------------------------
double MultimethodPerimeter(Figure* f1, Figure* f2) {
  switch(f1->k) {
    case RECTANGLE:
      switch(f2->k) {
        case RECTANGLE:
          return MMRRP(&(f1->r), &(f2->r));
        case TRIANGLE:
          return MMRTP(&(f1->r), &(f2->t));
        case CIRCLE:
          return MMRCP(&(f1->r), &(f2->c));
        default:
          return 0.0;
      }
      break;
        case TRIANGLE:
          switch(f2->k) {
            case RECTANGLE:
              return MMTRP(&(f1->t), &(f2->r));
            case TRIANGLE:
              return MMTTP(&(f1->t), &(f2->t));
            case CIRCLE:
              return MMTCP(&(f1->t), &(f2->c));
            default:
              return 0.0;
          }
          break;
            case CIRCLE:
              switch(f2->k) {
                case RECTANGLE:
                  return MMCRP(&(f1->c), &(f2->r));
                case TRIANGLE:
                  return MMCTP(&(f1->c), &(f2->t));
                case CIRCLE:
                  return MMCCP(&(f1->c), &(f2->c));
                default:
                  return 0.0;
              }
              break;
                default:
                  return 0.0;
  }
}
