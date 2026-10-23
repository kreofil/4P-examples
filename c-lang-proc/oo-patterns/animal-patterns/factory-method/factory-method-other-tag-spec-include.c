#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Конкретные животные
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

// Конкретных создателей можно задать через перечислимый тип.
typedef enum Creator {
    DuckCreator,
    DogCreator,
} Creator;

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
Animal* FactoryMethod(Creator c) {
  switch (c) {
    case DuckCreator: return DuckFactoryMethod();
    case DogCreator: return DogFactoryMethod();
    default: return NULL;
  }
}

// Обязанность Создателя не заключается только в создании животных.
// Обычно он содержит некоторую базовую логику, которая основана
// на функциях обобщенных животных, возвращаемых фабричным методом.
Animal* NewAnimal(Creator c) {
  // Вызываем фабричный метод, чтобы получить обобщенного животного.
  Animal* animal = FactoryMethod(c);
  return animal;
}

// Клиентский код работает с экземпляром конкретного создателя через его
// базовый интерфейс. Пока клиент продолжает работать с создателем через
// интерфейс, ему можно передать любого создателя.
void ClientCode(Creator creator) {
  // ...
  printf(
    "Client: I'm not aware of the creator's structure, but it still works.\n");
  Animal* animal = NewAnimal(creator);
  // Любые операции с животным, если для него есть дополнительные функции.
  // ...
  free(animal);
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main() {
  printf("Step 1: Launched with the DuckCreator.\n");
  Creator* creator1 = malloc(sizeof(Creator)); *creator1 = DuckCreator;
  ClientCode(*creator1);
  free(creator1);

  printf("\n");
  printf("Step 2: Launched with the DogCreator.\n");
  Creator* creator2 = malloc(sizeof(Creator)); *creator2 = DogCreator;
  ClientCode(*creator2);
  free(creator2);

  printf("\n");
  printf("Step 3: Launched with the DuckCreator.\n");
  Creator creator3 = DuckCreator;
  ClientCode(creator3);

  printf("\n");
  printf("Step 4: Launched with the DogCreator.\n");
  Creator creator4 = DogCreator;
  ClientCode(creator4);

  return 0;
}
