//==============================================================================
// container-perimeter-out.c - содержит функцию, осуществляющую
// вычислени и тестовый вывод периметров для фигур в контейнере
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include "figure.h"
#include "container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
double FigurePerimeter(struct Figure* s);

//------------------------------------------------------------------------------
// Вывод содержимого контейнера в указанный поток
void ContainerPerimeterOut(Container *c, FILE* ofst) {
  fprintf(ofst, "Perimeters of figures:\n");
  for(int i = 0; i < c->len; i++) {
    fprintf(ofst, "%d: %f\n" , i, FigurePerimeter(c->cont[i]));
  }
}

//==============================================================================
// Вычисление периметров фигур с использованием множества потоков
//==============================================================================

// Структура данных, передаваемых потоку для вычисления и возврата периметра
typedef struct FigurePerimeterData {
  int iThread;  // Номер потока для идентификации
  Figure *f;    // Указатель на обрабатываемую фигуру
  double p;     // Возвращаемое значение периметра
} FigurePerimeterData;

// Стартовая функция для формируемых потоков
void *thread_func(void *param) {    //вычисление суммы квадратов в потоке
  FigurePerimeterData* figurePerimeter = (FigurePerimeterData*)param;
  printf("The thread %d started\n", figurePerimeter->iThread);
  figurePerimeter->p = FigurePerimeter(figurePerimeter->f);
  printf("The thread %d: perimeter = %lf\n",
         figurePerimeter->iThread, figurePerimeter->p);
  return NULL;
}


//------------------------------------------------------------------------------
// Многопоточное вычисление периметров фигур, расположенных в контейнере
double CalcFigurePerimetersInContainer(Container *c) {
  pthread_t thread[c->len];   // Дескрипторы потоков. По потоку на фигуру
  FigurePerimeterData perimeterArray[c->len]; // Данные для потоков
  FigurePerimeterData *pElement;

  // Запуск потоков, осуществлеющих вычисление периметров для фигур
  for(int i = 0; i < c->len; ++i) {
    pElement = (perimeterArray+i);
    pElement->iThread = i;
    pElement->f = c->cont[i];
    pElement->p = 0.0;
    if (pthread_create((thread + i), NULL, thread_func, (void*)pElement)) {
      exit(EXIT_FAILURE);
    }
  }

  double perimeterSum = 0.0;
  // Сборка результатов, возвращаемых потоками
  for(int i = 0; i < c->len; ++i) {
    pElement = (perimeterArray+i);
    pthread_join(thread[i], NULL) ;  //и получение результата их вычислений
    perimeterSum += pElement->p;
    printf("The thread %d: result perimeter = %lf\n", pElement->iThread, pElement->p);
  }
  printf("Common Figures Thread Perimenter = %lf\n", perimeterSum);
  return perimeterSum;
}
