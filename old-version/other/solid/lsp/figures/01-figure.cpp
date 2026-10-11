#include <iostream>

struct Point {int x, y;};

struct Figure {
  enum FigureType {square, circle} itsType;
  Figure(FigureType t): itsType(t) {}
};

//------------------------------------------------------------------------------
struct Circle: public Figure {
  Circle(): Figure(circle) {};
  void Print() const;
  Point itsCenter;
  int itsRadius;
};

void Circle::Print() const {
  std::cout << "It is Circle. Center = ("
            << itsCenter.x << ", " << itsCenter.y << "). "
            <<  "Radius = " << itsRadius  << "\n";
}

//------------------------------------------------------------------------------
struct Square: public Figure {
  Square(): Figure(square) {};
  void Print() const;
  Point itsTopLeft;
  int itsSide;
};

void Square::Print() const {
  std::cout << "It is Square. Top left = ("
            << itsTopLeft.x << ", " << itsTopLeft.y << "). "
            <<  "Side = " << itsSide  << "\n";
}

//------------------------------------------------------------------------------
void PrintFigure(const Figure& f) {
  if(f.itsType == Figure::square) {
    static_cast<const Square&>(f).Print();
  } else if(f.itsType == Figure::circle) {
    static_cast<const Circle&>(f).Print();
  }
}

//------------------------------------------------------------------------------
int main() {
  Circle c;
  c.itsCenter.x = 0;
  c.itsCenter.y = 0;
  c.itsRadius = 5;
  Square s;
  s.itsTopLeft.x = -5;
  s.itsTopLeft.y = 5;
  s.itsSide = 10;

  Figure* fc = &c;
  PrintFigure(*fc);
  Figure* fs = &s;
  PrintFigure(*fs);

  return 0;
}
