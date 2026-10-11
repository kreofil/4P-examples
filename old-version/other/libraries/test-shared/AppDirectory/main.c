#include "library.h"
#include <stdio.h>

struct S2 {};

// struct Figure + <S2;>;

// void Print<struct Figure.S2* f>(){
//     printf("Figure.S2 from main\n");
// }

int main() {
    printf("Main program starting...\n");
    library_function();
    // struct Figure.S1 fs1;
    // Print<&fs1>();
    printf("Main program finished.\n");
    return 0;
}