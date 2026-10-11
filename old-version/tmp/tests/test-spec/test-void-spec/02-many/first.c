#include <stdio.h>
#include "first.h"

void printlnVoid<FigureTag *f>() {
  printf("Default generalized function\n");
}

void printlnVoid<FigureTag.first_tag *f>() {
  printf("first void entiy\n");
}

void printlnVoid<FigureTag.second_tag *f>() {
  printf("second void entiy\n");
}

void printlnVoid<FigureTag.third_tag *f>() {
  printf("third void entiy\n");
}
