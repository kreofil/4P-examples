//==============================================================================
// command.c - Определения функций, обеспечивающих работу с состояниями
//==============================================================================
#include <stdio.h>
#include <stdlib.h>

// #include "command.h"
#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "context.h"

//------------------------------------------------------------------------------
// Различные команды задаются расширяемыми перечислениями
// вместо использования классов
// typedef struct Command {} <> Command;
// Command + <NewRect: void;>;   // Создать и заполнить прямоугольник
// Command + <NewTrian: void;>;  // Создать и заполнить треугольник
// Command + <OutFig: void;>;    // Вывод текущей фигуры
// Command + <OutCont: void;>;   // Вывод содержимого контейнера
// Command + <Finish: void;>;    // Конечное состояние

//==============================================================================
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void ContainerInit(struct Container* c) ;
void ContainerClear(struct Container* c);
void ContainerOut(struct Container* c, FILE* ofst) ;
void ContainerAppend(struct Container* c, struct Figure * figure);

// Обобщающая функция для вывода параметров фигуры
void FigureOut<Figure *f>(FILE* file);

//==============================================================================
// Обобщенная функция обработки команды
void Execute<Command* command>(Context* context) {
  perror("Incorrect Command\n");
  exit(1);
}

//------------------------------------------------------------------------------
// Обработчик специализации для команды NewRect
void Execute<Command.NewRect* command>(Context* context) {
  printf("---> Command.NewRect\n");
  while(true) {
    // Команда, обеспечивающая ввод данных прямоугольника
    printf("Input rectangle:\n");
    printf("   x = ");
    scanf("%d", &context->a);
    printf("   y = ");
    scanf("%d", &context->b);

    if((context->a > 0) && (context->b >0)) {
      struct Figure.rect *pf = create_spec(Figure.rect);
      pf->@x = context->a;
      pf->@y = context->b;
      context->figure = (Figure*)pf;
      break;  // Фигура создана. Выход
    } else {
      printf("Incorrect rectangle sizes = (%d, %d). Repeat, please...\n",
            context->a, context->b);
      continue; // Коррекция ввода
    }
  }
  // Добавление введенной фигуры в контейнер
  printf("---> Command.AddFigure\n");
  ContainerAppend(context->container, context->figure);
  printf("Figure added to container\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для команды NewTrian
void Execute<Command.NewTrian* command>(Context* context) {
  // Состояние, определяющее выбор фигуры для ввода с консоли
  printf("---> Command.NewTrian\n");
  while(true) {
    // Ввод с консоли данных для треугольника
    printf("Input triangle:\n");
    printf("   a = ");
    scanf("%d", &context->a);
    printf("   b = ");
    scanf("%d", &context->b);
    printf("   c = ");
    scanf("%d", &context->c);

    if((context->a + context->b > context->c) &&
      (context->a + context->c > context->b) &&
      (context->b + context->c > context->a)) {
      struct Figure.trian *pf = create_spec(Figure.trian);
      pf->@a = context->a;
      pf->@b = context->b;
      pf->@c = context->c;
      context->figure = (Figure*)pf;
      break;  // Фигура создана. Выход
    } else {
      printf("Incorrect triangle sizes = (%d, %d, %d). Repeat, please...\n",
            context->a, context->b, context->c);
      continue; // Коррекция ввода
    }
  }
  // Добавление введенной фигуры в контейнер
  printf("---> Command.AddFigure\n");
  ContainerAppend(context->container, context->figure);
  printf("Figure added to container\n");
}

//------------------------------------------------------------------------------
// Обработчик специализации для команды OutFig
void Execute<Command.OutFig* command>(Context* context) {
  FigureOut<context->figure>(stdout);
}

//------------------------------------------------------------------------------
// Обработчик специализации для команды OutCont
void Execute<Command.OutCont* command>(Context* context) {
  // Вывод содержимого контейнера
  printf("---> Command.OutCont\n");
  ContainerOut(context->container, stdout);
}

//------------------------------------------------------------------------------
// Обработчик специализации для команды Finish
void Execute<Command.Finish* command>(Context* context) {
  // Завершение работы автомата
  printf("---> Command.Finish\n");
  ContainerClear(context->container);
  context->stop = true;
}

//------------------------------------------------------------------------------
// Начальная инициализация контекста.
//  устанавливаются поля, которые не меняются в начале работы
void InitContext(Context* context) {
  context->container = NULL; // Связь с контейнером для хранения фигур
  context->figure = NULL;  // Последняя введенная фигура
  // Переменные, используемые для формирования фигур
  context->a = context->b = context->c = 0;
  context->stop = false;   // Признак завершения работы в последнем состоянии
}

//------------------------------------------------------------------------------
// Функция установки связи с контейнером внутри контекста
void SetContainer(Context* context, struct Container *container) {
  context->container = container;
}
