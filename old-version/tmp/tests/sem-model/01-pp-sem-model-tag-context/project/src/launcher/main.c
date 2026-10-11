// main.c
#include <stdio.h>
#include "constant-spec.h"
#include "context-spec.h"

struct Constant<integer> intConstExt;
// struct Context<constant<integer> > intConstContextExt;


int main(void) {
  printf("Start\n");

  intConstExt.@constValue = 20;
  DebugOutOfConstant<&intConstExt>(stdout);

  struct Constant<integer> intConst;
  intConst.@constValue = 10;
  DebugOutOfConstant<&intConst>(stdout);

  struct Context<constant<integer> > intConstContext;
  intConstContext.@.@constValue = 10000;
  printf("Value test out: %d\n", intConstContext.@.@constValue);

  struct Context<constant<integer> > *pIntConstContext =
          CreateContextConstInt("Hello", 500);
  printf("Value test out: %d\n", pIntConstContext->@.@constValue);
  DebugOutOfContext<pIntConstContext>(stdout);
  free(pIntConstContext);

  pIntConstContext =
        create_spec(Context<constant<integer> >);
  pIntConstContext->@.@constValue = 20000;
  printf("Value test out: %d\n", pIntConstContext->@.@constValue);
  DebugOutOfContext<pIntConstContext>(stdout);

  struct Context<constant> *pConst = &pIntConstContext->@;
  DebugOutOfConstant<pConst>(stdout);

  DebugOutOfContext<pIntConstContext>(stdout);
  free(pIntConstContext);

  intConstContext.@.@constValue = 40000;
  pIntConstContext = &intConstContext;
  printf("Value test out: %d\n", intConstContext.@.@constValue);
  // DebugOutOfContext<pIntConstContext>(stdout);

  // intConstContextExt.@.@constValue = 30000;
  // pIntConstContext = &intConstContextExt;
  // DebugOutOfContext<pIntConstContext>(stdout);

  // pConst = &(intConstContext.@);
  // DebugOutOfConstant<pConst>(stdout);
  // DebugOutOfContext<&intConstContext>(stdout);

  printf("Finish\n");
  return 0;
} // end main

