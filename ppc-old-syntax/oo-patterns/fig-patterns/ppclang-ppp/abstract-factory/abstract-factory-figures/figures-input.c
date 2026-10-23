//==============================================================================
// figures-input.c - функция, осуществляющая создание и ввод для всех
// альтернативных фигур. Ввод организован как централизованная функция, которая
// единственная, требующая модификации при вводе данных.
// Но можно тоже сделать эволюционно расширяемой.
// Вводимые данные сразу распределяются по контейнерам
//==============================================================================

#include <stdio.h>
#include <stdlib.h>
#include "figure-factory.h"
#include "rectangle-container.h"
#include "triangle-container.h"

//------------------------------------------------------------------------------
// Прототипы обработчиков специализаций, используемых при вводе фигур
void RectangleIn<Rectangle *r>(FILE* ifst);
void TriangleIn<Triangle *r>(FILE* ifst);
void RectangleContainerIn(RectangleContainer* c, Rectangle* rectangle);
void TriangleContainerIn(TriangleContainer* c, Triangle* triangle);

//------------------------------------------------------------------------------
// Ввод параметров всех фигур из файла
void FigureCreateAndIn(FILE* ifst, FigureFactory* factory,
                       RectangleContainer* prc, TriangleContainer* ptc) {
  Rectangle *r;
  Triangle  *t;
  int k;
  while(!feof(ifst))  {
    fscanf(ifst, "%d", &(k));
    switch(k) {
    case 1:
      r = CreateRectangle<factory>(); // Запуск фабрики прямоугольников
      RectangleIn<r>(ifst);
      RectangleContainerIn(prc, r);
      break;
    case 2:
      t = CreateTriangle<factory>();  // Запуск фабрики треугольников
      TriangleIn<t>(ifst);
      TriangleContainerIn(ptc, t);
      break;
    default:
      perror("Incorrect Figure in FigureCreateAndIn\n");
      exit(1);
    }
  }
}
