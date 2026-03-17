//
// Created by Charalampos Giannelis on 17/3/26.
//

#include "FileManager.hpp"

#include <fstream>
using namespace std;

FileManager::FileManager(const string& fileName) : fileName(fileName)
{}

bool FileManager::addRecord(const Book& book)
{
    ofstream outFile(fileName, ios::app);

    if (!outFile.is_open())
    {
        return false;
    }

    outFile << book.getBookId() << "|"
            << book.getTitle() << "|"
            << book.getAuthor() << "|"
            << book.getGenre() << "|"
            << book.getPublicationYear() << "|"
            << book.getQuantity() << "|"
            << book.getPublisher() << "|"
            << book.getLanguage() << "|"
            << book.getPages() << "|"
            << book.getAgeSuitability() << "\n";

    outFile.close();
    return true;
}