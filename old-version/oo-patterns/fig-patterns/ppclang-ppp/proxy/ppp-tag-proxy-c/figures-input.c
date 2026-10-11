//==============================================================================
// figures-input.c - функция содания ввода всех альтернативных фигур.
// Реализована как централизованная. Единственная, требующая модификации
// при вводе данных. Но можно тоже сделать эволюционно расширяемой.
// Реализация использует динамически подключаемый декоратор
//==============================================================================

#include <stdio.h>
#include "figure-rectangle.h"
#include "figure-triangle.h"
#include "figure-proxy.h"

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
        sp = create_spec(Figure.rect);
        break;
    case 2:
        sp = create_spec(Figure.trian);
        break;
    case 3:
        // Создание прокси как фигуры
        sp = create_spec(Figure.proxy);
        break;
    default:
        return NULL;
    }
    FigureIn<sp>(ifst); // ввод фигуры или прокси
    return sp;
}
