//------------------------------------------------------------------------------
// newfig.go - содержит описание дополнительной функции создания фигуры

package figure

import (
    "fmt"

    "go-evolution/rectangle"
    "go-evolution/triangle"
)

// Функция осуществляющая ввод создание фигуры с подключением ее к интерфейсу
func NewFigure(key int) *ColoredFigure {
    var f Figure
    switch key {
        case 1: // Rectangle
            r := new(rectangle.Rectangle)
            f = r
        case 2: // Triangle
            t := new(triangle.Triangle)
            f = t
        default:
            panic(fmt.Sprintf("Incorrect figure key = %d", key))
    }
    cf := new(ColoredFigure)
    cf.Figure = f
    return cf
}
