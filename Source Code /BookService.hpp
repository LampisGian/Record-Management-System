//
// Created by Charalampos Giannelis on 18/3/26.
//
#ifndef BOOKSERVICE_HPP
#define BOOKSERVICE_HPP

#include "FileManager.hpp"
#include "DatabaseManager.hpp"
using namespace std;

class BookService {
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
};

#endif //BOOKSERVICE_HPP
