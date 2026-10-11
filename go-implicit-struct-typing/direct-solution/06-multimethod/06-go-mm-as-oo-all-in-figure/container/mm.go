package container

import (
    "fmt"
    "os"

    //"../figure"
)


//=================================================
// Реализация мультиметода прямой проверкой типов
func (c *Container)MM(outFile *os.File) {
    for i := 0; i < c.length; i++ {
        v1 := c.storage[i]
        for j := 0; j < c.length; j++ {
            v2 := c.storage[j]
            fmt.Fprint(outFile, "[", i+1, ",", j+1, "]: ")
            v1.MM(outFile, v2)
        }
    }
}
