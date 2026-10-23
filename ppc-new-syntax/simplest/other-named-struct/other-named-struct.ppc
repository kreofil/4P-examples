//==============================================================================
// noname-struct.ppc - ppclang -xc noname-struct.ppc -o noname-struct
// Проверка использования разных описаний структур в качестве специализаций
//==============================================================================

#include <stdio.h>

//------------------------------------------------------------------------------
// Начальное описание обобщений и обработчика от одного аргумента
//------------------------------------------------------------------------------

// Обобщеная фигура, расширяемая различными основами
typedef struct Shape {} case{} Shape;
// Общий обработчик по умолчанию для тех, кто не имеет своего обработчика.
void Action<Shape* s>() {
  printf("It is incorect Shape\n");
}

struct R2 {int x, y;};              // Проходит
Shape + {struct R2 Rectangle3;};               // Проходит
// typedef struct R {int x, y;} R;    // Проходит
typedef struct {int x, y;} R;         // Проходит
Shape + {R Rectangle;};               // Проходит
// Специализация обобщения с неименованной структурой
Shape + {struct{int x, y;} Rectangle2;};   // Не проходит
// И ее обработчик специализации
void Action<Shape.Rectangle* s>() {
  printf("It is Rectangle: x = %d, y = %d\n", s->Rectangle.x, s->Rectangle.y);
}
void Action<Shape.Rectangle2* s>() {
  printf("It is Rectangle2: x = %d, y = %d\n", s->Rectangle2.x, s->Rectangle2.y);
}
void Action<Shape.Rectangle3* s>() {
  printf("It is Rectangle3: x = %d, y = %d\n", s->Rectangle3.x, s->Rectangle3.y);
}


//------------------------------------------------------------------------------
// Тестирование вариантов фигур
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  Shape.Rectangle rectangle = {3, 10};
  Shape.Rectangle2 rectangle2 = {13, 10};
  Shape.Rectangle3 rectangle3 = {130, 100};

  // Тестирование неименованных специализированных фигур
  Action<&rectangle>();
  Action<&rectangle2>();
  Action<&rectangle3>();

  return 0;
}
