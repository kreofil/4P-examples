// RUN: %clang -c %s -o %S/a.o
// RUN: %clang %S/a.o -o %S/a.out
// RUN: %S/a.out | FileCheck %s -check-prefix=CHECK-RT
// RUN: rm %S/a.out %S/a.o



#include <stdio.h>

struct Figure { int f; } < int; >;
typedef struct FigureTag { } <
    first_tag, second_tag : int;
    third_tag : int;
> FigureTag;
FigureTag + < fourth_tag : int; >;
FigureTag + < fifth_tag : int; >;

int main() {
    struct Figure.int fc;
    fc.@ = 5;

    // CHECK-RT: Field value: 5
    printf("Field value: %d\n", fc.@);

    struct FigureTag.first_tag tfc;
    tfc.@ = 1;
    printf("Field value: %d\n", tfc.@);

    struct FigureTag.second_tag tfc2;
    tfc2.@ = 2;
    printf("Field value: %d\n", tfc2.@);

    struct FigureTag.third_tag tfc3;
    tfc3.@ = 3;
    printf("Field value: %d\n", tfc3.@);

    struct FigureTag.fourth_tag tfc4;
    tfc4.@ = 4;
    printf("Field value: %d\n", tfc4.@);

    struct FigureTag.fifth_tag tfc5;
    tfc5.@ = 5;
    printf("Field value: %d\n", tfc5.@);

    return 0;
}
