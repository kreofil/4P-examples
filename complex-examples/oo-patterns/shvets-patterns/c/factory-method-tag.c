#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Конкретные Продукты/
typedef struct ConcreteProduct1 {} ConcreteProduct1;
typedef struct ConcreteProduct2 {} ConcreteProduct2;

// Обобщенный продукт
typedef enum ProductTag {pTag1, pTag2,} ProductTag;
typedef struct Product {
  ProductTag tag;
  union {
    ConcreteProduct1 product1;
    ConcreteProduct2 product2;
  };
} Product;

char* OperationProduct1(ConcreteProduct1* p) {
  return "{Result of the ConcreteProduct1}";
}

char* OperationProduct2(ConcreteProduct2* p) {
  return "{Result of the ConcreteProduct2}";
}

char* Operation(Product* p) {
  switch(p->tag) {
    case pTag1: return OperationProduct1(&p->product1); break;
    case pTag2: return OperationProduct2(&p->product2); break;
    default: return NULL;
  }
};

// Создание конкретных продуктов
Product* FactoryMethodCreator1() {
  Product* p = malloc(sizeof(Product));
  p->tag = pTag1;
  return p;
}
Product* FactoryMethodCreator2() {
  Product* p = malloc(sizeof(Product));
  p->tag = pTag2;
  return p;
}

// Косвенное создание продукта в зависимости от создателя
Product* FactoryMethod(ProductTag c) {
  switch (c) {
    case pTag1: return FactoryMethodCreator1();
    case pTag2: return FactoryMethodCreator2();
    default: return NULL;
  }
}

// Также заметьте, что, несмотря на название, основная обязанность Создателя
// не заключается в создании продуктов. Обычно он содержит некоторую базовую
// бизнес-логику, которая основана на объектах Продуктов, возвращаемых
// фабричным методом.
void SomeOperation(ProductTag c, char* buf) {
  // Вызываем фабричный метод, чтобы получить объект-продукт.
  Product* product = FactoryMethod(c);
  // Далее, работаем с этим продуктом.
  char* result = "Creator: The same creator's code has just worked with ";
  strcpy(buf, result);
  strcat(buf, Operation(product));
  free(product);
}

// Клиентский код работает с экземпляром конкретного создателя, хотя и через его
// базовый интерфейс. Пока клиент продолжает работать с создателем через базовый
// интерфейс, вы можете передать ему любой подкласс создателя.
void ClientCode(ProductTag creator) {
  // ...
  printf("Client: I'm not aware of the creator's class, but it still works.\n");
  char buf[256];
  SomeOperation(creator, buf);
  printf("%s\n", buf);
  // ...
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main() {
  printf("App: Launched with the ConcreteCreator1.\n");
  ProductTag* creator1 = malloc(sizeof(ProductTag)); *creator1 = pTag1;
  ClientCode(*creator1);
  printf("\n");
  printf("App: Launched with the ConcreteCreator2.\n");
  ProductTag* creator2 = malloc(sizeof(ProductTag)); *creator2 = pTag2;
  ClientCode(*creator2);
  free(creator1);
  free(creator2);

  printf("\n");
  printf("App: Launched with the ConcreteCreator1.\n");
  ProductTag creator3 = pTag1;
  ClientCode(creator3);
  printf("\n");
  printf("App: Launched with the ConcreteCreator2.\n");
  ProductTag creator4 = pTag2;
  ClientCode(creator4);

  return 0;
}
