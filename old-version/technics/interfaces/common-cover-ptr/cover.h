#ifndef __cover__
#define __cover__

//==============================================================================
// cover.h - содержит описание оболочек, имитирующих использование
// нескольких интерфейсов в классах
//==============================================================================

#include "rectangle.h"
#include "inout-rectangle.h"
#include "geometry-rectangle.h"

// #include "triangle.h"
// #include "inout-triangle.h"
// #include "geometry-triangle.h"

//------------------------------------------------------------------------------
// Обертка, содержащая связи на прямоугольник и его интерфейсы
// typedef struct RectangleCover {
//   struct InOut.rect io;       // Интерфейс ввода-вывода для прямоугольника
//   struct Geometry.rect g;     // Геометрический интефейс прямоугольника
//   Rectangle r;                // Используемый прямоугольник
// } <> RectangleCover;

// Временнный вариант с использованием указателей для подключения интерфейсов
typedef struct RectangleCover {
  struct InOut.rect *io;       // Интерфейс ввода-вывода для прямоугольника
  struct Geometry.rect *g;     // Геометрический интефейс прямоугольника
  Rectangle r;                 // Используемый прямоугольник
} <> RectangleCover;

//------------------------------------------------------------------------------
// Описание функций обработки прямоугольника в обертке

// Инициализация связей между прямоугольником и интерфейсом
void RectangleLink(RectangleCover* rc);

// Добавление интерфейсов к прямоугольнику в обертке
void AddInterfacesToRectangleCover(RectangleCover* rc);

// Удаление из прямоугольника в обертке интерфейсов
void ClearInterfacesFromRectangleCover(RectangleCover* rc);

// Создание прямоугольника в обертке
RectangleCover* NewRectangleCover();

// Удаление прямоугольника в обертке
void DeleteRectangleCover(RectangleCover* rc);

#endif // __cover__