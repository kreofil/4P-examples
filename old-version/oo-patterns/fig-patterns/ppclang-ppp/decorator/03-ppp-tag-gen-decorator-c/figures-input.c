//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
// Реализация использует динамически подключаемый декоратор
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "figure-decorator.h"

void FigureIn<Figure *f>(FILE* file);

//------------------------------------------------------------------------------
// Ввод параметров одной из фигур из файла, включая ее цвет
Figure* FigureCreateAndIn(FILE* ifst)
{
    Figure* sp;
    int k;
    fscanf(ifst, "%d", &(k));
    switch (k) {
    case 1:
        // sp = create_spec(Figure <decor< Figure<rect> > > );
        sp = create_spec(Figure.decor.Figure.rect);
        break;
    case 2:
        // sp = create_spec(Figure <decor< Figure<trian> > > );
        sp = create_spec(Figure.decor.Figure.trian);
        break;
    default:
        return 0;
    }
    FigureIn<sp>(ifst); // ввод декорированной фигуры
    return sp;
}
