#ifndef __rectangle__
#define __rectangle__

//------------------------------------------------------------------------------
// rectangle.h - содержит описание класса прямоугольника,
// порожденного от базового класса Figure
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "simple-figure.h"

//------------------------------------------------------------------------------
// прямоугольник
class SimpleRectangle: public SimpleFigure {
  double x, y; // ширина, высота
public:
  // переопределяем интерфейс класса
  virtual void InData(std::ifstream &ifst); // ввод данных из потока
  virtual void Out(std::ofstream &ofst);    // вывод данных в стандартный поток
  SimpleRectangle() {} // создание без инициализации.
  virtual SimpleRectangle* Clone();                  // клонирование фигуры

  void Init(SimpleRectangle* parent);       // инициализация клоном
  double GetX() {return x;}
  double GetY() {return y;}
  void SetX(double _x) {x = _x;}
  void SetY(double _y) {y = _y;}
};

#endif // __rectangle__