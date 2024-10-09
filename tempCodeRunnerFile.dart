class Book {
  String title;
  String author;
  int pages;

  Book(this.title, this.author, this.pages);

  @override
  String toString() {
    return 'Title: $title, Author: $author, Pages: $pages';
  }
}

class Library {
  List<Book> books = [];

 
  void addBook(Book book) {
    books.add(book);
    print("Added: ${book.title}");
  }


  void removeBook(String title) {
    books.removeWhere((book) {
      return book.title == title;
    } );
    print("Removed book with title: $title");
  }

 
  void displayBooks() {
    print("\nBooks in the Library:");
    if (books.isEmpty) {
      print("No books available");
    } else {
      books.forEach((book) => print(book));
    }
  }
}

void main() {
  Library myLibrary = Library();

  
  Book book1 = Book("The Catcher in the Rye", "J.D. Salinger", 277);
  Book book2 = Book("To Kill a Mockingbird", "Harper Lee", 324);
  Book book3 = Book("1984", "George Orwell", 328);


  myLibrary.addBook(book1);
  myLibrary.addBook(book2);
  myLibrary.addBook(book3);


  myLibrary.displayBooks();

 
  myLibrary.removeBook("1984");


  myLibrary.displayBooks();
}
