//
// Created by Charalampos Giannelis on 17/3/26.
//
#ifndef ΒΟΟΚ_HPP
#define ΒΟΟΚ_HPP

#include <string>
using namespace std;

class Book
{
    private:
        int bookId;
        string title;
        string author;
        string genre;
        int publicationYear;
        int quantity;
        string publisher;
        string language;
        int pages;
        int ageSuitability;

    public:
        Book();

        Book(int bookId,
             const string& title,
             const string& author,
             const string& genre,
             int publicationYear,
             int quantity,
             const string& publisher,
             const string& language,
             int pages,
             int ageSuitability);

    int getBookId() const;
    string getTitle() const;
    string getAuthor() const;
    string getGenre() const;
    int getPublicationYear() const;
    int getQuantity() const;
    string getPublisher() const;
    string getLanguage() const;
    int getPages() const;
    int getAgeSuitability() const;

    void setBookId(int bookId);
    void setTitle(const string& title);
    void setAuthor(const string& author);
    void setGenre(const string& genre);
    void setPublicationYear(int publicationYear);
    void setQuantity(int quantity);
    void setPublisher(const string& publisher);
    void setLanguage(const string& language);
    void setPages(int pages);
    void setAgeSuitability(int ageSuitability);

    void display() const;
};
#endif //ΒΟΟΚ_HPP
