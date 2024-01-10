#include <iostream>
#include <cstring>

void printBook(const struct Books& book);

struct Books {
  char  title[50];
  char  author[50];
  char  subject[100];
  int   book_id;
};

int main() {
   Books Book1;          

  // Book 1 specification
  strcpy_s(Book1.title, "intro C++ Programming");
  strcpy_s(Book1.author, "Author1");
  strcpy_s(Book1.subject, "C++ Programming");
  Book1.book_id = 6453407;
 
  Books Book2;   
  // Book 2 specification
  strcpy_s(Book2.title, "23 things they dont tell youabout capitalism");
  strcpy_s(Book2.author, "Ha-Joon CHANG");
  strcpy_s(Book2.subject, "Economics");
  Book2.book_id = 6435000;

  // Print Book1 info 
  printBook(Book1);

  // Print Book1 info 
  printBook(Book2);

  return 0;
}

// This function accepts a const ref to a book structure.
void printBook(const struct Books & book) {
  std::cout << "title : " << book.title << std::endl;
  std::cout << "author : " << book.author << std::endl;
  std::cout << "subject : " << book.subject << std::endl;
  std::cout << "id : " << book.book_id << std::endl;
}