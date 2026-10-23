//==============================================================================
// container-perimeter-out.c - содержит функцию, осуществляющую
// вычислени и тестовый вывод периметров для фигур в контейнере
//==============================================================================

#include <stdio.h>
#include <omp.h>
#include "figure.h"
#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
double FigurePerimeter<Figure* f>();

//------------------------------------------------------------------------------
// Многопоточное вычисление периметров фигур, расположенных в контейнере
double CalcFigurePerimetersInContainer(Container *c) {
  double perimeterSum = 0.0;
  double p = 0.0;
  int threadNum = omp_get_num_threads();
  // Параллельное вычисление периметров для фигур
  #pragma omp parallel reduction (+: perimeterSum)
  {
    #pragma omp for
    for(int i = 0; i < c->len; ++i) {
      int count = omp_get_thread_num();
      printf("The thread %d started\n", count);
      p = FigurePerimeter<c->cont[i]>();
      perimeterSum += p;
      printf("The thread %d: perimeter = %lf\n", count, p);
    }
  }
  printf("Common Figures OpenMP Perimenter = %lf\n", perimeterSum);
  return perimeterSum;
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void ContainerPerimeterOut(Container *c, FILE* ofst) {
  double perimeterSum = 0.0;
  fprintf(ofst, "Perimeters of figures:\n");
  for(int i = 0; i < c->len; i++) {
    double p = FigurePerimeter<c->cont[i]>();
    fprintf(ofst, "%d: %f\n" , i, p);
    perimeterSum += p;
  }
  printf("Common Figures Sequential Perimenter = %lf\n", perimeterSum);
}
