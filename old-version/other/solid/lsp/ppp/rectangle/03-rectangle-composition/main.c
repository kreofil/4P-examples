#include <stdio.h>
#include <stdlib.h>

//==============================================================================
// Универсальный коннектор, позволяющий обобщать что угодно
typedef struct Connector {}<> Connector;

// Площадь чего угодно
double Area<Connector* c>() {
  printf("You need redefine Area function\n");
  exit(-1);
}

// Печать чего угодно
void Print<Connector* c>() {
  printf("You need redefine Area function\n");
  exit(-2);
}

//==============================================================================
// Обычный прямоугольник
typedef struct Rectangle {
  int x, y;   // стороны прямоугольника
} Rectangle;

void setX(Rectangle* r, int _x) {r->x = _x;}
void setY(Rectangle* r, int _y) {r->y = _y;}

int getX(Rectangle* r) {return r->x;}
int getY(Rectangle* r) {return r->y;}

double RectangleArea(Rectangle* r) {return (double)(r->x * r->y);}

void RectanglePrint(Rectangle* r) {
    printf("Rectangle. x = %d; y = %d\n", r->x, r->y);
}

//------------------------------------------------------------------------------
// Использование предварительной унификации для последующих разных подстановок
Connector + <Rectangle;>;

// Определение полиморфно, чтобы обеспечить поддержку LSP
double Area<Connector.Rectangle* cr>() {return RectangleArea(&(cr->@));}

// Площадь через коннектор
void Print<Connector.Rectangle* cr>() {RectanglePrint(&(cr->@));}


// Функция, изначально использующая прямоугольник, но учитывающая
// появление новых специализаций чтобы использовать LSP.
void BigMethod(struct Connector* с) {
  double result = Area<с>() / -2.0;
  printf("Big Method Result = %lf\n", result);
}

//==============================================================================
// Периметр для прямоугольника появился позднее.
// Он будет использоваться только с новыми специализациями
// и их функциями, расширяющими общую функциональность.
double RectanglePerimeter(Rectangle* r) {
  return 2.0 * (r->x + r->y);
}

//==============================================================================
// Специализированный прямоугольник с цветом, использующий композицию
typedef struct ColorRectangle {
  int color;
  Rectangle r;  // но можно и через указатель...
} ColorRectangle;

void setColor(ColorRectangle* cr, int c) {
  cr->color = c;
}

//------------------------------------------------------------------------------
// Добавление в специализацию  прямоугольников с цветом
Connector + <ColorRectangle;>;

// Так как будет использоваться LSP, то нужно площадь определить полиморфно.
double Area<Connector.ColorRectangle* cr>()  {
  return RectangleArea(&(cr->@r)); // явное обращение к основе
}

// Отдельный обработчик для печати прямоугольников с цветом
void Print<Connector.ColorRectangle* cr>() {
    RectanglePrint(&(cr->@r)); // явное обращение к основе
    printf("    Color = %d\n", cr->@color);
}

// Метод, обеспечивающий поддержку дополнительной функциональности
// для прямоугольников с цветом
void ColorExpandedMethod(struct ColorRectangle* cr) {
  double result = RectanglePerimeter(&(cr->r)) * 10.0;
  printf("Color Expanded result = %lf\n", result);
}

//==============================================================================
// Специализированный прямоугольник со счетчиком, использующий композицию
typedef struct CountRectangle {
  int counter;
  Rectangle* r;  // но можно и обчным включением...
} CountRectangle;

void setCounter(CountRectangle* cc, int c) {
  cc->counter = c;
}

//------------------------------------------------------------------------------
// Добавление в специализацию прямоугольника со счетчиком
Connector + <CountRectangle;>;

// Переопределение вычисления площади с добавлением счетчика
double Area<Connector.CountRectangle* cc>() {
  ++(cc->@counter);
  return RectangleArea(cc->@r);
}

// Отдельный обработчик для печати прямоугольников со счетчиком
void Print<Connector.CountRectangle* cc>() {
  RectanglePrint(cc->@r); // явное обращение к основе
  printf("    Counter = %d\n", cc->@counter);
}

// Метод, обеспечивающий поддержку дополнительной функциональности
// для прямоугольников со счетчиком
void CounterExpandedMethod(CountRectangle* cc) {
  double result = RectanglePerimeter(cc->r) * 20.0;
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
  struct Connector.Rectangle cr;
  // Использование исходного приложения для обернутого прямоугольника
  printf("---------- Using a simple rectangle ----------\n");
  setX(&(cr.@), atoi(argv[1]));
  setY(&(cr.@), atoi(argv[2]));
  Print<(Connector*)&cr>();
  BigMethod((Connector*)&cr);

  //----------------------------------------------------------------------------
  // Создание и использование прямоугольника с цветом
  printf("---------- Using a colored rectangle ----------\n");
  struct Connector.ColorRectangle ccr;
  setX(&(ccr.@r), atoi(argv[1]));
  setY(&(ccr.@r), atoi(argv[2]));
  setColor(&(ccr.@), atoi(argv[3]));
  Print<(Connector*)&ccr>();

  // Использование прежнего приложения для прямоугольника с цветом
  BigMethod((Connector*)&ccr);
  // Подключение расширенных функций
  ColorExpandedMethod(&(ccr.@));

  //----------------------------------------------------------------------------
  // Создание и использование прямоугольника со счетчиком
  printf("---------- Using a rectangle with a counter ----------\n");
  struct Connector.CountRectangle ctr;
  Rectangle r;
  ctr.@r = &r;
  setX(&r, atoi(argv[1]));
  setY(&r, atoi(argv[2]));
  setCounter(&(ctr.@), 0);      // начальная установка счетчика
  Print<(Connector*)&ctr>();

  // Использование прежнего приложения для прямоугольника со счетчиком
  BigMethod((Connector*)&ctr);
  BigMethod((Connector*)&ctr);
  // Подключение расширенных функций
  CounterExpandedMethod(&(ctr.@));
  Print<(Connector*)&ctr>();
}
