//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "builder.h"
#include "figure-container.h"

void AppliqueCollector(FILE* ofst, Builder* builder);

//------------------------------------------------------------------------------
int main() {
  // В демонстрационном примере данные для формирования семейств фигур
  // размещены в конкретных файлах с явным указанием путей
  char resultFigureFile[] = "../data/output1.txt";
  FILE* ofst = fopen(resultFigureFile, "w");

  FigureContainer container;
  FigureContainerInit(&container);

  struct Builder.SimpleBuilder simpleBuilder;
  simpleBuilder.@container = &container;

  struct Builder.CounterBuilder counterBuilder;
  counterBuilder.@rectanglesCounter = 0;
  counterBuilder.@trianglesCounter = 0;

  printf("Start\n");

  AppliqueCollector(ofst, (Builder*)&simpleBuilder);
  ResultOut<(Builder*)&simpleBuilder>(ofst);
  FigureContainerClear(&container);

  AppliqueCollector(ofst, (Builder*)&counterBuilder);
  ResultOut<(Builder*)&counterBuilder>(ofst);

  printf("Stop\n");
  return 0;
}