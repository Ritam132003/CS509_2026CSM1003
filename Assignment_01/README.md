# CS509 Laboratory Repository

## Student Details:

Name:Ritam Chowdhury
Entry Number:2026CSM1003

## Programming Language:

- Language: C
- Compiler: GCC(MinGW)
- IDE: Visual Studio Code

## Repository Structure:

CS509_2026CSM1003/
│
├── README.md
├── Makefile
│
├── common_wrapper/
│      wrapper.c
│
└── Assignment_01/
       ├── src/
       │      gemm.c
       │      gemm.h
       │
       ├── driver/
       │      driver.c
       │
       ├── tests/
       │      gemm_test_01.txt
       │
       └── outputs/


# Assignment 1:

## Title:

General Matrix Multiplication (GEMM)

## Objective:

Implement two versions of GEMM:

- Simple GEMM
- Blocking GEMM

Compare their execution times.

## Input Format

M K N

Matrix A

Matrix B

## Compilation

```bash
gcc Assignment_01/src/gemm.c Assignment_01/driver/driver.c -o gemm.exe
---

## Execution

```bash
.\gemm.exe
```

---

## Sample Output

=====================================
      Simple GEMM
=====================================
Result Matrix:
58 64
139 154

Execution Time : 0.000000 ms

=====================================
      BLOCKING GEMM
=====================================
58 64
139 154

Execution Time : 0.000000 ms
---
