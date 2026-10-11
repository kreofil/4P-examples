#ifndef FOOD_H
#define FOOD_H

// Максимально возможная энергия для пищи
#define MAX_FOOD_ENERGY 10
// Максимально возможное число шагов до клонирования пищи
#define MAX_STEPS_TO_CLONE 5 //6 //10

// Состояние пищи после анализа
typedef enum FoodState{foodNoactivity, foodReplication} FoodState;

// Структура, определяющая параметры пищи
typedef struct Food {
    int iStep;      // Счетчик шагов пищи до очередного размножения
    int energy;     // Энергетическая емкость пищи
} Food;

// Проверка состояния пищи
FoodState FoodNextState(Food* food);

// Инициализация созданного элемента пищи
void FoodInit(Food* food);

#endif // FOOD_H
