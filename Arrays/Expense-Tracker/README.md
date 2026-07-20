# Expense Tracker

## Problem Statement

Tracking daily expenses manually is difficult and makes it hard to analyze spending habits. This project provides a menu-driven Expense Tracker that helps users record expenses, analyze spending, categorize expenses, and sort records efficiently.

---

## Features

- Add Expense
- Update Expense
- Delete Expense
- Display All Expenses
- Expense Analysis
  - Total Spending
  - Highest Expense
  - Lowest Expense
- Category-wise Expense Analysis
- Display Expenses Within Budget
- Sort Expenses Using Merge Sort

---

## Data Structures Used

- Vector (`vector<Expense>`) for storing expenses.
- Structure (`struct Expense`) to represent each expense.
- Hash Map (`unordered_map`) for category-wise expense analysis.

---

## Algorithms Used

- Merge Sort
- Linear Search
- Hashing (`unordered_map`)
- CRUD Operations

---

## Time Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Add Expense | O(1) |
| Display Expenses | O(n) |
| Update Expense | O(n) |
| Delete Expense | O(n) |
| Expense Analysis | O(n) |
| Category-wise Analysis | O(n) |
| Budget Filter | O(n) |
| Merge Sort | O(n log n) |

where **n** is the number of expenses.

---

## Technologies Used

- C++
- STL Vector
- STL unordered_map
- iomanip
- Structures
- Classes
- Console-based UI

---

## Learning Outcomes

- Using vectors to manage dynamic data
- Working with structures and classes
- Implementing Merge Sort
- Using Hash Maps (`unordered_map`)
- Performing data analysis
- CRUD operations
- Console formatting using `iomanip`

---

## Future Improvements

- File Handling
- Monthly Expense Reports
- Search by Date
- Category Budget Limits
- Expense Charts and Graphs
- Export Reports to CSV/PDF
- Graphical User Interface (GUI)
