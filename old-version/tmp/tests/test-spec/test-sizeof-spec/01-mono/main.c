// Проверка sizeof
#include <stdio.h>

typedef struct Int{int i;} Int;
typedef struct Double{double d;} Double;
typedef struct Float{float f;} Float;
// typedef struct Char{char c;} Char;
struct Char{char c;};
typedef struct Triangle{long int a, b, c;}Triangle;


typedef struct Number {double x, y, z, q; } <
    Int;
    doub : Double;
    // int;
> Number;

Number + <Double;>;
// Number + <int: Double;>;
Number + <i: int;>;
Number + <int: int;>;
Number + <Float: int;>;
Number + <Char;>;
Number + <triangle: Triangle;>;

int main() {
  printf("Size of Number = %lu\n", sizeof(Number));
  // printf("Size of Number.Int = %lu\n", sizeof(Number.Int));
  // printf("Size of Number.Char = %lu\n", sizeof(Number.Char));
  // printf("Size of Number.Double = %lu\n", sizeof(Number.Double));
  // printf("Size of Number.triangle = %lu\n", sizeof(Number.triangle));

  struct Number.Int numInt;
  printf("Size of numInt = %lu\n", sizeof(numInt));

  struct Number.Char numChar;
  printf("Size of numChar = %lu\n", sizeof(numChar));

  struct Number.Double numDouble;
  printf("Size of numDouble = %lu\n", sizeof(numDouble));

  struct Number.triangle numTriangle;
  printf("Size of numTriangle = %lu\n", sizeof(numTriangle));

  return 0;
}
