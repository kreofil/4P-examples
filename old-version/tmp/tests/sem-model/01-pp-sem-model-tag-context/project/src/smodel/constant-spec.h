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
typedef struct ConstantInt {int constValue;} ConstantInt;
// Специализация целочисленной константы
Constant + <integer: ConstantInt;>;

//------------------------------------------------------------------------------
// Функция вывода значения целочисленной константы
void DebugOutOfConstant<Constant<integer>* constant>(FILE* file);

#endif // __constant_spec__
