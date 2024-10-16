

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

class Motorcycle extends Vehicle {
  double engineCapacity;
  String type; // e.g., Cruiser, Sport

  Motorcycle(String make, String model, int year, double mileage, this.engineCapacity, this.type)
      : super(make, model, year, mileage);

  @override
  void displayInfo() {
    super.displayInfo();
    print('Engine Capacity: $engineCapacity cc, Type: $type');
  }
}



class Garage {
  List<Vehicle> vehicles = [];

  void addVehicle(Vehicle vehicle) {
    vehicles.add(vehicle);
    print('${vehicle.model} added to garage.');
  }

  void removeVehicle(String model) {
    vehicles.removeWhere((vehicle) => vehicle.model == model);
    print('$model removed from garage.');
  }

  void showAllVehicles() {
    print('Vehicles in the garage:');
    for (var vehicle in vehicles) {
      vehicle.displayInfo();
    }
  }
}



void main() {
  // Instantiate some Car and Motorcycle objects
  Car car1 = Car('Toyota', 'Corolla', 2020, 15000, 5, 'Petrol');
  Motorcycle moto1 = Motorcycle('Harley', 'Sportster', 2018, 8000, 1200, 'Cruiser');

  // Create Garage and add vehicles
  Garage garage = Garage();
  garage.addVehicle(car1);
  garage.addVehicle(moto1);

  // Show all vehicles in garage
  garage.showAllVehicles();

  // Remove a vehicle by model
  garage.removeVehicle('Corolla');

  // Show remaining vehicles
  garage.showAllVehicles();
}
