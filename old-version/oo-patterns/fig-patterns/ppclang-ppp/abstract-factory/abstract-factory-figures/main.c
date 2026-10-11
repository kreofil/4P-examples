//==============================================================================
// main.c - содержит главную функцию,
// обеспечивающую простое тестирование
//==============================================================================

#include <stdio.h>

#include "figure-factory.h"
#include "rectangle-container.h"
#include "triangle-container.h"

//------------------------------------------------------------------------------
void RectangleContainerInit(RectangleContainer* c) ;
void RectangleContainerClear(RectangleContainer* c);
void RectangleContainerOut(RectangleContainer* c, FILE* ofst);

void TriangleContainerInit(TriangleContainer* c) ;
void TriangleContainerClear(TriangleContainer* c);
void TriangleContainerOut(TriangleContainer* c, FILE* ofst);

// Ввод параметров всех фигур из файла
void FigureCreateAndIn(FILE* ifst, FigureFactory* factory,
                       RectangleContainer* prc, TriangleContainer* ptc);

//------------------------------------------------------------------------------
int main() {
  // В демонстрационном примере данные для формирования семейств фигур
  // размещеены в конкретных файлов с явным указанием путей
  char simpleFigureFile[] = "../data/simple-input1.txt";
  char coordFigureFile[] = "../data/coord-input1.txt";
  char resultFigureFile[] = "../data/output1.txt";

  FILE* ifst_simple = fopen(simpleFigureFile, "r");
  FILE* ifst_coord = fopen(coordFigureFile, "r");
  FILE* ofst = fopen(resultFigureFile, "w");

  struct FigureFactory.simple simpleFactory;
  struct FigureFactory.coord  coordFactory;
  RectangleContainer rc;
  TriangleContainer  tc;

  RectangleContainerInit(&rc);
  TriangleContainerInit(&tc);

  printf("Start\n");

  FigureCreateAndIn(ifst_simple, &simpleFactory, &rc, &tc);
  fclose(ifst_simple);

  fprintf(stdout, "Filled Simple Rectangles.\n");
  RectangleContainerOut(&rc, stdout);
  fprintf(stdout, "Filled Simple Triangles.\n");
  TriangleContainerOut(&tc, stdout);

  fprintf(ofst, "Filled Simple Rectangles.\n");
  RectangleContainerOut(&rc, ofst);
  fprintf(ofst, "Filled Simple Triangles.\n");
  TriangleContainerOut(&tc, ofst);

  FigureCreateAndIn(ifst_coord, &coordFactory, &rc, &tc);
  fclose(ifst_coord);

  fprintf(stdout, "Filled All Rectangles.\n");
  RectangleContainerOut(&rc, stdout);
  fprintf(stdout, "Filled All Triangles.\n");
  TriangleContainerOut(&tc, stdout);

  fprintf(ofst, "Filled All Rectangles.\n");
  RectangleContainerOut(&rc, ofst);
  fprintf(ofst, "Filled All Triangles.\n");
  TriangleContainerOut(&tc, ofst);

  RectangleContainerClear(&rc);
  TriangleContainerClear(&tc);

  fprintf(stdout, "Empty Rectangle Container.\n");
  RectangleContainerOut(&rc, stdout);
  fprintf(stdout, "Empty Triangle Container.\n");
  TriangleContainerOut(&tc, stdout);

  fprintf(ofst, "Empty Rectangle Container.\n");
  RectangleContainerOut(&rc, ofst);
  fprintf(ofst, "Empty Triangle Container.\n");
  TriangleContainerOut(&tc, ofst);

  fclose(ofst);

  printf("Stop\n");
  return 0;
}