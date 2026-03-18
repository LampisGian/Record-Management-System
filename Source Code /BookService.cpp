//
// Created by Charalampos Giannelis on 18/3/26.
//

#include "BookService.hpp"

#include <iostream>

using namespace std;

BookService::BookService(FileManager& fileManager, DatabaseManager& dbManager)
    : fileManager(fileManager), dbManager(dbManager)
{}

bool BookService::syncFileWithDatabase()
{
    vector<Book> allBooks = dbManager.getAllRecords();
    return fileManager.rewriteAllRecords(allBooks);
}

bool BookService::addBook(const Book& book)
{
    if (!dbManager.addRecordToDB(book))
    {
        return false;
    }

    return syncFileWithDatabase();
}

void BookService::displayAllBooks()
{
    fileManager.displayAllRecords();
}

bool BookService::searchBookByID(int bookId)
{
    return fileManager.searchRecordByID(bookId);
}

bool BookService::deleteRecord(int bookId)
{
    if (!dbManager.deleteRecordFromDB(bookId))
    {
        return false;
    }

    return syncFileWithDatabase();
}

bool BookService::findBookByID(int bookId, Book& foundBook)
{
    return dbManager.findRecordByIDInDB(bookId, foundBook);
}

bool BookService::updateRecord(const Book& book)
{
    if (!dbManager.updateRecordInDB(book))
    {
        return false;
    }

    return syncFileWithDatabase();
}

void BookService::sortBooksByTitle()
{
    fileManager.sortRecordsByTitle();
}

void BookService::sortBooksByYear()
{
    fileManager.sortRecordsByYear();
}

bool BookService::exportBooksToCSV(const string& csvFilename)
{
    return fileManager.exportToCSV(csvFilename);
}

bool BookService::isBookIDExists(int bookId)
{
    Book foundBook;
    return dbManager.findRecordByIDInDB(bookId, foundBook);
}