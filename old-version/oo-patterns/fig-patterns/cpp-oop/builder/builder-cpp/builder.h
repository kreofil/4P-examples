#ifndef __builder__
#define __builder__

//------------------------------------------------------------------------------
// builder.h - абстрактный класс, определяющий интерфейс строителя
//------------------------------------------------------------------------------

#include <fstream>

//------------------------------------------------------------------------------
// Строитель
class Builder {
public:
  // Методы, используемые для строительства композиций
  virtual void BuildRectangle(double x, double y) {};
  virtual void BuildTriangle(double a, double b, double c) {};
  virtual void BuildCircle(double a, double b, double c) {}; // Вдруг будет?
  // Результат строительства сохраняется в файле
  virtual void ResultOut(std::ofstream &ofst) = 0;
};

//------------------------------------------------------------------------------

#endif // __builder__