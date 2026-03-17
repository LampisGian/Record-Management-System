//
// Created by Charalampos Giannelis on 17/3/26.
//

#ifndef DATABASEMANAGER_HPP
#define DATABASEMANAGER_HPP

#include "Book.hpp"
#include <mysql.h>
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
};

#endif //DATABASEMANAGER_HPP
