//==============================================================================
// Простая проверка 4П с использованием struct case
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

typedef struct Rectangle {int x, y;} Rectangle;
Shape + {Rectangle rect;};

void Action<Shape.rect* s>() {
  printf("It is Rectangle: x = %d, y = %d\n", s->rect.x, s->rect.y);
}

typedef struct Triangle {int a, b, c;} Triangle;
Shape + {Triangle trian;};

void Action<Shape.trian* s>() {
  printf("It is Triangle: a = %d, b = %d, c = %d\n",
         s->trian.a, s->trian.b, s->trian.c);
}

//------------------------------------------------------------------------------
// Тестирование вариантов фигур
//------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
  Shape.rect r1 = {3, 10};
  Shape.rect r2 = {130, 100};
  Shape.trian t1 = {13, 10, 11};

  // Тестирование специализированных фигур
  Action<&r1>();
  Action<&r2>();
  Action<&t1>();

  return 0;
}
