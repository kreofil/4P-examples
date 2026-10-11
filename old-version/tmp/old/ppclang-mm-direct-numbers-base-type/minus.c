//------------------------------------------------------------------------------
// Файл minus.cpp - задает функцию.вычитания
//------------------------------------------------------------------------------

#include <stdio.h>
#include "int.h"
// #include "double.h"

//------------------------------------------------------------------------------
// Мультиметод реализующий вычитание чисел
Number* Sub<Number* n1, Number* n2>() {
  return NULL;
};
// Обработчик комбинации int-int
Number* Sub<Number.int* n1, Number.int* n2>() {
  struct Number.int* result = create_spec(Number.int);
  result->@ = n1->@ - n2->@;
  return (Number*)result;
}

// Обработчик комбинации int-double
Number* Sub<Number.int* n1, Number.double* n2>() {
  struct Number.double* result = create_spec(Number.double);
  result->@value = (double)(n1->@) - n2->@value;
  return (Number*)result;
}
// Обработчик комбинации double-int
Number* Sub<Number.double* n1, Number.int* n2>() {
  struct Number.double* result = create_spec(Number.double);
  result->@value = n1->@value - (double)(n2->@);
  return (Number*)result;
}
// Обработчик комбинации double-double
Number* Sub<Number.double* n1, Number.double* n2>() {
  struct Number.double* result = create_spec(Number.double);
  result->@value = n1->@value - n2->@value;
  return (Number*)result;
}

//------------------------------------------------------------------------------
// Функция вычитания, являющаяся оболочкой над мультиметдом
Number* Subtract (Number* n1, Number* n2) {
  return Sub<n1, n2>();
}

