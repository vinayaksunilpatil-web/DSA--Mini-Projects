# Inventory Management System

## Problem Statement

Managing inventory manually can lead to incorrect stock records and difficulty in tracking products. This project provides a menu-driven Inventory Management System that allows users to add, update, delete, search, sort, and manage products efficiently.

---

## Features

- Add Multiple Products
- Update Product Details
- Delete Product
- Search Product by ID
- Display All Products
- Sort Products by Price (Merge Sort)
- Display Products Within Budget
- Prevent Duplicate Product IDs

---

## Data Structures Used

- Vector (`vector<Product>`) for storing product records.
- Structure (`struct Product`) to represent each product.

---

## Algorithms Used

- Merge Sort
- Linear Search
- CRUD Operations

---

## Time Complexity Analysis

| Operation | Time Complexity |
|-----------|-----------------|
| Add Product | O(n)* |
| Display Products | O(n) |
| Search Product | O(n) |
| Update Product | O(n) |
| Delete Product | O(n) |
| Display Products Within Budget | O(n) |
| Merge Sort | O(n log n) |

> *Insertion into the vector is **O(1)** on average, but checking for duplicate Product IDs requires **O(n)** time.

where **n** is the number of products.

---

## Technologies Used

- C++
- STL Vector
- Structures
- Classes
- Functions
- Merge Sort
- Console-based UI

---

## Learning Outcomes

- Working with vectors to store dynamic data
- Using structures and classes
- Implementing CRUD operations
- Implementing Merge Sort
- Applying Linear Search
- Preventing duplicate records
- Building modular C++ applications

---

## Future Improvements

- File Handling
- Search by Product Name
- Binary Search after Sorting
- Product Category Filtering
- Low Stock Alerts
- Automatic Product ID Generation
- Sales Report Generation
- Better Console UI using `iomanip`
- Graphical User Interface (GUI)
