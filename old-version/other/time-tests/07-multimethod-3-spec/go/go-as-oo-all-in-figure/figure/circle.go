//------------------------------------------------------------------------------
// circle.go - содержит описание окружности

package figure

import (
    "fmt"
    "os"
        "strconv"
)

// прямоугольник
type Circle struct {
    r int // радиус
}

// Ввод параметров окружности из файла
func (c *Circle)In(inFile *os.File) error  {
    var err error
    _, err = fmt.Fscan(inFile, &c.r)
    return err
}

// Формирование параметров для вывода окружности в строке
func (c *Circle)String() string {
    str := "It is Circle: r = " + strconv.Itoa(c.r) //+ "\n"
    return str
}
