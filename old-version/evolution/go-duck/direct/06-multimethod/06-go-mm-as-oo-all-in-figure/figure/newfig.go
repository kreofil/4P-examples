//------------------------------------------------------------------------------
// newfig.go - содержит описание дополнительной функции создания фигуры

package figure

import (
    "fmt"
)

// Функция осуществляющая ввод создание фигуры с подключением ее к интерфейсу
func NewFigure(key int) Figure {
    var f Figure
    switch key {
        case 1: // Rectangle
            r := new(Rectangle)
            f = r
            return f
        case 2: // Triangle
            t := new(Triangle)
            f = t
            return f
        default:
            panic(fmt.Sprintf("Incorrect figure key = %d", key))
    }
    return nil
}
