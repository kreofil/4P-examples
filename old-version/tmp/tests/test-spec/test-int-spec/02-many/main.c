#include <stdio.h>
#include "first.h"
#include "fourth.h"
#include "fifth.h"

int main() {
    struct FigureTag.first_tag tfc1;
    tfc1.@ = 1;
    printlnInt<(FigureTag*)&tfc1>();

    struct FigureTag.second_tag tfc2;
    tfc2.@ = 2;
    printlnInt<(FigureTag*)&tfc2>();

    struct FigureTag.third_tag tfc3;
    tfc3.@ = 3;
    printlnInt<(FigureTag*)&tfc3>();

    struct FigureTag.fourth_tag tfc4;
    tfc4.@ = 4;
    printlnInt<(FigureTag*)&tfc4>();

    struct FigureTag.fifth_tag tfc5;
    tfc5.@ = 5;
    printlnInt<(FigureTag*)&tfc5>();

    return 0;
}
