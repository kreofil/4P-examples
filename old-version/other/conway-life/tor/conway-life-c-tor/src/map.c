#include <stdio.h>
#include "map.h"

//------------------------------------------------------------------------------
// Вывод текущего состояния карты на дисплей
void DrawMap(Map* map) {
// Формирование строки для вывода карты
    for(int i = 0; i < map->height; ++i) {
        for(int j = 0; j < map->width; ++j) {
            switch(map->plane[i][j]) {
            case empty:
                printf("\x1b[1;30m.\x1b[0m");
                break;
            case locked:
                // printf("#");
                printf("\x1b[1;30m.\x1b[0m");
                break;
            case filled:
                // printf("O");
                printf("\x1b[1;32mO\x1b[0m");
                // printf("\x1b[1;31mO\x1b[0m");
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
// Фиксация ячейки на карте
void SetCellOnTheMap(Map* map, int i, int j, Cell cell) {
    map->plane[i][j] = cell;
}

//------------------------------------------------------------------------------
// Проверка окрестных клеток на число живых
int LivingCells(Map* map, int i, int j) {
    int count = 0;
    for(int k = -1; k <= 1; ++k) {
        for(int l = -1; l <= 1; ++l) {
            if(map->plane
                    [(i+k+map->height)%map->height]
                    [(j+l+map->width)%map->width]==filled) {
                ++count;
            }
        }
    }
    return count;
}
