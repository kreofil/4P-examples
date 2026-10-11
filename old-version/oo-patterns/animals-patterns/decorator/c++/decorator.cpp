#include <iostream>
#include <string>

// Обобщенное животное, определяемое в базовом классе.
// Также используется для обобщение декораторов.
class Animal {
 public:
  virtual ~Animal() {}
  virtual void GetInfo() const = 0;
};

// Утка
class Duck : public Animal {
public:
  void GetInfo() const override {
    std::cout << "I am the Duck";
  }
};
// Собака
class Dog : public Animal {
public:
  void GetInfo() const override {
    std::cout << "I am the Dog";
  }
};

// Абстрактный декоратор для расширения cdjqcnd животных
class Decorator : public Animal {
protected:
  Animal* animal;
public:
  Decorator(Animal* a) : animal{a} {}
  void GetInfo() const override {animal->GetInfo();}
};
// Конкретные Декораторы вызывают обёрнутый объект
// и изменяют его результат некоторым образом.
class Age : public Decorator {
  int age;
public:
  Age(Animal* a, int _age) : age{_age}, Decorator(a) {}
  void GetInfo() const override {
    Decorator::GetInfo();
    std::cout << ", I am " << age << " yeas old.";
  }
};
class Name : public Decorator {
  std::string name;
 public:
  Name(Animal* a, std::string n) : name{n}, Decorator(a) {}
  void GetInfo() const override {
    std::cout << "My name is " << name << ". ";
    Decorator::GetInfo();
  }
};

// Клиент запускает сформированных животных
void ClientCode(Animal* a) {
  std::cout << "\n";
  a->GetInfo();
  std::cout << "\n";
}

int main() {
  std::cout << "Different Animals:\n";
  Duck duck;
  Dog  dog;

  ClientCode(&duck);
  ClientCode(&dog);

  Age duckAge{&duck, 2};
  ClientCode(&duckAge);

  Age dogAge{&dog, 5};
  Name dogName{&dogAge, "Rex"};
  ClientCode(&dogName);

  Name otherDogName{&dog, "Mu-mu"};
  Age otherDogAge{&otherDogName, 3};
  ClientCode(&otherDogAge);

  return 0;
}