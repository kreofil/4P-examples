//==============================================================================
//  main.cpp
//==============================================================================
//  Главный файл проекта имитационной модели "жизнь по Конвею"
//  Программа разработана в учебных целях для демонстрации процесса
//  использования языка программирования Си
//==============================================================================
//  Распространяется свободно и без каких-либо ограничений.
//  Copyright (c) 2025 by Alexander Legalov
//
//  Email : legalov@mail.ru
//  Site  : http://www.softcraft.ru
//
//==============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include "eworld.h"
// int usleep(useconds_t usec);

//------------------------------------------------------------------------------
void clrscr(void) {
    //char a[80];
    printf("\033[2J");      // Clear the entire screen.
    printf("\033[0;0f");    // Move cursor to the top left hand corner
}

//------------------------------------------------------------------------------
int main (int argc, char** argv) {
    if(argc < 2 || argc > 3) {
        printf("incorrect command line!\nWaited: %s <file name> [step delay (ms)]\n", argv[0]);
        return 1;
    }
    int delayValue = 0;
    if(argc == 3) {
        delayValue = atoi(argv[2]);
    }
    if(delayValue <= 0) {
        delayValue = 200000;
    } else {
        delayValue *= 1000;
    }
    EWorld eWorld;
    LifeLoad(argv[1], &eWorld);
    // DrawTextMap(&eWorld); // Тестовый вывод исходного файла
    // sleep(2);

    CreateMap(&eWorld);
    printf("width = %d, heigth = %d\n",
           eWorld.currentMap->width, eWorld.currentMap->height);
    while(1) {
        clrscr();
        DrawWorld(&eWorld);
        usleep(delayValue);
        LifeNextState(&eWorld);
        MapExchange(&eWorld);
    }
    return 0;
}
