// new-generalization.c - дополнительное обобщение, связывающее используемое
// в нем значение с основами специализаций.

#include <stdio.h>
#include <stdlib.h>
#include "container.h"
#include "new-generalization.h"

//==============================================================================
// Формирование специализаций нового обобщения и занесение их в контейнер
// специализаций периметров фигур
//==============================================================================

//------------------------------------------------------------------------------
// Формирование конкретной специализации дополнительного обобщения на основе
// известной специализации фигуры. Область памяти под фигуру имеется

//------------------------------------------------------------------------------
// Вычисление периметра прямоугольника по параметрам подключаемой фигуры
// Можно сделать не виртуальной, определяемой отдельно в каждой специализации,
// но не хочется этим заниматься на уровне примера.
void FigurePerimeter::SelectNewPerimeterFromFigure(Figure* f) {
  perimeter = f->Perimeter();
}

//------------------------------------------------------------------------------
// Добавление основы специализации в массив, состоящий из специализаций
// дополнительного обобщения.
void ContainerOfPerimeters::AddNewGeneralization(Container* c) {
  len = c->GetLen();
  FigurePerimeter* fp = nullptr;
  for(int i = 0; i < len; ++i) {
    Figure* f = c->GetFigure(i);   // текущая фигура в исходном контейнере
    FigurePerimeterRectangle* fpr;
    FigurePerimeterTriangle*  fpt;
    // Создание специализации фигуры с периметром в зависимости от типа фигуры,
    if(dynamic_cast<Rectangle*>(f) != nullptr) {
      fpr = new FigurePerimeterRectangle(static_cast<Rectangle*>(f));
      fpr->SelectNewPerimeterFromFigure(f);
      cont[i] = fpr;
    } else if(dynamic_cast<Triangle*>(f) != nullptr) {
      fpt = new FigurePerimeterTriangle(static_cast<Triangle*>(f));
      fpt->SelectNewPerimeterFromFigure(f);
      cont[i] = fpt;
    } else {
      std::cerr << "Incorrect Figure\n";
      exit(13);
    }
  }
}

//==============================================================================
// Организация вывода специализаций нового обобщения и вывод содержимог
// контейнера с новыми специализациями периметров фигур
//==============================================================================

//  Функция вывода значения периметра прямоугольника из поля обобщения в файл
void FigurePerimeterRectangle::FieldPerimeterOut(std::ofstream &ofst) {
  ofst << "Rectangle Perimeter = " << perimeter << ". " ;
}

//  Функция вывода значения периметра прямоугольника из поля обобщения в консоль
void FigurePerimeterRectangle::FieldPerimeterOut() {
  std::cout << "Rectangle Perimeter = " << perimeter << ". " ;
}

//  Функция вывода значения периметра треугольника из поля обобщения в файл
void FigurePerimeterTriangle::FieldPerimeterOut(std::ofstream &ofst) {
  ofst << "Triangle Perimeter = " << perimeter << ". " ;
}

//  Функция вывода значения периметра треугольника из поля обобщения в консоль
void FigurePerimeterTriangle::FieldPerimeterOut() {
  std::cout << "Triangle Perimeter = " << perimeter << ". " ;
}

//------------------------------------------------------------------------------
// Вывод специализации прямоугольника с периметром в файл
void FigurePerimeterRectangle::Out(std::ofstream &ofst) {
  FieldPerimeterOut(ofst);
  rect->Out(ofst);
}

//------------------------------------------------------------------------------
// Вывод специализации прямоугольника с периметром в консоль
void FigurePerimeterRectangle::Out() {
  FieldPerimeterOut();
  rect->Out();
}

//------------------------------------------------------------------------------
// Вывод специализации треугольника с периметром в файл
void FigurePerimeterTriangle::Out(std::ofstream &ofst) {
  FieldPerimeterOut(ofst);
  trian->Out(ofst);
}

//------------------------------------------------------------------------------
// Вывод специализации треугольника с периметром в консоль
void FigurePerimeterTriangle::Out() {
  FieldPerimeterOut();
  trian->Out();
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера периметров фигур в файл
void ContainerOfPerimeters::Out(std::ofstream &ofst) {
  ofst << "Container contains " << len << " elements.\n";
  for(int i = 0; i < len; i++) {
    ofst << i << ": ";
    cont[i]->Out(ofst);
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера периметров фигур в консоль
void ContainerOfPerimeters::Out() {
  std::cout << "Container contains " << len << " elements.\n";
  for(int i = 0; i < len; i++) {
    std::cout << i << ": ";
    cont[i]->Out();
  }
}

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void ContainerOfPerimeters::Clear() {
  for(int i = 0; i < len; i++) {
    delete cont[i];
  }
  len = 0;
}
