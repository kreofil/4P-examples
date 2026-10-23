#ifndef __container__
#define __container__

//------------------------------------------------------------------------------
// container.h - содержит класс,
// представляющий простейший контейнер
//------------------------------------------------------------------------------

#include "simple-figure.h"

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
//------------------------------------------------------------------------------

class SimpleContainer: public SimpleFigure {
  enum {max_len = 100}; // максимальная длина
  int len; // текущая длина
  SimpleFigure *cont[max_len];
public:
  SimpleContainer();    // инициализация контейнера
  ~SimpleContainer() {Clear();} // утилизация контейнера перед уничтожением

  virtual void InData(std::ifstream &ifst);  // ввод фигур в котнейнер из потока
  virtual void Out(std::ofstream &ofst);     // вывод фигур в поток
  virtual SimpleContainer* Clone();                   // клонирование фигуры

  void Init(SimpleContainer* parent);        // инициализация
  void Clear();  // очистка контейнера от фигур

  double GetLen() {return len;}
  SimpleFigure* GetFigurePtr(int i) {return cont[i];}
};

#endif // __container__
