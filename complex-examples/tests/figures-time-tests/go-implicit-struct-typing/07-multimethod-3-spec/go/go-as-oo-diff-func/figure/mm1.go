package figure

import (
    "fmt"
    "os"
)


//=================================================
// Диспетчеризация

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

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника
// идет прямоугольник
func (r2 *Rectangle) RectangleContinue(outFile *os.File, r1 *Rectangle) {
    RR(outFile, r1, r2)
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника
// идет треугольник
func (t2 *Triangle) RectangleContinue(outFile *os.File, r1 *Rectangle) {
    RT(outFile, r1, t2)
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
func (t2 *Triangle) TriangleContinue(outFile *os.File, t1 *Triangle) {
    TT(outFile, t1, t2)
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
func RT(outFile *os.File, r1 *Rectangle, t2 *Triangle) {
    fmt.Fprintln(outFile, "Rectangle & Triangle")
}

//-------------------------------------------------
// Triangle & Rectangle
func TR(outFile *os.File, t1 *Triangle, r2 *Rectangle) {
    fmt.Fprintln(outFile, "Triangle & Rectangle")
}

//-------------------------------------------------
// Triangle & Triangle
func TT(outFile *os.File, t1, t2 *Triangle) {
    fmt.Fprintln(outFile, "Triangle & Triangle")
}

//=================================================
// Диспетчеризация для разных функций

// Старт диспетчеризации периметров, когда первый тип - прямоугольник
func (r1 *Rectangle)MMP(f2 Figure) int {
  return f2.RectangleContinueDiffFunc(r1)
}

//-------------------------------------------------
// Старт диспетчеризации, когда первый тип - треугольник
func (t1 *Triangle) MMP(f2 Figure) int {
  return f2.TriangleContinueDiffFunc(t1)
}

//=================================================
// Продолжение диспетчеризации

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника
// идет прямоугольник
func (r2 *Rectangle) RectangleContinueDiffFunc(r1 *Rectangle) int {
  // Возвращает сумму площадей двух прямоугольников
  return (r1.x * r1.y) + (r2.x * r2.y);
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после прямоугольника идет треугольник
func (t2 *Triangle) RectangleContinueDiffFunc(r1 *Rectangle) int {
  // Возвращает общую сумму сторон прямоугольника и треугольника
  return r1.x + r1.y + t2.a + t2.b + t2.c;
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после треугольника
// идет прямоугольник
func (r2 *Rectangle) TriangleContinueDiffFunc(t1 *Triangle) int {
  // Возвращает разность между суммами сторон прямоугольника и треугольника
  return (t1.a + t1.b + t1.c) - (r2.x + r2.y);
}

//-------------------------------------------------
// Продолжение диспетчеризации, когда после треугольника
// идет треугольник
func (t2 *Triangle) TriangleContinueDiffFunc(t1 *Triangle) int {
  // Возвращает произведение сумм сторон двух треугольников
  return (t1.a + t1.b + t1.c) * (t2.a + t2.b + t2.c);
}
