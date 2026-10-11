//==============================================================================
// figure-proxy-in.c - Обработчик специализации, осуществляющий
// ввод прокси как фигуры.
//==============================================================================

#include <stdio.h>
#include <string.h>
#include "figure-proxy.h"

//------------------------------------------------------------------------------
// Ввод фигуры из файла
struct Figure *FigureCreateAndIn(FILE* ifst);

//------------------------------------------------------------------------------
// Прототип обобщеннай функции ввода фигуры
void FigureIn<Figure *f>(FILE* file);

// Ввод фигуры через прокси из файла, заданного в буфере прокси
void FigureIn<Figure.proxy *p>(FILE* ifst) {
    p->@f = NULL;    // Фигура при вводе прокси не вводится
    // В качестве данных вводится имя файла, в котором располагается
    // фигура, связанная с прокси
    fscanf(ifst, "%s", p->@fileName);
    // char* ps = fgets(p->@fileName, FILE_NAME_MAX_LEN - 1, ifst);
    // printf("File name = %s\n", p->@fileName);
    // int n = strlen(p->@fileName);
    // printf("len = %d\n", n);
}

//------------------------------------------------------------------------------
// Ввод фигуры в прокси. Используется базовый тип
void ProxyFigureInBase(Proxy *p) {
    // printf("ProxyFigureIn\n");
    FILE* ifst = fopen(p->fileName, "r");
    if(ifst != NULL) {
        // printf("Before FigureCreateAndIn\n");
        p->f = FigureCreateAndIn(ifst);
        fclose(ifst);
        // printf("After FigureCreateAndIn\n");
    } else {
        printf("File not found\n");
        p->f = NULL;
    }
}

//------------------------------------------------------------------------------
// Прототип обобщенной функции ввода фигуры из прокси
void ProxyFigureIn<Figure *f>();

// Обработчик специализации для ввода фигуры из прокси
void ProxyFigureIn<Figure.proxy *f>() {
    ProxyFigureInBase(&(f->@));
}
