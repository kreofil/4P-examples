#ifndef FEEDER_H
#define FEEDER_H

#include <stdbool.h>

// Максимально возможное значение энергии пищееда
#define MAX_FEEDER_ENERGY 10
// Потеря энергии при отсутствии ее пополнения
#define DELTA_FEEDER_ENERGY 2
// Энергия, добавляемая при поедании пищи
#define DELTA_FOOD_ENERGY 10

// Состояние пищи после анализа
// typedef enum FeederState{
//    feederMooving, feederActive, feederReplication, feederDead
// } FeederState;

// Структура, определяющая дополнительные поля, свойственные поедателю пищи.
typedef struct Feeder {
   // Активная сущность может накапливать и тратить энергию
    int energy;
} Feeder;

#endif // FEEDER_H
