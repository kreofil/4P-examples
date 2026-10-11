from shape import *

#----------------------------------------------
class Rectangle(Shape):
    def __init__(self):
        self.x = 0
        self.y = 0

    def ReadStrArray(self, strArray, i):
        # должно быт как минимум два непрочитанных значения в массиве
        if i >= len(strArray) - 1:
            return 0
        self.x = int(strArray[i])
        self.y = int(strArray[i+1])
        i += 2
        #print("Rectangle: x = ", self.x, " y = ", self.y)
        return i

    def Print(self):
        print("Rectangle: x = ", self.x, " y = ", self.y, ", Perimeter = ", self.Perimeter())
        pass

    def Write(self, ostream):
        ostream.write("Rectangle: x = {}  y = {}, Perimeter = {}".format(self.x, self.y, self.Perimeter()))
        pass

    def Perimeter(self):
        return 2.0 * (self.x + self.y)
        pass
