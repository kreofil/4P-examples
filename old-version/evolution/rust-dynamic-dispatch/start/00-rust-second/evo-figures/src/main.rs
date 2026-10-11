// mod rectangle;
// use rectangle::out;

pub mod rectangle_out;
pub mod rectangle_area;

pub use rectangle_out::rectangle::Rectangle;
pub use rectangle_out::out as out2;
pub use rectangle_area::area;

mod r_out {
  // Вывод параметров прямоугольника в форматируемый поток
  pub fn out(r: &super::rectangle_out::rectangle::Rectangle) {
    println!("It is Rectangle: x = {}, y = {}", r.x, r.y);
  }
}

fn main() {
    let rect1 = Rectangle { x: 30, y: 50 };

    println!("It is Rectangle: x = {}, y = {}", rect1.x, rect1.y);
    rect1.out();
    out2(&rect1);
    out(&rect1);
    r_out::out(&rect1);
    rectangle_out::rectangle::out(&rect1);
    area(&rect1);
}

// Вывод параметров прямоугольника в форматируемый поток
pub fn out(r: &Rectangle) {
  println!("It is Rectangle: x = {}, y = {}", r.x, r.y);
}
