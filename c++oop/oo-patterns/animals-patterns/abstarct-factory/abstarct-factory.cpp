#include <iostream>
#include <string>

//------------------------------------------------------------------------------
// Абстрактная утка, от которой наследуюют утки разных семейств.
class Duck {
public:
  Duck() {std::cout << "Duck created! ";}
};
// Абстрактная собака, от которой наследуют собаки разных семейств
class Dog {
public:
  Dog() {std::cout << "Dog created! ";}
};

//------------------------------------------------------------------------------
// Семейство домашних животных
//------------------------------------------------------------------------------
// Домашняя утка
class DomesticDuck: public Duck {
public:
  DomesticDuck(): Duck() {
    std::cout << "It is Domestic duck.\n";
  }
};
// Домашняя собака
class DomesticDog: public Dog {
public:
  DomesticDog(): Dog() {
    std::cout << "It is Domestic dog.\n";
  }
};

//------------------------------------------------------------------------------
// Семейство животных - игрушек
//------------------------------------------------------------------------------
// Игрушечная утка
class ToyDuck:public Duck {
public:
  ToyDuck(): Duck() {
    std::cout << "It is Toy duck.\n";
  }
};
// Игрушечная собака
class ToyDog:public Dog {
public:
  ToyDog(): Dog() {
    std::cout << "It is Toy dog.\n";
  }
};

//------------------------------------------------------------------------------
// Абстрактная фабрика, используемая для порождения фабрик различных семейств.
class AbstractFactory {
 public:
  virtual Duck *CreateDuck() const = 0;
  virtual Dog  *CreateDog()  const = 0;
};

// Фабрика домашних животных
class DomesticFactory : public AbstractFactory {
 public:
  virtual Duck *CreateDuck() const override {
    return new DomesticDuck();
  }
  virtual Dog *CreateDog() const override {
    return new DomesticDog();
  }
};

// Фабрика животных - игрушек
class ToyFactory : public AbstractFactory {
public:
  virtual Duck *CreateDuck() const override {
    return new ToyDuck();
  }
  virtual Dog *CreateDog() const override {
    return new ToyDog();
  }
};


//------------------------------------------------------------------------------
// Клиентский код работает с фабриками и животными только через абстрактные
// типы: Это позволяет передавать любой подкласс фабрики или продукта
// клиентскому коду, не нарушая его.
void ClientCode(const AbstractFactory &factory) {
  const Duck *duck = factory.CreateDuck();
  const Dog *dog = factory.CreateDog();
  delete duck;
  delete dog;
}

//------------------------------------------------------------------------------
//  Тестирование фабрик и животных
int main() {
  std::cout <<
      "Step 1: Testing client code with the first factory type:\n";
  DomesticFactory *f1 = new DomesticFactory();
  ClientCode(*f1);
  delete f1;

  std::cout << std::endl;
  std::cout <<
      "Step 2: Testing the same client code with the second factory type:\n";
  ToyFactory *f2 = new ToyFactory();
  ClientCode(*f2);
  delete f2;

  std::cout << std::endl;
  std::cout <<
      "Step 3: Testing client code with the first factory type:\n";
  DomesticFactory f3;
  ClientCode(f3);

  std::cout << std::endl;
  std::cout <<
      "Step 4: Testing the same client code with the second factory type:\n";
  ToyFactory f4;
  ClientCode(f4);

  return 0;
}
