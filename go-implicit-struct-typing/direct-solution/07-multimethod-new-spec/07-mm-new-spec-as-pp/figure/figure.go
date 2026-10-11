//------------------------------------------------------------------------------
// figure.go - содержит описание фигуры как интерфейса

package figure

import (
    "os"
)

// фигура
type Figure interface {
    In(*os.File) error
}
