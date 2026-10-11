// RUN: %clang -c %s -o %S/a.o
// RUN: %clang %S/a.o -o %S/a.out
// RUN: %S/a.out | FileCheck %s -check-prefix=CHECK-RT
// RUN: rm %S/a.out %S/a.o



#include <stdio.h>

typedef struct FigureTag {} <
    first_tag, second_tag : void;
    third_tag : int;
> FigureTag;
FigureTag + < fourth_tag : int; >;
FigureTag + < fifth_tag : void; >;


void printlnIntVoidMix<FigureTag *f>() {
  printf("Default generalized function\n");
}

void printlnIntVoidMix<FigureTag.first_tag *f>() {
  printf("first void entiy\n");
}

void printlnIntVoidMix<FigureTag.second_tag *f>() {
  printf("second void entiy\n");
}

void printlnIntVoidMix<FigureTag.third_tag *f>() {
  printf("third =  %d\n", f->@);
}

void printlnIntVoidMix<FigureTag.fourth_tag *f>() {
  printf("fourth void entiy\n");
}

void printlnIntVoidMix<FigureTag.fifth_tag *f>() {
  printf("fifth void entiy\n");
}


int main() {
    struct FigureTag.first_tag tfc1;
    printlnIntVoidMix<&tfc1>();

    struct FigureTag.second_tag tfc2;
    printlnIntVoidMix<&tfc2>();

    struct FigureTag.third_tag tfc3;
    tfc3.@ = 3;
    printlnIntVoidMix<&tfc3>();

    struct FigureTag.third_tag tfc4;
    tfc4.@ = 4;
    printlnIntVoidMix<&tfc4>();

    struct FigureTag.fifth_tag tfc5;
    printlnIntVoidMix<&tfc5>();

    return 0;
}
