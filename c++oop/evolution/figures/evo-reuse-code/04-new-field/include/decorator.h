#ifndef __decorator__
#define __decorator__

//------------------------------------------------------------------------------
// decorator.h - содержит описание декоратора, порожденного от Figure
// и добавляющего цвет.
//------------------------------------------------------------------------------

// Требуется описание класса Figure
#include "figure.h"

//------------------------------------------------------------------------------
// Декоратор
class Decorator: public Figure {
  unsigned int color; // цвет фигуры
  Figure* fig; // декорируемая фигура
public:
  // переопределяем интерфейс класса
  virtual void In(std::ifstream &ifst);   // ввод данных из потока
  virtual void Out(std::ofstream &ofst);      // вывод данных в файл
  virtual void Out();                         // вывод данных в cout
  Decorator(Figure* f): color{0}, fig{f} {}
  virtual ~Decorator() {delete fig;}
};

#endif // __rectangle__