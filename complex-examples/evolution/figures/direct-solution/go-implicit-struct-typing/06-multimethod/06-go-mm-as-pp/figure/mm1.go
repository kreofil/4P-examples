package figure

import (
    "fmt"
    "os"

    "go-evolution/rectangle"
    "go-evolution/triangle"
)


//=================================================
// Реализация мультиметода прямой проверкой типов
func MM(outFile *os.File, f1 Figure, f2 Figure) {
    switch f1.(type) { // проверка типа первой фигуры
        case *rectangle.Rectangle:
            switch f2.(type) { // проверка типа второй фигуры
                case *rectangle.Rectangle:
                    fmt.Fprintln(outFile, "Rectangle & Rectangle")
                case *triangle.Triangle:
                    fmt.Fprintln(outFile, "Rectangle & Triangle")
                default: // тип первой фигуры некорректен
                    panic("First is Rectangle. Incorrect type of second figure")
        }
        case *triangle.Triangle:
            switch f2.(type) { // проверка типа второй фигуры
                case *rectangle.Rectangle:
                    fmt.Fprintln(outFile, "Triangle & Rectangle")
                case *triangle.Triangle:
                    fmt.Fprintln(outFile, "Triangle & Triangle")
                default: // тип первой фигуры некорректен
                    panic("First is Triangle. Incorrect type of second figure")
        }
        default: // тип первой фигуры некорректен
            panic("Incorrect type of first figure")
    }
    fmt.Fprintln(outFile, "    ", f1)
    fmt.Fprintln(outFile, "    ", f2)
}
