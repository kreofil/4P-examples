#ifndef __first__
#define __first__


typedef struct FigureTag {} <
    first_tag, second_tag : void;
    third_tag : void;
> FigureTag;

void printlnVoid<FigureTag *f>();

#endif //__first__