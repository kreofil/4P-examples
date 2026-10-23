//==============================================================================
// container-perimeter-out.c - содержит функцию, осуществляющую
// вычислени и тестовый вывод периметров для фигур в контейнере
//==============================================================================

#include <stdio.h>
#include "figure.h"
#include "container.h"
#include "ppp-thread.h" // Подключение ПП библиотеки потоков

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
double FigurePerimeter<Figure* f>();

// Структура данных, передаваемых потоку для вычисления и возврата периметра
typedef struct FigurePerimeterData {
  int iThread;  // Номер потока для идентификации
  Figure *f;    // Указатель на обрабатываемую фигуру
  double p;     // Возвращаемое значение периметра
} FigurePerimeterData;

//------------------------------------------------------------------------------
// Специализация для потока, вычисляющего периметр фигуры
struct ThreadData + <FigurePerimeterData;>;

//------------------------------------------------------------------------------
// Реализация обработчика специализации, запускаемого в потоке.
void RunThread<ThreadData.FigurePerimeterData *figurePerimeter>() {
  printf("The thread %d started\n", figurePerimeter->@iThread);
  figurePerimeter->@p = FigurePerimeter<figurePerimeter->@f>();
  printf("The thread %d: perimeter = %lf\n",
         figurePerimeter->@iThread, figurePerimeter->@p);
}

//------------------------------------------------------------------------------
// Многопоточное вычисление периметров фигур, расположенных в контейнере
double CalcFigurePerimetersInContainer(Container *c) {
  struct ThreadData.FigurePerimeterData perimeterArray[c->len];
  struct ThreadData.FigurePerimeterData *pElement;
  // Запуск потоков, осуществляющих вычисление периметров для фигур
  for(int i = 0; i < c->len; ++i) {
    init_spec(ThreadData.FigurePerimeterData, (perimeterArray+i));
    pElement = (perimeterArray+i);
    // (perimeterArray+i)->@iThread = i;
    // perimeterArray[i].@iThread = i;
    pElement->@iThread = i;
    pElement->@f = c->cont[i];
    pElement->@p = 0.0;
    StartThread((ThreadData*)(perimeterArray+i));
  }

  double perimeterSum = 0.0;
  // Сборка результатов, возвращаемых потоками
  for(int i = 0; i < c->len; ++i) {
    pElement = (perimeterArray+i);
    WaitThread((ThreadData*)(perimeterArray+i));
    perimeterSum += pElement->@p;
    printf("The thread %d: perimeter = %lf\n",
          pElement->@iThread, pElement->@p);
  }
  printf("Common Figures Thread Perimenter = %lf\n", perimeterSum);
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
