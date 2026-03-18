// Created by Charalampos Giannelis on 17/3/26.
//This files is responsible for the code implementation of the DatabaseManager class, which manages the connection and operations
// with the MySQL database for storing book records.

#include "DatabaseManager.hpp"

#include <iostream>

using namespace std;

DatabaseManager::DatabaseManager()
{
    conn = mysql_init(NULL);
}

DatabaseManager::~DatabaseManager()
{
    closeDB();
}

bool DatabaseManager::connectDB()
{
    conn = mysql_real_connect(
    conn,
    "127.0.0.1",
    "root",
    "",
    "library",
    1233,
    NULL,
    0
    );

    if (conn == NULL)
    {
        cout << "Database connection failed: " << mysql_error(conn) << endl;
        return false;
    }

    return true;
}

void DatabaseManager::closeDB()
{
    if (conn != NULL)
    {
        mysql_close(conn);
        conn = NULL;
    }
}

bool DatabaseManager::createTable()
{
    string query =
        "CREATE TABLE IF NOT EXISTS books ("
        "book_id INT PRIMARY KEY, "
        "title VARCHAR(255), "
        "author VARCHAR(255), "
        "genre VARCHAR(100), "
        "publication_year INT, "
        "quantity INT, "
        "publisher VARCHAR(255), "
        "language VARCHAR(100), "
        "pages INT, "
        "age_suitability INT)";

    if (mysql_query(conn, query.c_str()))
    {
        cout << "Table creation failed: " << mysql_error(conn) << endl;
        return false;
    }

    return true;
}

bool DatabaseManager::addRecordToDB(const Book& book)
{
    string query =
        "INSERT INTO books (book_id, title, author, genre, publication_year, quantity, publisher, language, pages, age_suitability) VALUES (" +
        to_string(book.getBookId()) + ", '" +
        book.getTitle() + "', '" +
        book.getAuthor() + "', '" +
        book.getGenre() + "', " +
        to_string(book.getPublicationYear()) + ", " +
        to_string(book.getQuantity()) + ", '" +
        book.getPublisher() + "', '" +
        book.getLanguage() + "', " +
        to_string(book.getPages()) + ", " +
        to_string(book.getAgeSuitability()) + ")";

    if (mysql_query(conn, query.c_str()))
    {
        cout << "Insert failed: " << mysql_error(conn) << endl;
        return false;
    }

    return true;
}

vector<Book> DatabaseManager::getAllRecords()
{
    vector<Book> books;

    string query =
        "SELECT book_id, title, author, genre, publication_year, quantity, publisher, language, pages, age_suitability FROM books";

    if (mysql_query(conn, query.c_str()))
    {
        cout << "Fetch failed: " << mysql_error(conn) << endl;
        return books;
    }

    MYSQL_RES* result = mysql_store_result(conn);

    if (result == NULL)
    {
        cout << "Result store failed: " << mysql_error(conn) << endl;
        return books;
    }

    MYSQL_ROW row;

    while ((row = mysql_fetch_row(result)))
    {
        Book book(
            stoi(row[0]),
            row[1] ? row[1] : "",
            row[2] ? row[2] : "",
            row[3] ? row[3] : "",
            stoi(row[4]),
            stoi(row[5]),
            row[6] ? row[6] : "",
            row[7] ? row[7] : "",
            stoi(row[8]),
            stoi(row[9])
        );

        books.push_back(book);
    }

    mysql_free_result(result);
    return books;
}

bool DatabaseManager::deleteRecordFromDB(int bookId)
{
    string query = "DELETE FROM books WHERE book_id = " + to_string(bookId);

    if (mysql_query(conn, query.c_str()))
        {
        cout << "Delete failed: " << mysql_error(conn) << endl;
        return false;
    }

    if (mysql_affected_rows(conn) == 0)
    {
        cout << "No record found with Book ID " << bookId << " in database.\n";
        return false;
    }

    return true;
}

bool DatabaseManager::findRecordByIDInDB(int bookId, Book& foundBook)
{
    string query =
        "SELECT book_id, title, author, genre, publication_year, quantity, publisher, language, pages, age_suitability "
        "FROM books WHERE book_id = " + to_string(bookId);

    if (mysql_query(conn, query.c_str())) {
        cout << "Search failed: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_RES* result = mysql_store_result(conn);

    if (result == NULL)
    {
        cout << "mysql_store_result failed: " << mysql_error(conn) << endl;
        return false;
    }

    MYSQL_ROW row = mysql_fetch_row(result);

    if (row == NULL)
    {
        mysql_free_result(result);
        return false;
    }

    foundBook = Book(
        row[0] ? stoi(row[0]) : 0,
        row[1] ? row[1] : "",
        row[2] ? row[2] : "",
        row[3] ? row[3] : "",
        row[4] ? stoi(row[4]) : 0,
        row[5] ? stoi(row[5]) : 0,
        row[6] ? row[6] : "",
        row[7] ? row[7] : "",
        row[8] ? stoi(row[8]) : 0,
        row[9] ? stoi(row[9]) : 0
    );

    mysql_free_result(result);
    return true;
}

bool DatabaseManager::updateRecordInDB(const Book& book)
{
    string query =
        "UPDATE books SET "
        "title = '" + book.getTitle() + "', "
        "author = '" + book.getAuthor() + "', "
        "genre = '" + book.getGenre() + "', "
        "publication_year = " + to_string(book.getPublicationYear()) + ", "
        "quantity = " + to_string(book.getQuantity()) + ", "
        "publisher = '" + book.getPublisher() + "', "
        "language = '" + book.getLanguage() + "', "
        "pages = " + to_string(book.getPages()) + ", "
        "age_suitability = " + to_string(book.getAgeSuitability()) + " "
        "WHERE book_id = " + to_string(book.getBookId());

    if (mysql_query(conn, query.c_str()))
    {
        cout << "Update failed: " << mysql_error(conn) << endl;
        return false;
    }

    if (mysql_affected_rows(conn) == 0)
    {
        cout << "No record found with Book ID " << book.getBookId() << ".\n";
        return false;
    }

    return true;
}
