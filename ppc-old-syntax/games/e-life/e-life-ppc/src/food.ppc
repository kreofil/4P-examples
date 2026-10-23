#include <stdio.h>

#include "food.h"

// Проверка состояния пищи
FoodState FoodNextState(Food* food) {
    // printf("FoodNextState\n");
    ++(food->iStep);
    if(food->iStep >= MAX_STEPS_TO_CLONE) {
        food->iStep = 0;
        return foodReplication;
    }
    return foodNoactivity;
}

// Инициализация созданного элемента пищи
void FoodInit(Food* food) {
    food->iStep = 0;
    food->energy = MAX_FOOD_ENERGY;
}
