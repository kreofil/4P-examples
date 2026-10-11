package figure

import (
    "fmt"
    "os"
)


//=================================================
// Диспетчеризация. Расширение за счет появления окружности
//=================================================

//-------------------------------------------------
// Старт диспетчеризации, когда первый тип - окружность
func (c1 *Circle)MM(outFile *os.File, f2 Figure) {
    f2.CircleContinue(outFile, c1)
    fmt.Fprintln(outFile, "    ", c1)
    fmt.Fprintln(outFile, "    ", f2)
}

//=================================================
// Продолжение диспетчеризации
//=================================================

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника
// идет окружность
func (с2 *Circle) RectangleContinue(outFile *os.File, r1 *Rectangle) {
    RC(outFile, r1, с2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после треугольника
// идет окружность
func (c2 *Circle) TriangleContinue(outFile *os.File, t1 *Triangle) {
    TC(outFile, t1, c2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после окружности
// идет прямоугольник
func (r2 *Rectangle) CircleContinue(outFile *os.File, c1 *Circle) {
    CR(outFile, c1, r2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после окружности
// идет треугольник
func (t2 *Triangle) CircleContinue(outFile *os.File, c1 *Circle) {
    CT(outFile, c1, t2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после окружности
// идет окружность
func (c2 *Circle) CircleContinue(outFile *os.File, c1 *Circle) {
    CC(outFile, c1, c2)
}

//=================================================
// Обработчики специализаций

//-------------------------------------------------
// Rectangle & Circle
func RC(outFile *os.File, r1 *Rectangle, c2 *Circle) {
    fmt.Fprintln(outFile, "Rectangle & Circle")
}

//-------------------------------------------------
// Triangle & Circle
func TC(outFile *os.File, t1 *Triangle, c2 *Circle) {
    fmt.Fprintln(outFile, "Triangle & Circle")
}

//-------------------------------------------------
// Circle & Rectangle
func CR(outFile *os.File, c1 *Circle, r2 *Rectangle) {
    fmt.Fprintln(outFile, "Circle & Rectangle")
}

//-------------------------------------------------
// Circle & Triangle
func CT(outFile *os.File, c1 *Circle, t2 *Triangle) {
    fmt.Fprintln(outFile, "Circle & Triangle")
}

//-------------------------------------------------
// Circle & Circle
func CC(outFile *os.File, c1, c2 *Circle) {
    fmt.Fprintln(outFile, "Circle & Circle")
}
