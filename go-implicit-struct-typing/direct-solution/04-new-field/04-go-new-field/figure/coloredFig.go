//------------------------------------------------------------------------------
// coloredFig.go - содержит описание фигуры с добавленным цветом 
// и соответствующий набор функций для решения целевой задачи


package figure

import (
    "os"
    "fmt"
)

const (
    black = iota
    white
    green
    red
    blue
    cyan
    yellow
    orange
    grey
    violet
)

// Фигура с описанием цвета
type ColoredFigure struct {
    Figure      // интерфейс для ипользования ранее созданных фигур.
    Color   int // Цвет фигуры
}

func ColorAsStr(value int) string {
    str := "Incorrect"
    switch value {
        case black:
            str = "Black"
        case white:
            str = "White"
        case green:
            str = "Green"
        case red:
            str = "Red"
        case blue:
            str = "Blue"
        case cyan:
            str = "Cyan"
        case yellow:
            str = "Yellow"
        case orange:
            str = "Orange"
        case grey:
            str = "Grey"
        case violet:
            str = "Violet"
    }
    return str
}

// Ввод параметров цветной фигуры из файла
func (cf *ColoredFigure)In(inFile *os.File) error  {
    var err error
    err = cf.Figure.In(inFile)
    _, err = fmt.Fscan(inFile, &cf.Color)
    ///fmt.Println("Color = ", cf.Color)
    return err
}

// Вывод параметров цветной фигуры в строку
func (cf *ColoredFigure)Out(outFile *os.File) {
    fmt.Fprint(outFile, cf.Figure)
    fmt.Fprintln(outFile, ".     Color is " + ColorAsStr(cf.Color))
}
