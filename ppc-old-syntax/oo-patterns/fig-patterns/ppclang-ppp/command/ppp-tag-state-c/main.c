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
void MenuExecutor() {
  // Контейнер
  Container container;
  ContainerInit(&container);

  // Контекст
  Context context;
  InitContext(&context);
  SetContainer(&context, &container);

  // Список команд
  struct Command.NewRect newRectCommand;
  struct Command.NewTrian newTrianCommand;
  struct Command.OutFig outFigCommand;
  struct Command.OutCont outContCommand;
  struct Command.Finish finishCommand;
  Command *command; // Указательна текущую команду

  // Запуск меню выбора команд
  while(!context.stop) {
    // Выбор команды (имитация пунктов меню)
    int key;
    printf("Select command to execute\n");
    printf("    1 - New Rectangle\n");
    printf("    2 - New Triangle\n");
    printf("    3 - Out Last Figure\n");
    printf("    4 - Out Container content\n");
    printf("    5 - Exit\n");
    printf("? ");
    scanf("%d", &key);
    switch(key) {
      case 1:
        command = (Command*)&newRectCommand;
        break;
      case 2:
        command = (Command*)&newTrianCommand;
        break;
      case 3:
        command = (Command*)&outFigCommand;
        break;
      case 4:
        command = (Command*)&outContCommand;
        break;
      case 5:
        command = (Command*)&finishCommand;
        break;
      default:
        printf("Incorrect figure number. Repeat, please...\n");
        continue;
    }
    Execute<command>(&context);
  }
}

//------------------------------------------------------------------------------
int main() {
  printf("Start\n");

  MenuExecutor();

  printf("Stop\n");
  return 0;
}
