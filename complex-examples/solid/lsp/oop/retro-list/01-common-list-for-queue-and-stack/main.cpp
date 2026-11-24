// main.cpp
// Главная функция, тестирующая набор функций работы
// очередью и стеком

#include "list.h"

int main(void) {
  // Тестирование автоматически создаваемой очереди
  QUEUE q((char*)"ОЧЕРЕДЬ");
  q.Out(stdout);

  q.Append(new ELEMENT((char*)"Первый"));
  q.Out(stdout);

  q.Append(new ELEMENT((char*)"Второй"));
  q.Out(stdout);

  ELEMENT* e = q.Read();
  printf("\nВывод элемента в голове очереди: ");
  e->Out(stdout);
  printf("\n");
  q.Pop();
  q.Out(stdout);

  // Тестирование динамически создаваемого стека
  printf("\n");
  STACK* s = new STACK((char*)"СТЕК");
  s->Out(stdout);

  s->Push(new ELEMENT((char*)"Первый"));
  s->Out(stdout);

  s->Push(new ELEMENT((char*)"Второй"));
  s->Out(stdout);

  e = q.Read();
  printf("\nВывод элемента на вершине стека: ");
  e->Out(stdout);

  delete s;

  return 0;
} // end main

