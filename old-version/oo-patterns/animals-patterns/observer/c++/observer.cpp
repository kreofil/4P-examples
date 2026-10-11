#include <iostream>
#include <string>

/**
 * Паттерн Наблюдатель
 *
 * Назначение: Создаёт механизм подписки, позволяющий одним объектам следить и
 * реагировать на события, происходящие в других объектах.
 */

#include <iostream>
#include <list>
#include <string>

//------------------------------------------------------------------------------
class IObserver { // Интерфейс наблюдателя
public:
  virtual ~IObserver(){};
  virtual void Update() = 0;
};

//------------------------------------------------------------------------------
// Абстрактный класс, определяющий базовый интерфейс субъекта
class ISubject { // Интерфейс субьекта
public:
  virtual ~ISubject(){};
  virtual void Attach(IObserver *observer) = 0;
  virtual void Detach(IObserver *observer) = 0;
  virtual void Notify() = 0;
};

//------------------------------------------------------------------------------
// Субьект, осуществляющий хранение целых чисел и уведомляющией своих
// наблюдателей по мере своих данных. Он также предоставляет наблюдателю
// по его запросу результат сложения двух аргументов
class AddSubject : public ISubject {
public:
  virtual ~AddSubject() {
    std::cout << "Goodbye, I was the AddSubject.\n";
  }

  // Методы управления подпиской.
  void Attach(IObserver *observer) override { // присоединение наблюдателя
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) override { // отсоединение наблюдателя
    list_observer_.remove(observer);
  }
  void Notify() override {  // уведомление наблюдателя об изменении
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObservers();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update();
      ++iterator;
    }
  }

  void HowManyObservers() { // число присоединенных наблюдателей
    std::cout << "There are " << list_observer_.size() << " observers in the list.\n";
  }

  // Изменение значений в субъекте
  void Set(int v1, int v2) {
    x1 = v1;
    x2 = v2;
    Notify();   // Уведомление об изменении
  }
  // Получение значения, предоставляемого субъектом
  int Get() {
    std::cout << x1 << " + " << x2 << " = ";
    return x1 + x2;
  }
  // Информация о субъекте
  void PrintInfo() {
    std::cout << "   Subject is Addition;\n";
  }
private:
  std::list<IObserver *> list_observer_; // список наблюдателей
  // целые числа, определяющие субъекта
  int x1;
  int x2;
};

//------------------------------------------------------------------------------
// Наблюдатель, получающий целое число от соответствующих субъектов
// и осуществляющий его вывод в десятичной системе счисления.
class DecObserver : public IObserver {
public:
  // Заточен на AddSubject, так как использует доступ
  // к невиртуальному методу Get
  DecObserver(AddSubject &subject) : subject_(subject) {
    subject_.Attach(this); // наблюдатель цепляется к полученному субъекту
  }
  virtual ~DecObserver() {
    std::cout << "Goodbye, I was the DecObserver.\n";
  }

  void Update() override {
    // Addition->Decimal: 32 + 10 = 42
    std::cout << "Addition->Decimal: " << std::dec << subject_.Get() << "\n";
    subject_.PrintInfo();
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "DecObserver removed from the list.\n";
  }
  void PrintInfo() {
    std::cout << "   Observer is Decimal;\n";
  }
private:
  AddSubject &subject_;
};

//------------------------------------------------------------------------------
// Наблюдатель, получающий целое число от соответствующих субъектов
// и осуществляющий его вывод в шестнадцатиричной системе счисления.
class HexObserver : public IObserver {
public:
  // Заточен на AddSubject, так как использует доступ
  // к невиртуальному методу Get
  HexObserver(AddSubject &subject) : subject_(subject) {
    subject_.Attach(this); // наблюдатель цепляется к полученному субъекту
  }
  virtual ~HexObserver() {
    std::cout << "Goodbye, I was the HexObserver.\n";
  }

  void Update() override {
    std::cout << "Addition->Hex: " << std::hex << subject_.Get() << "\n";
    subject_.PrintInfo();
    PrintInfo();
  }
  void RemoveMeFromTheList() {
    subject_.Detach(this);
    std::cout << "HexObserver removed from the list.\n";
  }
  void PrintInfo() {
    std::cout << "   Observer is Hex;\n";
  }
private:
  AddSubject &subject_;
};

void ClientCode() {
  AddSubject addSubject;
  DecObserver decObserver(addSubject);
  HexObserver hexObserver(addSubject);
  addSubject.Set(10, 32);
  addSubject.Set(-15, 10);
  addSubject.Set(10, 3);
  decObserver.RemoveMeFromTheList();
  addSubject.Set(100, 300);
}

int main() {
  ClientCode();
  return 0;
}
