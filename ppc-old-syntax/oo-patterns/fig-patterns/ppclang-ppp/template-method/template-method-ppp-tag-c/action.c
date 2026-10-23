//==============================================================================
// action.c - реализация обобщенных функций, определяющих действия над фигурами
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "action.h"

//==============================================================================
// Проверка того, что тэг из файла, совпадает с признаком предполагаемой фигуры
bool isFigure<Action *a>(int tag) {
  perror("It is impossible to use generalized function isFigure!\n");
  exit(1);
}

//------------------------------------------------------------------------------
// Обработчик, проверяющий, что это признак прямоугольника
bool isFigure<Action.rectangle *a>(int tag) {
  if(tag == 1) {return true;}
  return false;
}

//------------------------------------------------------------------------------
// Обработчик, проверяющий, что это признак треугольника
bool isFigure<Action.triangle *a>(int tag) {
  if(tag == 2) {return true;}
  return false;
}

//==============================================================================
// Создание специализированнойй фигуры с возвратом обобщенного указателя
Figure* CreateFigure<Action *a>() {
  perror("It is impossible to use generalized function CreateFigure!\n");
  exit(1);
}

//------------------------------------------------------------------------------
// Обработчик, порождающий прямоугольник
Figure* CreateFigure<Action.rectangle *a>() {
  Figure *pf = create_spec(Action.rectangle);
  return pf;
}

//------------------------------------------------------------------------------
// Обработчик, порождающий треугольник
Figure* CreateFigure<Action.triangle *a>() {
  Figure *pf = create_spec(Action.triangle);
  return pf;
}

//==============================================================================
// Обобщенная функция, осуществляющая ввод конкретной фигуры из
// заданного файла. Использует внутри другие функции.
// Определяет шаблонный метод, включающий другие обобщенные функции,
// а также общие функции
Figure* InputConcreteFigure<Action *a>(char* fileName) {
  perror("It is impossible to use generalized function InputConcreteFigure!\n");
  exit(1);
}

//------------------------------------------------------------------------------
// Прототип обобщеннай функции ввода фигуры
void FigureIn<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Обработчик, предназначенный для ввода из файла прямоугольника
Figure* InputConcreteFigure<Action.rectangle *a>(char* fileName) {
  FILE* ifst = fopen(fileName, "r");
  int k = 0;
  if(ifst == NULL) {
    printf("Incorrect file name %s\n", fileName);
    exit(5);
  }
  fscanf(ifst, "%d", &(k));
  if(!isFigure<(Action*)a>(k)) {
    // Это не признак прямоугольника
    return NULL;
  }
  Figure *pf = CreateFigure<(Action*)a>();
  FigureIn<pf>(ifst);
  fclose(ifst);
  return pf;
}

//------------------------------------------------------------------------------
// Обработчик, предназначенный для ввода из файла треугольника
Figure* InputConcreteFigure<Action.triangle *a>(char* fileName) {
  FILE* ifst = fopen(fileName, "r");
  if(ifst == NULL) {
    printf("Incorrect file name %s\n", fileName);
    exit(5);
  }
  int k = 0;
  fscanf(ifst, "%d", &(k));
  if(!isFigure<(Action*)a>(k)) {
    // Это не признак треугольника
    return NULL;
  }
  Figure *pf = CreateFigure<(Action*)a>();
  FigureIn<pf>(ifst);
  fclose(ifst);
  return pf;
}
