//
// Created by Charalampos Giannelis on 18/3/26.
//
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
