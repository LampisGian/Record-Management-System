-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Εξυπηρετητής: localhost
-- Χρόνος δημιουργίας: 18 Μαρ 2026 στις 13:13:28
-- Έκδοση διακομιστή: 10.4.28-MariaDB
-- Έκδοση PHP: 8.2.4

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Βάση δεδομένων: `library`
--

-- --------------------------------------------------------

--
-- Δομή πίνακα για τον πίνακα `books`
--

CREATE TABLE `books` (
  `book_id` int(11) NOT NULL,
  `title` varchar(255) DEFAULT NULL,
  `author` varchar(255) DEFAULT NULL,
  `genre` varchar(100) DEFAULT NULL,
  `publication_year` int(11) DEFAULT NULL,
  `quantity` int(11) DEFAULT NULL,
  `publisher` varchar(255) DEFAULT NULL,
  `language` varchar(100) DEFAULT NULL,
  `pages` int(11) DEFAULT NULL,
  `age_suitability` int(11) DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Άδειασμα δεδομένων του πίνακα `books`
--

INSERT INTO `books` (`book_id`, `title`, `author`, `genre`, `publication_year`, `quantity`, `publisher`, `language`, `pages`, `age_suitability`) VALUES
(101, 'Harry Potter and the Philosopher\'s Stone', 'J.K. Rowling', 'Fantasy', 1997, 5, 'Bloomsbury', 'English', 223, 10),
(102, 'Harry Potter and the Chamber of Secrets', 'J.K. Rowling', 'Fantasy', 1998, 4, 'Bloomsbury', 'English', 251, 10),
(103, 'The Hobbit', 'J.R.R. Tolkien', 'Fantasy', 1937, 6, 'George Allen & Unwin', 'English', 310, 10),
(104, 'The Lord of the Rings', 'J.R.R. Tolkien', 'Fantasy', 1954, 3, 'George Allen & Unwin', 'English', 1178, 14),
(105, '1984', 'George Orwell', 'Dystopian', 1949, 7, 'Secker & Warburg', 'English', 328, 16),
(106, 'Animal Farm', 'George Orwell', 'Political Satire', 1945, 6, 'Secker & Warburg', 'English', 112, 14),
(107, 'Pride and Prejudice', 'Jane Austen', 'Classic', 1813, 4, 'T. Egerton', 'English', 432, 14),
(108, 'To Kill a Mockingbird', 'Harper Lee', 'Classic', 1960, 5, 'J.B. Lippincott & Co.', 'English', 281, 14),
(109, 'The Great Gatsby', 'F. Scott Fitzgerald', 'Classic', 1925, 4, 'Charles Scribner\'s Sons', 'English', 180, 14),
(110, 'Moby-Dick', 'Herman Melville', 'Adventure', 1851, 2, 'Harper & Brothers', 'English', 635, 16),
(111, 'War and Peace', 'Leo Tolstoy', 'Historical Fiction', 1869, 2, 'The Russian Messenger', 'Russian', 1225, 16),
(112, 'Crime and Punishment', 'Fyodor Dostoevsky', 'Psychological Fiction', 1866, 3, 'The Russian Messenger', 'Russian', 671, 16),
(113, 'The Catcher in the Rye', 'J.D. Salinger', 'Classic', 1951, 5, 'Little, Brown and Company', 'English', 214, 15),
(114, 'Brave New World', 'Aldous Huxley', 'Dystopian', 1932, 4, 'Chatto & Windus', 'English', 311, 16),
(115, 'Jane Eyre', 'Charlotte Bronte', 'Classic', 1847, 3, 'Smith, Elder & Co.', 'English', 500, 14),
(116, 'Wuthering Heights', 'Emily Bronte', 'Classic', 1847, 3, 'Thomas Cautley Newby', 'English', 416, 15),
(117, 'The Alchemist', 'Paulo Coelho', 'Adventure', 1988, 6, 'HarperTorch', 'Portuguese', 208, 12),
(118, 'The Little Prince', 'Antoine de Saint-Exupery', 'Children\'s Literature', 1943, 8, 'Reynal & Hitchcock', 'French', 96, 8),
(119, 'The Da Vinci Code', 'Dan Brown', 'Thriller', 2003, 5, 'Doubleday', 'English', 489, 16),
(120, 'Angels & Demons', 'Dan Brown', 'Thriller', 2000, 4, 'Pocket Books', 'English', 616, 16),
(121, 'The Girl with the Dragon Tattoo', 'Stieg Larsson', 'Crime', 2005, 3, 'Norstedts Forlag', 'Swedish', 465, 18),
(122, 'The Hunger Games', 'Suzanne Collins', 'Dystopian', 2008, 7, 'Scholastic Press', 'English', 374, 13),
(123, 'Catching Fire', 'Suzanne Collins', 'Dystopian', 2009, 6, 'Scholastic Press', 'English', 391, 13),
(124, 'Mockingjay', 'Suzanne Collins', 'Dystopian', 2010, 6, 'Scholastic Press', 'English', 390, 13),
(125, 'The Book Thief', 'Markus Zusak', 'Historical Fiction', 2005, 4, 'Picador', 'English', 552, 14),
(126, 'The Kite Runner', 'Khaled Hosseini', 'Drama', 2003, 4, 'Riverhead Books', 'English', 371, 16),
(127, 'A Thousand Splendid Suns', 'Khaled Hosseini', 'Drama', 2007, 4, 'Riverhead Books', 'English', 384, 16),
(128, 'The Fault in Our Stars', 'John Green', 'Young Adult', 2012, 5, 'Dutton Books', 'English', 313, 13),
(129, 'The Shining', 'Stephen King', 'Horror', 1977, 3, 'Doubleday', 'English', 447, 18),
(130, 'It', 'Stephen King', 'Horror', 1986, 2, 'Viking', 'English', 1138, 18);

--
-- Ευρετήρια για άχρηστους πίνακες
--

--
-- Ευρετήρια για πίνακα `books`
--
ALTER TABLE `books`
  ADD PRIMARY KEY (`book_id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
