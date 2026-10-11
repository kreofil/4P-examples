// main.c
#include <stdio.h>
#include "constant-spec.h"

void test_type_tag(struct Constant* f) {
    printf("Tag = %d\n", f->__pp_specialization_type);
}

// Резмещение специализированной целочисленной константы на стеке
struct Constant<integer> intConstExt;

int main(void) {
  printf("Start\n");

  // Для специализаций, размещенных во внешней памяти не работает
  intConstExt.@constValue = 20;
  printf("Testout 1: %d\n", intConstExt.@constValue);
  test_type_tag(&intConstExt);
  DebugOutOfConstant<&intConstExt>(stdout);

  // Резмещение специализированной целочисленной константы на стеке
  struct Constant<integer> intConstAuto;
  intConstAuto.@constValue = 10;
  printf("Testout 2: %d\n", intConstAuto.@constValue);
  test_type_tag(&intConstAuto);
  DebugOutOfConstant<&intConstAuto>(stdout);

  // Резмещение специализированной целочисленной константы на куче
  struct Constant<integer> *pIntConstDyn = create_spec(Constant<integer>);
  pIntConstDyn->@constValue = 30;
  printf("Testout 3: %d\n", pIntConstDyn->@constValue);
  test_type_tag(pIntConstDyn);
  DebugOutOfConstant<pIntConstDyn>(stdout);
  free(pIntConstDyn);

  pIntConstDyn = &intConstExt;
  pIntConstDyn->@constValue = 40;
  printf("Testout 4: %d\n", pIntConstDyn->@constValue);
  printf("Testout 5: %d\n", intConstExt.@constValue);
  test_type_tag(pIntConstDyn);
  test_type_tag(&intConstExt);
  DebugOutOfConstant<pIntConstDyn>(stdout);

  pIntConstDyn = CreateConstInt(500);
  printf("Testout 4: %d\n", pIntConstDyn->@constValue);
  DebugOutOfConstant<pIntConstDyn>(stdout);

  printf("Finish\n");
  return 0;
} // end main

