#include <stdio.h>

typedef struct Point {int x, y;} Point;

//------------------------------------------------------------------------------
typedef struct Circle {
  Point itsCenter;
  int itsRadius;
} Circle;

void PrintCircle(Circle* c) {
  printf("It is Circle. Center = (%d, %d). Radius = %d\n",
         c->itsCenter.x, c->itsCenter.y, c->itsRadius);
}

//------------------------------------------------------------------------------
typedef struct Square  {
  Point itsTopLeft;
  int itsSide;
} Square;

void PrintSquare(Square* s) {
  printf("It is Square. Top left = (%d, %d). Side = %d\n",
         s->itsTopLeft.x, s->itsTopLeft.y, s->itsSide);
}

//------------------------------------------------------------------------------
typedef struct Figure {}<> Figure;
Figure + <Circle;>;
Figure + <Square;>;

void PrintFigure(Figure* f) {
  struct Figure.Circle c;
  struct Figure.Square s;
  // if(spec_index_cmp(&c, f) > 0) {
  if(spec_index_cmp(f, &c) > 0) {
      struct Figure.Circle* pc = (struct Figure.Circle*)f;
    PrintCircle(&(pc->@));
  // } else if(spec_index_cmp(&s, f) > 0) {
  } else if(spec_index_cmp(f, &s) > 0) {
    struct Figure.Square* ps = (struct Figure.Square*)f;
    PrintSquare(&(ps->@));
  }
}

void Print<Figure* f>() = 0; // {}
void Print<Figure.Circle* f>() {
  PrintCircle(&(f->@));
}
void Print<Figure.Square* f>() {
  PrintSquare(&(f->@));
}

//------------------------------------------------------------------------------
int main() {
  struct Figure.Circle c;
  c.@itsCenter.x = 0;
  c.@itsCenter.y = 0;
  c.@itsRadius = 5;
  struct Figure.Square s;
  s.@itsTopLeft.x = -5;
  s.@itsTopLeft.y = 5;
  s.@itsSide = 10;

  Figure* fc = (Figure*)&c;
  PrintFigure(fc);
  Figure* fs = (Figure*)&s;
  PrintFigure(fs);

  Print<(Figure*)&c>();
  Print<(Figure*)&s>();

  return 0;
}
