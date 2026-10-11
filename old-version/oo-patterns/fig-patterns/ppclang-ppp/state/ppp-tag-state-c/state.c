//==============================================================================
// state.c - Определения функций, обеспечивающих работу с состояниями
//==============================================================================
#include <stdio.h>
#include <stdlib.h>

// #include "state.h"
#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "context.h"

//------------------------------------------------------------------------------
// Различные состояния задаются расширяемыми перечислениями
// вместо использования классов
// typedef struct State {} <> State;
// State + <Start: void;>;     // Начальное состояние
// State + <InSelect: void;>;  // Выбор типа фигуры (диалог)
// State + <InRect: void;>;    // Ввод сторон прямоугольника
// State + <GoodRect: void;>;  // Проверка корректности сторон прямоугольника
// State + <InTrian: void;>;   // Ввод сторон треугольника
// State + <GoodTrian: void;>; // Проверка корректности сторон треугольника
// State + <AddFigure: void;>; // Добавление введенной фигуры в контейнер
// State + <OutCont: void;>;   // Вывод содержимого контейнера
// State + <Finish: void;>;    // Конечное состояние

//==============================================================================
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(struct Container* c) ;
void ContainerClear(struct Container* c);
void ContainerOut(struct Container* c, FILE* ofst) ;
void ContainerAppend(struct Container* c, struct Figure * figure);
//==============================================================================
// Обобщенная функция обработки состояния
void EvalState<State* state>(Context* context) {
  perror("Incorrect State\n");
  exit(1);
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния Start
void EvalState<State.Start* state>(Context* context) {
  // Первоначальное состояние используется для выбора из меню действия
  printf("---> State.Start\n");
  int key;
  printf("Print digit to select one of the action:\n");
  printf("    1 - Input next Figure\n");
  printf("    2 - Out of container content\n");
  printf("    3 - Exit\n");
  printf("? ");
  scanf("%d", &key);
  switch(key) {
    case 1:
      context->state = (State*)context->inSelectState;
      break;
    case 2:
      context->state = (State*)context->outContState;
      break;
    case 3:
      context->state = (State*)context->finishState;
      break;
    default:
      printf("Incorrect digit. Repeat, please...\n");
  }
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния InSelect
void EvalState<State.InSelect* state>(Context* context) {
  // Состояние, определяющее выбор фигуры для ввода с консоли
  printf("---> State.InSelect\n");
  int key;
  printf("Select figure to input\n");
  printf("    1 - Rectangle\n");
  printf("    2 - Triangle\n");
  printf("    3 - Exit\n");
  printf("? ");
  scanf("%d", &key);
  switch(key) {
    case 1:
      context->state = (State*)context->inRectState;
      break;
    case 2:
      context->state = (State*)context->inTrianState;
      break;
    case 3:
      context->state = (State*)context->finishState;
      break;
    default:
      printf("Incorrect figure number. Repeat, please...\n");
  }
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния InRect
void EvalState<State.InRect* state>(Context* context) {
  // Состояние, обеспечивающее ввод данных прямоугольника
  printf("---> State.InRect\n");
  printf("Input rectangle:\n");
  printf("   x = ");
  scanf("%d", &context->a);
  printf("   y = ");
  scanf("%d", &context->b);
  context->state = (State*)context->goodRectState;
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния GoodRect
void EvalState<State.GoodRect* state>(Context* context) {
  // Проверка корректности ввода данных прямоугольника
  printf("---> State.GoodRect\n");
  if((context->a > 0) && (context->b >0)) {
    struct Figure.rect *pf = create_spec(Figure.rect);
    pf->@x = context->a;
    pf->@y = context->b;
    context->figure = (Figure*)pf;
    context->state = (State*)context->addFigureState;
  } else {
    printf("Incorrect rectangle sizes = (%d, %d). Repeat, please...\n",
           context->a, context->b);
    context->state = (State*)context->inRectState;
  }
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния InTrian
void EvalState<State.InTrian* state>(Context* context) {
  // Ввод с консоли данных для треугольника
  printf("---> State.InTrian\n");
  printf("Input triangle:\n");
  printf("   a = ");
  scanf("%d", &context->a);
  printf("   b = ");
  scanf("%d", &context->b);
  printf("   c = ");
  scanf("%d", &context->c);
  context->state = (State*)context->goodTrianState;
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния GoodTrian
void EvalState<State.GoodTrian* state>(Context* context) {
  // Проверка корректности ввода данных треугольника
  printf("---> State.GoodTrian\n");
  if((context->a + context->b > context->c) &&
     (context->a + context->c > context->b) &&
     (context->b + context->c > context->a)) {
    struct Figure.trian *pf = create_spec(Figure.trian);
    pf->@a = context->a;
    pf->@b = context->b;
    pf->@c = context->c;
    context->figure = (Figure*)pf;
    context->state = (State*)context->addFigureState;
  } else {
    printf("Incorrect triangle sizes = (%d, %d, %d). Repeat, please...\n",
           context->a, context->b, context->c);
    context->state = (State*)context->inTrianState;
  }
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния AddFigure
void EvalState<State.AddFigure* state>(Context* context) {
  // Добавление введенной фигуры в контейнер
  printf("---> State.AddFigure\n");
  ContainerAppend(context->container, context->figure);
  printf("Figure added to container\n");
  context->state = (State*)context->startState;
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния OutCont
void EvalState<State.OutCont* state>(Context* context) {
  // Вывод содержимого контейнера
  printf("---> State.OutCont\n");
  ContainerOut(context->container, stdout);
  context->state = (State*)context->startState;
  // context->stop = true;
}

//------------------------------------------------------------------------------
// Обработчик специализации для состояния Finish
void EvalState<State.Finish* state>(Context* context) {
  // Завершение работы автомата
  printf("---> State.Finish\n");
  ContainerClear(context->container);
  context->stop = true;
}

//------------------------------------------------------------------------------
// Начальная инициализация контекста.
//  устанавливаются поля, которые не меняются в начале работы
void InitContext(Context* context) {
  // Состояния
  static struct State.Start startState;       // Начальное состояние
  static struct State.InSelect inSelectState; // Выбор типа фигуры (диалог)
  static struct State.InRect inRectState;     // Ввод сторон прямоугольника
  static struct State.GoodRect goodRectState; // Проверка сторон прямоугольника
  static struct State.InTrian inTrianState;   // Ввод сторон треугольника
  static struct State.GoodTrian goodTrianState; // Проверка сторон треугольника
  static struct State.AddFigure addFigureState; // Добавление фигуры
  static struct State.OutCont outContState;   // Вывод содержимого контейнера
  static struct State.Finish finishState;     // Конечное состояние

  // Перенос состояний в контекст
  context->startState = &startState;
  context->inSelectState = &inSelectState;
  context->inRectState = &inRectState;
  context->goodRectState = &goodRectState;
  context->inTrianState = &inTrianState;
  context->goodTrianState = &goodTrianState;
  context->addFigureState = &addFigureState;
  context->outContState = &outContState;
  context->finishState = &finishState;


  context->state = (State*)context->startState;   // Текущее состояние автомата
  context->container = NULL; // Связь с контейнером для хранения фигур
  context->figure = NULL;  // Последняя введенная фигура
  // Переменные, используемые для формирования фигур
  context->a = context->b = context->c = 0;
  context->stop = false;   // Признак завершения работы в последнем состоянии
}

//------------------------------------------------------------------------------
// Функция установки состояния внутри контекста
void SetState(Context* context, struct State* state) {
  context->state = state;
}

//------------------------------------------------------------------------------
// Функция установки связи с контейнером внутри контекста
void SetContainer(Context* context, struct Container *container) {
  context->container = container;
}
