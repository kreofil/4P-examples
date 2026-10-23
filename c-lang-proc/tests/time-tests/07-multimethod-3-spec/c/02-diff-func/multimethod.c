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
int MultimethodDifFunc(Figure* f1, Figure* f2) {
  switch(f1->k) {
    case RECTANGLE:
      switch(f2->k) {
        case RECTANGLE:
          // Возвращает сумму площадей двух прямоугольников
          return (f1->r.x * f1->r.y) + (f2->r.x * f2->r.y);
        case TRIANGLE:
          // Возвращает общую сумму сторон прямоугольника и треугольника
          return f1->r.x + f1->r.y + f2->t.a + f2->t.b + f2->t.c;
        case CIRCLE:
          // Возвращает разность между произведениями прямоугольника и круга
          return (f1->r.x * f1->r.y) - (f2->c.r * f2->c.r);
        default:
          return 0;
      }
      break;
        case TRIANGLE:
          switch(f2->k) {
            case RECTANGLE:
              // Возвращает разность между суммами сторон прямоугольника и треугольника
              return (f1->t.a + f1->t.b + f1->t.c) - (f2->r.x + f2->r.y);
            case TRIANGLE:
              // Возвращает произведение сумм сторон двух треугольников
              return (f1->t.a + f1->t.b + f1->t.c) * (f2->t.a + f2->t.b + f2->t.c);
            case CIRCLE:
              // Возвращает разность между периметром треугольника и диаметром круга
              return (f1->t.a + f1->t.b + f1->t.c) - 2 * f2->c.r;
            default:
              return 0;
          }
          break;
            case CIRCLE:
              switch(f2->k) {
                case RECTANGLE:
                  // Разность между диаметром круга и суммой двух сторон прямоугольника
                  return 2 * f1->c.r - (f2->r.x + f2->r.y);
                case TRIANGLE:
                  // Сумма радиуса круга и периметра треугольника
                  return f1->c.r * (f2->t.a + f2->t.b + f2->t.c);
                case CIRCLE:
                  // Произведение радиусов кругов
                  return f1->c.r * f2->c.r;
                default:
                  return 0;
              }
              break;
                default:
                  return 0;
  }
}
