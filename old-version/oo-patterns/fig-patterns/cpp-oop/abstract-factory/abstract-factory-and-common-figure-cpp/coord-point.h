#ifndef __coord_point__
#define __coord_point__

//==============================================================================
// coord-point.h - описание точки, задающей одну координату
//==============================================================================

#include <fstream>

//------------------------------------------------------------------------------
// точка
class Point {
  double x, y; // точка
public:
  double getX() {return x;}
  double getY() {return y;}
  void   setX(double _x) {x = _x;}
  void   setY(double _y) {y = _y;}
  void   In(std::ifstream &ifst) {
    ifst >> x >> y;
  }
  void   Out(std::ofstream &ofst) {
    ofst << "(" << x << "," << y << ")";
  }
};

#endif // __coord_point__
