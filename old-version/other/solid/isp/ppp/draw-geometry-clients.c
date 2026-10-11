//==============================================================================
// Реализации функций клиентов, использующих рисование и раздельное вычисление
// периметров и площадей
//==============================================================================

#include <stdio.h>
#include "container.h"

// Прототипы функций, используемых для организации вычислений
void ContainerOut(Container* c, FILE* ofst);
void ContainerPerimeterOut(Container* c, FILE* ofst);
void ContainerAreaOut(Container* c, FILE* ofst);


//------------------------------------------------------------------------------
// Рисование и вычисление периметров соответствующим клиентом
void DrawAndCalcPerimeters(Container* c, FILE* ofst) {
  fprintf(ofst, "\n    DrawAndCalcPerimeters:\n");
  ContainerOut(c, ofst);
  ContainerPerimeterOut(c, ofst);
}

//------------------------------------------------------------------------------
// Рисование и вычисление площадей соответствующим клиентом
void DrawAndCalcAreas(Container* c, FILE* ofst) {
  fprintf(ofst, "\n    DrawAndCalcAreas:\n");
  ContainerOut(c, ofst);
  ContainerAreaOut(c, ofst);
}
