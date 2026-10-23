//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "container.h"
#include "context.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(Container* c) ;
void ContainerClear(Container* c);
void ContainerOut(Container* c, FILE* ofst) ;


//------------------------------------------------------------------------------
// Машина состояний, реализующая требуемый автомат
void StateMachine() {
  // Контейнер
  Container container;
  ContainerInit(&container);

  // Контекст
  Context context;
  InitContext(&context);
  SetContainer(&context, &container);

  // Запуск машины состояний
  while(!context.stop) {
    EvalState<context.state>(&context);
  }
}

//------------------------------------------------------------------------------
int main() {
  printf("Start\n");

  StateMachine();
  printf("Stop\n");
  return 0;
}
