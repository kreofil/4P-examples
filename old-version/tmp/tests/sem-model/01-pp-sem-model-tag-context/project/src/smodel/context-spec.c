
// Определения функций, обеспечивающих обработку контекста.

#include <string.h>
#include "constant-spec.h"
#include "context-spec.h"

//==============================================================================
// Обобщенные функции для обработки контекста
//==============================================================================

//------------------------------------------------------------------------------
// Функция вывода содержимого контекста
void DebugOutOfContext<struct Context* context>(FILE* file) {
  fprintf(file, "Unknown context\n");
}

//==============================================================================
// Функции для обработки контекста константы
//==============================================================================

//------------------------------------------------------------------------------
// Функция вывода значения контекста константы
void DebugOutOfContext<struct Context<constant>* context>(FILE* file) {
  printf("Check point: constant context ---> ");
  // struct Context<constant>* pContext = &context->@;
  // DebugOutOfConstant<pContext>(file);
  DebugOutOfConstant<&(context->@)>(file);
}

//------------------------------------------------------------------------------
// Функция, создающая контекст для именованной целочисленной константы
Context* CreateContextConstInt(char* name, int value) {
  struct Context<constant<integer> > *context =
          create_spec(Context<constant<integer> >);
  strcpy(context->name, name);
  context->@.@constValue = value;
  return (Context*)context;
}
