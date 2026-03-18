//
// Created by Charalampos Giannelis on 17/3/26.
//

#include "Book.hpp"
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

Book::Book()
    : bookId(0),
      title(""),
      author(""),
      genre(""),
      publicationYear(0),
      quantity(0),
      publisher(""),
      language(""),
      pages(0),
      ageSuitability(0) {}

Book::Book(int bookId,
           const string& title,
           const string& author,
           const string& genre,
           int publicationYear,
           int quantity,
           const string& publisher,
           const string& language,
           int pages,
           int ageSuitability)
    : bookId(bookId),
      title(title),
      author(author),
      genre(genre),
      publicationYear(publicationYear),
      quantity(quantity),
      publisher(publisher),
      language(language),
      pages(pages),
      ageSuitability(ageSuitability) {}

int Book::getBookId() const
{
    return bookId;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

string Book::getGenre() const
{
    return genre;
}

int Book::getPublicationYear() const
{
    return publicationYear;
}

int Book::getQuantity() const
{
    return quantity;
}

string Book::getPublisher() const
{
    return publisher;
}

string Book::getLanguage() const
{
    return language;
}

int Book::getPages() const
{
    return pages;
}

int Book::getAgeSuitability() const
{
    return ageSuitability;
}

void Book::setBookId(int bookId)
{
    this->bookId = bookId;
}

void Book::setTitle(const string& title)
{
    this->title = title;
}

void Book::setAuthor(const string& author)
{
    this->author = author;
}

void Book::setGenre(const string& genre)
{
    this->genre = genre;
}

void Book::setPublicationYear(int publicationYear)
{
    this->publicationYear = publicationYear;
}

void Book::setQuantity(int quantity)
{
    this->quantity = quantity;
}

void Book::setPublisher(const string& publisher)
{
    this->publisher = publisher;
}

void Book::setLanguage(const string& language)
{
    this->language = language;
}

void Book::setPages(int pages)
{
    this->pages = pages;
}

void Book::setAgeSuitability(int ageSuitability)
{
    this->ageSuitability = ageSuitability;
}

void Book::display() const
{
    cout << "\nBook Information\n";
    cout << "-------------------------\n";
    cout << "Book ID: " << bookId << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Genre: " << genre << endl;
    cout << "Publication Year: " << publicationYear << endl;
    cout << "Quantity: " << quantity << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Language: " << language << endl;
    cout << "Pages: " << pages << endl;
    cout << "Age Suitability: " << ageSuitability << "+" << endl;
}

string Book::toFileString() const
{
    return to_string(bookId) + "|" +
           title + "|" +
           author + "|" +
           genre + "|" +
           to_string(publicationYear) + "|" +
           to_string(quantity) + "|" +
           publisher + "|" +
           language + "|" +
           to_string(pages) + "|" +
           to_string(ageSuitability);
}

Book Book::fromFileString(const string& line)
{
    stringstream ss(line);
    vector<string> fields;
    string part;

    while (getline(ss, part, '|'))
    {
        fields.push_back(part);
    }

    if (fields.size() != 10)
    {
        throw runtime_error("Invalid record format in file.");
    }

    return Book(
        stoi(fields[0]),
        fields[1],
        fields[2],
        fields[3],
        stoi(fields[4]),
        stoi(fields[5]),
        fields[6],
        fields[7],
        stoi(fields[8]),
        stoi(fields[9])
    );
}