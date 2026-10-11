package figure

import (
    "fmt"
    "os"
)


//=================================================
// Диспетчеризация
//=================================================

//-------------------------------------------------
// Старт диспетчеризации, когда первый тип - прямоугольник
func (r1 *Rectangle)MM(outFile *os.File, f2 Figure) {
    f2.RectangleContinue(outFile, r1)
    fmt.Fprintln(outFile, "    ", r1)
    fmt.Fprintln(outFile, "    ", f2)
}

//-------------------------------------------------
// Старт диспетчеризации, когда первый тип - треугольник
func (t1 *Triangle) MM(outFile *os.File, f2 Figure) {
    f2.TriangleContinue(outFile, t1)
    fmt.Fprintln(outFile, "    ", t1)
    fmt.Fprintln(outFile, "    ", f2)
}

//=================================================
// Продолжение диспетчеризации
//=================================================

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника
// идет прямоугольник
func (r2 *Rectangle) RectangleContinue(outFile *os.File, r1 *Rectangle) {
    RR(outFile, r1, r2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника
// идет треугольник
func (c2 *Triangle) RectangleContinue(outFile *os.File, r1 *Rectangle) {
    RT(outFile, r1, c2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после треугольника
// идет прямоугольник
func (r2 *Rectangle) TriangleContinue(outFile *os.File, t1 *Triangle) {
    TR(outFile, t1, r2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после треугольника
// идет треугольник
func (c2 *Triangle) TriangleContinue(outFile *os.File, t1 *Triangle) {
    TT(outFile, t1, c2)
}

//=================================================
// Обработчики специализаций

//-------------------------------------------------
// Rectangle & Rectangle
func RR(outFile *os.File, r1, r2 *Rectangle) {
    fmt.Fprintln(outFile, "Rectangle & Rectangle")
}

//-------------------------------------------------
// Rectangle & Triangle
func RT(outFile *os.File, r1 *Rectangle, c2 *Triangle) {
    fmt.Fprintln(outFile, "Rectangle & Triangle")
}

//-------------------------------------------------
// Triangle & Rectangle
func TR(outFile *os.File, t1 *Triangle, r2 *Rectangle) {
    fmt.Fprintln(outFile, "Triangle & Rectangle")
}

//-------------------------------------------------
// Triangle & Triangle
func TT(outFile *os.File, t1, c2 *Triangle,) {
    fmt.Fprintln(outFile, "Triangle & Triangle")
}
