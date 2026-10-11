// ОО версия программы про хорошего и плохого полицейских,
// использующая ОО (динамический) полиморфизм
#include <stdio.h>

struct Cop { // Обобщенный полицейский
  virtual void Action() {
    printf("Непонятно, какой полицейский.\n");
  }
};

struct BadCop: Cop { // Плохой полицейский
  virtual void Action() {
    printf("Бац-бац...\n");
  }
};

struct GoodCop: Cop { // Хороший полицейский
  virtual void Action() {
    printf("Именем закона...\n");
  }
};

int main() {
  int cop;
  printf("Какой полицейский? (0 - плохой, 1 - хороший): ");
  scanf("%d", &cop);

  // Пусть существуют одновременно разные полицейские
  // Лень использовать кучу
  BadCop  badCop;   // плохой
  GoodCop goodCop;  // хороший
  Cop     otherCop; // иной

  Cop* pCop = (cop==0? &badCop:(cop==1? &goodCop: &otherCop));
  pCop->Action();

  return 0;
}
