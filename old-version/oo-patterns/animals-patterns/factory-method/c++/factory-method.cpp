#include <iostream>

// Интерфейс животных. Может расширятья их общим поведением
class Animal {
 public:
  virtual ~Animal() {}
  // ...
};


// Конкретные животные предоставляют различные реализации интерфейса.
class Duck : public Animal {
public:
  Duck() {std::cout << "Duck created!\n";}
};
class Dog : public Animal {
public:
  Dog() {std::cout << "Dog created!\n";}
};


// Класс создателя животных объявляет фабричный метод, который должен возвращать
// Указатель на общий для всех животных интерфейс.
// Подклассы предоставляют реализацию этого метода.
class Creator {
  // Создатель может также обеспечить реализацию фабричного метода по умолчанию.
public:
  virtual ~Creator(){};
  virtual Animal* FactoryMethod() const = 0;
  // Обязанность Создателя не заключается в создании животных. Обычно он
  // содержит некоторую базовую логику. Подклассы могут косвенно изменять эту
  // логику, переопределяя фабричный метод и возвращая другой вид животных.
  Animal* NewAnimal() const {
    // Вызываем фабричный метод, чтобы получить некоторое животное.
    return this->FactoryMethod();
  }
};

// Конкретные Создатели переопределяют фабричный метод, чтобы изменить
// вид животного.
class DuckCreator : public Creator {
  // Сигнатура метода по-прежнему использует тип абстрактного животного,
  // хотя фактически из метода возвращается конкретное животное. Таким образом,
  // Создатель может оставаться независимым от конкретных классов животных.
public:
  Animal* FactoryMethod() const override {
    return new Duck();
  }
};

class DogCreator : public Creator {
 public:
  Animal* FactoryMethod() const override {
    return new Dog();
  }
};

// Клиентский код работает с экземпляром конкретного создателя, через его
// базовый интерфейс. Можно передать ему любой подкласс создателя.
void ClientCode(const Creator& creator) {
  // ...
  std::cout
    << "Client: I'm not aware of the creator's class, but it still works.\n";
  Animal* animal = creator.NewAnimal();
  // Любые операции с животным, если он содержит
  // дополнительные общие виртуальные методы.
  // ...
  delete animal;
}

// Приложение выбирает тип создателя в зависимости от конфигурации или среды.
int main() {
  std::cout << "Step 1: Launched with the DuckCreator.\n";
  Creator* creator1 = new DuckCreator();
  ClientCode(*creator1);
  delete creator1;

  std::cout << std::endl;
  std::cout << "Step 2: Launched with the DogCreator.\n";
  Creator* creator2 = new DogCreator();
  ClientCode(*creator2);
  delete creator2;

  std::cout << std::endl;
  std::cout << "Step 3: Launched with the DuckCreator.\n";
  DuckCreator creator3;
  ClientCode(creator3);

  std::cout << std::endl;
  std::cout << "Step 4: Launched with the DogCreator.\n";
  DogCreator creator4;
  ClientCode(creator4);

  return 0;
}
