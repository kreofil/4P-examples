#include <stdio.h>
#include "../../list/list.h"
#include "../../container/container.h"

Container + <List;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){

    struct Container.List l;
    InitContainer<&l>();

    // Setting numbers
    for(uint i = 0; i < 15; ++i){
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&l>(a);
    }

    // Printing
    while(l@size){
        struct Value.Int* a = FrontContainer<&l>();
        printf("%d ", a->@x); // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
        PopFrontContainer<&l>();
    }
    return 0;
}