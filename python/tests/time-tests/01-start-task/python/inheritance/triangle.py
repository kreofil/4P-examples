from shape import *

#----------------------------------------------
class Triangle(Shape):
    def __init__(self):
        self.a = 0
        self.b = 0
        self.c = 0

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум три непрочитанных значения в массиве
        if i >= len(strArray) - 2:
            return 0
        self.a = int(strArray[i])
        self.b = int(strArray[i+1])
        self.c = int(strArray[i+2])
        i += 3
        #print("Triangle: a = ", self.a, " b = ", self.b, "c = ", self.c)
        return i

    def Print(self):
        print("Triangle: a = ", self.a, " b = ", self.b, "c = ", self.c, ", Perimeter = ", self.Perimeter())
        pass

    def Write(self, ostream):
        ostream.write("Triangle: a = {}  b = {}  c = {}, Perimeter = {}".format \
                     (self.a, self.b, self.c, self.Perimeter()))
        pass

    def Perimeter(self):
        return float(self.a + self.b + self.c)
        pass
