//------------------------------------------------------------------------------
// main.cpp - содержит главную функцию,
// обеспечивающую простое тестирование
//------------------------------------------------------------------------------

#include <iostream>

#include "applique-collector.h"
#include "simple-figures-builder.h"
#include "figures-counter-builder.h"

//------------------------------------------------------------------------------
int main()
{
  // В демонстрационном примере формируется набор фигур, позволяющих
  // собрать аппликаци простого домика (размер не имеет значения)
  char resultFigureFile[] = "../data/output1.txt";
  std::ofstream ofst(resultFigureFile);
  FigureContainer container;
  SimpleBuilder simpleBuilder{&container};
  CounterBuilder counterBuilder;

  std::cout << "Start\n";

  AppliqueCollector::Collect(ofst, &simpleBuilder);
  simpleBuilder.ResultOut(ofst);

  container.Clear();

  AppliqueCollector::Collect(ofst, &counterBuilder);
  counterBuilder.ResultOut(ofst);

  std::cout << "Stop\n";
  return 0;
}