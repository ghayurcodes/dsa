class User {
  String _name;
  String _email;
  String _password;

  User(this._name, this._email, this._password);

  String get name => _name;
  set name(String name) => _name = name;

  String get email => _email;
  set email(String email) => _email = email;

  String get password => _password;
  set password(String password) => _password = password;

  void displayInfo() {
    print('Name: $_name, Email: $_email');
  }
}


class AdminUser extends User {
  AdminUser(String name, String email, String password) : super(name, email, password);

  void manageSystem() {
    print('Admin privileges granted.');
  }

  @override
  void displayInfo() {
    super.displayInfo();
    print('User Role: Admin');
  }
}


class RegularUser extends User {
  RegularUser(String name, String email, String password) : super(name, email, password);

  void browseContent() {
    print('Browsing as a regular user.');
  }

  @override
  void displayInfo() {
    super.displayInfo();
    print('User Role: Regular');
  }
}


void main() {
 
  AdminUser admin = AdminUser('Admin', 'admin@gmal.com', '000');
  RegularUser regularUser = RegularUser('employe', 'emp@gmail.com', '111');

 
  admin.displayInfo();
  regularUser.displayInfo();

 
  admin.manageSystem();

 
  regularUser.browseContent();
}
