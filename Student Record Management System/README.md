# Brief Overview

This C++ program is a student record management system that uses a singly linked list to store and process student data read from a file.

It performs the following key tasks:

📥 Reads student data (ID, name, department, semester, CGPA, credits, year) from an input file
🧱 Stores data in a linked list for dynamic memory handling
🔄 Creates copies of the list to perform multiple independent operations
📊 Sorts students in two different ways:
By CGPA (descending) using Bubble Sort
By Enrollment Year + ID using Insertion Sort
📤 Generates two output files:
ranked_by_cgpa.txt → ranked list of students based on performance
sorted_by_enrollment.txt → grouped by year with average CGPA

The program also includes:

✔️ Basic data validation (CGPA and semester limits)
✔️ Memory management using dynamic allocation and deallocation
✔️ Structured and formatted file output

👉 In short, this project demonstrates file handling, linked lists, sorting algorithms, and structured data processing in C++.
