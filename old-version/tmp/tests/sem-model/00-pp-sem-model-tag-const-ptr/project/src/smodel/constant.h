#ifndef __constant__
#define __constant__
// constant.h
// Объявление обобщенной константы, используемой в семантической модели,
// а также прототипов обобщенных функций, обеспечивающих ее обработку

#include <stdio.h>

//------------------------------------------------------------------------------
// Обобщенная константа
// typedef struct Constant {}< : > Constant;
// Основа целочисленной константы
typedef struct ConstantInt {int constValue;} ConstantInt;
// Специализация целочисленной константы
// Constant + <integerPtr: ConstantInt*;>;
typedef struct Constant {}<integerPtr: ConstantInt*;> Constant;

//==============================================================================
// Функции для работы со значением

// Обобщенная функция вывода значения константы
void DebugOutOfConstant<struct Constant* constant>(FILE* file);

#endif // __constant__
