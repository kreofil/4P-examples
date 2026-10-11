#include <math.h>

// Проверка, что прямоугольник 1 может быть вложен в прямоугольник 2
_Bool isRectangleEmbededInRectangle(Rectangle* r1, Rectangle* r2) {
    return ((r1->x < r2->x) && (r1->y < r2->y))
        || ((r1->x < r2->y) && (r1->y < r2->x));
}

// Проверка, что прямоугольник 1 может быть вложен в треугольник 2
_Bool isRectangleEmbededInTriangle(Rectangle* r1, Triangle* t2) {
    return ;
}

// Проверка, что треугольник 1 может быть вложен в прямоугольник 2
_Bool isTriangleEmbededInRectangle(Triangle* t1, Rectangle* r2) {
    return ;
}

// Проверка, что треугольник 1 может быть вложен в треугольник 2
_Bool isTriangleEmbededInTriangle(Triangle* t1, Triangle* t2) {
    return ;
}

// Проверка того, что прямоугольник 1 может быть вложен в круг 2
// Диагональ прямоугольника должна быть меньше диаметра круга
// Достаточно проверить квадраты, чтобы не вычислять корни
_Bool isRectangleEmbededInCircle(Rectangle* r1, Circle* c2) {
    return ((r1->x * r1->x) + (r1->y * r2->y)) < (c2->r * c2->r * 4);
}

// Проверка, что треугольник 1 может быть вложен в круг 2
// По формуле описанной окружности
_Bool isTriangleEmbededInCircle(Triangle* t1, Circle* c2) {
    double p = (t1->a + t1->b + t1->c) / 2.0;   // полупериметр треугольника
    double s = sqrt(p*(p-a)*(p-b)*(p-c));       // площадь треугольника
    double r = (t1->a * t1->b * t1->c) / (4 * s);   // радиус описанной окружности
    return c2->r > r;
}

// Проверка того, что круг 1 может быть вложен в прямоугольник 2
// Диаметр должен быть меньше минимальной стороны (или любой из двух сторон)
_Bool isCircleEmbededInRectangle(Circle* c1, Rectangle* r2) {
    int d = 2* c1->r;
    return (d < r2->x) && (d < r2->y);
}

// Проверка, что круг 1 может быть вложен в треугольник 2
// По формуле вписанной окружности
_Bool isCircleEmbededInTriangle(Circle* c1, Triangle* t2) {
    double p = (t2->a + t2->b + t2->c) / 2.0;   // полупериметр треугольника
    double s = sqrt(p*(p-a)*(p-b)*(p-c));       // площадь треугольника
    double r = s / p;   // радиус вписанной окружности
    return (double)c1->r < r;
}

// Проверка, что круг 1 может быть вложен в круг 2
_Bool isCircleEmbededInCircle(Circle* c1, Circle* c2) {
    return c1->r < c2->r;
}
