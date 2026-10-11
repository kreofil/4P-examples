#include <iostream>
#include <string>

// Абстрактный класс, определяющий обобщенную стратегию
class Strategy {
protected:
  Strategy* nextStrategy;
public:
  Strategy(): nextStrategy{nullptr} {}
  void SetStrategy(Strategy* s) {nextStrategy = s;}
  virtual ~Strategy() {}
  virtual void Action(std::string& name, int age) {
    if(nextStrategy != nullptr) {
      std::cout << "\n    ";
      nextStrategy->Action(name, age);
    }
  }
};

// Конкретная стратегия, осуществляющая вывод в начале имени, а затем возраста
class NameAgeStrategy : public Strategy {
public:
  void Action(std::string& name, int age) {
    std::cout << "Name is " << name << ", age = " << age;
    // Необязательное действие, если алгоритму не нужно
    Strategy::Action(name, age);
  }
};

// Конкретная стратегия, осуществляющая вывод в начале возраста, а затем имени
class AgeNameStrategy : public Strategy {
public:
  void Action(std::string& name, int age) {
    std::cout << "Age = " << age << ", name is " << name;
    // Необязательное действие, если алгоритму не нужно
    Strategy::Action(name, age);
  }
};

// Обобщенное животное, определяемое в базовом классе.
// Также используется для обобщение декораторов.
class Animal {
  Strategy* strategy;
  std::string name;
  int age;
public:
  Animal(std::string n, int a): name{n}, age{a}, strategy{nullptr} {}
  virtual ~Animal() {}
  virtual void GetInfo() const = 0;
  void SetStrategy(Strategy* s) {strategy = s;}
  void UseStrategy() {
    GetInfo();
    if(strategy != nullptr) {
      std::cout << ". ";
      strategy->Action(name, age);
    }
    std::cout << "\n";
  }
};

// Утка
class Duck : public Animal {
public:
  Duck(std::string n, int a): Animal{n, a} {}
  void GetInfo() const override {
    std::cout << "I am the Duck";
  }
};
// Собака
class Dog : public Animal {
public:
  Dog(std::string n, int a): Animal{n, a} {}
  void GetInfo() const override {
    std::cout << "I am the Dog";
  }
};

// Клиент запускает стратегию, подключенную к животному
void ClientCode(Animal* a) {
  a->UseStrategy();
}

int main() {
  NameAgeStrategy nas;
  AgeNameStrategy ans;

  Duck duck("Grey Neck", 2);
  duck.SetStrategy(&nas);
  ClientCode(&duck);
  duck.SetStrategy(&ans);
  ClientCode(&duck);

  Dog  dog("Rex", 5);
  dog.SetStrategy(&nas);
  ClientCode(&dog);
  dog.SetStrategy(&ans);
  ClientCode(&dog);

  Duck newDuck("Black Cape", 4);
  newDuck.SetStrategy(&nas);
  nas.SetStrategy(&ans);
  ClientCode(&newDuck);
  newDuck.SetStrategy(&ans);
  ClientCode(&newDuck);


  return 0;
}