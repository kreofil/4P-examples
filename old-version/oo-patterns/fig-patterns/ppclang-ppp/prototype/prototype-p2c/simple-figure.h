#ifndef __simple_figure__
#define __simple_figure__

//------------------------------------------------------------------------------
// figure.h - содержит описание обобщающей геометрической фигуры,
// объединяющей фигуры семейств.
//------------------------------------------------------------------------------

#include "simple-rectangle.h"
#include "simple-triangle.h"
#include "simple-figure-container.h"

//------------------------------------------------------------------------------
// Фигура
typedef struct SimpleFigure {}
    <SimpleRectangle; SimpleTriangle; FigureContainer>
SimpleFigure;

//------------------------------------------------------------------------------
// Ввод параметров одноЙ из фигур
SimpleFigure* FigureCreateAndIn(FILE* ifst);

//------------------------------------------------------------------------------
// Обобщенная функция ввода фигуры
void FigureIn<SimpleFigure *f>(FILE* ifst);
// Обработчики специализаций, вводящие конкретные фигуры
void FigureIn<SimpleFigure.SimpleRectangle *f>(FILE* ifst);
void FigureIn<SimpleFigure.SimpleTriangle *f>(FILE* ifst);
void FigureIn<SimpleFigure.FigureContainer *f>(FILE* ifst);

//------------------------------------------------------------------------------
// Обобщенная функция вывода фигуры
void FigureOut<SimpleFigure *f>(FILE* ofst);
// Обработчики специализаций, выводящие конкретные фигуры
void FigureOut<SimpleFigure.SimpleRectangle *f>(FILE* ofst);
void FigureOut<SimpleFigure.SimpleTriangle *f>(FILE* ofst);
void FigureOut<SimpleFigure.FigureContainer *f>(FILE* ofst);

//------------------------------------------------------------------------------
// Обобщенная функция клонирования фигуры
SimpleFigure* FigureClone<SimpleFigure *f>();
// Обработчики специализаций, клонирующие конкретные фигуры
SimpleFigure* FigureClone<SimpleFigure.SimpleRectangle *f>();
SimpleFigure* FigureClone<SimpleFigure.SimpleTriangle *f>();
SimpleFigure* FigureClone<SimpleFigure.FigureContainer *f>();

#endif // __simple_figure__