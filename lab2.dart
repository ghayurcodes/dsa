import 'dart:io';

// void main() {
//   stdout.write("Enter a number");
//   int num = int.parse(stdin.readLineSync()!);
//   for (var i = 1; i <= num; i++) {
//     if (num % i == 0) {
//       print(i);
//     }
//   }
// }



void main() {
  print(factorial(6));
}

int factorial(int number) {
  if (number <= 0) {
    // termination case
    return 1;
  } else {
    return (number * factorial(number - 1));
    // function invokes itself
  }
}
