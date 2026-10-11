// Figure.cpp - Реализация функций, поддерживающих работу с базовой фигурой.
// В основном это функции и данные фабрики абстрактной фигуры.

#include <iostream>
#include "figure-creator.h"

// Первоначальный список зарегистрированных фабрик пуст.
// Поэтому указатель обнулен.
FigureCreator* FigureCreator::top = nullptr;

// Конструктор, обеспечивающий начальную расстановку элементов в стеке и их ранжирование
FigureCreator::FigureCreator(int m): mark(m) {
  this->next = top;
  top = this;
}

//------------------------------------------------------------------------------
// Реализация метода, обеспечивающего создание фигуры по ее признаку,
// который задается при вводе из файла или из консоли (при реализации).
Figure* FigureCreator::Make(int key) {
  // Указатель, фиксирующий созданную фигуру
  Figure* f = nullptr;
  // Формирование указателя для обхода
  FigureCreator* tmp = top;

  // Обход фабрик в стеке до той, у которой ключ совпадает с искомым
  while (tmp) {
    f = tmp->CreateFigure(key);
    // При создании фигуры обход завершается
    if(f) return f;
    tmp = tmp->next;
  }
  return nullptr;
}

// иденитфикация, порождение и ввод фигуры из потока
Figure* FigureCreator::In(std::ifstream &ifst) {
  Figure *pf = nullptr;
  int k;
  ifst >> k;
  pf = Make(k);
  if(pf)
    pf->InData(ifst);
  return pf;

}
