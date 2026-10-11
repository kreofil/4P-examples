//------------------------------------------------------------------------------
// newfig.go - содержит описание вывода только прямоугольника

package figure

import (
    "fmt"
    "os"

    "go-evolution/rectangle"
    //"../triangle"
)

// Функция, осуществляющая выделение только прямоугольника
func IsRect(f Figure) *rectangle.Rectangle {
    switch f.(type) {
        case *rectangle.Rectangle:
            return f.(*rectangle.Rectangle)
    }
    return nil
}

// Вывод только прямоугольника
func OutRectOnly(outFile *os.File, f *Figure) {
    if IsRect(*f) != nil {
        fmt.Fprint(outFile, f)
    }
}
