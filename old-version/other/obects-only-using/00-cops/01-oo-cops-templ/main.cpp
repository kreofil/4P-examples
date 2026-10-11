// ОО версия программы про хорошего и плохого полицейских,
// использующая ОО (динамический) полиморфизм
#include <stdio.h>

struct BadCop { void Action() {
  printf("Бац-бац...\n"); }
};

struct GoodCop {
  void Action() { printf("Именем закона...\n"); }
};

struct UnknownCop { void Action() {
  printf("Непонятно, какой полицейский.\n"); }
};

template<typename T = UnknownCop> void Action() {
  T cop;
  cop.Action();
}

int main() {
  Action<BadCop>();
  // Action<GoodCop>();
  // Action<UnknownCop>();
  // Action();

  return 0;
}
