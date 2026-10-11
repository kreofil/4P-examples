// RUN: %clang -c %s -o %S/a.o
// RUN: %clang %S/a.o -o %S/a.out
// RUN: %S/a.out | FileCheck %s -check-prefix=CHECK-RT
// RUN: rm %S/a.out %S/a.o



#include <stdio.h>

typedef struct FigureTag {} <
    first_tag, second_tag : void;
    third_tag : void;
> FigureTag;
FigureTag + < fourth_tag : void; >;
FigureTag + < fifth_tag : void; >;


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

void printlnVoid<FigureTag.fourth_tag *f>() {
  printf("fourth void entiy\n");
}

void printlnVoid<FigureTag.fifth_tag *f>() {
  printf("fifth void entiy\n");
}


int main() {
    struct FigureTag.first_tag tfc1;
    printlnVoid<&tfc1>();

    struct FigureTag.second_tag tfc2;
    printlnVoid<&tfc2>();

    struct FigureTag.third_tag tfc3;
    printlnVoid<&tfc3>();

    struct FigureTag.fourth_tag tfc4;
    printlnVoid<&tfc4>();

    struct FigureTag.fifth_tag tfc5;
    printlnVoid<&tfc5>();

    return 0;
}
