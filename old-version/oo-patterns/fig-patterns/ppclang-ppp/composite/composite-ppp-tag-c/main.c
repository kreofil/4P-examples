//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "figure-container.h"

//------------------------------------------------------------------------------
// Сигнатуры требуемых функций можно тоже подключить через
// заголовочный файл. Но, для простоты, можно и так описать.
void FigureContainerInit(struct Figure.cont* c) ;
void FigureContainerClear(struct Figure.cont* c);
void FigureContainerAppend(struct Figure.cont* c, struct Figure * figure);

void FigureIn<Figure* c>(FILE* ifst) ;
void FigureOut<Figure* c>(FILE* ofst) ;

//------------------------------------------------------------------------------
int main() {
  printf("Start\n");

  // Формирование первой контейнерной композиции
  struct Figure.cont c1;
  FigureContainerInit(&c1);

  struct Figure.rect r1;
    r1.@x = 3; r1.@y = 10;
  struct Figure.trian t1;
    t1.@a = 3; t1.@b = 4; t1.@c = 5;
  struct Figure.rect r2;
    r2.@x = 13; r2.@y = 20;
  FigureContainerAppend(&c1, (Figure*)&r1);
  FigureContainerAppend(&c1, (Figure*)&t1);
  FigureContainerAppend(&c1, (Figure*)&r2);

  // fprintf(stdout, "Only Figures\n");
  // FigureOut<(Figure*)&c1>(stdout);

  struct Figure.cont c2;
  FigureContainerInit(&c2);
  FigureContainerAppend(&c1, (Figure*)&c2);

  struct Figure.rect r3;
    r3.@x = 13; r3.@y = 110;
  struct Figure.trian t2;
    t2.@a = 13; t2.@b = 14; t2.@c = 15;
  struct Figure.rect r4;
    r4.@x = 113; r4.@y = 120;
  FigureContainerAppend(&c2, (Figure*)&r3);
  FigureContainerAppend(&c2, (Figure*)&t2);
  FigureContainerAppend(&c1, (Figure*)&r4);

  struct Figure.rect r5;
    r5.@x = 23; r5.@y = 210;
  struct Figure.trian t3;
    t3.@a = 23; t3.@b = 24; t3.@c = 25;
  struct Figure.rect r6;
    r6.@x = 213; r6.@y = 220;
  FigureContainerAppend(&c1, (Figure*)&r5);
  FigureContainerAppend(&c1, (Figure*)&t3);
  FigureContainerAppend(&c1, (Figure*)&r6);

  struct Figure.rect r7;
    r7.@x = 333; r7.@y = 3210;
  struct Figure.trian t4;
    t4.@a = 323; t4.@b = 324; t4.@c = 325;
  struct Figure.rect r8;
    r8.@x = 3213; r8.@y = 3220;
  FigureContainerAppend(&c2, (Figure*)&r7);
  FigureContainerAppend(&c1, (Figure*)&t4);
  FigureContainerAppend(&c1, (Figure*)&r8);

  fprintf(stdout, "Using Container as Figure\n");
  FigureOut<(Figure*)&c1>(stdout);

  // Формирование первой контейнерной композиции
  // struct Figure.cont c2;
  // FigureContainerAppend(&c, (Figure*)&c2);
  // struct Figure.rect r1;
  // r1.@x = 3; r1.@y = 10;
  // struct Figure.trian t1;
  // t1.@a = 3; t1.@b = 4; t1.@c = 5;
  // struct Figure.rect r2;
  // r2.@x = 13; r2.@y = 20;
  // FigureContainerAppend(&c2, (Figure*)&r1);
  // FigureContainerAppend(&c2, (Figure*)&t1);
  // FigureContainerAppend(&c2, (Figure*)&r2);

  // struct Figure.cont *pc1 = create_spec(Figure.cont);
  // FigureContainerAppend(&c, (Figure*)&pc1);
  // struct Figure.rect *pr1 = create_spec(Figure.rect);
  // pr1->@x = 30; pr1->@y = 10;
  // struct Figure.trian *pt1 = create_spec(Figure.trian);
  // pt1->@a = 30; pt1->@b = 40; pt1->@c = 50;
  // struct Figure.rect *pr2 = create_spec(Figure.rect);
  // pr2->@x = 130; pr2->@y = 200;
  // FigureContainerAppend(pc1, (Figure*)pr1);
  // FigureContainerAppend(pc1, (Figure*)pt1);
  // FigureContainerAppend(pc1, (Figure*)pr2);

  printf("Stop\n");
  return 0;
}
