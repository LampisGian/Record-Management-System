#include <iostream>
#include <limits>
#include <vector>
#include <ctime>

#include "Book.hpp"
#include "FileManager.hpp"
#include "DatabaseManager.hpp"
#include "BookService.hpp"


using namespace std;

int getCurrentYear() 
{
    time_t now = time(0);
    tm* localTime = localtime(&now);
    return 1900 + localTime->tm_year;
}



int readInt(const string& message) 
{
    int value;

    while (true) 
    {
        cout << message;
        cin >> value;

        if (cin.fail()) 
        {
            cout << "Invalid input. Please enter a valid number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return value;
    }
}

int readPositiveInt(const string& message) 
{
    int value;

    while (true) 
    {
        value = readInt(message);

        if (value < 0) 
        {
            cout << "Value cannot be negative. Please try again.\n";
            continue;
        }

        return value;
    }
}

int readValidYear(const string& message)
{
    int year;
    int currentYear = getCurrentYear();

    while (true)
    {
        year = readPositiveInt(message);

        if (year > currentYear)
        {
            cout << "Future years are not allowed. Current year is " << currentYear << ".\n";
            continue;
        }

        return year;
    }
}

string readNonEmptyString(const string& message) 
{
    string value;

    while (true) 
    {
        cout << message;
        getline(cin, value);

        if (value.empty()) 
        {
            cout << "This field cannot be empty. Please try again.\n";
            continue;
        }

        return value;
    }
}

void showMenu() 
{
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

Book editBook(const Book& oldBook) 
{
    cout << "\nCurrent record:\n";
    cout << "--------------------------\n";
    oldBook.display();

    string title = readNonEmptyString("\nEnter new Title: ");
    string author = readNonEmptyString("Enter new Author: ");
    string genre = readNonEmptyString("Enter new Genre: ");
    int publicationYear = readPositiveInt("Enter new Publication Year: ");
    int quantity = readPositiveInt("Enter new Quantity: ");
    string publisher = readNonEmptyString("Enter new Publisher: ");
    string language = readNonEmptyString("Enter new Language: ");
    int pages = readPositiveInt("Enter new Pages: ");
    int ageSuitability = readPositiveInt("Enter new Age Suitability: ");

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

Book inputBook() 
{
    int bookId = readPositiveInt("Enter Book ID: ");
    string title = readNonEmptyString("Enter Title: ");
    string author = readNonEmptyString("Enter Author: ");
    string genre = readNonEmptyString("Enter Genre: ");
    int publicationYear = readPositiveInt("Enter Publication Year: ");
    int quantity = readPositiveInt("Enter Quantity: ");
    string publisher = readNonEmptyString("Enter Publisher: ");
    string language = readNonEmptyString("Enter Language: ");
    int pages = readPositiveInt("Enter Pages: ");
    int ageSuitability = readPositiveInt("Enter Age Suitability: ");

    return Book(bookId, title, author, genre, publicationYear, quantity,
                publisher, language, pages, ageSuitability);
}

int main() 
{
    int choice;

    FileManager fileManager("/Users/lampis/Documents/GitHub/Record-Management-System/books.txt");
    DatabaseManager dbManager;
    BookService bookService(fileManager, dbManager);

    if (!dbManager.connectDB()) 
    {
        cout << "Warning: Program continues, but database is not connected.\n";
    } 
    else 
    {
        dbManager.createTable();
        
        if (bookService.syncFileWithDatabase()) 
        {
            cout << "File synchronized with database successfully at startup.\n";
        } 
        else 
        {
            cout << "Failed to synchronize file at startup.\n";
        }
    }

    do 
    {
        showMenu();
        choice = readInt("Enter your choice: ");
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) 
        {
            case 1: 
            {
                Book newBook = inputBook();

                if (bookService.isBookIDExists(newBook.getBookId())) 
                {
                    cout << "\nA book with this ID already exists. Please use a different ID.\n";
                    break;
                }

                if (bookService.addBook(newBook)) 
                {
                    cout << "\nBook added successfully.\n";
                } 
                else 
                {
                    cout << "\nFailed to add book.\n";
                }
                break;
            }

            case 2:
                bookService.displayAllBooks();
                break;

            case 3: 
            {
                int searchId = readPositiveInt("Enter Book ID to search: ");
                bookService.searchBookByID(searchId);
                break;
            }

            case 4:
            {
                int updateId = readPositiveInt("Enter Book ID to update: ");

                Book existingBook;

                if (!bookService.findBookByID(updateId, existingBook)) 
                {
                    cout << "\nNo record found with Book ID " << updateId << ".\n";
                    break;
                }

                Book updatedBook = editBook(existingBook);

                if (bookService.updateRecord(updatedBook)) 
                {
                    cout << "\nBook updated successfully.\n";
                } 
                else 
                {
                    cout << "\nFailed to update book.\n";
                }
                break;
            }

            case 5: 
            {
                int deleteId = readPositiveInt("Enter Book ID to delete: ");

                if (bookService.deleteRecord(deleteId)) 
                {
                    cout << "\nBook deleted successfully.\n";
                } 
                else 
                {
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
                {
                string csvPath = "/Users/lampis/Documents/GitHub/Record-Management-System/books.csv";

                if (bookService.exportBooksToCSV(csvPath)) 
                {
                    cout << "\nBooks exported successfully to CSV.\n";
                    cout << "CSV file: " << csvPath << endl;
                } 
                else 
                {
                    cout << "\nFailed to export books to CSV.\n";
                }
                break;
                }

            case 9:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 9);

    return 0;
}