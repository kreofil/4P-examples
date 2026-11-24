// list.hpp
// Разработка производных классов СТЕК и ОЧЕРЕДЬ
// Класс STACK разрабатывается на основе класса LIST0.
// Класс QUEUE разрабатывается на основе класса STACK.

#include <stdio.h>
#include <string.h>

// Элемент списка со значением
class ELEMENT {
  char* name;
public:
  ELEMENT(char*); // конструктор класса
  ~ELEMENT() {delete name;} // Деструктор класса
  // вывод элемента класса
  void Out(FILE* filePtr) {fprintf(filePtr, "%s  ", name);}
};

// Промежуточный узел списка
struct NODE {
public:
  ELEMENT* elemPtr;
  NODE* next;
  NODE(ELEMENT* e) {elemPtr = e;} // Конструктор
  ~NODE() {delete elemPtr;}  // Деструктор
  void Out(FILE* f) {elemPtr->Out(f);}
};

// Сам однонаправленный кольцевой базовый список
class LIST0 {
public:
  NODE* tail; // указатель на последний элемент списка
  char* name; // Имя списка (для идентификации при выводе).
  LIST0(char* n); // Конструктор списка
  ~LIST0() {delete name;} // Деструктор
  void Out(FILE*);
};

// Производный класс СТЕК
class STACK: public LIST0 {
public:
  STACK(char* n): LIST0(n) {}; // Конструктор стека
  void Empty(void); // Опустошение стека
  ~STACK() {Empty();} // Деструктор
  void Push(ELEMENT*); // Занесение элемента в стек
  void Pop(void);  // Выталкивание элемента из стека
  ELEMENT* Read(void); // Чтение элемента в голове стека
};

// Производный класс ОЧЕРЕДЬ
class QUEUE: public STACK {
public:
  QUEUE(char* n): STACK(n) {}; // Конструктор очереди
  // Добавление элемента в очередь
  void Append(ELEMENT* e) {Push(e); tail = tail->next;}
};

