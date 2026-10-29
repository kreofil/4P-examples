//------------------------------------------------------------------------------
// figure.go - содержит описание фигуры как интерфейса

package figure

import (
    "os"
)

// фигура
type Figure interface {
    In(inFile *os.File) error
    Perimeter() float64
}
