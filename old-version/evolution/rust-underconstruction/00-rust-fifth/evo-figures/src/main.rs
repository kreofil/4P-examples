use std::env;
use std::fs;

pub use project::rectangle::Rectangle;
pub use project::rectangle_out::out as out2;
pub use project::rectangle_area::area;

pub mod project;

mod r_out {
  // Вывод параметров прямоугольника в форматируемый поток
  pub fn out(r: &super::Rectangle) {
    println!("It is Rectangle: x = {}, y = {}", r.x, r.y);
  }
}

fn new(args: &[String]) -> Config {
  if args.len() < 3 {
    panic!("not enough arguments");
  }
}

fn main() {
  let args: Vec<String> = env::args().collect();
  println!("{:?}", args);

  let in_file_name  = &args[1];
  let out_file_name = &args[2];
  println!("Input File Name: {in_file_name}");
  println!("Output File Name: {out_file_name}");

  let contents = fs::read_to_string(in_file_name)
      .expect("Should have been able to read the file");
  println!("With text:\n{contents}");

  let rect1 = Rectangle { x: 30, y: 50 };
  println!("It is Rectangle: x = {}, y = {}", rect1.x, rect1.y);

  rect1.out();
  out2(&rect1);
  out(&rect1);
  r_out::out(&rect1);
  out(&rect1);
  area(&rect1);
}

// Вывод параметров прямоугольника в форматируемый поток
pub fn out(r: &Rectangle) {
  println!("It is Rectangle: x = {}, y = {}", r.x, r.y);
}
