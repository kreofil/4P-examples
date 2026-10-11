// vector.c
// Реализация базовых функций, связанных с обработкой вектора
// на основе одномерного массива

#include <stdio.h>
#include <stdlib.h>
#include "vector.h"

// Начальная инициализация вектора. Связана с установкой признака специализации
// Пока не проработано
void InitVector(Vector* vector) {
  vector->len = 0;
  vector->current = -1;
  // for(int i = 0; i < maxLen; ++i) {
  //   vector->value[i] = NULL;
  // }
}

//------------------------------------------------------------------------------
// Добавление значения к концу вектора
void AppendVector(Vector* vector, Value* value) {
  if(vector->len < maxLen) {
    vector->value[vector->len++] = value;
  } else {
    perror("Vector Overflow\n");
    exit(-1);
  }
}

//------------------------------------------------------------------------------
// Удаление элемента из хвоста вектора с его сохранением
Value* DeleteTailOfVector(Vector* vector) {
  if(vector->len <= 0) {
    return NULL;   // элементы отсутствуют
  }
  Value* value = vector->value[vector->len];
  vector->value[vector->len--] = NULL;
  return value;
}

//------------------------------------------------------------------------------
// Удаление всех элементов вектора (очистка от данных)
void EmptyVector(Vector* vector) {
  for(int i = 0; i < vector->len; ++i) {
    free(vector->value[i]);
  }
  vector->len = 0;
}

//------------------------------------------------------------------------------
// Вывод значения указанного элемента, из данного узла
void OutCurrentVectorValue(FILE* file, Value* value) {
  if(value == NULL) { // Элемент отсутствует
    fprintf(file, "Element is absent! ");
  } else {
    OutValue<value>(file);
  }
}

//------------------------------------------------------------------------------
// Вывод элементов вектора в указанный файл, который
// должен быть предварително открыт
void OutVectorValues(FILE* file, Vector* vector) {
  if(vector->len == 0) {
    fprintf(file, "Empty Vector of Values\n");
    return;
  }
  fprintf(file, "Vector of Values is:\n");
  for(int i = 0; i < vector->len; ++i) {
    fprintf(file, "    ");
    OutCurrentVectorValue(file, vector->value[i]);
    fprintf(file, "\n");
  }
}
