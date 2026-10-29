#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание класса треугольника,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "figure.h"

//------------------------------------------------------------------------------
// треугольник
class Triangle: public Figure {
public:
  int a, b, c; // стороны
  // переопределяем интерфейс класса
  void InData(std::ifstream &ifst);  // ввод данных из потока
  void Out(std::ofstream &ofst);     // вывод данных в стандартный поток
  virtual void Multimethod(Figure& fig2, std::ofstream &ofst); // мультиметод
  virtual void FirstRectangle(Rectangle& rect, std::ofstream &ofst);
  virtual void FirstTriangle(Triangle& trian, std::ofstream &ofst);
  virtual void FirstCircle(Circle& circ, std::ofstream &ofst);
  virtual double Perimeter();            // вычисление периметра
  virtual int MultimethodDifFunc(Figure& fig2); // мультиметод
  virtual int FirstRectangleDifFunc(Rectangle& rect);
  virtual int FirstTriangleDifFunc(Triangle& trian);
  virtual int FirstCircleDifFunc(Circle& circ);
  int GetA() {return a;}
  int GetB() {return b;}
  int GetC() {return c;}
  Triangle(): a{0}, b{0}, c{0} {} // создание без инициализации.
};

#endif // __triangle__

