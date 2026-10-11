//------------------------------------------------------------------------------
// onlyrects.go - вывод из контейнера только прямоугольников

package container

import (
    "fmt"
//    "io"
    "os"
    "strconv"

    "go-evolution/figure"
)

// Вывод содержимого контейнера в указанный поток
// С использованием интерфейсов, размещенных в пакете fmt
func (c *Container )OutRects(outFile *os.File) {
    str := "Out only Rectangles:"
    fmt.Fprintln(outFile, str)
    count := 0
    for i := 0; i < c.length; i++ {
        v := c.storage[i]
        if figure.IsRect(v) != nil {
            elem := strconv.Itoa(i+1) + ": "
            fmt.Fprint(outFile, elem)
            fmt.Fprint(outFile, v)
            count++
            fmt.Fprintln(outFile)
        }
    }
    fmt.Fprintln(outFile, "There are only ", count, "Rectangles in Contaner")
}
