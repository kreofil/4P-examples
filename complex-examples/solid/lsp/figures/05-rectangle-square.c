#include <stdio.h>

//------------------------------------------------------------------------------
typedef struct Rectangle {
  int width;
  int height;
}<Square:void;> Rectangle;
// Rectangle + <Square:void;>;

void SetWidt<Rectangle* r>(int w) {r->width = w;};
int GetWidth(Rectangle* r) {return r->width;}
void SetHeight<Rectangle* r>(int h) {r->height = h;};
int GetHeight(Rectangle* r) {return r->height;}
int Area(Rectangle* r) {return r->width * r->height;}

//------------------------------------------------------------------------------
void SetWidt<Rectangle.Square* r>(int w) {
  r->width = w;
  r->height = w;
};
void SetHeight<Rectangle.Square* r>(int h) {
  r->height = h;
  r->width = h;
};

//------------------------------------------------------------------------------
void f_val(Rectangle r) {
  SetWidt<&r>(32);
  printf("f_val(Rectangle) = (%d,%d)\n", GetWidth(&r), GetHeight(&r));
}

void f_ref(Rectangle* r) {
  SetWidt<r>(32);
  printf("f_ref(Rectangle*) = (%d,%d)\n", GetWidth(r), GetHeight(r));
}

void g_val(Rectangle r) {
  SetWidt<&r>(5);
  SetHeight<&r>(4);
  printf("g_val(Rectangle) = (%d,%d)\n", GetWidth(&r), GetHeight(&r));
  printf("Area = %d\n", Area(&r));
}

void g_ref(Rectangle* r) {
  SetWidt<r>(5);
  SetHeight<r>(4);
  printf("g_ref(Rectangle*) = (%d,%d)\n", GetWidth(r), GetHeight(r));
  printf("Area = %d\n", Area(r));
}

//------------------------------------------------------------------------------
int main() {
  struct Rectangle.Square s;
  SetWidt<&s>(1);
  printf("Square(%d,%d)\n", GetWidth(&s), GetHeight(&s));
  SetHeight<&s>(2);
  printf("Square(%d,%d)\n", GetWidth(&s), GetHeight(&s));
  // f_val(s);
  f_ref(&s);
  // g_val(s);
  g_ref(&s);

  struct Rectangle r;
  SetWidt<&r>(1);
  printf("Rectangle(%d,%d)\n", GetWidth(&r), GetHeight(&r));
  SetHeight<&r>(2);
  printf("Rectangle(%d,%d)\n", GetWidth(&r), GetHeight(&r));
  f_val(r);
  f_ref(&r);
  g_val(r);
  g_ref(&r);

  return 0;
}
