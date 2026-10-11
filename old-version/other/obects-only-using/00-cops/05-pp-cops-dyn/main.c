// Процедурно-параметрическая версия программы про хорошего и плохого
// полицейских, использующая динамический полиморфизм
#include <stdio.h>

// Обобщенный полицейский
typedef struct Cop {}<> Cop;
// Плохой полицейский
Cop + <Bad: void;>;
// Хороший полицейский
Cop + <Good: void;>;

// Обобщенное действие полицейского
void Action<Cop* cop>() {
  printf("Непонятно, какой полицейский.\n");
}

// Действие плохого полицейского
void Action<Cop.Bad* cop>() {
  printf("Бац-бац...\n");
}

// Действие хорошего полицейского
void Action<Cop.Good* cop>() {
  printf("Именем закона...\n");
}

int main() {
  int cop;
  printf("Какой полицейский? (0 - плохой, 1 - хороший): ");
  scanf("%d", &cop);

  // Пусть существуют одновременно разные полицейские
  // Лень использовать кучу
  struct Cop.Bad  badCop;   // плохой
  struct Cop.Good goodCop;  // хороший
  Cop     otherCop;         // иной

  Action<cop==0? (Cop*)&badCop:(cop==1? (Cop*)&goodCop: &otherCop)>();

  return 0;
}