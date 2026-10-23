//==============================================================================
// figures-input.c - функция, осуществляющая создание и ввод для всех
// альтернативных фигур. Ввод организован как централизованная функция, которая
// единственная, требующая модификации при вводе данных.
// Но можно тоже сделать эволюционно расширяемой.
//==============================================================================

#include <stdio.h>
#include "figure.h"
#include "figure-factory.h"

//------------------------------------------------------------------------------
// Обобщенная функция ввода любой фигуры
void FigureIn<Figure *f>(FILE* ifst);

//------------------------------------------------------------------------------
// Ввод параметров одной из фигур из файла
Figure* FigureCreateAndIn(FILE* ifst, struct FigureFactory* factory) {
  // printf("FigureCreateAndIn\n");
  struct Figure *pf;  // указатель на фигуру
  int k;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    pf = CreateRectangle<factory>(); // Запуск фабрики прямоугольников
    break;
  case 2:
    pf = CreateTriangle<factory>();  // Запуск фабрики треугольников
    break;
  default:
    return 0;
  }
  // printf("FigureCreateAndIn: before FigureIn\n");
  FigureIn<pf>(ifst);
  // printf("FigureCreateAndIn: after FigureIn\n");
  return pf;
}
