//------------------------------------------------------------------------------
// rectangle.go - содержит описание прямоугольника

package container

import (
    "fmt"
    "io"
    "os"
    "strconv"

    "go-evolution/figure"
)

//------------------------------------------------------------------------------
// Простейший контейнер на основе одномерного массива
//------------------------------------------------------------------------------
type Container struct {
    length int
    storage [100]figure.ColoredFigure
}


// Инициализация контейнера
func (c *Container )Init() {
    c.length = 0
}

// Очистка контейнера от элементов (освобождение памяти)
func (c *Container )Clear() {
    c.length = 0
}

// Ввод содержимого контейнера из указанного потока
func (c *Container )In(inFile *os.File) {
    var err error
    for err != io.EOF {
        var key int
        _, err = fmt.Fscan(inFile, &key)
        if err != nil {
            if err == io.EOF {
                return
            }
            fmt.Println(err)
            panic(fmt.Sprintf("Incorrect key =", key))
        }
        f := figure.NewFigure(key)
        err = f.In(inFile)
        c.storage[c.length] = *f
        c.length++
        //f.Out(os.Stdout)
    }
}

// Вывод содержимого контейнера в указанный поток
// С использованием интерфейсов, размещенных в пакете fmt
func (c *Container )Out(outFile *os.File) {
    str := "Container contains " + strconv.Itoa(c.length) + " elements"
    fmt.Fprintln(outFile, str)
    for i := 0; i < c.length; i++ {
        elem := strconv.Itoa(i+1) + ": "
        fmt.Fprint(outFile, elem)
        v := c.storage[i]
        v.Out(outFile)
    }
}
