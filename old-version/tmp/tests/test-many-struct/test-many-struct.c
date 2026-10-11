// Тестирование многократного объявления структур в одной единице компиляции
// !!! Проходит в gcc. Не проходит в clang

typedef struct Name {} Name;
// struct Name {};
struct Name n1;

typedef struct Name {} Name;
Name t1;

struct Name {};
struct Name n2;

int main() {
  struct Name {};
  struct Name n3;

  struct Name {};
  struct Name n4;

  return 0;
}