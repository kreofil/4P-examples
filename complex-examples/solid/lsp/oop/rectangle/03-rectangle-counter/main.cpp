#include <iostream>

class Rectangle {
  int x, y;   // стороны прямоугольника
public:
  void setX(int _x) {x = _x;}
  void setY(int _y) {y = _y;}

  int getX() {return x;}
  int getY() {return y;}

  virtual double Area() {
    return double(x * y);
  }
  virtual void Print() {
    std::cout << "Rectangle. x = " << x << "; y = " << y << "\n";
  }
};

// Код, использующий прямоугольник в большом приложении
class Application {
public:
  // Метод, обеспечивающий использование подстановки
  void BigMethod(Rectangle& r) {
    auto result = r.Area() / -2.0;
    std::cout << "Result = " << result << "\n";
  }
};

// Подтип, расширяющий родителя посчетом числа вызвов метода
// вычисления площади и вычислением периметра
class CountedRectangle: public Rectangle {
  int counter;
public:
  CountedRectangle(): counter(0) {}

  double Area() override {
    ++counter;
    return Rectangle::Area();
  }

  virtual void Print() {
    Rectangle::Print();
    std::cout << "    Counter = " << counter << "\n";
  }

  double Perimeter() {
    return 2.0 * (getX() + getY());
  }
};

// Дополнительный код расширяющий ранее написанное приложение
class Expanded {
public:
  // Метод, обеспечивающий поддержку дополнительной функциональности
  void ExpandedMethod(CountedRectangle &cr) {
    auto result = cr.Perimeter() * 20.0;
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
  Rectangle r;
  r.setX(std::stoi(argv[1]));
  r.setY(std::stoi(argv[2]));
  r.Print();

  // Использование приложения
  Application a;
  a.BigMethod(r);

  //----------------------------------------------------------------------------
  std::cout << "---------- Using a rectangle with a counter ----------\n";
  // Формирование подтипа
  CountedRectangle cr;
  cr.setX(std::stoi(argv[1]));
  cr.setY(std::stoi(argv[2]));
  cr.Print();
  // Использование прежнего приложения дважды для изменения счетчика
  a.BigMethod(cr);
  a.BigMethod(cr);
  // Подключение расширенных функций
  Expanded e;
  e.ExpandedMethod(cr);
  cr.Print();
}
