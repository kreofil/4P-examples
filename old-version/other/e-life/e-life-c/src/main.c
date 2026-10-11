//==============================================================================
//  main.cpp
//==============================================================================
//  Главный файл проекта имитационной модели "Электронная жизнь
//  Программа разработана в учебных целях для демонстрации процесса
//  использования языка программирования Си
//==============================================================================
//  Распространяется свободно и без каких-либо ограничений.
//  Copyright (c) 2023 by Alexander Legalov
//
//  Email : legalov@mail.ru
//  Site  : http://www.softcraft.ru
//
//==============================================================================

#include <unistd.h>
#include <stdlib.h>
#include <time.h>
// #include "map.h"
#include "entity.h"
#include "eworld.h"
// #include "eworldlabelview.h"

void clrscr(void) {
    //char a[80];
    printf("\033[2J");      // Clear the entire screen.
    printf("\033[0;0f");    // Move cursor to the top left hand corner
}

//------------------------------------------------------------------------------
int main (/*int argc, char** argv*/)
{
    srand(time(0));     // Начальная установка ГСЧ
    EWorld eWorld;
    // Загрузка начальных параметров жизни из текстового образа
    AttachMapAndEntityList(&eWorld.map, &eWorld.entityList);
    LifeLoad("../data/eworld-01.dat", &eWorld);
    EntityListInit(&(eWorld.entityList));
    CreateMap(&eWorld);

    clrscr();
    // DrawTextMap(&eWorld); // Тестовый вывод исходного файла
    // DrawWorld(&eWorld);
    // EntityListOut(&(eWorld.entityList));

    int step = 0;
    while(1) {
        clrscr();
        DrawWorld(&eWorld);
        printf("\x1b[1;33mStep:    \x1b[1;37m%d\x1b[0m\n", step++);
        printf("\x1b[1;33mFoods:   \x1b[1;37m%d\x1b[0m\n", eWorld.entityList.foodCount);
        printf("\x1b[1;33mFeeders: \x1b[1;37m%d\x1b[0m\n", eWorld.entityList.feederCount);
        printf("\x1b[1;33mEntities: \x1b[1;37m%d\x1b[0m\n", eWorld.entityList.busyCount);
        printf("\x1b[1;33mEmpty: \x1b[1;37m%d\x1b[0m\n", eWorld.entityList.freeCount);
        printf("\x1b[1;33mSpace: \x1b[1;37m%d\x1b[0m\n", eWorld.map.spaceCount);
        // if(eWorld.map.spaceCount == eWorld.entityList.foodCount) {
        if((eWorld.entityList.feederCount == 0) && (eWorld.entityList.foodCount == 0)) {
                // Пища закончилась. Пищееды вымерли.
                printf("\x1b[1;31mGAME OVER!!!\nThe World is dead!!!\n\x1b[0m");
                exit(10);
        }
        if((eWorld.entityList.feederCount == 0) && (eWorld.entityList.foodCount != 0)) {
                // Пищееды вымерли. Осталась только пища
                perror("\x1b[1;32mGAME OVER!!!\nOnly Food will be more...\n\x1b[0m");
                exit(11);
        }
        sleep(1);
        EWorldNextState(&eWorld);
    }
    return 0;
}
