//------------------------------------------------------------------------------
// main.go - содержит главную функцию,
// обеспечивающую простое тестирование путем имитации клиента
//------------------------------------------------------------------------------

package main

import "os"
import "fmt"
import "log"
import "path/filepath"

import "go-evolution/container"

//------------------------------------------------------------------------------
func main() {
    var err error
    // Выделение входного и выходного файлов из командной строки
    inFilename, outFilename, err := filenamesFromCommandLine()

    if err != nil {
        fmt.Println(err)
        os.Exit(1)
    }

    //! Тестовый вывод имен входного и выходного файлов
    fmt.Println("inFilename = ", inFilename)
    fmt.Println("outFilename = ", outFilename)

    inFile, outFile := os.Stdin, os.Stdout
    if inFilename != "" {
        if inFile, err = os.Open(inFilename); err != nil {
            log.Fatal(err)
        }
        defer inFile.Close()
    }
    if outFilename != "" {
        if outFile, err = os.Create(outFilename); err != nil {
            log.Fatal(err)
        }
        defer outFile.Close()
    }


    fmt.Println("Start")

    var c container.Container
    c.Init()
    c.In(inFile)

    fmt.Println("Filled container. ")
    c.Out(os.Stdout)
    c.Out(outFile)

    c.Perimeter(os.Stdout)
    c.Perimeter(outFile)


    c.Clear();
    fmt.Println("Empty container. ")
    c.Out(os.Stdout)
    c.Out(outFile)

    fmt.Println("Stop")
}

//-----------------------------------------------------------------------------
// Обработка данных из командной строки
func filenamesFromCommandLine() (inFilename, outFilename string, err error) {
    if len(os.Args) > 1 && (os.Args[1] == "-h" || os.Args[1] == "--help") {
        err = fmt.Errorf("usage: %s [<]infile.txt [>]outfile.txt",
            filepath.Base(os.Args[0]))
        return "", "", err
    }
    if len(os.Args) > 1 {
        inFilename = os.Args[1]
        if len(os.Args) > 2 {
            outFilename = os.Args[2]
        }
    }
    if inFilename != "" && inFilename == outFilename {
        log.Fatal("won't overwrite the infile")
    }
    return inFilename, outFilename, nil
}
