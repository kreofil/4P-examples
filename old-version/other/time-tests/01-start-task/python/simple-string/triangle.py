#----------------------------------------------
def Read(trian, strArray, i):
    # должно быть как минимум три непрочитанных значения в массиве
    if i >= len(strArray) - 2:
        return 0
    trian.append("triangle")
    trian.append(int(strArray[i]))
    trian.append(int(strArray[i+1]))
    trian.append(int(strArray[i+2]))
    i += 3
    #print("Triangle: a = ", trian[1], " b = ", trian[2], "c = ", trian[3])
    return i

def Print(trian):
    print("Triangle: a = ", trian[1], " b = ", trian[2], "c = ", trian[3], ", Perimeter = ", Perimeter(trian))
    pass

def Write(trian, ostream):
    ostream.write("Triangle: a = {}  b = {}  c = {}, Perimeter = {}".format \
                 (trian[1], trian[2], trian[3], Perimeter(trian)))
    pass

def Perimeter(trian):
    return float(trian[1] + trian[2] + trian[3])
    pass
