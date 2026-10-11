#include <stdio.h>
#include <stdlib.h>

//==============================================================================
typedef struct Rectangle {
  int x, y;   // стороны прямоугольника
}<> Rectangle;

void setX(Rectangle* r, int _x) {r->x = _x;}
void setY(Rectangle* r, int _y) {r->y = _y;}

int getX(Rectangle* r) {return r->x;}
int getY(Rectangle* r) {return r->y;}

double RectangleArea(Rectangle* r) {return (double)(r->x * r->y);}

void RectanglePrint(Rectangle* r) {
    printf("Rectangle. x = %d; y = %d\n", r->x, r->y);
}

//------------------------------------------------------------------------------
double Area<Rectangle* r>() {return RectangleArea(r);}

void Print<Rectangle* r>() {RectanglePrint(r);}

// Функция, использующая прямоугольник
void BigMethod(Rectangle* r) {
  double result = Area<r>() / -2.0;
  printf("Big Result = %lf\n", result);
}


//==============================================================================
// Периметр можно обобщить. Он может использоваться с любыми прямоугольниками.
double Perimeter<Rectangle* r>() {
  return 2.0 * (r->x + r->y);
}

//==============================================================================
// Специализированный прямоугольник с цветом
Rectangle + <Color: int;>;

void setColor(struct Rectangle.Color* cr, int c) {
  cr->@ = c;
}

// Отдельный обработчик для печати прямоугольников с цветом
void Print<Rectangle.Color* cr>() {
    RectanglePrint((Rectangle*)cr); // явное обращение к основе
    printf("    Color = %d\n", cr->@);
}

// Метод, обеспечивающий поддержку дополнительной функциональности
// для прямоугольников с цветом
void ColorExpandedMethod(struct Rectangle.Color* cr) {
  double result = Perimeter<(Rectangle*)cr>() * 10.0;
  printf("Color Expanded result = %lf\n", result);
}

//==============================================================================
// Специализированный прямоугольник со счетчиком
Rectangle + <Counter: int;>;

void setCounter(struct Rectangle.Counter* ct, int v) {
  ct->@ = v;
}

// Переопределение вычисление площади с добавлением счетчика
double Area<Rectangle.Counter* ct>() {
  ++ct->@;
  return RectangleArea((Rectangle*)ct);
}

// Отдельный обработчик для печати прямоугольников со счетчиком
void Print<Rectangle.Counter* ct>() {
  RectanglePrint((Rectangle*)ct); // явное обращение к основе
  printf("    Counter = %d\n", ct->@);
}

// Метод, обеспечивающий поддержку дополнительной функциональности
// для прямоугольников со счетчиком
void CounterExpandedMethod(struct Rectangle.Counter* ct) {
  double result = Perimeter<(Rectangle*)ct>() * 20.0;
  printf("Counter Expanded result = %lf\n", result);
}

//==============================================================================
// Клиентский код, использующий расширенное приложение
int main(int argc, char* argv[]) {
  if(argc != 4) {
    printf("Incorrect command line. Use %s X Y Color\n", argv[0]);
    return -1;
  }
  //----------------------------------------------------------------------------
  // Использование обычного прямоугольника, но уже в обертке.
  printf("---------- Using a simple rectangle ----------\n");
  struct Rectangle r;
  // Использование исходного приложения для обернутого прямоугольника
  setX(&r, atoi(argv[1]));
  setY(&r, atoi(argv[2]));
  Print<&r>();
  BigMethod(&r);
  //----------------------------------------------------------------------------
  // Создание и использование прямоугольника с цветом
  printf("---------- Using a colored rectangle ----------\n");
  struct Rectangle.Color cr;
  setX((Rectangle*)&cr, atoi(argv[1]));
  setY((Rectangle*)&cr, atoi(argv[2]));
  setColor(&cr, atoi(argv[3]));
  Print<(Rectangle*)&cr>();

  // Использование прежнего приложения для прямоугольника с цветом
  BigMethod((Rectangle*)&cr);
  // Подключение расширенных функций
  ColorExpandedMethod(&cr);

  //----------------------------------------------------------------------------
  // Создание и использование прямоугольника со счетчиком
  printf("---------- Using a rectangle with a counter ----------\n");
  struct Rectangle.Counter ctr;
  setX((Rectangle*)&ctr, atoi(argv[1]));
  setY((Rectangle*)&ctr, atoi(argv[2]));
  setCounter(&ctr, 0);      // начальная установка счетчика
  Print<(Rectangle*)&ctr>();

  // Использование прежнего приложения для прямоугольника со счетчиком
  BigMethod((Rectangle*)&ctr);
  BigMethod((Rectangle*)&ctr);
  // Подключение расширенных функций
  CounterExpandedMethod(&ctr);
  Print<(Rectangle*)&ctr>();
}
