#include <iostream>

class Rectangle {
  int x, y;   // стороны прямоугольника
public:
  void setX(int _x) {x = _x;}
  void setY(int _y) {y = _y;}

  int getX() {return x;}
  int getY() {return y;}

  double Area() {
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

// Клиентский код, использующий разработанное большое приложение
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
}