#include <stdio.h>
#include "first.h"
#include "fourth.h"
#include "fifth.h"

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
