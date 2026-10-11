#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pair.h"
#include "tree.h"

int find(Tree* tree, char* n) {
  if(tree->root == NULL) {
    tree->p_find = NULL; // элемента с заданным ключом нет
    tree->pp_find = &(tree->root); // точка подключения корня
    return 0;
  }
  struct node* p_tmp = tree->root; // временный указатель на текущий элемент
  tree->pp_find = &(tree->root); // адрес указателя, ссылающегося на текущий элемент
  do { // поиск  элемента с заданным ключом n)
    int cmprez = strcmp(n, p_tmp->val.name);
    if(cmprez == 0) {// совпадение ключей
      tree->p_find = p_tmp;
      // tree->pp_find указывает на точку подключения найденного узла
      return 1;
    } else if(cmprez < 0) { // ключ в буфере меньше ключа в узле
      tree->pp_find = &(p_tmp->left);
      p_tmp = p_tmp->left;
    } else { // ключ в буфере больше ключа в узле
      tree->pp_find = &(p_tmp->right);
      p_tmp = p_tmp->right;
    }
  } while(p_tmp != NULL); // завершение при отсутствии узла
  tree->p_find = NULL; // указатель найденного элемента элемента пуст
  // tree->pp_find указывает на элемент, к которому можно подключаться
  return 0; // элемент не найден
}

void incl(Tree* tree, char* n) {
    node* p_tmp = (struct node *)malloc(sizeof(struct node));
    p_tmp->val.name = (char *)malloc(sizeof(char)*(strlen(n)+1));
    strcpy(p_tmp->val.name, n);
    p_tmp->val.count = 1;
    p_tmp->left = NULL;
    p_tmp->right = NULL;
    *(tree->pp_find) = p_tmp;
}

void del(Tree* tree) {
  if(tree->p_find->left == NULL && tree->p_find->right == NULL) {// нет потомков
    free(tree->p_find->val.name);
    free(tree->p_find);
    *(tree->pp_find) = NULL; // с уничтожением элемента обнуляется указатель на него
  } else if(tree->p_find->left == NULL) {// нет только левого потомка
    *(tree->pp_find) = tree->p_find->right;
    free(tree->p_find->val.name);
    free(tree->p_find);
  } else if(tree->p_find->right == NULL) {// нет только правого потомка
    *(tree->pp_find) = tree->p_find->left;
    free(tree->p_find->val.name);
    free(tree->p_find);
  } else {// имеются оба потомка
    // поиск самого правого элемента в левом поддереве:
    struct node* p_tmp;
    struct node** pp_tmp = &(tree->p_find->left);
    for(p_tmp = tree->p_find->left; p_tmp->right != NULL; p_tmp = p_tmp->right)
      pp_tmp = &(p_tmp->right);
    if(p_tmp != tree->p_find->left) {
      // самый правый узел левого поддерева не следует за удаляемым
      *(pp_tmp) = p_tmp->left;
      p_tmp->left = tree->p_find->left;
    }
    // для любого самого правого узла левого поддерева
    *(tree->pp_find) = p_tmp;
    p_tmp->right = tree->p_find->right;
    free(tree->p_find->val.name);
    free(tree->p_find);
  } // завершение обработки удаляемого узла с двумя потомками
}

void printTree(FILE* f, node* p, int h) {
  if(p != NULL) {
    printTree(f, p->left, h + 1);
    for(int i = 0; i < h; ++i) {
      // printf(step);
      fprintf(f, step);
    }
    // printf("---%s[%d]\n", p->val.name, p->val.count);

    OutValue<p->val>(f);
    // fprintf(f, "---%s[%d]\n", p->val.name, p->val.count);
    printTree(f, p->right, h + 1);
  }
}

void treeOut(FILE* f, Tree* tree) {
  if(tree->root == NULL) {
    fprintf(f, "таблица имен пустая\n");
    return;
  }
  printTree(f, tree->root, 0);
}

void output(Tree* tree, char* n) {
  FILE* outfil;
  outfil = fopen(n, "wt");
  // printf("\n");
  treeOut(outfil, tree);
  fclose(outfil);
}
