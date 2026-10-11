//------------------------------------------------------------------------------
// perimeterCont.go - содержит тестовый вывод для функции 
// вычисления периметров фигур, расположенных в контейнере

package container

import (
    "fmt"
    //"io"
    "os"
    "strconv"

    //"../figure"
)

// Вывод содержимого контейнера в указанный поток
// С использованием интерфейсов, размещенных в пакете fmt
func (c *Container )Perimeter(outFile *os.File) {
    //var fp FigurePerimeter
    fmt.Fprintln(outFile, "List of Perimeters:")
    for i := 0; i < c.length; i++ {
        elem := strconv.Itoa(i+1) + ": "
        fmt.Fprint(outFile, elem)
        v := c.storage[i]
        //fp = &v
        p := v.Perimeter()
        fmt.Fprintln(outFile, p)
    }
}

//------------------------------------------------------------------------------
// Сумма всех периметров в контейнере
func (c *Container )OnlyPerimeter() float64 {
  // var p float64
  p := 0.0
  for i := 0; i < c.length; i++ {
    v := c.storage[i]
    p = p + v.Perimeter()
  }
  return p;
}
