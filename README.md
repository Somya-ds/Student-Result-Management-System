# Student Result Management System

A console-based **Student Result Management System** developed using C++ as a mini project for the Object-Oriented Programming (OOPS) subject.

The application helps manage student records, maintain subject marks, calculate percentages, generate grades, and compare academic performance. It also includes a unique feature called the **What-If Grade Calculator**, which allows students to simulate their academic results using hypothetical marks.

## Project Overview

The Student Result Management System is designed to simplify basic student academic record management through a menu-driven C++ application.

It allows users to add student details, search and update records, manage subject marks, generate performance reports, and calculate grades automatically.

## Features

- **Add Student:** Register students with their ID, name, course, and semester.
- **Display Students:** View all registered student records.
- **Search Student:** Find student details using their unique ID.
- **Update Student Details:** Modify existing student information.
- **Update Marks:** Change marks for individual subjects.
- **Performance Report:** Display subject-wise marks, total marks, percentage, and grade.
- **Delete Student:** Remove a student record.
- **Compare Students:** Compare the academic performance of two students.
- **What-If Grade Calculator:** Simulate hypothetical marks and calculate the predicted percentage and grade without changing the original marks.

## Unique Feature – What-If Grade Calculator

The What-If Grade Calculator is an additional feature developed to make the application more useful than a basic result management system.

It allows students to select a subject, enter hypothetical marks, and calculate how those marks would affect their overall percentage and grade.

**Example:**

If a student has scored 65 marks in Mathematics and wants to check what happens if they score 90 instead, the application calculates the predicted academic performance.

The original marks remain unchanged during the simulation.

## Technologies Used

- **Programming Language:** C++
- **Header Files:** `iostream`, `string`
- **Concepts:** Arrays, Classes, Objects, Constructors, Destructors, Inheritance, Function Overloading, Function Overriding, Virtual Functions, Polymorphism, Pointers, and Friend Functions.

## OOPS Concepts Implemented

| Concept | Implementation |
|---|---|
| Classes and Objects | Person and Student classes |
| Encapsulation | Private and protected data members |
| Inheritance | Student inherits from Person |
| Constructors | Initialising student objects |
| Destructors | Class cleanup |
| Function Overloading | Overloaded grade calculation functions |
| Function Overriding | Overriding the display function |
| Virtual Functions | Runtime polymorphism |
| Pointers | Base-class pointer |
| Friend Functions | Comparing two students |

## How to Run the Project

1. Clone or download this repository.
2. Open the project in a C++ IDE such as Code::Blocks or VS Code.
3. Open the `main.cpp` file.
4. Compile and run the program.

**Using GCC:**

```bash
g++ -std=c++17 main.cpp -o StudentResult
```

Run the executable:

```bash
./StudentResult
```

On Windows:

```bash
StudentResult.exe
```

## Project Limitations

- The application supports up to 50 students.
- Each student can have a maximum of 5 subjects.
- Student records are stored in memory during program execution.
- Records are not permanently saved after the application is closed.
- Names and subject details are currently entered as single words.

## Future Scope

The project can be improved in the future by adding:

- Permanent data storage using file handling.
- Database connectivity.
- A graphical user interface.
- Student login and authentication.
- More detailed academic performance analysis.

## Learning Outcomes

Through this project, I gained practical experience in C++ programming and learned how to apply Object-Oriented Programming concepts to develop a menu-driven application.

I also improved my understanding of arrays, classes, inheritance, polymorphism, pointers, and functions while implementing a practical academic management system.

## Author

**Somya Gupta**

BCA (Data Science)  
Chandigarh University

## Project Information

- **Project:** Student Result Management System
- **Subject:** Object-Oriented Programming (C++)
- **Language:** C++
- **Project Type:** College Mini Project
