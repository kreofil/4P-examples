#! /usr/bin/python
# ./main.py input1.txt 0.txt
import sys
import string
import time

from extender import *

#----------------------------------------------
if __name__ == '__main__':
    if len(sys.argv) == 3:
        inputFileName  = sys.argv[1]
        outputFileName = sys.argv[2]
    elif len(sys.argv) == 2:
        inputFileName  = sys.argv[1]
        outputFileName = "output.txt"
    elif len(sys.argv) == 1:
        print("Incorrect command line! You must write: python main <inputFileName> [<outputFileName>]")
        exit()

    # Чтение исходного файла, содержащего данные, разделенные пробелами и переводами строки
    ifile = open(inputFileName)
    str = ifile.read()
    ifile.close()

    #print(str)
    #print("len(str) = ", len(str))

    # Формирование массива строк, содержащего чистые данные в виде массива строк символов.
    strArray = str.replace("\n", " ").split(" ")
    #print(strArray)
    #print("len(strArray) = ", len(strArray))
    #figNum = ReadArray(strArray)

    print('==> Start')

    container = Container()
    figNum = ReadStrArray(container, strArray)
    container.Print()

    ofile = open(outputFileName, 'w')
    container.Write(ofile)
    ofile.close()

    # Тестовый цикл, определяющий время вычисления метода для сравнения
    # с использованием утиной типизации в другой программе
    startTime = time.time()
    for i in range(1, 10000000):
        container.Perimeter()
    endTime = time.time()

    print('==> Finish')

    print('Delta time = ', endTime - startTime)
