#----------------------------------------------
from extender import *

def Read(cont, strArray):
    arrayLen = len(strArray)
    i = 0   # Индекс, задающий текущую строку в массиве
    figNum = 0  # Счетчик фигур
    while i < arrayLen:
        str = strArray[i]
        key = int(str)   # преобразование в целое
        #print("key = ", key)    # тестовый вывод ключа фигуры
        if key == 1: # признак прямоугольника
            i += 1
            rect = []   # прямоугольник - это список с признаком и значениями
            i = rectangle.Read(rect, strArray, i)   # Заполнение фигуры значением и получение следующей позиции
            cont.append(rect)      # прямоугольник поступает в контейнер
        elif key == 2: # признак треугольника
            i += 1
            trian = []   # треугольник - это список с признаком и значениями
            i = triangle.Read(trian, strArray, i)   # Заполнение фигуры значением и получение следующей позиции
            cont.append(trian)      # треугольник поступает в контейнер
        else:
            # что-то пошло не так. Должен быть известный признак
            # Возврат количества прочитанных фигур
            return figNum
        # Количество фигур увеличивается на 1
        if i == 0:
            return figNum
        figNum += 1
    return figNum

def Print(cont):
    print("Container stores", len(cont), "shapes:")
    for shape in cont:
        if shape[0] == "rectangle":
            rectangle.Print(shape)
        elif shape[0] == "triangle":
            triangle.Print(shape)
        else:
            print("Incorrect figure ", shape)
    print("Summa of Perimeters  = ", Perimeter(cont))
    pass

def Write(cont, ostream):
    ostream.write("Container stores {} shapes:\n".format(len(cont)))
    for shape in cont:
        if shape[0] == "rectangle":
            rectangle.Write(shape, ostream)
        elif shape[0] == "triangle":
            triangle.Write(shape, ostream)
        else:
            ostream.write("Incorrect figure ")
            ostream.write(shape)
        ostream.write("\n")
    ostream.write("Summa of Perimeters  = {}\n".format(Perimeter(cont)))
    pass

def Perimeter(cont):
    perim = 0.0
    for shape in cont:
        if shape[0] == "rectangle":
            perim += rectangle.Perimeter(shape)
        elif shape[0] == "triangle":
            perim += triangle.Perimeter(shape)
        else:
            perim += 0.0
    return perim
