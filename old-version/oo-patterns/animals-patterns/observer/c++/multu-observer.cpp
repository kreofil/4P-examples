#include <iostream>
#include <string>

/**
 * Паттерн Наблюдатель, использующий наблюдателя с разными субъектами
 *
 * Назначение: Создаёт механизм подписки, позволяющий одним объектам следить и
 * реагировать на события, происходящие в других объектах.
 */

#include <iostream>
#include <list>
#include <string>

class BaseSubject;

//------------------------------------------------------------------------------
class IObserver { // Интерфейс наблюдателя
public:
  virtual ~IObserver(){};
  virtual void Update(BaseSubject* subject) = 0;
};

//------------------------------------------------------------------------------
// Абстрактный класс, определяющий базовый интерфейс субъекта
class BaseSubject { // Интерфейс субьекта
public:
  virtual ~BaseSubject(){};
  // Методы управления подпиской.
  void Attach(IObserver *observer) { // присоединение наблюдателя
    list_observer_.push_back(observer);
  }
  void Detach(IObserver *observer) { // отсоединение наблюдателя
    list_observer_.remove(observer);
  }
  void Notify() {  // уведомление наблюдателя об изменении
    std::list<IObserver *>::iterator iterator = list_observer_.begin();
    HowManyObservers();
    while (iterator != list_observer_.end()) {
      (*iterator)->Update(this);
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
  virtual int Get() = 0;
  // Информация о субъекте
  virtual void PrintInfo() = 0;
protected:
  std::list<IObserver *> list_observer_; // список наблюдателей
  // целые числа, определяющие субъекта
  int x1;
  int x2;
};

//------------------------------------------------------------------------------
// Субьект, осуществляющий хранение целых чисел и уведомляющией своих
// наблюдателей по мере своих данных. Он также предоставляет наблюдателю
// по его запросу результат сложения двух аргументов
class AddSubject : public BaseSubject {
public:
  virtual ~AddSubject() {
    std::cout << "Goodbye, I was the AddSubject.\n";
  }

  // Получение значения, предоставляемого субъектом
  int Get() override {
    std::cout << x1 << " + " << x2 << " = ";
    return x1 + x2;
  }
  // Информация о субъекте
  void PrintInfo() override {
    std::cout << "   Subject is Addition;\n";
  }
};

//------------------------------------------------------------------------------
// Субъект, осуществляющий деление целых чисел.
// Совместим по наблюдателям с субъектом, складывающим целые числа.
class DivSubject : public BaseSubject {
public:
  virtual ~DivSubject() {
    std::cout << "Goodbye, I was the DivSubject.\n";
  }

  // Получение значения, предоставляемого субъектом
  int Get() override {
    std::cout << x1 << " / " << x2 << " = ";
    return x1 / x2;
  }
  // Информация о субъекте
  void PrintInfo() override {
    std::cout << "   Subject is Division;\n";
  }
};

//------------------------------------------------------------------------------
// Наблюдатель, получающий целое число от соответствующих субъектов
// и осуществляющий его вывод в десятичной системе счисления.
class DecObserver : public IObserver {
public:
  // Заточен на AddSubject, так как использует доступ
  // к невиртуальному методу Get
  // DecObserver(AddSubject &subject) : subject_(subject) {
  //   subject_.Attach(this); // наблюдатель цепляется к полученному субъекту
  // }
  virtual ~DecObserver() {
    std::cout << "Goodbye, I was the DecObserver.\n";
  }

  void Update(BaseSubject* subject) override {
    // Addition->Decimal: 32 + 10 = 42
    std::cout << "Addition->Decimal: " << std::dec << subject->Get() << "\n";
    subject->PrintInfo();
    PrintInfo();
  }
  // void RemoveMeFromTheList() {
  //   subject_.Detach(this);
  //   std::cout << "DecObserver removed from the list.\n";
  // }
  void PrintInfo() {
    std::cout << "   Observer is Decimal;\n";
  }
// private:
//   BaseSubject &subject_;
};

//------------------------------------------------------------------------------
// Наблюдатель, получающий целое число от соответствующих субъектов
// и осуществляющий его вывод в шестнадцатиричной системе счисления.
class HexObserver : public IObserver {
public:
  // Заточен на AddSubject, так как использует доступ
  // к невиртуальному методу Get
  // HexObserver(AddSubject &subject) : subject_(subject) {
  //   subject_.Attach(this); // наблюдатель цепляется к полученному субъекту
  // }
  virtual ~HexObserver() {
    std::cout << "Goodbye, I was the HexObserver.\n";
  }

  void Update(BaseSubject* subject) override {
    std::cout << "Addition->Hex: " << std::hex << subject->Get() << "\n";
    subject->PrintInfo();
    PrintInfo();
  }
  // void RemoveMeFromTheList() {
  //   subject_.Detach(this);
  //   std::cout << "HexObserver removed from the list.\n";
  // }
  void PrintInfo() {
    std::cout << "   Observer is Hex;\n";
  }
// private:
//   AddSubject &subject_;
};

void ClientCode() {
  AddSubject addSubject;
  DecObserver decObserver;
  addSubject.Attach(&decObserver);
  HexObserver hexObserver;
  addSubject.Attach(&hexObserver);
  addSubject.Set(10, 32);
  addSubject.Set(-15, 10);
  addSubject.Set(10, 3);
  addSubject.Set(100, 300);

  DivSubject divSubject;
  divSubject.Attach(&decObserver);
  divSubject.Attach(&hexObserver);
  divSubject.Set(10, 3);

}

int main() {
  ClientCode();
  return 0;
}
