//==============================================================================
// rectangle-cover.c - Функции обработки прямоугольника в оболочке
//==============================================================================

#include <stdlib.h>
#include "cover.h"

//------------------------------------------------------------------------------
// Инициализация связей между прямоугольником и интерфейсом
void RectangleLink(RectangleCover* rc) {
  rc->io.@ = &(rc->r);
  rc->g.@ = &(rc->r);
}

//------------------------------------------------------------------------------
// Добавление интерфейсов к прямоугольнику в обертке
// void AddInterfacesToRectangleCover(RectangleCover* rc) {
//   rc->io = create_spec(InOut.rect);
//   rc->g = create_spec(Geometry.rect);
//   RectangleLink(rc);
// }

//------------------------------------------------------------------------------
// Удаление из прямоугольника в обертке интерфейсов
// void ClearInterfacesFromRectangleCover(RectangleCover* rc) {
//   free(rc->io);
//   free(rc->g);
// }

//------------------------------------------------------------------------------
// Создание прямоугольника в обертке
RectangleCover* NewRectangleCover() {
  RectangleCover* rc = malloc(sizeof(RectangleCover));
  // RectangleCover* rc = create_spec(RectangleCover);
  RectangleLink(rc);
  // AddInterfacesToRectangleCover(rc);
  return rc;
}

//------------------------------------------------------------------------------
// Удаление прямоугольника в обертке
void DeleteRectangleCover(RectangleCover* rc) {
  // ClearInterfacesFromRectangleCover(rc);
  free(rc);
}

