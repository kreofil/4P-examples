// Вариант задания:
//   хранение в элементе указателя на динамически создаваемый ключ
//   таблица на основе двоичного дерева

#include <stdio.h>
#include "tree.h"

int nextName(FILE *infil, char *strBuf); // ЧТЕНИЕ ОЧЕРЕДНОГО ИМЕНИ ИЗ ВХОДНОГО ФАЙЛА

#define STR_BUF_SIZE        256
char strBuf[STR_BUF_SIZE];      // Буфер для выделения имени из файла
Tree tree = {NULL, NULL, NULL}; // Дерево
FILE* infil;                    // Указатель на читаемый файл

int main(int argc, char* argv[]) {
  if(argc !=3) {
    printf("incorrect command line! Wated: command file_with_names file_for_deleting\n");
    return -1;
  }

  if((infil = fopen(argv[1], "rt"))==NULL) {
    printf("No file_with_names\n");
    return -1;
  }

  while(!nextName(infil, strBuf)) {
    if(find(&tree, strBuf)) {
      tree.p_find->val.count++;
    } else {
      incl(&tree, strBuf);
    }
  }

  printf("\nSource Table of names:\n");
  treeOut(stdout, &tree);
  output(&tree, (char*)"incltab.txt");
  fclose(infil);

  if((infil = fopen(argv[2], "rt"))==NULL) {
    printf("No infil\n");
    return -2;
  }

  while(!nextName(infil, strBuf)) {
    if(find(&tree, strBuf)) {
      del(&tree);
    }
  }
  fclose(infil);

  printf("\nTable of names after deleting:\n");
  treeOut(stdout, &tree);
  output(&tree, (char*)"deltab.txt");

  printf("\nNormal END of work!\n");

  return 0;
}
