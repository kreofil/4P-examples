#include <stdio.h>
#include "first.h"

void printlnInt<FigureTag *f>() {
  printf("Default generalized function\n");
}

void printlnInt<FigureTag.first_tag *f>() {
  printf("first =  %d\n", f->@);
}

void printlnInt<FigureTag.second_tag *f>() {
  printf("second =  %d\n", f->@);
}

void printlnInt<FigureTag.third_tag *f>() {
  printf("third =  %d\n", f->@);
}
