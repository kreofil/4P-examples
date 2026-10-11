// Процедурная версия программы про хорошего и плохого полицейских,
// использующая проверку типа во время выполнения через явно заданный признак.
#include <stdio.h>

// Обобщенный полицейский
typedef enum Cop {
  BadCop,  // Плохой полицейский
  GoodCop, // Хороший полицейский
  OtherCop // Иной полицейский
} Cop;

// Действие плохого полицейского
void ActionOfBadCop() {
  printf("Бац-бац...\n");
}

// Действие хорошего полицейского
void ActionOfGoogCop() {
  printf("Именем закона...\n");
}

// Обобщенное действие полицейского
void Action(Cop cop) {
  switch(cop) {
    case BadCop:
      ActionOfBadCop();
      break;
    case GoodCop:
      ActionOfGoogCop();
      break;
    default:
      printf("Непонятно, какой полицейский.\n");
  }
}

int main() {
  int cop;
  printf("Какой полицейский? (0 - плохой, 1 - хороший): ");
  scanf("%d", &cop);

  Action(cop==0?BadCop:(cop==1?GoodCop:OtherCop));

  return 0;
}