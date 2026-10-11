// Исправлено. Работает!!!

// Проверка присваивания различных переменных, порождаемых от одного
// обобщения. На примере фигур треугольника и прямоугольника.
// Присваиеваие друг другу разных специализаци в любом случае не должно
// проходить. Компилятор после проверки основного типа должен сопоставлять
// всю цепочку подтипов.

#include <stdio.h>

typedef struct Rectangle {int x, y;} Rectangle;
typedef struct Triangle {int a, b, c;} Triangle;

// typedef struct Figure {} case {
//   Triangle t;
//   Rectangle r;
// } Figure;

typedef struct Figure {} case {} Figure;
Figure + {Triangle t;};
Figure + {Rectangle r;};

int main() {
  Figure f;
  Figure.t t = {3,4,5};
  Figure.r r = {10,20};

  printf("Triangle(%d,%d,%d)\n", t.t.a, t.t.b, t.t.c);
  printf("Rectangle(%d,%d)\n", r.r.x, r.r.y);

  // А это косяки. Они отработаны и работают корректно.
  // t = r;
  // r = t;
  // f = r;    // Здесь вывод вообще невозможен
  // f = t;
  // t = f;
  // r = f;

  // Присваивание однотипных специализаций
  Figure.t t2 = t;
  Figure.r r2 = r;

  printf("Triangle(%d,%d,%d)\n", t2.t.a, t2.t.b, t2.t.c);
  printf("Rectangle(%d,%d)\n", r2.r.x, r2.r.y);

  return 0;
}

