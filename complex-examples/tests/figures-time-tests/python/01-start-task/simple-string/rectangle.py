#----------------------------------------------
def Read(rect, strArray, i):
    # должно быть как минимум два непрочитанных значения в массиве
    if i >= len(strArray) - 1:
        return 0
    rect.append("rectangle")
    rect.append(int(strArray[i]))
    rect.append(int(strArray[i+1]))
    i += 2
    #print("Rectangle: x = ", rect[1], " y = ", rect[2])
    return i

def Print(rect):
    print("Rectangle: x = ", rect[1], " y = ", rect[2], ", Perimeter = ", Perimeter(rect))
    pass

def Write(rect, ostream):
    ostream.write("Rectangle: x = {}  y = {}, Perimeter = {}".format(rect[1], rect[2], Perimeter(rect)))
    pass

def Perimeter(rect):
    return 2.0 * (rect[1] + rect[2])
    pass
