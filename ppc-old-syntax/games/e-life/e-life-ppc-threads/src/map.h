#ifndef MAP_H
#define MAP_H

// =============================================================================
//  map.h
// =============================================================================
//  Структура map обеспечивает хранение карты мира.
//  На карте отмечается текущее состояние всех сущностей и изменение их положения или статуса
// =============================================================================

#define MAX_MAP_HEIGHT 13   // Максимальная высота карты
#define MAX_MAP_WIDTH  30   // Максимальная ширина карты

// Сущности мира задаются на карте в виде  перечислимого типа данных
typedef enum Entities {
    er,         // Ошибочная клетка
    empty,      // Пустая (свободная) клетка
    locked,     // Недоступная клетка
    food,       // Пища
    feeder      // Пищеед (едок)
} Entities;

// Структура, описывающая карту.
typedef struct Map {
    Entities plane[MAX_MAP_HEIGHT][MAX_MAP_WIDTH]; // Плоскость карты
    int height; // Заданная высота карты
    int width;  // Заданная ширина карты
    // Пространство карты, доступное для заполнения пищей и пищеедами
    int spaceCount;
} Map;


// Процедура загрузки карты из исходного списка строк
// void CreateMap(Map* map, char** textMap);

// Получение содержимого заданной клетки карты
static inline Entities GetCell(Map *map, int i, int j) {
    return map->plane[i][j];
}
// Установка нового значения содержимого клетки карты
static inline void SetCell(Map* map, Entities e, int i, int j) {
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

// Фиксация сущности на карте
void SetEntityOnTheMap(Map* map, int i, int j, Entities entity);


#endif // MAP_H
