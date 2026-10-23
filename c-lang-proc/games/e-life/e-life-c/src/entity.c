#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "entity.h"
#include "feeder.h"
#include "food.h"
#include "map.h"
// #include "eworld.h"

// Присоединение карты мира и списка сущностей к статическим указателям
void AttachMapAndEntityList(Map* pmap, struct EntityList* pentityList) {
    map = pmap;
    entityList = pentityList;
}

void GetMapInfo(Entity* entity, Map* map) {
    entity->mapInfo[0] = map->plane[entity->i-1][entity->j];
    entity->mapInfo[1] = map->plane[entity->i-1][entity->j+1];
    entity->mapInfo[2] = map->plane[entity->i][entity->j+1];
    entity->mapInfo[3] = map->plane[entity->i+1][entity->j+1];
    entity->mapInfo[4] = map->plane[entity->i+1][entity->j];
    entity->mapInfo[5] = map->plane[entity->i+1][entity->j-1];
    entity->mapInfo[6] = map->plane[entity->i][entity->j-1];
    entity->mapInfo[7] = map->plane[entity->i-1][entity->j-1];
}

// Выдача координат активной сущности по строке
int GetI(Entity* entity) {
    return entity->i;
}

// Выдача координат активной сущности по столбцу
int GetJ(Entity* entity) {
    return entity->j;
}

// Преобразование текущей позиции в mapInfo в новую координату по строке
int ConvertMapInfoToI(Entity* entity, int k) {
    switch(k) {
    case 0: case 1: case 7:
        return entity->i - 1;
    case 2: case 6:
        return entity->i;
    case 3: case 4: case 5:
        return entity->i + 1;
    default:
        return 0;
    }
}

// Преобразование текущей позиции в mapInfo в новую координату по столбцу
int ConvertMapInfoToJ(Entity* entity, int k) {
    switch(k) {
    case 1: case 2: case 3:
        return entity->j + 1;
    case 0: case 4:
        return entity->j;
    case 5: case 6: case 7:
        return entity->j - 1;
    default:
        return 0;
    }
}

// Генератор случайных чисел, осуществляющий выбор целого в диапазоне [0...k).
// Начальная инициализация генератора осуществляется в главной функции
int RandomSelect(int k) {
    if(k==0) {
        perror("Incorrect value for Randomize = 0");
        exit(9);
    }
    if(k==1) {
        return 0;
    }
    return rand() % k;
}

// Проверка состояния очередной сущности
void EntityNextState(Entity* entity) {
    // printf("EntityNextState\n");
    int clonePosition;
    switch(entity->tag) {
        case food:
            // запуск алгоритма поведения пищи в данной клетке
            // foodState = FoodNextState(&entity->food);
            if(FoodNextState(&entity->food)==foodReplication) {
                // Формирование клона в списке сущностей
                clonePosition = CloneFood(entityList, entity);
            }
            break;
        case feeder:
            // запуск алгоритма поведения пищееда в данной клетке
            FeederNextState(entity);
            break;
        default:
            // такой клетки в данном цикле быть не должно
            perror("Imposible next state for this entity");
            // EntityListOut(entityList);
            exit(4);
    }
    // // if(map->spaceCount == entityList->foodCount) {
    // if(map->spaceCount == entityList->busyCount) {
    //     // Пища заполонила мир
    //     perror("Only Food is living");
    //     exit(6);
    // }
}

//------------------------------------------------------------------------------
// Установка новых координат сущности
void SetPosition(Entity* entity, int i, int j) {
    entity->i = i;
    entity->j = j;
}

//==============================================================================
// Функции для обработки пищееда как специализации обобщения
//==============================================================================

//------------------------------------------------------------------------------
// Инициализация пищееда-специализации
void FeederInit(Entity* entity, int i, int j, int index) {
    entity->i = i;
    entity->j = j;
    entity->index = index;
    entity->tag = feeder;
    entity->feeder.energy = MAX_FEEDER_ENERGY / 2;
}

//------------------------------------------------------------------------------
// Формирование состояния пищееда-специализации на очередном шаге
void FeederNextState(Entity* entity) {
    // Научим пищееда перемещаться по простому алгоритму на свободное место.
    // Первоначально получаем информацию о соседних клетках.
    GetMapInfo(entity, map);
    // Если максимум энергии, то размножение пищееда
    if(FeederClone(entity)) return;
    // Если есть пища, то поедаем ее, оставаясь на месте
    if(FeederEatingFood(entity)) return;
    // Перемещение на случайно выбранную свободную клетку
    FeederRandomStep(entity);
}

//------------------------------------------------------------------------------
// Клонирование пищееда-специализации с занесением в список сущностей
bool FeederClone(Entity* entity) {
    // Размножение происходит при условии накопления максимума энергии
    if(entity->feeder.energy == MAX_FEEDER_ENERGY) {
        // Формирование вектора свободных позиций
        int freeCells[8];
        int l = 0;
        for(int k = 0; k < 8; ++k) {
            Entities e = entity->mapInfo[k];
            if(e == empty) {
                freeCells[l++] = k;
            }
        }
        // Размножение возможно, если есть хотя бы одна свободная клетка
        if(l > 0 ) {
            int kSelected = freeCells[RandomSelect(l)];
            int iNew = ConvertMapInfoToI(entity, kSelected);
            int jNew = ConvertMapInfoToJ(entity, kSelected);
            // Установка клона на карте в найденную позицию
            SetEntityOnTheMap(map, iNew, jNew, feeder);
            // Добавление пищееда в список активных объектов
            AddEntityToList(entityList, iNew, jNew, feeder);

            // Энергия родителя при размножении уменьшается в 2 раза
            entity->feeder.energy /= 2;
            return true;
        }
        return false;
    }
    return false;   // размножение невозможно
}

//------------------------------------------------------------------------------
// Поедание пищеедом-специализацией пищу
bool FeederEatingFood(Entity* entity) {
    // Формирование вектора с едой
    int freeCells[8];
    int l = 0;
    for(int k = 0; k < 8; ++k) {
        Entities e = entity->mapInfo[k];
        if(e == food) {
            freeCells[l++] = k;
        }
    }
    // Еда возможна, если есть хотя бы одна клетка с едой
    if(l > 0 ) {
        int kSelected = freeCells[RandomSelect(l)];
        int iNew = ConvertMapInfoToI(entity, kSelected);
        int jNew = ConvertMapInfoToJ(entity, kSelected);
        // Накопление энергии от поедания пищи до максимума
        entity->feeder.energy += DELTA_FOOD_ENERGY;
        if(entity->feeder.energy > MAX_FEEDER_ENERGY) {
            entity->feeder.energy = MAX_FEEDER_ENERGY;
        }
        // Клетка с пищей получена. Ее нужно опустошить на карте.
        // SetEntityOnTheMap(map, iNew, jNew, empty);
        // А пищу нужно удалить из списка активных сущностей.
        FoodEraseUsingPlan(entityList, iNew, jNew);
        return true;    // поели
    }
    // Пища отсутствует
    return false;
}

//------------------------------------------------------------------------------
// Перемещение пищееда-специализацией на случайно выбранную свободную клетку
void FeederRandomStep(Entity* entity) {
    // потеря энергии при отсутствии пищи
    entity->feeder.energy -= DELTA_FEEDER_ENERGY;
    // Возможна смерть от голода
    if(entity->feeder.energy <= 0) {
        FeederErase(entityList, entity);
        return;
    }
    // Формирование вектора свободных позиций
    int freeCells[8];
    int l = 0;
    for(int k = 0; k < 8; ++k) {
        Entities e = entity->mapInfo[k];
        if(e == empty) {
            freeCells[l++] = k;
        }
    }
    // Переход возможен, если есть хотя бы одна свободная клетка
    if(l > 0 ) {
        SetEntityOnTheMap(map, entity->i, entity->j, empty);
        int kSelected = freeCells[RandomSelect(l)];
        int iNew = ConvertMapInfoToI(entity, kSelected);
        int jNew = ConvertMapInfoToJ(entity, kSelected);
        SetPosition(entity, iNew,jNew);
        SetEntityOnTheMap(map, iNew, jNew, feeder);
    }
    // Отображение перехода на карте
}

//==============================================================================
// Функции, реализующие работу с пищей
//==============================================================================

//------------------------------------------------------------------------------
// Инициализация пищи-специализации
void FoodSpecInit(Entity* entity, int i, int j, int index) {
    entity->i = i;
    entity->j = j;
    entity->index = index;
    entity->tag = food;
    Food* food = &(entity->food);
    FoodInit(food);
}

//==============================================================================
// Функции, реализующие работу со списком сущностей
//==============================================================================

//------------------------------------------------------------------------------
// Начальная инициализаци списка сущностей, когда все элементы свободны
void EntityListInit(EntityList* entityList) {
    entityList->freeCount = MAX_MAP_HEIGHT*MAX_MAP_WIDTH;
    entityList->busyCount = 0;
    entityList->foodCount = 0;
    entityList->feederCount = 0;
}

//------------------------------------------------------------------------------
// Добавление сущности в список
// out: Возвращается количество элементов в массиве
int AddEntityToList(EntityList* entityList, int i, int j, Entities e) {
    // entityList->entity[entityList->busyCount].i = i;
    // entityList->entity[entityList->busyCount].j = j;
    // entityList->entity[entityList->busyCount].index = entityList->busyCount;
    // entityList->entity[entityList->busyCount].tag = e;
    switch(e) {
        case food:
            // Инициализация пищи
            // FoodInit(&(entityList->entity[entityList->busyCount].food));
            FoodSpecInit(&entityList->entity[entityList->busyCount],
                       i, j, entityList->busyCount);
            ++(entityList->foodCount);
            break;
        case feeder:
            FeederInit(&entityList->entity[entityList->busyCount],
                       i, j, entityList->busyCount);
            // entityList->entity[entityList->busyCount].feeder.energy =
            //                                         MAX_FEEDER_ENERGY / 2;
            ++(entityList->feederCount);
            break;
        default:
            perror("Incorrect entity type");
            exit(3);
    }
    ++(entityList->busyCount);
    --(entityList->freeCount);
    return entityList->busyCount;
}

//------------------------------------------------------------------------------
// Тестовый вывод списка сущностей
void EntityListOut(EntityList* entityList) {
    printf("Entities in the List: %d\n", entityList->busyCount);
    printf("Foods in the List: %d\n", entityList->foodCount);
    printf("Feeders in the List: %d\n", entityList->feederCount);
    for(int i = 0; i < entityList->busyCount; ++i) {
        printf("    %d: Entity is %d;    position = (%d, %d)\n",
               i,
               (int)entityList->entity[i].tag,
               entityList->entity[i].i,
               entityList->entity[i].j
        );
    }
}

//------------------------------------------------------------------------------
// Формирование состояния сущностей на следующем шаге обхода
void EntitiesNextState(EntityList* entityList) {
    // printf("EntitiesNextState, busyCount = %d\n", entityList->busyCount);
    int i = 0;
    while(i < entityList->busyCount) {
        // Проверка состояния очередной сущности
        EntityNextState(&(entityList->entity[i]));
        ++i;
    }
}

//------------------------------------------------------------------------------
// Клонирование пищи в список сущностей
// out: индекс клонированной сущности для ее дополнительной обработки
int CloneFood(EntityList* entityList, Entity* parent) {
    // printf("CloneFood\n");
    int clonePosition = -1;     // Возможно, что пища не будет создана
    // Определение свободных позиций, возможных для новой пищи
    GetMapInfo(parent, map); // Формируется массив окружений родителя
    int freeCells[8];   // Максимум их 8
    int l = 0;
    // Формируется массив пустых ячеек, доступных для клона
    for(int k = 0; k < 8; ++k) {
        Entities e = parent->mapInfo[k];
        if(e == empty) {
            freeCells[l++]=k;
        }
    }
    // Случайно выбирается одна свободная клетка.
    if(l != 0) {
        if(l == 1) {
            l = freeCells[0];
        } else {
            l = freeCells[RandomSelect(l)];
        }
    } else {
        // Нет свободных клеток для клонирования
        return 0;
    }
    // Установка координат для формирования новой пищи
    int i = ConvertMapInfoToI(parent, l);
    int j = ConvertMapInfoToJ(parent, l);
    // Добавление пищи в список
    clonePosition = AddEntityToList(entityList, i, j, food);
    // Инициализация пищи
    FoodInit(&(entityList->entity[clonePosition].food));
    // Фиксация пищи на карте
    SetEntityOnTheMap(map, i, j, food);
    return clonePosition;
}

//------------------------------------------------------------------------------
// Удаление из списка пищееда
void FeederErase(EntityList* entityList, Entity* entity) {
    // Пришла с косой. Нужно очистить жилплощадь
    int i = entity->i;
    int j = entity->j;
    int index = entity->index; // Индекс в списке

    if(index > entityList->busyCount) {
        perror("Index of feeder in entity list > size of list");
        exit(12);
    }

    SetEntityOnTheMap(map, i, j, empty); // Стирание на карте
    // Удаление из списка сущностей...
    --(entityList->busyCount);  // Уменьшить количество сущностей
    --(entityList->feederCount);  // Уменьшить количество пищеедов
    ++(entityList->freeCount);  // Увеличить количество пустых клеток
    // if(entityList->busyCount == 0) {
    //     printf("Game Over. No more entities\n");
    // }
    if(index != entityList->busyCount) {
        // Не последний элемент в списке
        // Фиксируем новый индекс в последнем элементе
        entityList->entity[entityList->busyCount].index = index;
        // Переносим фрагмент памяти размером в сущность
        memcpy(&(entityList->entity[index]),
               &(entityList->entity[entityList->busyCount]),
               sizeof(Entity));
    }
    // Последний элемент отпадает автоматически
}
//------------------------------------------------------------------------------
// Удаление из списка пищи
void FoodErase(EntityList* entityList, Entity* entity) {
    // Пришла с косой. Нужно очистить жилплощадь
    int i = entity->i;
    int j = entity->j;
    int index = entity->index; // Индекс в списке

    if(index > entityList->busyCount) {
        perror("Index of food in entity list > size of list");
        exit(11);
    }

    // Удаление из списка сущностей...
    --(entityList->busyCount);  // Уменьшить количество сущностей
    --(entityList->foodCount);  // Уменьшить количество пищи
    ++(entityList->freeCount);  // Увеличить количество пустых клеток
    SetEntityOnTheMap(map, i, j, empty); // Стирание на карте
    // if(entityList->busyCount == 0) {
    //     printf("Game Over. No more entities\n");
    // }
    if(index != entityList->busyCount) {
        // Не последний элемент в списке
        // Фиксируем новый индекс в последнем элементе
        entityList->entity[entityList->busyCount].index = index;
        // Переносим фрагмент памяти размером в сущность
        memcpy(&(entityList->entity[index]),
               &(entityList->entity[entityList->busyCount]),
               sizeof(Entity));
    }
    // Последний элемент отпадает автоматически
}

//------------------------------------------------------------------------------
// Удаление из списка любой сущности, используя координаты плана
void FoodEraseUsingPlan(EntityList* entityList, int i, int j) {
    // В начале нужно найти сущность с этими координатами.
    // Используется последовательный поиск.
    for(int k = 0; k < entityList->busyCount; ++k) {
        Entity* entity = &entityList->entity[k];
        if((entity->i == i) && (entity->j == j)) {
            // Нашли. Делаем удаление
            FoodErase(entityList, entity);
            return;
        }
    }
    // Не нашли. Значит что-то пошло не так.
    perror("The entity using this coordinates is absent");
    exit(7);
}
