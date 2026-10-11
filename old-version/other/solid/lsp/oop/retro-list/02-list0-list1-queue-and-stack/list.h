// list.h
// Разработка производных классов СТЕК и ОЧЕРЕДЬ на основе базового списка
// LIST1, построенного на основе базового списка LIST0

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

// Однонаправленный кольцевой список второго уровня
class LIST1: public LIST0 {
public:
  LIST1(char* n): LIST0(n) {}
  void Empty(void); // Опустошение списка
  ~LIST1() {Empty();} // Деструктор
  void Pop(void);  // Выталкивание элемента из списка
  ELEMENT* Read(void); // Чтение элемента в голове списка
};

// Производный класс ОЧЕРЕДЬ
class QUEUE: public LIST1 {
public:
  QUEUE(char* n): LIST1(n) {} // Конструктор очереди
  void Append(ELEMENT*); // Добавление элемента в очередь
};

// Производный класс СТЕК
class STACK: public LIST1 {
public:
  STACK(char* n): LIST1(n) {} // Конструктор стека
  void Push(ELEMENT*); // Занесение элемента в стек
};
