#ifndef __context_spec__
#define __context_spec__
// context-spec.h
// Объявления контекстов - основ специализаций и построенных из них специализаций,
// а также прототипов обобщенных функций, обеспечивающих их обработку

// #include <stdio.h>
#include "constant.h"
#include "context.h"

//==============================================================================
// Специализация контекста константы
Context + <constant: Constant;>;

//------------------------------------------------------------------------------
// Функция вывода значения контекста константы
void DebugOutOfContext<Context<constant>* context>(FILE* file);

// Функция, создающая контекст для именованной целочисленной константы
Context* CreateContextConstInt(char* name, int value);
#endif // __context_spec__
