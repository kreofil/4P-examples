#ifndef __first__
#define __first__


typedef struct FigureTag { } <
    first_tag, second_tag : int;
    third_tag : int;
> FigureTag;

void printlnInt<FigureTag *f>();

#endif //__first__