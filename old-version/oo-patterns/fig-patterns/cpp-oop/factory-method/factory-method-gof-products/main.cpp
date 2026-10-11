//------------------------------------------------------------------------------
// main.cpp - Демонстрация фабричного метода, использующего дополнительный
// параметр для обращения к продуктам из одного создателя, а также подменяющего
// эти продукты в производном классе.
// Ведет к явному использованию условных операторов и невозможности
// эволюционного расширения
//------------------------------------------------------------------------------

#include <iostream>

//==============================================================================
// Описание возможных продуктов
//==============================================================================

//------------------------------------------------------------------------------
// Базовый класс, определяющий исходный продукт.
class Product {
public:
  // Вывод информации о продукте
  virtual void Print();
};
// Реализация метода вывода информации о базовом продукте
void Product::Print() { std::cout << "It is Product\n"; }

//------------------------------------------------------------------------------
// Класс, определяющий MyProduct.
class MyProduct: public Product {
public:
  // Вывод информации о продукте
  virtual void Print();
};
// Реализация метода вывода информации о базовом продукте
void MyProduct::Print() { std::cout << "It is MyProduct\n"; }

//------------------------------------------------------------------------------
// Класс, определяющий YourProduct.
class YourProduct: public Product {
public:
  // Вывод информации о продукте
  virtual void Print();
};
// Реализация метода вывода информации о базовом продукте
void YourProduct::Print() { std::cout << "It is YourProduct\n"; }

//------------------------------------------------------------------------------
// Класс, определяющий TheirProduct.
class TheirProduct: public Product {
public:
  // Вывод информации о продукте
  virtual void Print();
};
// Реализация метода вывода информации о базовом продукте
void TheirProduct::Print() { std::cout << "It is TheirProduct\n"; }

//==============================================================================
// Описание создателей продуктов
//==============================================================================

enum ProductId {DEFAULT, MINE, YOURS, THEIRS};

//------------------------------------------------------------------------------
// Создатель базового набора продуктов
class Creator {
public:
  virtual Product* Create(ProductId);
};
// Создатель линейки базового набора продуктов
Product* Creator::Create (ProductId id) {
  if (id == MINE) return new MyProduct;
  if (id == YOURS) return new YourProduct;
  // Повторить для всех остальных продуктов...
  return new Product;
}

//------------------------------------------------------------------------------
// Создатель дополнительного набора продуктов
class MyCreator: public Creator {
public:
  virtual Product* Create(ProductId);
};
// Создатель линейки базового набора продуктов
Product* MyCreator::Create (ProductId id) {
  // Внимание!!! YOURS и MINE переставлены
  if (id == YOURS) return new MyProduct;
  if (id == MINE)  return new YourProduct;
  if (id == THEIRS) return new TheirProduct;
  return Creator::Create(id); // Вызывается, если других вариантов не осталось
}


//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  std::cout << "Start\n";
  Product* product;
  Creator* c;

  Creator creator;
  c = &creator;

  std::cout << "MINE: ";
  product = c->Create(MINE);
  product->Print();
  delete product;

  std::cout << "YOURS: ";
  product = c->Create(YOURS);
  product->Print();
  delete product;

  std::cout << "DEFAULT: ";
  product = c->Create(DEFAULT);
  product->Print();
  delete product;

  MyCreator myCreator;
  c = &myCreator;

  std::cout << "MINE: ";
  product = c->Create(MINE);
  product->Print();
  delete product;

  std::cout << "YOURS: ";
  product = c->Create(YOURS);
  product->Print();
  delete product;

  std::cout << "THEIRS: ";
  product = c->Create(THEIRS);
  product->Print();
  delete product;

  std::cout << "DEFAULT: ";
  product = c->Create(DEFAULT);
  product->Print();
  delete product;

  std::cout << "Stop\n";
  return 0;
}