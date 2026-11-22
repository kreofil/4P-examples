#ifndef __triangle__
#define __triangle__

//------------------------------------------------------------------------------
// triangle.h - содержит описание класса треугольника,
// порожденного от базового класса shape
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "simple-figure.h"

//------------------------------------------------------------------------------
// треугольник
class SimpleTriangle: public SimpleFigure
{
  double a, b, c; // стороны
public:
  // переопределяем интерфейс класса
  virtual void InData(std::ifstream &ifst);  // ввод данных из потока
  virtual void Out(std::ofstream &ofst);     // вывод данных в стандартный поток
  SimpleTriangle() {} // создание без инициализации.
  virtual SimpleTriangle* Clone();                   // клонирование фигуры

  void Init(SimpleTriangle* parent);         // инициализация клоном

  double GetA() {return a;}
  double GetB() {return b;}
  double GetC() {return c;}
  void SetA(double _a) {a = _a;}
  void SetB(double _b) {b = _b;}
  void SetC(double _c) {c = _c;}
};

#endif // __triangle__
