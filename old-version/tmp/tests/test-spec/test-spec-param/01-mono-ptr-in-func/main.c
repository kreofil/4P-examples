// Проверка спецциализированного параметра, расположенного в обычных
// круглых скобках
#include <stdio.h>

typedef struct Spec1 {int x;} Spec1;
typedef struct Spec2 {double y;} Spec2;

typedef struct General {int commonField;} <
    spec1: Spec1;
    spec2: Spec2;
> General;

/*
 * Хотелось, чтобы можно было использовать указатели на специализации
 * внутри круглых скобок примерно таким образом:
 */
// void printlnSpec1(General<spec1>* spec) {
void printlnSpec1(struct General.spec1* spec) {
  printf("General.spec1 = (%d, %d)\n", spec->commonField, spec->@x);
}

// void printlnSpec2(General<spec2>* spec) {
void printlnSpec2(struct General.spec2* spec) {
  printf("General.spec2 = (%d, %f)\n", spec->commonField, spec->@y);
}

/*
 * Пока же приходится делать дополнительные явные преобразования,
 * что снижает юзабилити и надежность.
 */
// void printlnSpec1(General* spec_transformed) {
//   struct General<spec1>* spec = (struct General<spec1>*)spec_transformed;
//   printf("General.spec1 = (%d, %d)\n", spec->commonField, spec->@x);
// }
//
// void printlnSpec2(General* spec_transformed) {
//   struct General<spec2>* spec = (struct General<spec2>*)spec_transformed;
//   printf("General.spec2 = (%d, %f)\n", spec->commonField, spec->@y);
// }

int main() {
    struct General.spec1 specInt;
    specInt.commonField = -10;
    specInt.@x = 10;
    // printlnSpec1((General*)&specInt);
    printlnSpec1(&specInt);

    struct General.spec2 specDouble;
    specDouble.commonField = -100;
    specDouble.@y = 3.14;
    // printlnSpec2((General*)&specDouble);
    printlnSpec2(&specDouble);

    return 0;
}
