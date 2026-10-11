// constant-spec.h
#ifndef __constant_spec__
#define __constant_spec__
// constant-spec.h
// Объявления констан - основ специализаций и построенных из них специализаций,
// а также прототипов обобщенных функций, обеспечивающих их обработку

// #include <stdio.h>
#include "constant.h"

//==============================================================================
// Основа целочисленной константы
// typedef struct ConstantInt {int constValue;} ConstantInt;
// Специализация целочисленной константы
// Constant + <integerPtr: ConstantInt*;>;

//------------------------------------------------------------------------------
// Функция вывода значения целочисленной константы
void DebugOutOfConstant<Constant<integerPtr>* constant>(FILE* file);

// Функция создания целочисленнокй контстанты в куче
Constant *CreateConstInt(int constValue);

#endif // __constant_spec__
