// Тестирование возможности использования union в качестве основы специализации
#include <stdio.h>

//------------------------------------------------------------------------------
typedef struct Rectangle {
  int x;
  int y;
} Rectangle;

// Вывод прямоугольника
void RectanglePrint(Rectangle* r) {
  fprintf(stdout, "Rectangle: x = %d, y = %d\n", r->x, r->y);
}

//------------------------------------------------------------------------------
typedef struct Triangle {
  int a;
  int b;
  int c;
} Triangle;

// Вывод треугольника
void TrianglePrint(Triangle* t) {
  fprintf(stdout, "Triangle: a = %d, b = %d, c = %d\n", t->a, t->b, t->c);
}

//------------------------------------------------------------------------------
typedef  struct Mix {
  union {
    Rectangle r;
    Triangle t;
  };
} Mix;

// Специализации на основе объединения
typedef struct Figure {} <rect, trian: Mix> Figure;

// Вывод содержимого специализаций с использованием полиморфизма
void FigurePrint<Figure* f>() {
  fprintf(stdout, "Incorrect Figure\n");
}

void FigurePrint<Figure.rect* f>() {
  RectanglePrint(&(f->@r));
}

void FigurePrint<Figure.trian* f>() {
  TrianglePrint(&(f->@t));
}


//------------------------------------------------------------------------------
int main() {
  struct Figure.rect t;
  printf("size of Mix  = %lu\n", sizeof(Mix));
  printf("size of Figure.rect  = %lu\n", sizeof(struct Figure.rect));
  printf("size t = %lu\n", sizeof(t));
  init_spec(Figure.rect, &t);
  t@r.x = 5;
  t.@r.y = 10;
  printf("size x = %d, y = %d\n", t.@r.x, t.@r.y);

  struct Figure.rect A[10];
  printf("size A = %lu\n", sizeof(A));
  init_spec(Figure.rect, &A[0]);
  A->@r.x = 13;
  A->@r.y = 17;
  // struct Figure.rect* p = &A[0];
  struct Figure.rect* p = A+0;
  printf("size x = %d, y = %d\n", p->@r.x, p->@r.y);
  // printf("size x = %d, y = %d\n", (A+0)->@r.x, (A+0)->@r.y);
  // printf("size x = %d, y = %d\n", (&A[0])->@r.x, (&A[0])->@r.y);
  // printf("size x = %d, y = %d\n", A[0].@r.x, A[0].@r.y);

  return 0;
}
