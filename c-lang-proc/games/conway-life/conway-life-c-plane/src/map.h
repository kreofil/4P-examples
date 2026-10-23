#ifndef MAP_H
#define MAP_H

// =================================================================================================
//  map.h
// =================================================================================================
//  Структура map обеспечивает хранение карты мира.
//  На карте отмечается текущее состояние сущностей и изменение их положения или статуса
// =================================================================================================

#define MAX_MAP_HEIGHT 150
#define MAX_MAP_WIDTH  150

// Клетки игры, отображающие протекание жизни
typedef enum Cell {
    empty,      // Пустая (свободная) клетка
    filled,     // Занятая клетка
    locked,     // Границы плоскости
} Cell;

// Структура, описывающая карту.
typedef struct Map {
    Cell plane[MAX_MAP_HEIGHT][MAX_MAP_WIDTH]; // Плоскость карты
    int height; // Высота карты
    int width;  // Ширина карты
} Map;


// Процедура загрузки карты из исходного списка строк
// void CreateMap(Map* map, char** textMap);

// Получение содержимого заданной клетки карты
static inline Cell GetCell(Map *map, int i, int j) {
    return map->plane[i][j];
}
// Установка нового значения содержимого клетки карты
static inline void SetCell(Map* map, Cell e, int i, int j) {
    map->plane[i][j] = e;
}
// Выдача информации о ширине карты
static inline int GetWidth(Map* map) { return map->width; }

// Выдача информации о высоте карты
static inline int GetHeight(Map* map) { return map->height; }

// Вывод текущего состояния карты на дисплей
void DrawMap(Map* map);

// Тестовый вывод информации о текущем состоянии карты
void MapTestOut(Map* map);

// Обработка состояния ячеки на карте
void SetCellOnTheMap(Map* map, int i, int j, Cell cell);

// Проверка окрестных клеток на число живых
int LivingCells(Map* map, int i, int j);

#endif // MAP_H
