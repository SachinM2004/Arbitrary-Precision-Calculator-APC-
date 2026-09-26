

# 🧮 Arbitrary Precision Calculator (APC)

An **Arbitrary Precision Calculator** developed in **C** that performs arithmetic operations on integers of virtually unlimited length using **Doubly Linked Lists**. The application overcomes the size limitations of built-in data types by representing each digit as a node, enabling accurate computation of extremely large numbers.

---

## 📖 Overview

Most programming languages have limitations on the size of integers they can represent using built-in data types. This project implements an Arbitrary Precision Calculator that supports mathematical operations on numbers containing hundreds or even thousands of digits.

Each digit is stored in a node of a doubly linked list, allowing efficient traversal from both directions while performing arithmetic operations.

---

## ✨ Features

- ➕ Addition of large integers
- ➖ Subtraction of large integers
- ✖ Multiplication of large integers
- ➗ Division of large integers
- 🔢 Supports numbers of unlimited length
- 🚫 Handles leading zeros
- ⚠ Handles invalid input
- 📊 Efficient memory management using doubly linked lists

---

## 🛠 Technologies Used

- C Programming
- GCC Compiler
- Linux
- Doubly Linked Lists
- Dynamic Memory Allocation
- File Handling
- Modular Programming

---

## 📂 Project Structure

```
.
├── main.c
├── main.h
├── insert.c
├── addition.c
├── subtraction.c
├── multiplication.c
├── division.c
├── compare.c
├── print_list.c
├── delete_list.c
├── validation.c
├── Makefile
└── README.md
```

---

## ⚙️ Working Principle

### Step 1: Read Input

Accept two large integer numbers from the command line.

Example

```
123456789123456789123456789
987654321987654321987654321
```

---

### Step 2: Store Digits

Each digit is stored in a doubly linked list.

Example

```
Number

12345

Stored as

NULL ← 1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 → NULL
```

---

### Step 3: Perform Arithmetic

Depending on the selected operator, the calculator performs

- Addition
- Subtraction
- Multiplication
- Division

using linked list operations instead of built-in integer types.

---

## ➕ Addition

Example

```
Input

999999999999999999
1

Output

1000000000000000000
```

The algorithm processes digits from the least significant digit while managing carry values.

---

## ➖ Subtraction

Example

```
Input

1000000000000000
999999999999999

Output

1
```

Borrow is handled during traversal.

---

## ✖ Multiplication

Example

```
Input

123456789
987654321

Output

121932631112635269
```

Implements digit-by-digit multiplication similar to the manual multiplication method.

---

## ➗ Division

Example

```
Input

1000000000000
25

Output

40000000000
```

Uses repeated subtraction or long division logic depending on the implementation.

---

## 🚀 Compilation

Using GCC

```bash
gcc *.c -o apc
```

or

```bash
make
```

---

## ▶️ Execution

```bash
./apc 123456789123456789 + 987654321987654321
```

Examples

Addition

```bash
./apc 999999999999999999 + 1
```

Subtraction

```bash
./apc 1000000000000 - 999999999999
```

Multiplication

```bash
./apc 12345 x 6789
```

Division

```bash
./apc 987654321 / 9
```

---

## 📷 Sample Output

```
Enter First Number : 999999999999999999
Enter Operator : +
Enter Second Number : 1

Result

1000000000000000000
```

---

## 📊 Data Structure

```
Head
 │
 ▼
NULL ← 1 ⇄ 2 ⇄ 3 ⇄ 4 ⇄ 5 → NULL
```

Each node stores one digit.

```c
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
```

---

## ⏱ Time Complexity

| Operation | Complexity |
|------------|------------|
| Addition | O(n) |
| Subtraction | O(n) |
| Multiplication | O(n²) |
| Division | O(n²) (implementation dependent) |
| Comparison | O(n) |

---

## 📚 Concepts Used

- Doubly Linked Lists
- Dynamic Memory Allocation
- Pointer Manipulation
- Modular Programming
- String Processing
- Arithmetic Algorithms
- File Handling
- Command-Line Arguments

---

## 🎯 Learning Outcomes

This project helped me understand:

- Implementation of arbitrary precision arithmetic
- Doubly linked list operations
- Dynamic memory management
- Carry and borrow handling
- Large-number multiplication techniques
- Command-line argument processing
- Modular software development
- Efficient pointer manipulation

---

## 🔮 Future Enhancements

- Support decimal numbers
- Modulus (%) operation
- Exponentiation
- Square root
- Negative number optimization
- Scientific notation
- Expression evaluation
- GUI version

---

## 👨‍💻 Author

**Sudarshan Jadhav**

- 📧 Email: jadhavsudarshan470@gmail.com
- 💻 GitHub: https://github.com/sudarshan142023
- 🔗 LinkedIn: https://www.linkedin.com/in/sudarshan-jadhav14/

---

## ⭐ If you found this project useful, please give the repository a star!
