// Created by Charalampos Giannelis on 18/3/26.
//This class is responsible for the functions headers of the BookService class, which provides services to manage books in the 
//library system, including synchronization between file and database, adding, displaying, searching, deleting, updating records, 
//sorting books, and exporting to CSV.
//The reason is so we could perform all the operations both in the database and the file .

#ifndef BOOKSERVICE_HPP
#define BOOKSERVICE_HPP

#include "FileManager.hpp"
#include "DatabaseManager.hpp"

using namespace std;

class BookService
{
private:
    FileManager& fileManager;
    DatabaseManager& dbManager;

public:
    BookService(FileManager& fileManager, DatabaseManager& dbManager);

    bool syncFileWithDatabase();
    bool addBook(const Book& book);
    void displayAllBooks();
    bool searchBookByID(int bookId);
    bool deleteRecord(int bookId);
    bool findBookByID(int bookId, Book& foundBook);
    bool updateRecord(const Book& book);
    void sortBooksByTitle();
    void sortBooksByYear();
    bool exportBooksToCSV(const string& csvFilename);
    bool isBookIDExists(int bookId);
};
#endif //BOOKSERVICE_HPP
