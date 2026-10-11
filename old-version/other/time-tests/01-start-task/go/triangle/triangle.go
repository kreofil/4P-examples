//------------------------------------------------------------------------------
// triangle.go - содержит описание треугольника

package triangle

import (
    "fmt"
    "os"
    "strconv"
)

// треугольник
type Triangle struct {
    // стороны
    a int
    b int
    c int
}

// Ввод параметров треугольника из файла
func (t *Triangle)In(inFile *os.File) error {
    var err error
    _, err = fmt.Fscan(inFile, &t.a)
    _, err = fmt.Fscan(inFile, &t.b)
    _, err = fmt.Fscan(inFile, &t.c)
    return err
}

// Формирование параметров для вывода треугольника в строке
func (t *Triangle)String() string {
    str := "It is Triangle: a = " + strconv.Itoa(t.a) + 
            ", b = " + strconv.Itoa(t.b) + ", c = " + strconv.Itoa(t.c) //+ "\n"
    return str
}
