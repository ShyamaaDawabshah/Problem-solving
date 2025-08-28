#include <iostream>
#include <vector>
#include <string>
using namespace std;

// =======================
// Class Book
// =======================
class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    string getTitle() { return title; }
    string getAuthor() { return author; }
    int getYear() { return year; }

    void displayBook() {
        cout << " Title: " << title
             << "  Author: " << author
             << "  Year: " << year << endl;
    }
};

// =======================
// Class Library
// =======================
class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, int year) {
        Book newBook(title, author, year);
        books.push_back(newBook);
        cout << " Book added successfully!\n";
    }

    void showBooks() {
        if (books.empty()) {
            cout << " No books in the library.\n";
            return;
        }
        cout << "\n Books in Library:\n";
        for (int i = 0; i < books.size(); i++) {
            cout << i + 1 << ". ";
            books[i].displayBook();
        }
    }

    void searchBook(string title) {
        bool found = false;
        for (auto &book : books) {
            if (book.getTitle() == title) {
                cout << "Found Book: ";
                book.displayBook();
                found = true;
                break;
            }
        }
        if (!found) cout << "Book not found!\n";
    }

    void removeBook(string title) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getTitle() == title) {
                books.erase(books.begin() + i);
                cout << "Book removed successfully!\n";
                return;
            }
        }
        cout << "Book not found!\n";
    }
};

// =======================
// Main Function
// =======================
int main() {
    Library lib;
    int choice;
    string title, author;
    int year;

    do {
        cout << "\n====== Library Menu ======\n";
        cout << "1. Add Book\n";
        cout << "2. Show All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Remove Book\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // clear buffer

        switch (choice) {
        case 1:
            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter year: ";
            cin >> year;
            lib.addBook(title, author, year);
            break;
        case 2:
            lib.showBooks();
            break;
        case 3:
            cout << "Enter title to search: ";
            getline(cin, title);
            lib.searchBook(title);
            break;
        case 4:
            cout << "Enter title to remove: ";
            getline(cin, title);
            lib.removeBook(title);
            break;
        case 5:
            cout << " Exiting program...\n";
            break;
        default:
            cout << " Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
