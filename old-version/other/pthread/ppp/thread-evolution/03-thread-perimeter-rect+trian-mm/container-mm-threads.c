//==============================================================================
// container-mm-out.c - содержит функцию
// вывода всех пар, контейнера, применяя к каждой мультиметод
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "container.h"
#include "ppp-thread.h" // Подключение ПП библиотеки потоков

//------------------------------------------------------------------------------
// Сигнатура мультиметода
void Multimethod<Figure* f1, Figure* f2>(FILE* ofst);

//==============================================================================
// Организация многопоточных вычислений в мультиметоде
//==============================================================================

//------------------------------------------------------------------------------
// Функция, запускающая обработчик комбинации фигур
void MultimethodLauncher(int iThread, Container *c, int i, int j, FILE* ofst) {
  sleep(rand()%3);
  printf("%d [%d,%d]: ", iThread, i, j);
  Multimethod<c->cont[i], c->cont[j]>(ofst);
}

// Структура данных, передаваемых потоку, обрабатывающему одну комбинацию
// мультиметода
typedef struct MultimethodData {
  int iThread;  // Номер потока для идентификации
  Container* c;     // Контейнер, содержащий фигуры
  int figureIndex1; // Индекс первой фигуры
  int figureIndex2; // Индекс второй фигуры
  FILE* ofst;
  double p;         // Значение возвращаемое из обработчика потока
} MultimethodData;

//------------------------------------------------------------------------------
// Специализация для потока, используемого в мультиметоде
ThreadData + <MultimethodData;>;

//------------------------------------------------------------------------------
// Реализация обработчика специализации, запускаемого в потоке.
void RunThread<ThreadData.MultimethodData *mm>() {
  // printf("The thread %d started\n", mm->@iThread);
  MultimethodLauncher(mm->@iThread,
                      mm->@c,
                      mm->@figureIndex1, mm->@figureIndex2,
                      mm->@ofst);
}

//------------------------------------------------------------------------------
// Вывод пар элементов контейнера в указанный поток через вызов мультиметода
void TreadContainerMultimethodOut(Container *c, FILE* ofst) {
  struct ThreadData.MultimethodData mmArray[c->len][c->len];
  struct ThreadData.MultimethodData *pElement;
  int threadId = 0;
  for(int i = 0; i < c->len; i++) {
    for(int j = 0; j < c->len; j++) {
      init_spec(ThreadData.MultimethodData, &mmArray[i][j]);
      pElement = &mmArray[i][j];
      pElement->@iThread = threadId;
      pElement->@c = c;
      pElement->@figureIndex1 = i;
      pElement->@figureIndex2 = j;
      pElement->@ofst = ofst;
      pElement->@p = 0.0;
      StartThread((ThreadData*)(&mmArray[i][j]));
      threadId++;
    }
  }

  // double perimeterSum = 0.0;
  // Сборка результатов, возвращаемых потоками
  for(int i = 0; i < c->len; i++) {
    for(int j = 0; j < c->len; j++) {
      pElement = (&mmArray[i][j]);
      WaitThread((ThreadData*)&mmArray[i][j]);
    }
  }
}
