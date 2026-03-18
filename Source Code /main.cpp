#include <iostream>
#include <limits>
#include <vector>
#include "Book.hpp"
#include "FileManager.hpp"
#include "DatabaseManager.hpp"
#include "BookService.hpp"

using namespace std;

void showMenu() {
    cout << "\n========== Library Book Management System ==========\n";
    cout << "1. Add Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Search Book by ID\n";
    cout << "4. Update Book\n";
    cout << "5. Delete Book\n";
    cout << "6. Sort Books by Title\n";
    cout << "7. Sort Books by Publication Year\n";
    cout << "8. Export Books to CSV\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

Book editBook(const Book& oldBook) {
    string title, author, genre, publisher, language;
    int publicationYear, quantity, pages, ageSuitability;

    cout << "\nCurrent record:\n";
    cout << "--------------------------\n";
    oldBook.display();

    cout << "\nEnter new Title: ";
    getline(cin, title);

    cout << "Enter new Author: ";
    getline(cin, author);

    cout << "Enter new Genre: ";
    getline(cin, genre);

    cout << "Enter new Publication Year: ";
    cin >> publicationYear;

    cout << "Enter new Quantity: ";
    cin >> quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter new Publisher: ";
    getline(cin, publisher);

    cout << "Enter new Language: ";
    getline(cin, language);

    cout << "Enter new Pages: ";
    cin >> pages;

    cout << "Enter new Age Suitability: ";
    cin >> ageSuitability;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Book(
        oldBook.getBookId(),
        title,
        author,
        genre,
        publicationYear,
        quantity,
        publisher,
        language,
        pages,
        ageSuitability
    );
}

Book inputBook() {
    int bookId, publicationYear, quantity, pages, ageSuitability;
    string title, author, genre, publisher, language;

    cout << "Enter Book ID: ";
    cin >> bookId;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Title: ";
    getline(cin, title);

    cout << "Enter Author: ";
    getline(cin, author);

    cout << "Enter Genre: ";
    getline(cin, genre);

    cout << "Enter Publication Year: ";
    cin >> publicationYear;

    cout << "Enter Quantity: ";
    cin >> quantity;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Publisher: ";
    getline(cin, publisher);

    cout << "Enter Language: ";
    getline(cin, language);

    cout << "Enter Pages: ";
    cin >> pages;

    cout << "Enter Age Suitability: ";
    cin >> ageSuitability;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    return Book(bookId, title, author, genre, publicationYear, quantity,
                publisher, language, pages, ageSuitability);
}

int main() {
    int choice;

    FileManager fileManager("/Users/lampis/Documents/GitHub/Record-Management-System/books.txt");
    DatabaseManager dbManager;
    BookService bookService(fileManager, dbManager);

    if (!dbManager.connectDB()) {
        cout << "Warning: Program continues, but database is not connected.\n";
    } else {
        dbManager.createTable();
        if (bookService.syncFileWithDatabase()) {
            cout << "File synchronized with database successfully at startup.\n";
        } else {
            cout << "Failed to synchronize file at startup.\n";
        }
    }

    do {
        showMenu();
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                Book newBook = inputBook();

                if (bookService.addBook(newBook)) {
                    cout << "\nBook added successfully.\n";
                } else {
                    cout << "\nFailed to add book.\n";
                }
                break;
            }

            case 2:
                bookService.displayAllBooks();
                break;

            case 3: {
                int searchId;
                cout << "Enter Book ID to search: ";
                cin >> searchId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                bookService.searchBookByID(searchId);
                break;
            }

            case 4:
            {
                int updateId;
                cout << "Enter Book ID to update: ";
                cin >> updateId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                Book existingBook;

                if (!bookService.findBookByID(updateId, existingBook)) {
                    cout << "\nNo record found with Book ID " << updateId << ".\n";
                    break;
                }

                Book updatedBook = editBook(existingBook);

                if (bookService.updateRecord(updatedBook)) {
                    cout << "\nBook updated successfully.\n";
                } else {
                    cout << "\nFailed to update book.\n";
                }
                break;
            }

            case 5: {
                int deleteId;
                cout << "Enter Book ID to delete: ";
                cin >> deleteId;
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                if (bookService.deleteRecord(deleteId)) {
                    cout << "\nBook deleted successfully.\n";
                } else {
                    cout << "\nDelete failed or record not found.\n";
                }
                break;
            }

            case 6:
                cout << "Sort Books by Title will be implemented next.\n";
                bookService.sortBooksByTitle();
                break;

            case 7:
                cout << "Sort Books by Publication Year will be implemented next.\n";
                bookService.sortBooksByYear();
                break;

            case 8:
                cout << "Export Books to CSV will be implemented next.\n";
                break;

            case 9:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}