#include "library.h"

struct Figure{}<>;

struct S1 {};

struct Figure + <S1;>;

void Print<struct Figure* f>(){
    printf("Default from lib\n");
}

void Print<struct Figure.S1* f>(){
    printf("Figure.S1 from lib\n");
}

void library_function(void) {
    printf("Hello from shared library (v2)!\n");
}
