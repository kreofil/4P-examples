
// list.cpp
//                          Пример 7.
// Разработка производных классов СТЕК и ОЧЕРЕДЬ
// Класс STACK разрабатывается на основе класса LIST0.
// Класс QUEET разрабатывается на основе класса STACK.

#include "list.h"

// Конструктор элемента
ELEMENT::ELEMENT(char* n) {
  name = new char[strlen(n) + 1];
  strcpy(name, n);
}

// Конструктор базового списка
LIST0::LIST0(char* n) {
  tail = 0;
  name = new char[strlen(n) + 1];
  strcpy(name, n);
}

// Вывод значений элементов списка в предварительно открытый файл
void LIST0::Out(FILE* filePtr) {
  NODE* tmpPtr;
  fprintf(filePtr, "\nСодержимое списка %s:\n    ", name);
  if(tail == 0) {
    fprintf(filePtr, "Список пуст.\n");
  } else {
    tmpPtr = tail;
    do {
      tmpPtr->next->Out(filePtr);
      fprintf(filePtr, "\n    ");
      tmpPtr = tmpPtr->next;
    } while(tmpPtr != tail);
  }
}

// Опустошение стека
void STACK::Empty(void) {
  while(tail != 0) {
    NODE* tmpNodePtr = tail->next;
    if(tmpNodePtr == tail) // Один элемент
      tail = 0;
    else
      tail->next = tmpNodePtr->next;
    delete tmpNodePtr;
  }
}

// Добавление элемента в вершину стека
void STACK::Push(ELEMENT* elemPtr) {
  NODE* tmpNodePtr = new NODE(elemPtr);
  if(tail == 0) { // имеем пустой стек
    tmpNodePtr->next = tmpNodePtr;
    tail = tmpNodePtr;
  } else {
    tmpNodePtr->next = tail->next;
    tail->next = tmpNodePtr;
  }
}

// Выталкивание элемента из стека
void STACK::Pop(void) {
  if(tail == 0)
    return; // Стек пуст.
  NODE* tmpNodePtr = tail->next;
  if(tail == tail->next)
    // В стеке один элемент. Он очищается.
    tail = 0;
  else  // Элементов не меньше двух
    tail->next = tail->next->next;
  tmpNodePtr->elemPtr = 0;
  delete tmpNodePtr;
}

// Чтение элемента, расположенного в вершине стека
ELEMENT* STACK::Read(void) {
  if(tail) return tail->next->elemPtr;
  else return 0;
}
