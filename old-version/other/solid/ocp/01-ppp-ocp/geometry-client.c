#ifndef __geometry_client__
#define __geometry_client__

//==============================================================================
// geometry-client.c - содержит спрятанную реализацию клиента,
// осуществляющего геометрические вычисления.
//==============================================================================

#include <stdio.h>
#include "container.h"

// Прототипы функций, используемых для организации вычислений
void ContainerPerimeterOut(Container* c, FILE* ofst);
void ContainerAreaOut(Container* c, FILE* ofst);


//------------------------------------------------------------------------------
// Вычисление периметров геометрическим клиентом
void CalcPerimeter(Container* c, FILE* ofst) {
  ContainerPerimeterOut(c, ofst) ;
}

//------------------------------------------------------------------------------
// Вычисление периметров геометрическим клиентом
void CalcArea(Container* c, FILE* ofst) {
  ContainerAreaOut(c, ofst) ;
}

#endif // __geometry_client__