//
// Created by Charalampos Giannelis on 17/3/26.
//
#include <iostream>
#include "Book.hpp"

using namespace std;

void showMenu()
{
    cout << "\n========== Library Book Management System ==========\n";
    cout << "1. Add Book\n";
    cout << "2. Display All Books\n";
    cout << "3. Search Book by ID\n";
    cout << "4. Update Book\n";
    cout << "5. Delete Book\n";
    cout << "6. Sort Books by Title\n";
    cout << "7. Sort Books by Publication Year\n";
    cout << "8. Export Books to CSV\n";
    cout << "9. Exit\n";
    cout << "Enter your choice: ";
}

int main()
{
    int choice;

    do
    {
        showMenu();
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Add Book option selected.\n";
                break;
            case 2:
                cout << "Display All Books option selected.\n";
                break;
            case 3:
                cout << "Search Book by ID option selected.\n";
                break;
            case 4:
                cout << "Update Book option selected.\n";
                break;
            case 5:
                cout << "Delete Book option selected.\n";
                break;
            case 6:
                cout << "Sort Books by Title option selected.\n";
                break;
            case 7:
                cout << "Sort Books by Publication Year option selected.\n";
                break;
            case 8:
                cout << "Export Books to CSV option selected.\n";
                break;
            case 9:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }

    }
    while (choice != 9);

    return 0;
}