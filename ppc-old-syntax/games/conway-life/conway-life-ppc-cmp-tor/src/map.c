#include <stdio.h>
#include "map.h"

//------------------------------------------------------------------------------
// Вывод текущего состояния карты на дисплей
void DrawMap(Map* map) {
    // Эталон для проверки занятой клетки
    struct Cell.filled filledCell;
    // Эталон для проверки свободной клетки
    struct Cell.empty emptyCell;
    // Эталон для проверки граничной клетки
    struct Cell.locked lockedCell;

    // Формирование строки для вывода карты
    for(int i = 0; i < map->height; ++i) {
        for(int j = 0; j < map->width; ++j) {
            Cell* pCell = &(map->plane[i][j]);
            if(spec_index_cmp(pCell, &emptyCell) >= 0) {
                printf("\x1b[1;30m.\x1b[0m");
            } else if(spec_index_cmp(pCell, &lockedCell) >= 0) {
                // printf("#");
                printf("\x1b[1;30m.\x1b[0m");
            } else if(spec_index_cmp(pCell, &filledCell) >= 0) {
                // printf("O");
                printf("\x1b[1;32mO\x1b[0m");
                // printf("\x1b[1;31mO\x1b[0m");
            } else {
                printf("?");
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
            // Эталон для проверки занятой клетки
            struct Cell.filled filledCell;
            Cell* pCell = &(map->plane[(i+k+map->height)%map->height]
                                      [(j+l+map->width)%map->width]);
            if(spec_index_cmp(pCell, &filledCell) >= 0) {
                ++count;
            }
        }
    }
    return count;
}
