# Record Management System

## Description
A Library Book Management System developed in C++ with MySQL support for storing and managing book records. The application provides a menu-driven command-line interface that allows users to add, display, search, update, and delete book records efficiently. It also includes sorting options, CSV export functionality, and basic input validation and error handling. In addition, the system maintains synchronization between the MySQL database and a file-based copy of the records, combining structured database management with file-based backup and access.

## Getting Started
1. Clone this repository or download the project files.
2. Open the project in your C++ IDE or editor.
3. Make sure the code is compiled as a C++ OOP application, since the project is structured using classes such as `Book`, `FileManager`, `DatabaseManager`, and `BookService`.
4. Run the `main.cpp` file to start the application. Once the program starts, the CLI menu will appear and you can use the available options to add, display, search, update, delete, sort, and export book records.
5. The project also includes an SQL file that should be imported into a MySQL database in order to create the required database structure.
6. After importing the SQL file, open the `DatabaseManager.cpp` file and go to the `connectDB()` function. There, you must enter the correct database connection details, such as host, username, password, database name, and port.
7. Once the database connection is configured correctly, the application will connect to MySQL and perform updates both in the database and in the file-based record storage.

The system has been designed so that the file containing the records stays synchronized with the database. The database acts as the main source of data, while the record file is updated accordingly to reflect the latest changes. In this way, records are stored consistently both in the database and in the file-based copy.


