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
  // Create Admin and Regular users
  AdminUser admin = AdminUser('Admin', 'admin@example.com', 'adminPass');
  RegularUser regularUser = RegularUser('John Doe', 'john@example.com', 'userPass');

  // Display user info
  admin.displayInfo();
  regularUser.displayInfo();

  // Admin performs management actions
  admin.manageSystem();

  // Regular user browses content
  regularUser.browseContent();
}
