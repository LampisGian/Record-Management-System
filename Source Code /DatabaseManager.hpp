// Created by Charalampos Giannelis on 17/3/26.
//This file is responsible for the code headers of the DatabaseManager class, which manages the connection and operations on the 
//end of the MySQL database for storing book records.

#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include "Book.hpp"

#include <mysql.h>
#include <vector>

using namespace std;

class DatabaseManager
{
private:
    MYSQL* conn;

public:
    DatabaseManager();
    ~DatabaseManager();

    bool connectDB();
    void closeDB();
    bool createTable();
    bool addRecordToDB(const Book& book);
    vector<Book> getAllRecords();
    bool deleteRecordFromDB(int bookId);
    bool findRecordByIDInDB(int bookId, Book& foundBook);
    bool updateRecordInDB(const Book& book);
};

#endif //DATABASEMANAGER_HPP
