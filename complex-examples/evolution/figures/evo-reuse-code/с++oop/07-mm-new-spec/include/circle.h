#ifndef __circle__
#define __circle__

//------------------------------------------------------------------------------
// circle.h - содержит описание класса круга,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "figure.h"

//------------------------------------------------------------------------------
// круг
class Circle: public Figure {
  int r; // радиус
public:
  // переопределяем интерфейс класса
  void In(std::ifstream &ifst);  // ввод данных из потока
  virtual void Out(std::ofstream &ofst);    // вывод данных в файл
  virtual void Out();                       // вывод данных в cout
  virtual std::string Multimethod(Figure& fig2); // мультиметод
  virtual std::string FirstRectangle(Rectangle& rect);
  virtual std::string FirstTriangle(Triangle& trian);
  virtual std::string FirstCircle(Circle& circ);
  Circle(): r{0} {} // создание без инициализации.
};

#endif // __circle__
