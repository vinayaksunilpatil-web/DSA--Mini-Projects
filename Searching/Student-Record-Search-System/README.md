# 🎓 Student Record Search System

## 📌 Problem Statement

Educational institutions maintain records for hundreds or even thousands of students. As the number of records grows, searching and managing student information manually becomes time-consuming and inefficient. Administrators require a system that can quickly organize, update, display, and retrieve student records while ensuring data accuracy.

The **Student Record Search System** is a menu-driven C++ application that allows users to manage student records efficiently. Each student record contains details such as **PRN Number (Unique Identifier), Roll Number, Student Name, Department, Semester, and CGPA**. The system supports adding, updating, deleting, displaying, department-wise grouping, and searching student records, providing a simple and practical solution for managing academic information.

---

## ✨ Features

- ➕ Add multiple student records.
- 🔒 Prevent duplicate PRN numbers.
- ✏️ Update existing student records.
- 🗑️ Delete student records.
- 📋 Display all student records in a tabular format.
- 🏢 Display department-wise grouped student records.
- 🔍 Search students by name (supports multiple students with the same name).
- 📊 Automatically keeps records sorted by PRN after insertion.
- 📑 Clean and formatted console interface.

---

## 📚 Data Structures Used

- **Vector (`vector<Student>`)**
  - Stores all student records dynamically.

- **Map (`map<string, vector<Student>>`)**
  - Groups students according to their departments for department-wise display.

---

## ⚙️ Algorithms Used

- **Linear Search**
  - Used to search student records by **Student Name**. Since multiple students can have the same name, the algorithm scans all records and displays every matching result, reflecting a real-world college administration scenario.

- **Binary Search**
  - Used for efficient searching during record update and deletion operations after records are maintained in sorted order by PRN.

- **Built-in Sort (`std::sort`)**
  - Automatically sorts student records by PRN after insertion, ensuring binary search operates correctly.

---

## ⏱️ Time Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Add Student | **O(n log n)** *(sorting after insertion)* |
| Update Student | **O(log n)** |
| Delete Student | **O(log n) + O(n)** *(binary search + vector erase)* |
| Display All Records | **O(n)** |
| Department-wise Display | **O(n log k)** *(where `k` is the number of departments)* |
| Search Student by Name | **O(n)** |

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
- `<map>`

---

## 🎯 Learning Outcomes

- Implemented CRUD operations using C++.
- Learned dynamic data management using vectors.
- Applied Linear Search and Binary Search in a practical application.
- Used `std::sort()` to maintain sorted records.
- Learned to group data using `map`.
- Improved console UI using formatted tables with `iomanip`.
- Understood how to design a menu-driven real-world management system.

---

## 🚀 Future Improvements

- Save and load records using file handling.
- Search using multiple filters (PRN, Roll Number, Department).
- Export records to CSV or Excel.
- Add password-protected administrator login.
- Develop a GUI version using Qt or another C++ framework.
