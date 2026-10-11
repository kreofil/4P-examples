// Процедурная версия программы про хорошего и плохого полицейских
// с выбором копа на этапе компиляции. Варианты
// - плохой коп, когда при компиляции задается ключ -DBAD_COP
// - хороший коп, когда при компиляции задается ключ -DGOOD_COP
// - по умолчанию иной коп. Используется также -std=c23
#include <stdio.h>

#ifdef BAD_COP
  // Действие плохого полицейского
  void ActionOfBadCop() {
    printf("Бац-бац...\n");
  }
#elifdef GOOD_COP
// Действие хорошего полицейского
  void ActionOfGoogCop() {
    printf("Именем закона...\n");
  }
#endif

// Обобщенное действие полицейского
void Action() {
  #ifdef BAD_COP
    ActionOfBadCop();
  #elifdef GOOD_COP
    ActionOfGoogCop();
  #else
    printf("Непонятно, какой полицейский.\n");
  #endif
}

int main() {
  Action();
  return 0;
}
