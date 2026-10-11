#include <stdio.h>
#include <stdlib.h>

typedef struct Rectangle {
  int x, y;   // стороны прямоугольника
} Rectangle;

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

// Процедурный агрегат, включающий прямоугольник
typedef struct ColoredRectangle {
  int color;
} <Rectangle> ColoredRectangle;

void setColor(struct ColoredRectangle.Rectangle* cr, int c) {
  cr->color = c;
}

double Perimeter(struct ColoredRectangle.Rectangle* cr) {
    return 2.0 * (cr->@x + cr->@y);
  }

void ColoredRectanglePrint(struct ColoredRectangle.Rectangle* cr) {
    Print(&(cr->@));
    printf("    Color = %d\n", cr->color);
}

// Метод, обеспечивающий поддержку дополнительной функциональности
void ExpandedMethod(struct ColoredRectangle.Rectangle* cr) {
  double result = Perimeter(cr) * 10.0;
  printf("Expanded result = %lf\n", result);
}

// Клиентский код, использующий расширенное приложение
int main(int argc, char* argv[]) {
  if(argc != 4) {
    printf("Incorrect command line. Use %s X Y Color\n", argv[0]);
    return -1;
  }
  struct ColoredRectangle.Rectangle cr;
  setX(&(cr.@), atoi(argv[1]));
  setY(&(cr.@), atoi(argv[2]));
  setColor(&cr, atoi(argv[3]));
  ColoredRectanglePrint(&cr);

  // Использование прежнего приложения
  BigMethod(&(cr.@));

  // Подключение расширенных функций
  ExpandedMethod(&cr);
}