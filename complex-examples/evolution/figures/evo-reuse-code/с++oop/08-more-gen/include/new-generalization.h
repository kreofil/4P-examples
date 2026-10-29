#ifndef __new_generalization__
#define __new_generalization__

//==============================================================================
// new-generalization.h
// Добавление в программу обобщения, содержащего периметры различных фигур,
// подключаемых через указатели на основы специализаций
//==============================================================================

//------------------------------------------------------------------------------
// в данном примере не будем плодить лишние единицы компиляции, хотя
// специализации можно размазать для большей гибкости.
#include <fstream>
#include <iostream>
#include "rectangle.h"
#include "triangle.h"
#include "container.h"

//------------------------------------------------------------------------------
// Класс, обобщающает все имеющиеся фигуры.
// Является абстрактным, обеспечивая, тем самым, проверку интерфейса
class FigurePerimeter {
protected:
  double perimeter;
  // Конкретные фигуры прицепляются к производным классам
public:
  virtual void Out(std::ofstream &ofst) = 0;     // вывод данных в файл
  virtual void Out() = 0;                        // вывод данных в консоль
  // вычисление периметра по параметрам подключаемой фигуры
  void SelectNewPerimeterFromFigure(Figure* f);
  // virtual void FieldPerimeterOut(std::ofstream &ofst) = 0;
  virtual void FieldPerimeterOut() = 0;
};

// Производный класс, расчитанный на подключение прямоугольников
class FigurePerimeterRectangle: public FigurePerimeter {
  // Связь только с прямоугольником
  Rectangle *rect;
public:
  virtual void Out(std::ofstream &ofst);
  virtual void Out();
  void FieldPerimeterOut(std::ofstream &ofst);
  void FieldPerimeterOut();
  FigurePerimeterRectangle(Rectangle* r): rect{r} {}
};

// Производный класс, расчитанный на подключение треугольников
class FigurePerimeterTriangle: public FigurePerimeter {
  // Связь только с треугольником
  Triangle *trian;
public:
  virtual void Out(std::ofstream &ofst);
  virtual void Out();
  void FieldPerimeterOut(std::ofstream &ofst);
  void FieldPerimeterOut();
  FigurePerimeterTriangle(Triangle* t): trian{t} {}
};

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
// для хранения данных нового обобщения
class ContainerOfPerimeters {
  enum {max_len_p = 100}; // максимальная длина
  int len; // текущая длина
  FigurePerimeter* cont[max_len_p];
public:
  void AddNewGeneralization(Container* c);
  void In(std::ifstream &ifst);     // ввод фигур в котнейнер из входного потока
  void Out(std::ofstream &ofst);    // вывод фигур в файл
  void Out();    // вывод фигур в cout
  void Clear();  // очистка контейнера от фигур
  ContainerOfPerimeters() {len = 0;}    // инициализация контейнера
  ~ContainerOfPerimeters() {Clear();} // утилизация контейнера перед уничтожением
};

#endif // __new_generalization__