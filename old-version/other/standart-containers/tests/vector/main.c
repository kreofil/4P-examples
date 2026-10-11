#include <stdio.h>
#include "../../vector/vector.h"
#include "../../container/container.h"

Container + <Vector;>;

// Create specialisation for Value
typedef struct Int {int x;} Int;
Value + <Int;>;

int main(){

    struct Container.Vector v;
    InitContainerWithSize<&v>(0);

    // Setting numbers
    for(uint i = 0; i < 15; ++i){
        struct Value.Int* a = create_spec(Value.Int);
        a->@x = i;
        PushBackContainer<&v>(a);
    }

    // Printing
    for(Value** iter = BeginContainer<&v>(); iter != EndContainer<&v>(); NextIteratorContainer<&v>(&iter)) {
        struct Value.Int* a = create_spec(Value.Int);
        a = *iter;
        printf("%d ", a->@x); // 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14
    }
    return 0;
}