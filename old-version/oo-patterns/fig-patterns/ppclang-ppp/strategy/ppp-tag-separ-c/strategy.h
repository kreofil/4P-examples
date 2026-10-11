#ifndef __strategy__
#define __strategy__

//==============================================================================
// strategy.h - Описание стратегий и прототипов функций, обеспечивающим
// различные операции над контейнером фигур.
//==============================================================================

#include "container.h"
// struct Container;

//------------------------------------------------------------------------------
// Различные стратегии задаются расширяемыми перечислениями
// вместо использования классов
// typedef struct Strategy {} <out, perimeter: void;> Strategy;

typedef struct Strategy {} <> Strategy;
Strategy + <out: void;>;
Strategy + <perimeter: void;>;

// Функция запуска одной из стратегий
void RunStrategy<struct Strategy *s>(struct Container* c);

#endif // __strategy__

