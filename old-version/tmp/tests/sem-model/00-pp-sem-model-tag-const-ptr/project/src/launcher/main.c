// main.c
#include <stdio.h>
#include "constant-spec.h"

void test_type_tag(struct Constant* f) {
    printf("Tag = %d\n", f->__pp_specialization_type);
}

// Резмещение специализированной целочисленной константы на стеке
struct Constant<integerPtr> pIntConstExt;

int main(void) {
  printf("Start\n");

  struct Constant<integerPtr> *pIntConstDyn = CreateConstInt(600);
  // printf("Testout 4: %d\n", pIntConstDyn->@constValue);
  DebugOutOfConstant<pIntConstDyn>(stdout);

  printf("Finish\n");
  return 0;
} // end main

