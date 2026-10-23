#include <stdio.h>
#include <string.h>
#include <error.h>
#include <stdlib.h>
// #include "food.h"
// #include "feeder.h"
#include "eworld.h"
#include "map.h"

// Загрузка начальных параметров жизни из текстового образа
void LifeLoad(char* fileName, EWorld* eWorld) {
    FILE* eLifeIn = fopen(fileName, "r"); // Файл с картой
    if(eLifeIn == NULL) {
        perror("Can not open map file");
        exit(2);
    }
    eWorld->mapLines = 0;
    while(!feof(eLifeIn)) {
        fgets(eWorld->textMap[eWorld->mapLines++], MAX_MAP_WIDTH, eLifeIn);
    }
    fclose(eLifeIn);
}

void DrawTextMap(EWorld* eWorld) {
    for(int i = 0; i < eWorld->mapLines; ++i) {
        printf("%s", eWorld->textMap[i]);
    }
    printf("\n");
}

// Процедура загрузки карты из исходного списка строк
// В ходе подгрузки карты также формируются параметры сущностей
// и заполняется список сущностей
void CreateMap(EWorld* eWorld) {
    int width = strlen(eWorld->textMap[0]);
    eWorld->map.spaceCount = 0;     // Определение пространства карты
    // Entities** plane = (eWorld->map).plane;  // Прямой доступ к плану
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
        for(int j = 0; j < width; ++j) {
            ch = eWorld->textMap[i][j];
            switch (ch) {
            case ' ':
                (eWorld->map).plane[i][j] = empty;
                ++eWorld->map.spaceCount;
                break;
            case '#':
                (eWorld->map).plane[i][j] = locked;
                break;
            case '*':
                (eWorld->map).plane[i][j] = food;
                // В список сущностей добавляется пища
                AddEntityToList
                        (&(eWorld->entityList), i, j, food);
                ++eWorld->map.spaceCount;
                break;
            case 'O':
                (eWorld->map).plane[i][j] = feeder;
                // В список сущностей добавляется пищеед
                AddEntityToList
                        (&(eWorld->entityList), i, j, feeder);
                ++eWorld->map.spaceCount;
                break;
            default:
                (eWorld->map).plane[i][j] = er;
                break;
            }
        }
        width = nextWidth;
    }
    eWorld->map.height = eWorld->mapLines;
    eWorld->map.width = width;
}

// Вывод текущего состояния карты на дисплей
void DrawWorld(EWorld* eWorld) {
    Map* map = GetMap(eWorld);
    DrawMap(map);
    // printf("Working space = % d\n", map->spaceCount);
}

// Вычисление следующего состояния мира
void EWorldNextState(EWorld* eWorld) {
    // Пошел перебор активных сущностей, размещенных в списке
    // с изменением их состояния и отражении, при необходимости
    // этого состояния на карте.
    // printf("EWorldNextState\n");
    EntitiesNextState(&(eWorld->entityList));

}
