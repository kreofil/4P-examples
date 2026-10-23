#include <iostream>
#include <string>

/**
 * Интерфейс Посетителя объявляет набор методов посещения, соответствующих
 * классам компонентов. Сигнатура метода посещения позволяет посетителю
 * определить конкретный класс компонента, с которым он имеет дело.
 */
class Duck;
class Dog;

class Visitor {
 public:
  virtual void VisitDuck(const Duck *duck) const = 0;
  virtual void VisitDog(const Dog *dog) const = 0;
};

// Интерфейс животных. Может расширятья их общим поведением
class Animal {
public:
  virtual ~Animal() {}
  virtual void Accept(Visitor *visitor) const = 0;
  // ...
};

// Конкретные животные предоставляют различные реализации интерфейса.
class Duck : public Animal {
public:
  Duck() {std::cout << "Duck created!\n";}
  void Accept(Visitor *visitor) const override {
    visitor->VisitDuck(this);
  }
  std::string AboutDuck() const {
    return "It is the Duck.";
  }
};
class Dog : public Animal {
public:
  Dog() {std::cout << "Dog created!\n";}
  void Accept(Visitor *visitor) const override {
    visitor->VisitDog(this);
  }
  std::string AboutDog() const {
    return "It is the Dog.";
  }
};

// Посетитель, показывающий предпочтения в еде
class FeedVisitor : public Visitor {
 public:
  void VisitDuck(const Duck *duck) const override {
    std::cout << duck->AboutDuck() << " It eats grain\n";
  }
  void VisitDog(const Dog *dog) const override {
    std::cout << dog->AboutDog() << " It eats meat\n";
  }
};

// Посетитель, демонстрирующий отношение к плаванию
class SwimVisitor : public Visitor {
 public:
   void VisitDuck(const Duck *duck) const override {
     std::cout << duck->AboutDuck() << " It is very good swimmer.\n";
   }
   void VisitDog(const Dog *dog) const override {
     std::cout << dog->AboutDog() << " It is not a good swimmer.\n";
   }
};

// Клиентский код может выполнять операции посетителя над любым набором.
void Client(Animal* animal, Visitor *visitor) {
    animal->Accept(visitor);
}

int main() {
  Duck duck;
  Dog dog;
  FeedVisitor feeding;
  SwimVisitor swimming;
  Client(&duck, &feeding);
  Client(&dog, &feeding);
  Client(&duck, &swimming);
  Client(&dog, &swimming);

  return 0;
}
