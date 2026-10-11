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
  Circle(): r{0} {} // создание без инициализации.
  int GetR() {return r;}
};

#endif // __circle__
