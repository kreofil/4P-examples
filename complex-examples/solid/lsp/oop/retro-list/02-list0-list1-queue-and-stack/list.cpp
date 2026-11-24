// list.cpp
// Разработка производных классов СТЕК и ОЧЕРЕДЬ на основе базового списка
// LIST1, построенного на основе базового списка LIST0.

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

// Опустошение  списка LIST1
void LIST1::Empty(void) {
  while(tail != 0) {
    NODE* tmpNodePtr = tail->next;
    if(tmpNodePtr == tail) // Один элемент
      tail = 0;
    else
      tail->next = tmpNodePtr->next;
    delete tmpNodePtr;
  }
}

// Выталкивание элемента из списка LIST1
void LIST1::Pop(void) {
  if(tail == 0)
    return; // Очередь пуста.
  NODE* tmpNodePtr = tail->next;
  if(tail == tail->next)
    // В очереди один элемент. Она очищается.
    tail = 0;
  else  // Элементов не меньше двух
    tail->next = tail->next->next;
  tmpNodePtr->elemPtr = 0;
  delete tmpNodePtr;
}

// Чтение элемента, расположенного в голове списка LIST1
ELEMENT* LIST1::Read(void) {
  if(tail) return tail->next->elemPtr;
  else return 0;
}

// Добавление элемента в хвост очереди
void QUEUE::Append(ELEMENT* elemPtr) {
  NODE* tmpNodePtr = new NODE(elemPtr);
  if(tail == 0)  // имеем пустой список
    tmpNodePtr->next = tmpNodePtr;
  else {
    tmpNodePtr->next = tail->next;
    tail->next = tmpNodePtr;
  }
  tail = tmpNodePtr;
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

