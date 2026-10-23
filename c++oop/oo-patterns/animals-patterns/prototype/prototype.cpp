#include <iostream>
#include <string>

// Паттерн Прототип. Позволяет копировать объекты,
// не вдаваясь в подробности их реализации.

// Используется клонирование животных.
class Animal {
protected:
  std::string name;
public:
  Animal(std::string n): name{n} {}
  virtual ~Animal(){}
  virtual Animal *Clone() const = 0;
};

class Duck : public Animal {
public:
  Duck(std::string n): Animal(n) {
    std::cout << "The Duck " << name << " created\n";
  }
  Animal *Clone() const override {
    std::cout << "The clone of duck: ";
    return new Duck(name);
  }
};

class Dog : public Animal {
public:
  Dog(std::string n): Animal(n) {
    std::cout << "The Dog " << name  << " created\n";
  }
  Animal *Clone() const override {
    std::cout << "The clone of dog: ";
    return new Dog(name);
  }
};

void Client() {
  std::cout << "Let's create a Duck\n";
  Duck duck("Grey Neck");
  std::cout << "\nLet's create a Clone of the Duck\n";
  Animal* duckClone = duck.Clone();
  delete duckClone;

  std::cout << "\nLet's create a Dog\n";
  Dog dog("Rex");
  std::cout << "\nLet's create a Clone of the Dog\n";
  Animal* dogClone = dog.Clone();
  delete dogClone;
}

int main() {
  Client();

  return 0;
}