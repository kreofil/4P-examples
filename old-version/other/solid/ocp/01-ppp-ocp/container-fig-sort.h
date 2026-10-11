#ifndef __container_fig_sort__
#define __container_fig_sort__

//==============================================================================
// container-fig-sort.h - специализация контейнера, используемая для сортировки
//==============================================================================
#include "container.h"

Container + <Sort: void;>;

//------------------------------------------------------------------------------
// Прототипы, используемые для поддержки старых функций контейнера и
// обобщенного алгорима сортировки
void ContainerOut(Container *c, FILE* ofst);
_Boll FigCmp<Figure* f1, Figure*f2>();

typedef struct Container {
  int len; // текущая длина
  struct Figure *cont[max_len];
} <> Container;

#endif // __container_fig_sort__