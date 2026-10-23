//------------------------------------------------------------------------------
// rectangle.go - содержит описание прямоугольника

package rectangle

import (
    "fmt"
    "os"
    "strconv"
)

// прямоугольник
type Rectangle struct {
    x int // ширина
    y int // высота
}

// Ввод параметров прямоугольника из файла
func (r *Rectangle)In(inFile *os.File) error  {
    var err error
    _, err = fmt.Fscan(inFile, &r.x)
    _, err = fmt.Fscan(inFile, &r.y)
    return err
}

// Формирование параметров для вывода прямоугольника в строке
func (r *Rectangle)String() string {
    str := "It is Rectangle: x = " + strconv.Itoa(r.x) + ", y = " + strconv.Itoa(r.y) //+ "\n"
    return str
}
