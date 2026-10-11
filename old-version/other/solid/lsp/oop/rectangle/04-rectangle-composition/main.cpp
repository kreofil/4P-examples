#include <iostream>

// Интерфейс, используемый для родственных связей
class RectInterface {
public:
  virtual double Area() = 0;
  virtual void Print() = 0;
};

class Rectangle: public RectInterface {
  int x, y;   // стороны прямоугольника
public:
  void setX(int _x) {x = _x;}
  void setY(int _y) {y = _y;}

  int getX() {return x;}
  int getY() {return y;}

  double Area() override {
    return double(x * y);
  }
  void Print() override {
    std::cout << "Rectangle. x = " << x << "; y = " << y << "\n";
  }
};

// Код, использующий прямоугольник в большом приложении
class Application {
public:
  // Метод, обеспечивающий использование подстановки
  void BigMethod(RectInterface& r) {
    auto result = r.Area() / -2.0;
    std::cout << "Result = " << result << "\n";
  }
};

// Подтип, расширяющий родителя добавлением счетчика и вычислением периметра
class Counter: public RectInterface {
  int counter;
  Rectangle* rect;
public:
  Counter(Rectangle* r): counter{0}, rect{r} {}

  double Area() override {
    ++counter;
    return rect->Area();
  }

  void Print() override {
    rect->Print();
    std::cout << "    Counter = " << counter << "\n";
  }

  double Perimeter() {
    return 2.0 * (rect->getX() + rect->getY());
  }
};

// Дополнительный код расширяющий ранее написанное приложение
class Expanded {
public:
  // Метод, обеспечивающий поддержку дополнительной функциональности
  void ExpandedMethod(Counter &c) {

    auto result = c.Perimeter() * 20.0;
    std::cout << "Counted Expanded result = " << result << "\n";
  }
};

// Новый клиентский код, использующий разработанное большое приложение
// И дополнительную приладу, связанную с появлением подставляемого подтипа
int main(int argc, char* argv[]) {
  if(argc != 3) {
    std::cout << "Incorrect command line. Use " << argv[0] << "X Y\n";
    return -1;
  }
  //----------------------------------------------------------------------------
  std::cout << "---------- Using a simple rectangle ----------\n";
  // Формирование прямоугольника
  Rectangle r;
  // Инициализация прямоугольника
  r.setX(std::stoi(argv[1]));
  r.setY(std::stoi(argv[2]));
  r.Print();

  Application a;
  a.BigMethod(r);


  //----------------------------------------------------------------------------
  std::cout << "---------- Using a rectangle with a counter ----------\n";
  // Формирование счетчика с подключением прямоугольника
  Counter c(&r);
  c.Print();

  // Использование отдельного прямоугольника, вызывающее первоначальный метод

  // Использование прежнего приложения с новым прямоугольником
  a.BigMethod(c);
  a.BigMethod(c);

  // Использование расширенных функций
  Expanded e;
  e.ExpandedMethod(c);
  c.Print();
}
