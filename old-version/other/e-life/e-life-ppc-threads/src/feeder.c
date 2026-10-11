#include "feeder.h"

// Проверка состояния пищееда
// FeederState FeederNextState(Feeder* feeder) {
//     // printf("FoodNextState\n");
//     if(feeder->energy == MAX_FEEDER_ENERGY) {
//         return feederReplication;
//     }
//     --feeder->energy;
//     if(feeder->energy <= 0) {
//         return feederDead;
//     }
//     return feederActive;
// }

// Метод, определяющий поведение пищееда на очередном шаге
// void FeederMakeStep(Feeder* feeder) {
    // Научим пищееда перемещаться по простому алгоритму на свободное место.
    // Первоначально получаем информацию о соседних клетках.
    // GetMapInfo();
    // Если максимум энергии, то размножение пищееда
    // if(Clone()) return;
    // Если есть пища, то поедаем ее, оставаясь на месте
    // if(EatFood()) return;
    /// Перемещение на первую (по часовой стрелке) свободную клетку
    ///StepToFirstEmpty();
    // Перемещение на случайно выбранную свободную клетку
    // RandomStep();
// }

// Устанавливается новая позиция, на карте происходит перемещение пищееда
// void Feeder::SetPosition(int iNew, int jNew)
// {
//     pMap->SetCell(empty, i, j);
//     pMap->SetCell(feeder, iNew, jNew);
//     i = iNew;
//     j = jNew;
// }

// Перемещение на первую (по часовой стрелке) свободную клетку
// void Feeder::StepToFirstEmpty()
// {
//     // Ищем первую пустую, на которую и делается переход, если найдена.
//     // Иначе стоит на месте
//     for(int k = 0; k < 8; ++k) {
//         Entities e = mapInfo[k];
//         if(e == empty) {
//             int iNew = ConvertMapInfoToI(k);
//             int jNew = ConvertMapInfoToJ(k);
//             SetPosition(iNew,jNew);
//             break;
//         }
//     }
// }

// Выбор свободной клетки из множества доступных случайным образом
// void Feeder::RandomStep()
// {
//     // Формирование вектора свободных позиций
//     QVector<int> freeCells;
//     for(int k = 0; k < 8; ++k) {
//         Entities e = mapInfo[k];
//         if(e == empty) {
//             freeCells.append(k);
//         }
//     }
//     int freeSize = freeCells.size();
//     // Переход возможен, если есть хотя бы одна свободная клетка
//     if(freeSize > 0 ) {
//         int kSelected = freeCells[RandomSelect(freeSize)];
//         int iNew = ConvertMapInfoToI(kSelected);
//         int jNew = ConvertMapInfoToJ(kSelected);
//         SetPosition(iNew,jNew);
//     }
//     // потеря энергии при отсутствии пищи
//     energy -= deltaFeederEnergy;
//     // Возможна смерть от голода
//     if(energy <= 0) {
//         EraseMe();
//     }
// }

// Поедание пищи при ее наличии, оставаясь на месте.
// Поедание подтверждается возвратом true.
// bool Feeder::EatFood()
// {
//     // Формирование вектора с едой
//     QVector<int> foodCells;
//     for(int k = 0; k < 8; ++k) {
//         Entities e = mapInfo[k];
//         if(e == food) {
//             foodCells.append(k);
//         }
//     }
//     int foodSize = foodCells.size();
//     // Еда возможна, если есть хотя бы одна клетка с едой
//     if(foodSize > 0 ) {
//         int kSelected = foodCells[RandomSelect(foodSize)];
//         int iNew = ConvertMapInfoToI(kSelected);
//         int jNew = ConvertMapInfoToJ(kSelected);
//         // Клетка с пищей получена. Ее нужно опустошить.
//         ErasePosition(iNew,jNew);
//         // А пищу нужно удалить из списка активных сущностей.
//         // Недостаток данной версии: нельзя удалить напрямую,
//         // так как карта не содержит указателей на сущности.
//         // Информация к размышлению!!!
//         pEWorld->EraseEntity(iNew, jNew);
//         // Накопление энергии от поедания пищи до максимума
//         energy += deltaFoodEnergy;
//         if(energy > maxFeederEnergy) {
//             energy = maxFeederEnergy;
//         }
//         return true;    // поели
//     }
//     // Пища отсутствует
//     return false;
// }

// Очистка позиции на карте от пищи (ее поедание)
// void Feeder::ErasePosition(int iNew, int jNew)
// {
//     pMap->SetCell(empty, iNew, jNew);
// }

// Размножение пищееда при накоплении энергии и наличии свободных клеток
// bool Feeder::Clone()
// {
//     // Размножение происходит при условии накопления максимума энергии
//     if(energy == maxFeederEnergy) {
//         QVector<int> freeCells;
//         for(int k = 0; k < 8; ++k) {
//             Entities e = mapInfo[k];
//             if(e == empty) {
//                 freeCells.append(k);
//             }
//         }
//         // Размножение возможно, если есть хотя бы одна свободная клетка
//         int freeSize = freeCells.size();
//         if(freeSize > 0 ) {
//             int kSelected = freeCells[RandomSelect(freeSize)];
//             int iNew = ConvertMapInfoToI(kSelected);
//             int jNew = ConvertMapInfoToJ(kSelected);
//             Entity* newFeeder =  new Feeder(iNew, jNew, pMap, pEWorld);
//             newFeeder->SetPosition(iNew,jNew);
//             // Добавление пищееда в список активных объектов
//             //(pEWorld->activeEntities).append(newFood);
//             pEWorld->AppendMe(newFeeder);
//         }
//         // Энергия при размножении уменьшается в 2 раза
//         energy /= 2;
//         return true;
//     }
//     return false;   // размножение невозможно
// }

// Смерть от отсутствия энергии (самуничтожение)
// void Feeder::EraseMe()
// {
//     // Пришла с косой. Нужно очистить жилплощадь
//     ErasePosition(i,j);
//     // И убрать себя из списка живущих
//     pEWorld->EraseEntity(i, j);
// }
