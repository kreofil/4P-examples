#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Конкретные животные/
typedef struct Duck {} Duck;
typedef struct Dog {} Dog;

// Признаки конкретных животных
typedef enum AnimalTag {duckTag, dogTag,} AnimalTag;

// Животное. Непосредственно включает конкретных животных
typedef struct Animal {
  AnimalTag tag;
  union {
    Duck duck;
    Dog dog;
  };
} Animal;

// Создание конкретных животных
Animal* DuckFactoryMethod() {
  Animal* p = malloc(sizeof(Animal));
  p->tag = duckTag;
  printf("Duck created!\n");
  return p;
}
Animal* DogFactoryMethod() {
  Animal* p = malloc(sizeof(Animal));
  p->tag = dogTag;
  printf("Dog created!\n");
  return p;
}

// Косвенное создание животного в зависимости от Создателя
Animal* FactoryMethod(AnimalTag c) {
  switch (c) {
    case duckTag: return DuckFactoryMethod();
    case dogTag: return DogFactoryMethod();
    default: return NULL;
  }
}

// Обязанность Создателя не заключается только в создании животных.
// Обычно он содержит некоторую базовую логику, которая основана
// на функциях обобщенных животных, возвращаемых фабричным методом.
Animal* NewAnimal(AnimalTag c) {
  // Вызываем фабричный метод, чтобы получить обобщенного животного.
  Animal* animal = FactoryMethod(c);
  return animal;
}

// Клиентский код работает с экземпляром конкретного создателя через его
// базовый интерфейс. Пока клиент продолжает работать с создателем через
// интерфейс, ему можно передать любого создателя.
void ClientCode(AnimalTag creator) {
  // ...
  printf(
    "Client: I'm not aware of the creator's structure, but it still works.\n");
  Animal* animal = NewAnimal(creator);
  // Любые операции с Продуктом, если для него есть дополнительные функции.
  // ...
  free(animal);
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main() {
  printf("Step 1: Launched with the duckTag.\n");
  AnimalTag* creator1 = malloc(sizeof(AnimalTag)); *creator1 = duckTag;
  ClientCode(*creator1);
  free(creator1);

  printf("\n");
  printf("Step 2: Launched with the dogTag.\n");
  AnimalTag* creator2 = malloc(sizeof(AnimalTag)); *creator2 = dogTag;
  ClientCode(*creator2);
  free(creator2);

  printf("\n");
  printf("Step 3: Launched with the duckTag.\n");
  AnimalTag creator3 = duckTag;
  ClientCode(creator3);

  printf("\n");
  printf("Step 4: Launched with the dogTag.\n");
  AnimalTag creator4 = dogTag;
  ClientCode(creator4);

  return 0;
}
