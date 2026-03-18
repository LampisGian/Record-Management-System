//
// Created by Charalampos Giannelis on 17/3/26.
//

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include <vector>
#include "Book.hpp"
using namespace std;

class FileManager
{
private:
    string fileName;

public:
    FileManager(const string& fileName);

    bool addRecord(const Book& book);
    vector<Book> readAllRecords();
    void displayAllRecords();
    bool rewriteAllRecords(const vector<Book>& books);
    bool searchRecordByID(int bookId);
    void sortRecordsByTitle();
    void sortRecordsByYear();
};

#endif //FILEMANAGER_HPP
