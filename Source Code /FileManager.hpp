//
// Created by Charalampos Giannelis on 17/3/26.
//

#ifndef FILEMANAGER_HPP
#define FILEMANAGER_HPP

#include <string>
#include "Book.hpp"
using namespace std;

class FileManager
{
private:
    string fileName;

public:
    FileManager(const string& fileName);

    bool addRecord(const Book& book);
};

#endif //FILEMANAGER_HPP
