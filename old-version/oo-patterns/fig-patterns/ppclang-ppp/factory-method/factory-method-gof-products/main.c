//------------------------------------------------------------------------------
// main.c - Демонстрация фабричного метода, использующего дополнительный
// параметр для обращения к продуктам из одного создателя, а также подменяющего
// эти продукты в производном классе.
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
void Print<Product* p>() { printf("It is Product\n"); }

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
// Специализация, определяющая Product.YourProduct
typedef struct TheirProduct {} TheirProduct;
Product + <TheirProduct;>;
// Реализация метода вывода информации о специализации Product.YourProduct
void Print<Product.TheirProduct* p>() { printf("It is TheirProduct\n"); }

//==============================================================================
// Описание создателей продуктов
//==============================================================================

// Обобщение, определяющее создатель для исходного продукта
typedef struct Creator {}<> Creator;

// Обобщение, определяющее разновидность продукта
// typedef struct SubProduct {}<MINE, YOURS: void;> SubProduct;
typedef struct SubProduct {} <> SubProduct;

// Обобщение и специализации для порождения конкретных подпродуктов
// struct SubProduct + <MINE, YOURS: void;>;
struct SubProduct + <MINE: void;>;
struct SubProduct + <YOURS: void;>;

//------------------------------------------------------------------------------
// Обобщающая функция, реализующая создание Product
Product* CreateSubProduct<SubProduct* id>() {
  return create_spec(Product);
}

// Обработчик специализации, реализующий создание Product.MyProduct
Product* CreateSubProduct<SubProduct.MINE* id>() {
  return create_spec(Product.MyProduct);
}

// Обработчик специализации, реализующий создание Product.YourProduct
Product* CreateSubProduct<SubProduct.YOURS* id>() {
  return create_spec(Product.YourProduct);
}
// Реализация прочих субпродуктов ...

// Обработчик специализации, реализующий создание альтернативных продуктов
Product* CreateProduct<Creator* tag>(SubProduct* id) {
  return CreateSubProduct<id>();
}

//------------------------------------------------------------------------------
// Новый создатель
Creator + <MyCreator: void;>;
// Новый подпродукт
struct SubProduct + <THEIR: void;>;

//------------------------------------------------------------------------------
// Обобщающая функция, реализующая Обращение к предыдущим подпродуктам
Product* CreateMySubProduct<SubProduct* id>() {
  return CreateSubProduct<id>();
}

// Обработчик специализации, реализующий создание Product.YourProduct
// используя другой признак
Product* CreateMySubProduct<SubProduct.MINE* id>() {
  return create_spec(Product.YourProduct);
}

// Обработчик специализации, реализующий создание Product.MyProduct
// используя другой признак
Product* CreateMySubProduct<SubProduct.YOURS* id>() {
  return create_spec(Product.MyProduct);
}

// Обработчик специализации, реализующий создание Product.TheirProduct
Product* CreateMySubProduct<SubProduct.THEIR* id>() {
  return create_spec(Product.TheirProduct);
}

// Обработчик специализации, реализующий создание моих продуктов
Product* CreateProduct<Creator.MyCreator* tag>(SubProduct* id) {
  return CreateMySubProduct<id>();
}

//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  printf("Start\n");
  Product* product;
  Creator* c;
  struct SubProduct.MINE mine;
  struct SubProduct.YOURS yours;
  struct SubProduct base;
  struct SubProduct.THEIR their;

  Creator creator;
  c = &creator;

  printf("MINE: ");
  product = CreateProduct<c>((struct SubProduct *)&mine);
  Print<product>();
  free(product);

  printf("YOURS: ");
  product = CreateProduct<c>((struct SubProduct *)&yours);
  Print<product>();
  free(product);

  printf("DEFAULT: ");
  product = CreateProduct<c>(&base);
  Print<product>();
  free(product);

  struct Creator.MyCreator myCreator;
  c = (Creator*)&myCreator;

  printf("MINE: ");
  product = CreateProduct<c>((struct SubProduct *)&mine);
  Print<product>();
  free(product);

  printf("YOURS: ");
  product = CreateProduct<c>((struct SubProduct *)&yours);
  Print<product>();
  free(product);

  printf("THEIR: ");
  product = CreateProduct<c>((struct SubProduct *)&their);
  Print<product>();
  free(product);

  printf("DEFAULT: ");
  product = CreateProduct<c>(&base);
  Print<product>();
  free(product);

  printf("Stop\n");
  return 0;
}