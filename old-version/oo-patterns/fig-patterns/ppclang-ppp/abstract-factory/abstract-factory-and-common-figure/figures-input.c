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
// Прототипы обработчиков специализаций, используемых при вводе фигур
void RectangleIn<Rectangle *r>(FILE* ifst);
void TriangleIn<Triangle *r>(FILE* ifst);

//------------------------------------------------------------------------------
// Ввод параметров одной из фигур из файла
Figure* FigureCreateAndIn(FILE* ifst, struct FigureFactory* factory) {
  struct Figure.rect *pr;   // указатель на специализированный прямоугольник
  struct Figure.trian *pt;  // указатель на специализированный треугольник
  Rectangle *r;
  Triangle  *t;
  int k;
  fscanf(ifst, "%d", &(k));
  switch(k) {
  case 1:
    pr = create_spec(Figure.rect);     // Создается оболочка
    r = CreateRectangle<factory>(); // Запуск фабрики прямоугольников
    RectangleIn<r>(ifst);
    pr->@ = r;
    return (Figure*)pr;
  case 2:
    pt = create_spec(Figure.trian);    // Создается оболочка
    t = CreateTriangle<factory>();  // Запуск фабрики треугольников
    TriangleIn<t>(ifst);
    pt->@ = t;
    return (Figure*)pt;
  default:
    return 0;
  }
}
