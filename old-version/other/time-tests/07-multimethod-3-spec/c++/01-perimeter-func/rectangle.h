#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание класса прямоугольника,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "figure.h"

//------------------------------------------------------------------------------
// прямоугольник
class Rectangle: public Figure {
  int x, y; // ширина, высота
public:
  // переопределяем интерфейс класса
  virtual void InData(std::ifstream &ifst);  // ввод данных из потока
  virtual void Out(std::ofstream &ofst);    // вывод данных в стандартный поток
  virtual void Multimethod(Figure& fig2, std::ofstream &ofst); // мультиметод
  virtual void FirstRectangle(Rectangle& rect, std::ofstream &ofst);
  virtual void FirstTriangle(Triangle& trian, std::ofstream &ofst);
  virtual void FirstCircle(Circle& circ, std::ofstream &ofst);
  virtual double Perimeter();            // вычисление периметра
  virtual double MultimethodPerimeter(Figure& fig2); // мультиметод
  virtual double FirstRectanglePerimeter(Rectangle& rect);
  virtual double FirstTrianglePerimeter(Triangle& trian);
  virtual double FirstCirclePerimeter(Circle& circ);
  Rectangle(): x{0}, y{0} {} // создание без инициализации.
};

#endif // __rectangle__