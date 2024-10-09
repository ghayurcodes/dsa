class Shape {
  double area() {
    return 0;
  }

  void displayInfo() {
    print("This is a shape");
  }
}

class Circle extends Shape {
  double radius;

  Circle(this.radius);

  @override
  double area() {
    return 3.14 * radius * radius;
  }

  @override
  void displayInfo() {
    print("This is a circle with radius $radius");
  }
}

class Rectangle extends Shape {
  double length, width;

  Rectangle(this.length, this.width);

  
  double area() {
    return length * width;
  }

  
  void displayInfo() {
    print("This is a rectangle with length $length and width $width");
  }
}

void main() {
  Shape shape1 = Circle(5);
  Shape shape2 = Rectangle(4, 6);
  


  shape1.displayInfo();
  print("Area: ${shape1.area()}");

  shape2.displayInfo();
  print("Area: ${shape2.area()}");
}
