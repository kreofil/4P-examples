// Определения функций, обеспечивающих обработку констант.

#include "constant-spec.h"

//==============================================================================
// Обобщенные функции для обработки константы
//==============================================================================

//------------------------------------------------------------------------------
// Функция вывода значения целочисленной константы
void DebugOutOfConstant<struct Constant* constant>(FILE* file) {
  fprintf(file, "Unknown constant\n");
}

//==============================================================================
// Функции для обработки целочисленной константы
//==============================================================================

//------------------------------------------------------------------------------
// Функция вывода значения целочисленной константы
void DebugOutOfConstant<struct Constant<integerPtr>* constant>(FILE* file) {
  printf("Check point const int\n");
  fprintf(file, "const int = %d\n", (constant->@)->constValue);
}

//------------------------------------------------------------------------------
// Функция создания целочисленнокй контстанты в куче
Constant *CreateConstInt(int constValue) {
  struct Constant<integerPtr> *pConstant = create_spec(Constant<integerPtr>);
  ConstantInt* pConstantInt = malloc(sizeof(ConstantInt));
  pConstantInt->constValue = constValue;
  pConstant->@ = pConstantInt;
  return pConstant;
}
