import 'dart:io';

void main() {
  List list = List.filled(3, 0);

  list[0] = 2;
  list[1] = 4;
  list[2] = 7;
  

  print(list);
  list.add(34);
  print('after');
  print(list);
}
