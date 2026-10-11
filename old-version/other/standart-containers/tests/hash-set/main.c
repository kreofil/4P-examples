#include <stdio.h>
#include "../../hashset/hashset.h"
#include "../../container/container.h"

Container + <HashSet;>;

// Create specialisation for Value
typedef struct String {char* str;} String;
Value + <String;>;

int main(){
    struct Container.HashSet set;
    InitContainer<&set>();

    struct Value.String *a = create_spec(Value.String);
    a->@str = "hello";
    InsertContainer<&set>(a);

    struct Value.String *b = create_spec(Value.String);
    b->@str = "world";
    printf("is 'hello' inside: %d\n is 'world' inside: %d", ContainsContainer<&set>(a), ContainsContainer<&set>(b));

    return 0;
}