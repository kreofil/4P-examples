#ifndef __tree__
#define __tree__

// tree.h - построение двоичного дерева
// ключ хранится динамически

#include "value.h"

#define step  "    "

typedef struct node {
  struct Value *val;
  struct node  *left;
  struct node  *right;
} node;

// Структура, задающея корень дерева и вспомогательные указатели
// для работы с ним
typedef struct Tree {
  node*  root;       // корень создаваемого дерева имен
  node*  p_find;     // указатель на найденный элемент таблицы
  node** pp_find;    // указатель, хранящий указатель на
                     // точку подстановки нового элемента
} Tree;

int find(Tree*, char*);     // НАХОЖДЕНИЕ ЭЛЕМЕНТА ТАБЛИЦЫ С ЗАДАННЫМ ИМЕНЕМ
void incl(Tree*, char*);    // ВКЛЮЧЕНИЕ НОВОГО ЭЛЕМЕНТА В ТАБЛИЦУ
void del(Tree*);            // УДАЛЕНИЕ ЭЛЕМЕНТА ИЗ ТАБЛИЦЫ
void output(Tree*, char*);  // ПЕЧАТЬ ТАБЛИЦЫ ИМЕН В ФАЙЛЕ И НА ЭКРАНЕ
void treeOut(FILE* f, Tree* tree); // Вывод дерева в поток

#endif // __tree__
