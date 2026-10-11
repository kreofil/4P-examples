#ifndef __figure__
#define __figure__

//------------------------------------------------------------------------------
// figure.h - содержит описание обобщающей геометрической фигуры,
// являющееся базовыым классом для всех прочих фигур
//------------------------------------------------------------------------------

#include <fstream>
#include <iostream>
#include <string>

class Rectangle;
class Triangle;
class Circle;

//------------------------------------------------------------------------------
// Класс, обобщающает все имеющиеся фигуры.
// Является абстрактным, обеспечивая, тем самым, проверку интерфейса
class Figure {
public:
  // идентификация, порождение и ввод фигуры из потока
  virtual void In(std::ifstream &ifst) = 0;  // ввод данных из потока
  virtual void Out(std::ofstream &ofst) = 0;     // вывод данных в файл
  virtual void Out() = 0;                        // вывод данных в консоль
  virtual std::string Multimethod(Figure& fig2) = 0; // мультиметод
  virtual std::string FirstRectangle(Rectangle& rect) = 0;
  virtual std::string FirstTriangle(Triangle& trian) = 0;
  virtual std::string FirstCircle(Circle& circ) = 0;
};

#endif // __figure__