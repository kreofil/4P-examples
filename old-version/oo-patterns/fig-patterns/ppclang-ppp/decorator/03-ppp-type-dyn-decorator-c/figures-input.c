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
    int k = 0;
    fscanf(ifst, "%d", &(k));
    switch (k) {
    case 1:
        sp = create_spec(Figure.Rectangle);
        break;
    case 2:
        sp = create_spec(Figure.Triangle);
        break;
    default:
        return 0;
    }
    // Создание декоратора
    struct Figure.Decorator* sd = create_spec(Figure.Decorator );
    sd->@.f = sp; // связывание с фигурой
    FigureIn<sd>(ifst); // ввод декорированной фигуры
    return sd;
}
