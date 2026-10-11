#ifndef __vector__
#define __vector__
// vector.h
// Объявление структур и  базовых функций, связанных с обработкой вектора
// на основе одномерного массива

#include <stdio.h>
#include <stddef.h>
#include "value.h"

enum {maxLen = 100}; // максимальная длина вектора значений

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного вектора
typedef struct Vector {
  int len;      // текущее число элементов
  int current;  // текущий элемент
  int size;     // Максимальный размер формируемого вектора (в начале maxLen)
  int valSize;  // Размер значения (на всякий случай)
  Value* value; // Динамически создаваемый массив полиморфных аргументов
} Vector;


//==============================================================================
// Функции для работы с вектором

// Начальная инициализация вектора
void InitVector(Vector* vector);

// Добавление значения к концу вектора
void AppendVector(Vector* vector, Value* value);

// Удаление последнего элемента вектора
void DeleteTailOfVector(Vector* vector);

// Удаление всех элементов вектора (очистка от данных)
void EmptyVector(Vector* vector);

// Вывод элементов вектора в указанный поток
void OutVectorValues(FILE* file, Vector* vector);

// Вывод значения указанного элемента вектора
void OutCurrentVectorValue(FILE* file, Value* value);

#endif // __vector__