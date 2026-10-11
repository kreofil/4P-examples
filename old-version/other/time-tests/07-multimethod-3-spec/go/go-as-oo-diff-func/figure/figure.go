//------------------------------------------------------------------------------
// figure.go - содержит описание фигуры как интерфейса

package figure

import (
    "os"
)

// фигура
type Figure interface {
    In(*os.File) error
    MM(*os.File, Figure)                      // Мультиметод
    RectangleContinue(*os.File, *Rectangle)   // Продолжение, когда первый - прямоугольник
    TriangleContinue(*os.File, *Triangle)     // Продолжение, когда первый - треугольник
    CircleContinue(*os.File, *Circle)         // Продолжение, когда первый - круг

    Perimeter() float64

    MMP(Figure) int                     // Мультиметод, вычисляющий разные функции
    RectangleContinueDiffFunc(*Rectangle) int  // Продолжение, когда первый - прямоугольник
    TriangleContinueDiffFunc(*Triangle) int  // Продолжение, когда первый - треугольник
    CircleContinueDiffFunc(*Circle) int  // Продолжение, когда первый - круг
}
