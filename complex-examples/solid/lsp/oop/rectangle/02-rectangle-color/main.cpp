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

// Подтип, расширяющий родителя добавлением цвета и вычислением периметра
class ColoredRectangle: public Rectangle {
  int color;
public:
  void setColor(int c) {color = c;}

  double Perimeter() {
    return 2.0 * (getX() + getY());
  }
  virtual void Print() {
    Rectangle::Print();
    std::cout << "    Color = " << color << "\n";
  }
};

// Дополнительный код расширяющий ранее написанное приложение
class ColoredExpanded {
public:
  // Метод, обеспечивающий поддержку дополнительной функциональности
  void ExpandedMethod(ColoredRectangle &cr) {
    auto result = cr.Perimeter() * 10.0;
    std::cout << "Colored Expanded result = " << result << "\n";
  }
};

// Новый клиентский код, использующий разработанное большое приложение
// И дополнительную приладу, связанную с появлением подставляемого подтипа
int main(int argc, char* argv[]) {
  if(argc != 4) {
    std::cout << "Incorrect command line. Use " << argv[0] << "X Y Color\n";
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
  std::cout << "---------- Using a colored rectangle ----------\n";
  // Формирование подтипа
  ColoredRectangle cr;
  cr.setX(std::stoi(argv[1]));
  cr.setY(std::stoi(argv[2]));
  cr.setColor(std::stoi(argv[3]));
  cr.Print();

  // Использование прежнего приложения
  a.BigMethod(cr);

  // Подключение расширенных функций
  ColoredExpanded ce;
  ce.ExpandedMethod(cr);
}
