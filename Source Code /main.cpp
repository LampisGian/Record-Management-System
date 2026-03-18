#include <iostream>
#include <limits>
#include <vector>
#include "Book.hpp"
#include "FileManager.hpp"
#include "DatabaseManager.hpp"

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

    if (!dbManager.connectDB()) {
        cout << "Warning: Program continues, but database is not connected.\n";
    } else {
        if (dbManager.createTable()) {
            cout << "Table ready.\n";
        }

        vector<Book> allBooks = dbManager.getAllRecords();
        cout << "Books loaded at startup: " << allBooks.size() << endl;

        if (fileManager.rewriteAllRecords(allBooks)) {
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

                if (dbManager.addRecordToDB(newBook)) {
                    vector<Book> allBooks = dbManager.getAllRecords();

                    if (fileManager.rewriteAllRecords(allBooks)) {
                        cout << "\nBook added successfully. File synchronized with database.\n";
                    } else {
                        cout << "\nBook added to database, but file synchronization failed.\n";
                    }
                } else {
                    cout << "\nDatabase insert failed. File was not updated.\n";
                }
                break;
            }

            case 2:
                fileManager.displayAllRecords();
                break;

            case 3:
                cout << "Search Book by ID will be implemented next.\n";
                break;

            case 4:
                cout << "Update Book will be implemented next.\n";
                break;

            case 5:
                cout << "Delete Book will be implemented next.\n";
                break;

            case 6:
                cout << "Sort Books by Title will be implemented next.\n";
                break;

            case 7:
                cout << "Sort Books by Publication Year will be implemented next.\n";
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