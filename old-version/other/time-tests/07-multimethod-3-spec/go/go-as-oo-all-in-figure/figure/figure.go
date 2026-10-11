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

    MMP(Figure) float64                     // Мультиметод, вычисляющий переметры
    RectangleContinuePerimeter(*Rectangle) float64    // Продолжение, когда первый - прямоугольник
    TriangleContinuePerimeter(*Triangle) float64      // Продолжение, когда первый - треугольник
    CircleContinuePerimeter(*Circle) float64          // Продолжение, когда первый - круг
}
