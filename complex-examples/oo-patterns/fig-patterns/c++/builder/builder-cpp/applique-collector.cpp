//------------------------------------------------------------------------------
// applique-collector.cpp - содержит методо формирования аппликации
// простого домика
//------------------------------------------------------------------------------

#include "applique-collector.h"

//------------------------------------------------------------------------------
// Класс, формирующий аппликацию.

void AppliqueCollector::Collect(std::ofstream &ofst, Builder* builder) {
  builder->BuildRectangle(20, 15);      // окно
  builder->BuildRectangle(100, 80);     // здание
  builder->BuildRectangle(20, 60);     // дверь
  builder->BuildTriangle(120, 80, 70);  // крыша
  // builder->Out(ofst);
}