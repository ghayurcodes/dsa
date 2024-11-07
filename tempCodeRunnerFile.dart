import 'dart:io';

class shape {
  void area() {
    //overrided in child classes
  }
}

class circle extends shape {
  int r = 0;
  double pi = 3.14;
  var ans;

  circle(int radi) {
    this.r = radi;
  }
  void area() {
    ans = (r * r) * pi;
    print("Area of circle is: $ans");
  }
}

class square extends shape {
  var length;
  var ans;

  square(var len) {
    this.length = len;
  }

  void area() {
    ans = length * length;
    print("Area of square is: $ans");
  }
}

void main() {
  circle c = circle(3); //radius taken 3
  square s = square(5); //radius taken 5
  c.area();
  s.area();
}
