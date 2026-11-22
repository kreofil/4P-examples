// Использование решения с подключением основ специализаций через косвенное связывание и раздельные признаки для животных и их создателей.
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Конкретные животные/
typedef struct Duck {} Duck;
typedef struct Dog {} Dog;

// Промежуточные функции, обеспечивающие динамическое создание
// конкретных животных
Duck* CreateDuck() {
  return malloc(sizeof(Duck));
}
Dog* CreateDog() {
  return malloc(sizeof(Dog));
}

// Признаки конкретных животных
typedef enum AnimalTag {duckTag, dogTag,} AnimalTag;

// Обобщенное животное.
typedef struct Animal {
  AnimalTag tag;
  union {
    Duck *duck;
    Dog *dog;
  };
} Animal;

// Создание конкретных животных при динамическом создании обобщения
Animal* DuckFactoryMethod() {
  Animal* p = malloc(sizeof(Animal));
  p->tag = duckTag;
  p->duck = CreateDuck();
  printf("Duck created dynamicly!\n");
  return p;
}
Animal* DogFactoryMethod() {
  Animal* p = malloc(sizeof(Animal));
  p->tag = dogTag;
  p->dog = CreateDog();
  printf("Dog created dynamicly!\n");
  return p;
}

// Конкретные Создатели можно задать через перечислимый тип.
typedef enum Creator {
  DuckCreator,
  DogCreator,
} Creator;

// Косвенное создание животного в зависимости от создателя
Animal* FactoryMethod(Creator c) {
  switch (c) {
    case DuckCreator: return DuckFactoryMethod();
    case DogCreator:  return DogFactoryMethod();
    default: return NULL;
  }
}

// Удаление конкретного животного из обобщенной оболочки.
void DeleteConcreteAnimal(Animal* p) {
  switch (p->tag) {
    case duckTag:
      free(p->duck);
      break;
    case dogTag:
      free(p->dog);
      break;
    default:
      printf("Incorrect tag of deleted concrecte animal = %d\n", (int)p->tag);
      exit(-1);
  }
}
// Удаление динамически созданного обобщенного животного осуществляется
// процедурным деструктором, вызывающим удаление конкретного животного
void DeleteAnimal(Animal* p) {
  DeleteConcreteAnimal(p);
  free(p);
}

// Обязанность Создателя не заключается только в создании животных.
// Обычно он содержит некоторую базовую бизнес-логику, которая основана
// на функциях животных, возвращаемых фабричным методом.
Animal* NewAnimal(Creator c) {
  // Вызываем фабричный метод, чтобы получить животное.
  Animal* animal = FactoryMethod(c);
  return animal;
}

// Клиентский код работает с экземпляром конкретного создателя, хотя и через его
// базовый интерфейс. Пока клиент продолжает работать с создателем через базовый
// интерфейс, вы можете передать ему любой подкласс создателя.
void ClientCode(Creator creator) {
  // ...
  printf(
    "Client: I'm not aware of the creator's structure, but it still works.\n");
  Animal* animal = NewAnimal(creator);
  // ...
  DeleteAnimal(animal);
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main() {
  // Создание и удаление в клиенте всей утки
  printf("Step 1: Launched with the DuckCreator.\n");
  Creator* creator1 = malloc(sizeof(Creator)); *creator1 = DuckCreator;
  ClientCode(*creator1);
  free(creator1);

  printf("\n");
  // Создание и удаление в клиенте всей собаки
  printf("Step 2: Launched with the DogCreator.\n");
  Creator* creator2 = malloc(sizeof(Creator)); *creator2 = DogCreator;
  ClientCode(*creator2);
  free(creator2);

  printf("\n");
  // Автоматическое создание и удаление, так как утка создана локально
  // Пока утка не подключается
  printf("Step 3: Launched with the DuckCreator.\n");
  Creator creator3 = DuckCreator;
  ClientCode(creator3);

  printf("\n");
  // Автоматическое создание и удаление, так как собака создана локально
  // Пока собака не подключается
  Dog dog;
  printf("Step 4: Launched with the DogCreator.\n");
  Creator creator4 = DogCreator;
  ClientCode(creator4);

  return 0;
}
