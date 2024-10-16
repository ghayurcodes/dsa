

class Vehicle {
  String make;
  String model;
  int year;
  double mileage;

  Vehicle(this.make, this.model, this.year, this.mileage);

  void displayInfo() {
    print('Make: $make, Model: $model, Year: $year, Mileage: $mileage');
  }
}

class Car extends Vehicle {
  int seats;
  String fuelType;

  Car(String make, String model, int year, double mileage, this.seats, this.fuelType)
      : super(make, model, year, mileage);

  @override
  void displayInfo() {
    super.displayInfo();
    print('Seats: $seats, Fuel Type: $fuelType');
  }
}
