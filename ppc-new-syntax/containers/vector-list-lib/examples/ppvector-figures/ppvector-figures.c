#include <stdlib.h>
#include <stdio.h>
#include "ppvector.h"
#include "figure-rectangle.h"
#include "figure-triangle.h"

//==============================================================================
// Все, что сопровождает формируемую специализацию вектора
//==============================================================================

// Cпециализация вектора как указателей на обобщенные фигуры
ppVector+{Figure* figure_ptr;};
// Прототип обобщеннай функции вывода фигуры
void FigureOut<Figure *f>(FILE* ofst);

//------------------------------------------------------------------------------
// Обработчик специализации, обеспечивающий вывод фигуры через указатель на нее
void ppVector_element_print<ppVector.figure_ptr* v>(FILE* f) {
  FigureOut<v->figure_ptr>(stdout);
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
  Figure.rect r1 = {10, 20};
  Figure.trian t1 = {3, 4, 5};
  Figure.rect r2 = {1, 2};
  Figure.trian t2 = {13, 14, 15};
  Figure.rect r3 = {100, 20};
  Figure.trian t3 = {1, 1, 1};
  Figure.rect r4 = {20, 10};
  Figure.trian t4 = {30, 40, 50};
  Figure.rect r5 = {101, 1};
  Figure.trian t5 = {31, 41, 51};

  ppVector_PUSH_BACK(figures, figure_ptr, &r1)
  ppVector_PUSH_BACK(figures, figure_ptr, &r2)
  ppVector_PUSH_BACK(figures, figure_ptr, &r3)
  ppVector_PUSH_BACK(figures, figure_ptr, &r4)
  ppVector_PUSH_BACK(figures, figure_ptr, &r5)
  ppVector_PUSH_BACK(figures, figure_ptr, &t1)
  ppVector_PUSH_BACK(figures, figure_ptr, &t2)
  ppVector_PUSH_BACK(figures, figure_ptr, &t3)
  ppVector_PUSH_BACK(figures, figure_ptr, &t4)
  ppVector_PUSH_BACK(figures, figure_ptr, &t5)

  ppVector_print(stdout, (ppVector*)&figures);

  // Вызов функции сортировки
  ppVector_sort<(ppVector*)&figures>();
  // Тестовый вывод отсортированного вектора
  ppVector_print(stdout, (ppVector*)&figures);

  ppVector_destroy((ppVector*)&figures);
  // Отсутствует возможность прямого использования указателя на специализацию
  // в "?" выражении. Поэтому реализовал через присваивание
  Figure* p = figures.figure_ptr;
  printf("value = %s; size = %u; capacity = %u\n",
         (p == NULL) ? "NULL" : "It's Impossible!!!",
         ppVector_size((ppVector*)&figures),
         ppVector_capacity((ppVector*)&figures)
  );

  return 0;
} // end main

