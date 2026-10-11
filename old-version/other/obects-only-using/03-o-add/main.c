// Использование ПП полиморфизма и явной проверки для обобщенных объектов
// На примере операции сложения
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Объект для всего
typedef struct O {} <> O;
O+<int;>;         // Целое как объект
O+<double;>;      // Действительное как объект
O+<char;>;        // Символ как объект
O+<str: char*;>;  // Указатель на строку как объект

//==============================================================================
// Общие полиморфные операции для одиночных объектов
//==============================================================================

//------------------------------------------------------------------------------
// Информация о типе объекта. Обобщенная функция
char* TypeInfo<O* o>() {return "Undefined";}
// Информация о типе целочисленного объекта
char* TypeInfo<O.int* o>() {return "int";}
// Информация о типе действительного объекта
char* TypeInfo<O.double* o>() {return "double";}
// Информация о типе символьного объекта
char* TypeInfo<O.char* o>() {return "char";}
// Информация о типе строкового объекта
char* TypeInfo<O.str* o>() {return "str";}

//------------------------------------------------------------------------------
// Обобщенный вывод значения объекта с использованием ПП полиморфизма
void Print<O* o>() {printf("Empty object");}
// Вывод целочисленного объекта
void Print<O.int* o>() {printf("%d", o->@);}
// Вывод действительного объекта
void Print<O.double* o>() {printf("%le", o->@);}
// Вывод символьного объекта
void Print<O.char* o>() {printf("%c", o->@);}
// Вывод строкового объекта
void Print<O.str* o>() {printf("%s", o->@);}

//==============================================================================
// Операции для которых нецелесообразно использовать динамический полиморфизм
// из-за разреженности таблицы параметрический отношений
//==============================================================================

//------------------------------------------------------------------------------
// Проверка типов может в принципе идти напрямую путем сравнения обобщенного
// объекта с конкретной специализацией. Это позволяет сформировать набор
// сравнений только на нужные объекты. Сравнение идет путем сопоставления
// признаков без прямой проверки типов.
// У всех объектов одного типа признаки совпадают
//------------------------------------------------------------------------------
// Проверка на обобщенный (пустой) объект
// Можно сравнить сам с собой для получения его индекса
// Для обобщения он должен быть равен 0
_Bool isO(O* o) {
  return spec_index_cmp(o, o) == 0;
}
// Проверка, что объект целочисленный
_Bool isIntO(O* o) {
  struct O.int i; // использование локальной переменной
  return spec_index_cmp(o, (O*)&i) > 0;
}
// Проверка, что объект действительный
static struct O.double d; // использование статической переменной
_Bool isDoubleO(O* o) {
  return spec_index_cmp(o, (O*)&d) > 0;
}

//------------------------------------------------------------------------------
// Операции сложения могут быть только целое с целым и действительное с
// действительным. В начале прямые обработчики
//------------------------------------------------------------------------------
// Суммирование целого с целым с порождением обобщенного
O* AddIntInt(struct O.int* o1, struct O.int* o2) {
  struct O.int* r = create_spec(O.int);
  r->@ = o1->@ + o2->@;
  return (O*)r;
}
// Суммирование действительного с действительным с порождением обобщенного
O* AddDoubleDouble(struct O.double* o1, struct O.double* o2) {
  struct O.double *r = create_spec(O.double);
  r->@ = o1->@ + o2->@;
  return (O*)r;
}
// Суммирование  с использованием мультиметода
O* Add<O* o1, O* o2>(){return create_spec(O);}
O* Add<O.int* o1, O.int* o2>(){return AddIntInt(o1, o2);}
O* Add<O.double* o1, O.double* o2>(){return AddDoubleDouble(o1, o2);}

// Суммирование с использованием информации о типах
O* Add2(O* o1, O* o2) {
  if(!strcmp(TypeInfo<o1>(),"int") && !strcmp(TypeInfo<o2>(), "int")) {
    return AddIntInt((struct O.int*)o1, (struct O.int*)o2);
  }
  if(!strcmp(TypeInfo<o1>(),"double") && !strcmp(TypeInfo<o2>(), "double")) {
    return AddDoubleDouble((struct O.double*)o1, (struct O.double*)o2);
  }
  return create_spec(O);
}

// Суммирование с использованием прямой проверки типов
O* Add3(O* o1, O* o2) {
  if(isIntO(o1) && isIntO(o2)) {
    return AddIntInt((struct O.int*)o1, (struct O.int*)o2);
  }
  if(isDoubleO(o1) && isDoubleO(o2)) {
    return AddDoubleDouble((struct O.double*)o1, (struct O.double*)o2);
  }
  return create_spec(O);
}

//  Функция целочисленного сложения через обобщенные аргументы
O* AddIntIntO(O* o1, O* o2) {
  return AddIntInt((struct O.int*)o1, (struct O.int*)o2);
}

//  Функция сложения действительных чисел через обобщенные аргументы
O* AddDoubleDoubleO(O* o1, O* o2) {
  return AddDoubleDouble((struct O.double*)o1, (struct O.double*)o2);
}

//------------------------------------------------------------------------------
// Построение простого демонстрационного словаря
typedef struct Pair {int key; O*(*f)(O* o1, O* o2);} Pair;
typedef struct Map {Pair p[2];} Map;
// Алгоритм заполения словаря для сложения технически можно разнести
void CreateMap(Map* m) {
  // Добавление в словарь информации о целочисленном сложении
  struct O.int i;
  int key = spec_index_cmp(&i, &i);
  m->p[0].key = key + (key << 8); // будет достаточно
  m->p[0].f = AddIntIntO;
  // Добавление в словарь информации о сложении действительных чисел
  struct O.double d;
  key = spec_index_cmp(&d, &d);
  m->p[1].key = key + (key << 8); // будет достаточно
  m->p[1].f = AddDoubleDoubleO;
}
// Суммирование с использованием словаря для выбора обработчика
O* Add4(Map* m, O* o1, O* o2) {
  for(int i = 0; i <2; ++i) {
    if(m->p[i].key ==
              (spec_index_cmp(o1, o1)) + (spec_index_cmp(o2, o2) << 8)) {
      return m->p[i].f(o1, o2);
    }
  }
  return create_spec(O);
}



int main() {
  Map m;
  CreateMap(&m);
  O*o ;
  O* X[10];
  struct O.int i0; i0.@ = 10; X[0] = (O*)&i0; Print<(O*)X[0]>(); printf("\n");
  struct O.int i1; i1.@ = 32;  X[1] = (O*)&i1; Print<(O*)X[1]>(); printf("\n");
  o = Add<X[0], X[1]>();  Print<o>(); printf("\n");  free(o);
  o = Add2(X[0], X[1]);   Print<o>(); printf("\n");  free(o);
  o = Add3(X[0], X[1]);   Print<o>(); printf("\n");  free(o);
  o = Add4(&m, X[0], X[1]);   Print<o>(); printf("\n");  free(o);

  struct O.double d0; d0.@ = 2.71; X[2] = (O*)&d0; Print<(O*)X[2]>(); printf("\n");
  struct O.double d1; d1.@ = 3.14; X[3] = (O*)&d1; Print<(O*)X[3]>(); printf("\n");
  o = Add<X[2], X[3]>();  Print<o>(); printf("\n");  free(o);
  o = Add2(X[2], X[3]);   Print<o>(); printf("\n");  free(o);
  o = Add3(X[2], X[3]);   Print<o>(); printf("\n");  free(o);
  o = Add4(&m, X[2], X[3]);   Print<o>(); printf("\n");  free(o);

  o = Add<X[1], X[2]>();  Print<o>(); printf("\n");  free(o);
  o = Add2(X[3], X[0]);   Print<o>(); printf("\n");  free(o);
  o = Add3(X[3], X[1]);   Print<o>(); printf("\n");  free(o);
  o = Add4(&m, X[0], X[3]);   Print<o>(); printf("\n");  free(o);

  return 0;
}