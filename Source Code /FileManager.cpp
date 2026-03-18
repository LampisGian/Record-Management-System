//
// Created by Charalampos Giannelis on 17/3/26.
//

#include "FileManager.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
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

vector<Book> FileManager::readAllRecords()
{
    vector<Book> books;
    ifstream inFile(fileName);

    if (!inFile.is_open())
        {
        cout << "Error: Could not open file for reading: " << fileName << endl;
        return books;
    }

    string line;
    while (getline(inFile, line)) {
        if (line.empty()) {
            continue;
        }

        try {
            books.push_back(Book::fromFileString(line));
        } catch (...) {
            cout << "Warning: Invalid line skipped.\n";
        }
    }

    inFile.close();
    return books;
}

void FileManager::displayAllRecords() {
    vector<Book> books = readAllRecords();

    if (books.empty()) {
        cout << "\nNo records found in file.\n";
        return;
    }

    cout << "\n========== All Book Records ==========\n";
    for (int i = 0; i < books.size(); i++) {
        cout << "\nRecord #" << i + 1 << endl;
        cout << "--------------------------\n";
        books[i].display();
    }
}

bool FileManager::rewriteAllRecords(const vector<Book>& books)
{
    ofstream outFile(fileName, ios::trunc);

    if (!outFile.is_open()) {
        cout << "Error: Could not open file for rewriting: " << fileName << endl;
        return false;
    }

    for (const Book& book : books) {
        outFile << book.toFileString() << "\n";
    }

    outFile.close();
    return true;
}

bool FileManager::searchRecordByID(int bookId) {
    vector<Book> books = readAllRecords();

    for (const Book& book : books) {
        if (book.getBookId() == bookId) {
            cout << "\nBook found:\n";
            cout << "--------------------------\n";
            book.display();
            return true;
        }
    }

    cout << "\nBook with ID " << bookId << " was not found.\n";
    return false;
}

void FileManager::sortRecordsByTitle() {
    vector<Book> books = readAllRecords();

    if (books.empty()) {
        cout << "\nNo records found in file.\n";
        return;
    }

    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getTitle() < b.getTitle();
    });

    cout << "\n========== Books Sorted by Title ==========\n";
    for (int i = 0; i < books.size(); i++) {
        cout << "\nRecord #" << i + 1 << endl;
        cout << "--------------------------\n";
        books[i].display();
    }
}

void FileManager::sortRecordsByYear() {
    vector<Book> books = readAllRecords();

    if (books.empty()) {
        cout << "\nNo records found in file.\n";
        return;
    }

    sort(books.begin(), books.end(), [](const Book& a, const Book& b) {
        return a.getPublicationYear() < b.getPublicationYear();
    });

    cout << "\n========== Books Sorted by Publication Year ==========\n";
    for (int i = 0; i < books.size(); i++) {
        cout << "\nRecord #" << i + 1 << endl;
        cout << "--------------------------\n";
        books[i].display();
    }
}

bool FileManager::exportToCSV(const string& csvFilename)
{
    vector<Book> books = readAllRecords();

    ofstream csvFile(csvFilename);

    if (!csvFile.is_open())
    {
        cout << "Error: Could not open CSV file: " << csvFilename << endl;
        return false;
    }

    csvFile << "Book ID,Title,Author,Genre,Publication Year,Quantity,Publisher,Language,Pages,Age Suitability\n";

    for (const Book& book : books) {
        csvFile << book.getBookId() << ","
                << "\"" << book.getTitle() << "\","
                << "\"" << book.getAuthor() << "\","
                << "\"" << book.getGenre() << "\","
                << book.getPublicationYear() << ","
                << book.getQuantity() << ","
                << "\"" << book.getPublisher() << "\","
                << "\"" << book.getLanguage() << "\","
                << book.getPages() << ","
                << book.getAgeSuitability() << "\n";
    }

    csvFile.close();
    return true;
}