//------------------------------------------------------------------------------
// main.c - Демонстрация фабричного метода, использующего вместо дополнительного
// параметра полиморфный аргумент для обращения к продуктам из одного создателя.
// То есть, используется мультиметод
// Ведет к явному использованию условных операторов и невозможности
// эволюционного расширения
//------------------------------------------------------------------------------

#include "stdio.h"
#include "stdlib.h"

//==============================================================================
// Описание возможных продуктов
//==============================================================================

//------------------------------------------------------------------------------
// Обобщение, определяющее исходный продукт.
typedef struct Product {} <> Product;
// Реализация обобщающей функции вывода информации о базовом продукте
void Print<Product* p>() { printf("Error: It is not Product\n"); }

//------------------------------------------------------------------------------
// Специализация, определяющая Product.Base
typedef struct Base {} Base;
Product + <Base;>;
// Реализация метода вывода информации о специализации Product.Base
void Print<Product.Base* p>() { printf("It is BaseProduct\n"); }

//------------------------------------------------------------------------------
// Специализация, определяющая Product.MyProduct
typedef struct MyProduct {} MyProduct;
Product + <MyProduct;>;
// Реализация метода вывода информации о специализации Product.MyProduct
void Print<Product.MyProduct* p>() { printf("It is MyProduct\n"); }

//------------------------------------------------------------------------------
// Специализация, определяющая Product.YourProduct
typedef struct YourProduct {} YourProduct;
Product + <YourProduct;>;
// Реализация метода вывода информации о специализации Product.YourProduct
void Print<Product.YourProduct* p>() { printf("It is YourProduct\n"); }

//------------------------------------------------------------------------------
// Специализация, определяющая Product.TheirProduct
typedef struct TheirProduct {} TheirProduct;
Product + <TheirProduct;>;
// Реализация метода вывода информации о специализации Product.YourProduct
void Print<Product.TheirProduct* p>() { printf("It is TheirProduct\n"); }

//==============================================================================
// Описание создателей продуктов
//==============================================================================

// Обобщение, определяющее создатель для исходного продукта
typedef struct Creator {}<Base: void> Creator;

// Обобщение, определяющее разновидность продукта
// typedef struct SubProduct {}<MINE, YOURS: void;> SubProduct;
typedef struct SubProduct {} <BASE: void> SubProduct;

// Обобщение и специализации для порождения конкретных подпродуктов
// struct SubProduct + <MINE, YOURS: void;>;
struct SubProduct + <MINE: void;>;
struct SubProduct + <YOURS: void;>;

//------------------------------------------------------------------------------
// Использование мультиметода, вместо передачи параметра

// Обобщающая функция, реализующая создание Product
Product* CreateProduct<Creator* tag, SubProduct* id>() {
  return create_spec(Product);
}

// Обработчик специализации, реализующий создание Product.Base
Product* CreateProduct<Creator.Base* tag, SubProduct.BASE* id>() {
  Product* p = (Product*)create_spec(Product.Base);
  return p;
}

// Обработчик специализации, реализующий создание Product.MyProduct
Product* CreateProduct<Creator.Base* tag, SubProduct.MINE* id>() {
  Product* p = (Product*)create_spec(Product.MyProduct);
  return p;
}

// Обработчик специализации, реализующий создание Product.YourProduct
Product* CreateProduct<Creator.Base* tag, SubProduct.YOURS* id>() {
  return create_spec(Product.YourProduct);
}
// Реализация прочих субпродуктов ...

//------------------------------------------------------------------------------
// Новый создатель
Creator + <MyCreator: void;>;
// Новый подпродукт
struct SubProduct + <THEIR: void;>;

//------------------------------------------------------------------------------
// Обработчик специализации, реализующий создание Product.MyProduct
Product* CreateProduct<Creator.MyCreator* tag, SubProduct.MINE* id>() {
  return (Product*)create_spec(Product.YourProduct);
}

// Обработчик специализации, реализующий создание Product.YourProduct
Product* CreateProduct<Creator.MyCreator* tag, SubProduct.YOURS* id>() {
  return (Product*)create_spec(Product.MyProduct);
}

// Обработчик специализации, реализующий создание Product.TheirProduct
Product* CreateProduct<Creator.MyCreator* tag, SubProduct.THEIR* id>() {
  return (Product*)create_spec(Product.TheirProduct);
}

// Обработчик специализации, реализующий создание от Creator
// Для прочих ситуаций
Product* CreateProduct<Creator.MyCreator* tag, SubProduct.BASE* id>() {
  struct Creator.Base c;
  return CreateProduct<(Creator*)&c, (SubProduct*)id>();
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  printf("Start\n");
  Product* product;
  Creator* c;
  struct SubProduct incorrect;
  struct SubProduct.MINE mine;
  struct SubProduct.YOURS yours;
  struct SubProduct.BASE base;
  struct SubProduct.THEIR their;

  struct Creator.Base creator;
  c = (Creator*)&creator;

  printf("BASE: ");
  product = CreateProduct<c, (SubProduct*)&base>();
  Print<product>();
  free(product);

  printf("MINE: ");
  product = CreateProduct<c, (SubProduct*)&mine>();
  Print<product>();
  free(product);

  printf("YOURS: ");
  product = CreateProduct<c, (SubProduct*)&yours>();
  Print<product>();
  free(product);

  printf("DEFAULT: ");
  product = CreateProduct<c, (SubProduct*)&base>();
  Print<product>();
  free(product);

  struct Creator.MyCreator myCreator;
  c = (Creator*)&myCreator;

  printf("MINE: ");
  product = CreateProduct<c, (SubProduct*)&mine>();
  Print<product>();
  free(product);

  printf("YOURS: ");
  product = CreateProduct<c, (SubProduct*)&yours>();
  Print<product>();
  free(product);

  printf("THEIR: ");
  product = CreateProduct<c, (SubProduct*)&their>();
  Print<product>();
  free(product);

  printf("DEFAULT: ");
  product = CreateProduct<c, (SubProduct*)&base>();
  Print<product>();
  free(product);

  printf("Stop\n");
  return 0;
}