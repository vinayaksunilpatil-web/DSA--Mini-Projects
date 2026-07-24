# 📚 Library Book Finder

## 📌 Problem Statement

Managing a library manually becomes difficult as the number of books increases. Librarians need an efficient system to organize books, quickly locate them, and display available inventory. Searching through shelves or maintaining records manually is time-consuming and prone to errors.

The **Library Book Finder** is a menu-driven C++ application that helps manage a collection of books efficiently. Each book record contains details such as **Book ID (Unique Identifier), Title, Author, and Number of Copies**. The system supports adding books, searching by Book ID or Title, displaying all available books, and automatically sorting books by their IDs to enable faster searching.

---

## ✨ Features

- ➕ Add multiple books.
- 🔒 Prevent duplicate Book IDs.
- 🔍 Search books by Book ID using Binary Search.
- 📖 Search books by Title using Linear Search.
- 📋 Display all available books in a tabular format.
- 📊 Automatically sort books by Book ID after insertion.
- 📑 Clean and user-friendly console interface.

---

## 📚 Data Structures Used

- **Vector (`vector<Library>`)**
  - Stores all book records dynamically.

---

## ⚙️ Algorithms Used

- **Linear Search**
  - Used to search books by **Title**, allowing users to locate books even when they do not know the Book ID.

- **Binary Search**
  - Used to efficiently search books by **Book ID** after the records are sorted.

- **Built-in Sort (`std::sort`)**
  - Automatically sorts books by Book ID after insertion, ensuring Binary Search works correctly.

---

## ⏱️ Time Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Add Book | **O(n log n)** *(sorting after insertion)* |
| Search by Book ID | **O(log n)** |
| Search by Title | **O(n)** |
| Display Available Books | **O(n)** |

---

## 💻 Technologies Used

- **Language:** C++
- **Compiler:** GCC / G++
- **IDE:** Visual Studio Code

### Libraries Used

- `<iostream>`
- `<vector>`
- `<string>`
- `<iomanip>`
- `<algorithm>`

---

## 🎯 Learning Outcomes

- Implemented a menu-driven library management application using C++.
- Learned to store and manage dynamic records using vectors.
- Applied Binary Search for efficient searching by unique Book ID.
- Applied Linear Search for searching books by title.
- Used `std::sort()` to maintain sorted records.
- Improved console UI using formatted tables with `iomanip`.
- Understood how searching algorithms are applied in real-world applications.

---

## 🚀 Future Improvements

- Update and delete book records.
- Store records permanently using file handling.
- Search books by author.
- Display books category-wise.
- Track issued and returned books.
- Develop a GUI version using Qt or another C++ framework.
