// Проверка sizeof
#include <stdio.h>

typedef struct Int{int i;} Int;
typedef struct Double{double d;} Double;

typedef struct Number {} <
    Integer: Int;
    Double : Double;
> Number;

typedef struct Variant {} <
    num: Number;
> Variant;


typedef struct Combi {
  struct Number.Integer numInt;
  struct Number.Double numDouble;
} Combi;

struct Number.Integer numIntExt;
static struct Number.Integer numIntStatic;

Combi combiExt;

void test_type_tag(struct Number* num) {
  printf("Tag = %d\n", num->__pp_specialization_type);
}

int main() {
  struct Variant.num.Integer vNumInteger;
  // test_type_tag(&vNumInteger);
  vNumInteger.@.@i = 33;
  printf("Size of vNumInteger = %lu\n", sizeof(vNumInteger));
  printf("    vNumInteger = %d\n", vNumInteger.@.@i);
  test_type_tag((Variant*)&vNumInteger);
  struct Number.Integer nInt;



  numIntExt.@i = 111;
  printf("Size of numIntExt = %lu\n", sizeof(numIntExt));
  printf("    numIntExt = %d\n", numIntExt.@i);
  test_type_tag((Number*)&numIntExt);

  numIntStatic.@i = 222;
  printf("Size of numIntStatic = %lu\n", sizeof(numIntStatic));
  printf("    numIntStatic = %d\n", numIntStatic.@i);
  test_type_tag((Number*)&numIntStatic);

  static struct Number.Integer numIntStaticMain;
  numIntStaticMain.@i = 333;
  printf("Size of numIntStaticMain = %lu\n", sizeof(numIntStaticMain));
  printf("    numIntStaticMain = %d\n", numIntStaticMain.@i);
  test_type_tag((Number*)&numIntStaticMain);

  struct Number.Integer numInt;
  numInt.@i = 444;
  printf("Size of numInt = %lu\n", sizeof(numInt));
  printf("    numInt = %d\n", numInt.@i);
  test_type_tag((Number*)&numInt);

  struct Number.Double numDouble;
  numDouble.@d = 555;
  printf("Size of numDouble = %lu\n", sizeof(numDouble));
  printf("    numDouble = %f\n", numDouble.@d);
  test_type_tag((Number*)&numDouble);

  Combi combi;
  combi.numInt.@i = 777;
  combi.numDouble.@d = 888;
  printf("Size of combi = %lu\n", sizeof(combi));
  printf("    combi.numInt = %d;  combi.numDouble = %f\n",
         combi.numInt.@i, combi.numDouble.@d);
  test_type_tag((Number*)&combi.numInt);
  test_type_tag((Number*)&combi.numDouble);

  Combi combiStatMain;
  combiStatMain.numInt.@i = 7777;
  combiStatMain.numDouble.@d = 8888;
  printf("Size of combi = %lu\n", sizeof(combiStatMain));
  printf("    combiStatMain.numInt = %d;  combiStatMain.numDouble = %f\n",
         combiStatMain.numInt.@i, combiStatMain.numDouble.@d);
  test_type_tag((Number*)&combiStatMain.numInt);
  test_type_tag((Number*)&combiStatMain.numDouble);

  combiExt.numInt.@i = 9999;
  combiExt.numDouble.@d = 1212;
  printf("Size of combi = %lu\n", sizeof(combiExt));
  printf("    combiExt.numInt = %d;  combiExt.numDouble = %f\n",
         combiExt.numInt.@i, combiExt.numDouble.@d);
  test_type_tag((Number*)&combiExt.numInt);
  test_type_tag((Number*)&combiExt.numDouble);

  return 0;
}
