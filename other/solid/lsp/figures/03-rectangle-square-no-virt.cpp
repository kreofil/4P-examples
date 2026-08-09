#include <iostream>

//------------------------------------------------------------------------------
class Rectangle {
public:
  void SetWidt(int w) {width = w;};
  int GetWidth() {return width;}
  void SetHeight(int h) {height = h;};
  int GetHeight() {return height;}
  int Area() {return width*height;}
protected:
  int width;
  int height;
};

//------------------------------------------------------------------------------
struct Square: public Rectangle {
  void SetWidt(int w) {
    Rectangle::SetWidt(w);
    Rectangle::SetHeight(w);
  };
  void SetHeight(int h) {
    Rectangle::SetHeight(h);
    Rectangle::SetWidt(h);
  }
};

//------------------------------------------------------------------------------
void f_val(Rectangle r) {
  r.SetWidt(32);
  std::cout << "f_val(Rectangle) = ("
            << r.GetWidth() << "," << r.GetHeight() << ")\n";
}

void f_ref(Rectangle& r) {
  r.SetWidt(32);
  std::cout << "f_ref(Rectangle&) ("
            << r.GetWidth() << "," << r.GetHeight() << ")\n";

}

void g_val(Rectangle r) {
  r.SetWidt(5);
  r.SetHeight(4);
  std::cout << "g_val(Rectangle) ("
            << r.GetWidth() << "," << r.GetHeight() << ")\n";
  std::cout << "Area = " << r.Area() << "\n";
}

void g_ref(Rectangle& r) {
  r.SetWidt(5);
  r.SetHeight(4);
  std::cout << "g_ref(Rectangle&) ("
            << r.GetWidth() << "," << r.GetHeight() << ")\n";
  std::cout << "Area = " << r.Area() << "\n";
}

//------------------------------------------------------------------------------
int main() {
  Square s;
  s.SetWidt(1);
  std::cout << "Square (" << s.GetWidth() << "," << s.GetHeight() << ")\n";
  s.SetHeight(2);
  std::cout << "Square (" << s.GetWidth() << "," << s.GetHeight() << ")\n";
  f_val(s);
  f_ref(s);
  g_val(s);
  g_ref(s);

  return 0;
}
