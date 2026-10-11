#----------------------------------------------
class Container:
    def __init__(self):
        self.store = []

    #def ReadStrArray(self, strArray):

    def Print(self):
        print("Container is store", len(self.store), "shapes:")
        for shape in self.store:
            shape.Print()
        print("Summa of Perimeters  = ", self.Perimeter())
        pass

    def Write(self, ostream):
        ostream.write("Container is store {} shapes:\n".format(len(self.store)))
        for shape in self.store:
            shape.Write(ostream)
            ostream.write("\n")
        ostream.write("Summa of Perimeters  = {}\n".format(self.Perimeter()))
        pass

    def Perimeter(self):
        perim = 0.0
        for shape in self.store:
            perim += shape.Perimeter()
        return perim
