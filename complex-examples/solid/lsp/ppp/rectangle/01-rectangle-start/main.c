#include <stdio.h>
#include <stdlib.h>

// typedef struct Rectangle {
//   int x, y;   // стороны прямоугольника
// } Rectangle;

typedef struct Rectangle {
  int x, y;   // стороны прямоугольника
}<> Rectangle;

void setX(Rectangle* r, int _x) {r->x = _x;}
void setY(Rectangle* r, int _y) {r->y = _y;}

int getX(Rectangle* r) {return r->x;}
int getY(Rectangle* r) {return r->y;}

double Area(Rectangle* r) {return (double)(r->x * r->y);}

void Print(Rectangle* r) {
    printf("Rectangle. x = %d; y = %d\n", r->x, r->y);
}

// Функция, использующая прямоугольник
void BigMethod(Rectangle* r) {
  double result = Area(r) / -2.0;
  printf("Result = %lf\n", result);
}

// Клиентский код, использующий разработанное большое приложение
int main(int argc, char* argv[]) {
  if(argc != 3) {
    printf("Incorrect command line. Use %s X Y\n", argv[0]);
    return -1;
  }
  //----------------------------------------------------------------------------
  printf("---------- Using a simple rectangle ----------\n");
  Rectangle r;
  setX(&r, atoi(argv[1]));
  setY(&r, atoi(argv[2]));
  Print(&r);

  // Использование приложения
  BigMethod(&r);
}