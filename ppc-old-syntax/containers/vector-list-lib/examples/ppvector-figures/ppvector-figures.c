#include <stdlib.h>
#include <stdio.h>
#include "ppvector.h"
#include "figure-rectangle.h"
#include "figure-triangle.h"

//==============================================================================
// Все, что сопровождает формируемую специализацию вектора
//==============================================================================

// Cпециализация вектора как указателей на обобщенные фигуры
ppVector+<figure_ptr:Figure*;>;
// Прототип обобщеннай функции вывода фигуры
void FigureOut<Figure *f>(FILE* ofst);

//------------------------------------------------------------------------------
// Обработчик специализации, обеспечивающий вывод фигуры через указатель на нее
void ppVector_element_print<ppVector.figure_ptr* v>(FILE* f) {
  FigureOut<v->@>(stdout);
}

//------------------------------------------------------------------------------
// Прототип обобщенной функции вычисление периметра для текущей фигуры
double FigurePerimeter<Figure *f>();

//------------------------------------------------------------------------------
// Функция, используемая для сравнения фигур по длине переметра
int cmp_figure_perimeter(const void *pf1, const void *pf2) {
  Figure* f1 = *(Figure**)pf1;
  Figure* f2 = *(Figure**)pf2;
  double p1 = FigurePerimeter<f1>();
  double p2 = FigurePerimeter<f2>();
  return (int)(p1 - p2);
}

//------------------------------------------------------------------------------
// Обработчик специализации, осуществляющий обработку целочисленного вектора
void ppVector_sort<ppVector.figure_ptr* v>()  {
  // Получение указателя на массив указателей на целые чисел
  void* v_ptr = ppVector_data((ppVector*)v);
  qsort(v_ptr, ppVector_size((ppVector*)v), sizeof(Figure*), cmp_figure_perimeter);
}

//==============================================================================
// Тестовая функция
//==============================================================================

//------------------------------------------------------------------------------
int main(void) {
  ppVector_VAR(figure_ptr, figures)
  struct Figure.rect r1;  r1.@x = 10;   r1.@y = 20;
  struct Figure.trian t1; t1.@a = 3;    t1.@b = 4;  t1.@c = 5;
  struct Figure.rect r2;  r2.@x = 1;    r2.@y = 2;
  struct Figure.trian t2; t2.@a = 13;   t2.@b = 14; t2.@c = 15;
  struct Figure.rect r3;  r3.@x = 100;  r3.@y = 20;
  struct Figure.trian t3; t3.@a = 1;    t3.@b = 1;  t3.@c = 1;
  struct Figure.rect r4;  r4.@x = 20;   r4.@y = 10;
  struct Figure.trian t4; t4.@a = 30;   t4.@b = 40; t4.@c = 50;
  struct Figure.rect r5;  r5.@x = 101;  r5.@y = 1;
  struct Figure.trian t5; t5.@a = 31;   t5.@b = 41; t5.@c = 51;

  ppVector_PUSH_BACK(figures, (Figure*)&r1)
  ppVector_PUSH_BACK(figures, (Figure*)&r2)
  ppVector_PUSH_BACK(figures, (Figure*)&r3)
  ppVector_PUSH_BACK(figures, (Figure*)&r4)
  ppVector_PUSH_BACK(figures, (Figure*)&r5)
  ppVector_PUSH_BACK(figures, (Figure*)&t1)
  ppVector_PUSH_BACK(figures, (Figure*)&t2)
  ppVector_PUSH_BACK(figures, (Figure*)&t3)
  ppVector_PUSH_BACK(figures, (Figure*)&t4)
  ppVector_PUSH_BACK(figures, (Figure*)&t5)

  ppVector_print(stdout, (ppVector*)&figures);

  // Вызов функции сортировки
  ppVector_sort<(ppVector*)&figures>();
  // Тестовый вывод отсортированного вектора
  ppVector_print(stdout, (ppVector*)&figures);

  ppVector_destroy((ppVector*)&figures);
  // Отсутствует возможность прямого использования указателя на специализацию
  // в "?" выражении. Поэтому реализовал через присваивание
  Figure* p = figures.@;
  printf("value = %s; size = %u; capacity = %u\n",
         (p == NULL) ? "NULL" : "It's Impossible!!!",
         ppVector_size((ppVector*)&figures),
         ppVector_capacity((ppVector*)&figures)
  );

  return 0;
} // end main

