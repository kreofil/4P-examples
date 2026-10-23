#ifndef __figure__
#define __figure__

//------------------------------------------------------------------------------
// figure.h - содержит описание обобщающей геометрической фигуры,
// являющееся базовыым классом для всех прочих фигур
//------------------------------------------------------------------------------

#include <fstream>

class Rectangle;
class Triangle;
class Circle;

//------------------------------------------------------------------------------
// Класс, обобщающает все имеющиеся фигуры.
// Является абстрактным, обеспечивая, тем самым, проверку интерфейса
class Figure {
public:
  // идентификация, порождение и ввод фигуры из потока
  static  Figure* In(std::ifstream &ifst);
  virtual void InData(std::ifstream &ifst) = 0;  // ввод данных из потока
  virtual void Out(std::ofstream &ofst) = 0;     // вывод данных в стандартный поток
  virtual void Multimethod(Figure& fig2, std::ofstream &ofst) = 0; // мультиметод
  virtual void FirstRectangle(Rectangle& rect, std::ofstream &ofst) = 0;
  virtual void FirstTriangle(Triangle& trian, std::ofstream &ofst) = 0;
  virtual void FirstCircle(Circle& circ, std::ofstream &ofst) = 0;
};

#endif // __figure__