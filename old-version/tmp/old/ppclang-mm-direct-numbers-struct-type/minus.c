//------------------------------------------------------------------------------
// Файл minus.cpp - задает функцию.вычитания
//------------------------------------------------------------------------------

#include <stdio.h>
#include "int.h"
#include "double.h"

//------------------------------------------------------------------------------
// Мультиметод реализующий вычитание чисел
Number* Sub<Number* n1, Number* n2>() {
  return NULL;
};
// Обработчик комбинации int-int
Number* Sub<Number.Int* n1, Number.Int* n2>() {
  struct Number.Int* result = create_spec(Number.Int);
  result->@value = n1->@value - n2->@value;
  return (Number*)result;
}
// Обработчик комбинации int-double
Number* Sub<Number.Int* n1, Number.Double* n2>() {
  struct Number.Double* result = create_spec(Number.Double);
  result->@value = (double)(n1->@value) - n2->@value;
  return (Number*)result;
}
// Обработчик комбинации double-int
Number* Sub<Number.Double* n1, Number.Int* n2>() {
  struct Number.Double* result = create_spec(Number.Double);
  result->@value = n1->@value - (double)(n2->@value);
  return (Number*)result;
}
// Обработчик комбинации double-double
Number* Sub<Number.Double* n1, Number.Double* n2>() {
  struct Number.Double* result = create_spec(Number.Double);
  result->@value = n1->@value - n2->@value;
  return (Number*)result;
}

//------------------------------------------------------------------------------
// Функция вычитания, являющаяся оболочкой над мультиметдом
Number* Subtract (Number* n1, Number* n2) {
  return Sub<n1, n2>();
}

