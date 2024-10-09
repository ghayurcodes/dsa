import 'dart:io';

void main() {
  List list = List.filled(3, 0);

  list[0] = 2;
  list[1] = 4;
  list[2] = 7;

  List list_expanded = [3, 5, 7];

  print(list_expanded);
  list_expanded.add(34);
  list_expanded.insert(1, 1);
  print('after');
  print(list_expanded);


}
