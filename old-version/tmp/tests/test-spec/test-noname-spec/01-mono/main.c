// Проверка использования в качестве основ специализаций неименованных структур,
// непосредственно подключаемых к обобщению.
#include <stdio.h>

//!!! Наверно стоит реализовать использование неименованных структуро хотя бы
//!!! в ряде из этих комбинаций. Каких? Проверить на принадлежность синтаксису Си.
// typedef struct Figure {} <rect: struct Rectangle{int x; int y};> Figure; //-- fail.  А почему нет?
// struct Figure {} <rect: struct Rectangle {int x; int y};>; //-- fail.  А почему нет?
// typedef struct Figure {} <rect: struct {int x; int y};> Figure; //-- fail. А почему нет?
// struct Figure {} <rect: struct {int x; int y};>; //-- fail. А почему нет?

//!!! Есть поддержка, когда тип задается только именем
//!!! Возмжно не стоит делать корректным без использования struct?
// struct Rectangle {int x; int y;};
// struct Figure {} <rect: Rectangle;>; //-- OK а нужно ли???
// struct Figure {} <rect: struct Rectangle;>; //-- fail. Хотя возможно

typedef struct Rectangle {int x; int y;} Rectangle;
// struct Figure {} <rect: struct Rectangle;>; //-- fail А почему нет?
// struct Figure {} <rect: Rectangle;>; //-- OK
typedef struct Figure {} <rect: Rectangle;> Figure; //-- OK

void print<Figure *f>() {
  printf("Default generalized function\n");
}

void print<Figure.rect *f>() {
  printf("Rectangle: (%d, %d)\n", f->@x, f->@y);
}

int main() {
  struct Figure.rect fr;
  // Figure.rect fr; //-- fail А почему нет при наличии typedef?
  fr.@x = 3;
  fr.@y = 5;
  print<&fr>();

  return 0;
}
