#include <stdio.h>

#include "map.h"
///#include "food.h"
///#include "feeder.h"

//------------------------------------------------------------------------------
// Вывод текущего состояния карты на дисплей
void DrawMap(Map* map) {
// Формирование строки для вывода карты
    for(int i = 0; i < map->height; ++i) {
        for(int j = 0; j < map->width; ++j) {
            switch(map->plane[i][j]) {
            case empty:
                printf(" ");
                break;
            case locked:
                // printf("#");
                printf("\x1b[1;30m#\x1b[0m");
                break;
            case food:
                // printf("*");
                // printf("\x1b[1;32m%c\x1b[0m", '*');
                printf("\x1b[1;32m*\x1b[0m");
                break;
            case feeder:
                // printf("O");
                printf("\x1b[1;31mO\x1b[0m");
                break;
            default:
                printf("?");
                break;
            }
        }
        printf("\n");
    }
}

//------------------------------------------------------------------------------
// Тестовый вывод информации о текущем состоянии карты
void MapTestOut(Map* map) {
    // Формирование информации о размере карты
    printf("Map parameters:\n");
    printf("    - height = %d;\n", map->height);
    printf("    - width  = %d;\n", map->width);
    DrawMap(map);
}

//------------------------------------------------------------------------------
// Фиксация пищи на карте
void SetEntityOnTheMap(Map* map, int i, int j, Entities entity) {
    map->plane[i][j] = entity;
}
