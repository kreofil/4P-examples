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
        sp = create_spec(Figure.rect);
        break;
    case 2:
        sp = create_spec(Figure.trian);
        break;
    default:
        return NULL;
    }
    // Создание декоратора
    struct Figure.decor *sd = create_spec(Figure.decor);
    sd->@f = sp; // связывание с фигурой
    FigureIn<sd>(ifst); // ввод декорированной фигуры
    return sd;
}
