#include <iostream>
#include <string>

// Обобщенное животное, определяемое в базовом классе.
class Animal {
protected:
  std::string name;   // имя животного, чтобы отличать экземпляры
  int age;            // возраст
public:

  Animal(std::string n, int a): name{n}, age{a} {}
  virtual ~Animal() {}
  void PrintNameAndAge() {
    std::cout << "My name is " << name << ". I'm " << age << " years old.\n";
  }
  virtual void Info() = 0;  // Общие сведения
  virtual void StandUp() = 0;       // когда встает
  virtual void Action() = 0;        // повседневное занятие
  virtual void Voice() = 0;         // какой голос

  void Behavior() {         // поведение - комплекс действий
    Info();
    StandUp();
    Voice();
    Action();
  }
};

// Петух
class Rooster : public Animal {
public:
  Rooster(std::string n, int a): Animal{n, a} {}
  void Info() {
    std::cout << "Hi! I am the Rooster. ";
    PrintNameAndAge();
  }
  void Voice() {
    std::cout << "I shout \"Cock-a-doodle-doo!\" all day long.\n";
  }
  void StandUp() {
    std::cout << "I get up early in the morning and go to bed when the sun sets.\n";
  }
  void Action() {
    std::cout << "I spend all day chasing chickens.\n";
  }
};

// Собака
class Dog : public Animal {
public:
  Dog(std::string n, int a): Animal{n, a} {}
  void Info() {
    std::cout << "Hello! I am the Dog. ";
    PrintNameAndAge();
  }
  void Voice() {
    std::cout << "I bark \"woof-woof\" when I see strangers.\n";
  }
  void StandUp() {
    std::cout << "I sleep all day and wake up in the evening.\n";
  }
  void Action() {
    std::cout << "My job is to protect the house from burglars.\n";
  }
};

// Клиент использует шаблонный метод через указатель на обобщение
void ClientCode(Animal* a) {
  a->Behavior();
}

// Тестовая функция, создающая животных
// и запускающая их поведение через клиента.
int main() {
  Rooster rooster("Petya", 2);
  ClientCode(&rooster);

  std::cout << "\n";

  Dog  dog("Rex", 5);
  ClientCode(&dog);

  return 0;
}