//------------------------------------------------------------------------------
// container.cpp - содержит методы контейнера
//------------------------------------------------------------------------------

#include <iostream>
#include "simple-container.h"

//------------------------------------------------------------------------------
// Инициализация контейнера
SimpleContainer::SimpleContainer(): len(0) { }

//------------------------------------------------------------------------------
// Очистка контейнера от элементов (освобождение памяти)
void SimpleContainer::Clear()
{
  for(int i = 0; i < len; i++) {
    delete cont[i];
  }
  len = 0;
}

//------------------------------------------------------------------------------
// Ввод содержимого контейнера
void SimpleContainer::InData(std::ifstream &ifst) {
  while(!ifst.eof())
  {
    if((cont[len] = SimpleFigure::In(ifst)) != 0)
    {
      len++;
    }
  }
}

//------------------------------------------------------------------------------
// Вывод содержимого контейнера
void SimpleContainer::Out(std::ofstream &ofst) {
  ofst << "Container contents " << len << " elements.\n";
  for(int i = 0; i < len; i++) {
    ofst << i << ": ";
    cont[i]->Out(ofst);
  }
}

//------------------------------------------------------------------------------
// Клонирование
SimpleContainer* SimpleContainer::Clone() {
  SimpleContainer* clone = new SimpleContainer;
  clone->Init(this);
  return clone;
}

//------------------------------------------------------------------------------
// Инициализация клона данными родителя
void SimpleContainer::Init(SimpleContainer* parent) {
  len = parent->GetLen();
  for(int i = 0; i < len; i++) {
    SimpleFigure* pf = parent->GetFigurePtr(i);
    // std::cout << (pf==nullptr?"zero":"!!!") << "\n";
    cont[i] = pf->Clone();
  }
}
