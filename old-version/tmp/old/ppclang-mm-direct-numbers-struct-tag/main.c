//------------------------------------------------------------------------------
// Файл main.cpp - задает тестовую функцию.
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "int.h"
#include "double.h"

// Функция вычитания, использующая множественный полиморфизм.
Number* Subtract(Number* n1, Number* n2);

// Маленький тест.
int main(void) {
  Number* rez;
  struct Number.Int i1;
  i1.@value = 10;
  StdOut<(Number*)&i1>();

  struct Number.Int i2;
  i2.@value = 3;
  StdOut<(Number*)&i2>();

  struct Number.Double d1;
  d1.@value =  3.14;
  StdOut<(Number*)&d1>();

  struct Number.Double d2;
  d2.@value =  2.7;
  StdOut<(Number*)&d2>();

  rez = Subtract((Number*)&i1, (Number*)&i2);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&i2, (Number*)&i1);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&d1, (Number*)&d2);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&d2, (Number*)&d1);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&i1, (Number*)&d2);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&i2, (Number*)&d1);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&d1, (Number*)&i2);   StdOut<rez>(); free(rez);
  rez = Subtract((Number*)&d2, (Number*)&i1);   StdOut<rez>(); free(rez);

  return 0;
}