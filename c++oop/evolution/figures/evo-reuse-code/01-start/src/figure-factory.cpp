// figure-factory.cpp - реализация функции обобщенной фабрики фигур

#include "figure.h"
#include "figure-factory.h"

//------------------------------------------------------------------------------
// Начальная инициализация числа зарегистрированных фабрик
int FigureFactory::counter = 0;
FigureFactory* FigureFactory::factory[10];

//------------------------------------------------------------------------------
// Реализация метода обхода зарегистрированных фабрик
Figure* FigureFactory::Create(std::ifstream &ifst) {
  int k;
  ifst >> k;
  for(int i = 0; i < FigureFactory::counter; ++i) {
    Figure* f = factory[i]->Test(k);
    if(f != nullptr) {
      f->In(ifst);
      // f->Out();
      return f;
    }
  }
  return nullptr;
}
