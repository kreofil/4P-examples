#include <stdio.h>

//------------------------------------------------------------------------------
typedef enum {rectangle, square} key;
typedef struct RectangleSquare {
  key k;
  int width;
  int height;
} RectangleSquare;


void SetWidth(RectangleSquare* rs, int w) {
  rs->width = w;
  switch(rs->k) {
    case square:
      rs->height = w;
  }
};

int GetWidth(RectangleSquare* rs) {return rs->width;}

void SetHeight(RectangleSquare* rs, int h) {
  rs->height = h;
  switch(rs->k) {
    case square:
      rs->width = h;
  }
};

int GetHeight(RectangleSquare* rs) {return rs->height;}

int Area(RectangleSquare* rs) {return rs->width * rs->height;}

//------------------------------------------------------------------------------
void f_val(RectangleSquare rs) {
  SetWidth(&rs, 32);
  printf("f_val(Rectangle) = (%d,%d)\n", GetWidth(&rs), GetHeight(&rs));
}

void f_ref(RectangleSquare* rs) {
  SetWidth(rs, 32);
  printf("f_ref(Rectangle*) = (%d,%d)\n", GetWidth(rs), GetHeight(rs));
}

void g_val(RectangleSquare rs) {
  SetWidth(&rs, 5);
  SetHeight(&rs, 4);
  printf("g_val(Rectangle) = (%d,%d)\n", GetWidth(&rs), GetHeight(&rs));
  printf("Area = %d\n", Area(&rs));
}

void g_ref(RectangleSquare* rs) {
  SetWidth(rs, 5);
  SetHeight(rs, 4);
  printf("g_ref(Rectangle*) = (%d,%d)\n", GetWidth(rs), GetHeight(rs));
  printf("Area = %d\n", Area(rs));
}

//------------------------------------------------------------------------------
int main() {
  struct RectangleSquare s;
  s.k = square;
  SetWidth(&s, 1);
  printf("Square(%d,%d)\n", GetWidth(&s), GetHeight(&s));
  SetHeight(&s, 2);
  printf("Square(%d,%d)\n", GetWidth(&s), GetHeight(&s));
  f_val(s);
  f_ref(&s);
  g_val(s);
  g_ref(&s);

  struct RectangleSquare r;
  s.k = rectangle;
  SetWidth(&r, 1);
  printf("Rectangle(%d,%d)\n", GetWidth(&r), GetHeight(&r));
  SetHeight(&r, 2);
  printf("Rectangle(%d,%d)\n", GetWidth(&r), GetHeight(&r));
  f_val(r);
  f_ref(&r);
  g_val(r);
  g_ref(&r);

  return 0;
}
