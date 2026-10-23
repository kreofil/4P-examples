#include <stdio.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>
// #include "food.h"
// #include "feeder.h"
#include "eworld.h"
#include "map.h"

//------------------------------------------------------------------------------
// Загрузка начальных параметров жизни из текстового образа
void LifeLoad(char* fileName, EWorld* eWorld) {
    FILE* eLifeIn = fopen(fileName, "r"); // Файл с картой
    if(eLifeIn == NULL) {
        perror("Can not open map file");
        exit(2);
    }
    eWorld->mapLines = 0;
    // Загружается map01 как начальное состояние
    // char** textMap = eWorld->textMap;
    while(!feof(eLifeIn)) {
        fgets(eWorld->textMap[eWorld->mapLines++], MAX_MAP_WIDTH, eLifeIn);
    }
    fclose(eLifeIn);
    eWorld->currentMap = &(eWorld->map01);
}

//------------------------------------------------------------------------------
// Рисование текстового образа карты мира.
// В основном для тестирования исходных данных
void DrawTextMap(EWorld* eWorld) {
    for(int i = 0; i < eWorld->mapLines; ++i) {
        printf("%s", eWorld->textMap[i]);
    }
    printf("\n");
}

//------------------------------------------------------------------------------
// Процедура загрузки карты из исходного списка строк
// В ходе подгрузки карты также формируются параметры сущностей
// и заполняется список сущностей
void CreateMap(EWorld* eWorld) {
    eWorld->cells = 0;  // Считаем живые клетки в начальном состоянии
    int width = strlen(eWorld->textMap[0]);
    // Перебор строк формирующих карту
    for(int i = 0; i < eWorld->mapLines; ++i) {
        // Проверка корректности карты (все строки д.б. одинаковой ширины)
        int nextWidth = strlen(eWorld->textMap[i]);
        // printf("width = %d, nextWidth = %d\n", width, nextWidth);
        // if(width != nextWidth) {
        //     perror("Incorrect map file");
        //     exit(1);
        // }
        char ch;   // Текущий символ общего перебора
        for(int j = 0; j < width-1; ++j) {
            ch = eWorld->textMap[i][j];
            switch (ch) {
            case ' ':
                (eWorld->map01).plane[i][j] = empty;
                break;
            case '#':
                (eWorld->map01).plane[i][j] = locked;
                break;
            case '*':
                (eWorld->map01).plane[i][j] = filled;
                ++eWorld->cells;
                break;
            default:
                printf("[%d, %d]: Incorrect symbol '%c'\n",
                       i, j, eWorld->textMap[i][j]);
                exit(5);
            }
        }
        width = nextWidth;
    }
    eWorld->map01.height = eWorld->mapLines;
    eWorld->map01.width = width;
    eWorld->currentMap = &(eWorld->map01);
    eWorld->nextMap = &(eWorld->map02);
    // Инициализация пустой карты
    eWorld->map02 = eWorld->map01;
    eWorld->step = 0;
}

//------------------------------------------------------------------------------
// Вывод текущего состояния карты на дисплей
void DrawWorld(EWorld* eWorld) {
    Map* map = eWorld->currentMap;
    DrawMap(map);
    printf("Step: %d\n",  eWorld->step);
    printf("Cells: %d\n", eWorld->cells);
}

//------------------------------------------------------------------------------
// Установка значения клетки на новой карте в зависимости от ее соседей
void NewStateOfCell(EWorld* eWorld, int i, int j) {
    // Проверка окрестных клеток на число живых
    int count = LivingCells(eWorld->currentMap, i, j);
    // Принятие решений для занятой или пустой клетки
    Cell currentCell = eWorld->currentMap->plane[i][j];
    switch(currentCell) {
        case empty:
            // Клетка пустая. Проверка на возможность зарождения жизни
            if(count==3) {
                eWorld->nextMap->plane[i][j]=filled;
                ++eWorld->cells;
            } else {
                eWorld->nextMap->plane[i][j]=empty;
            }
            break;
        case filled:
            // Клетка живая. Счетчик на 1 меньше.
            --count;
            if(count == 2 || count == 3) {
                eWorld->nextMap->plane[i][j]=filled;
            } else {
                eWorld->nextMap->plane[i][j]=empty;
                --eWorld->cells;
            }
            break;
        default:
            break;
    }
}

//------------------------------------------------------------------------------
// Вычисление следующего состояния мира
void LifeNextState(EWorld* eWorld) {
    ++eWorld->step;
    // Формирование следующего состояния на другом поле
    for(int i = 1; i < (eWorld->currentMap->height)-1; ++i) {
        for(int j = 1; j < (eWorld->currentMap->width)-1; ++j) {
            NewStateOfCell(eWorld, i, j);
        }
    }
}

//------------------------------------------------------------------------------
// Обмен статусом между текущей и следующей картами
void MapExchange(EWorld* eWorld) {
    Map* tmp = eWorld->currentMap;
    eWorld->currentMap = eWorld->nextMap;
    eWorld->nextMap = tmp;
}
