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
## Test Results

### 10 × 10 Matrix Multiplication

Input File:`Assignment_01/tests/gemm_test_10.txt`

| Algorithm | Execution Time |
|-----------|---------------:|
| Simple GEMM | 7.000000 ms |
| Blocking GEMM | 4.000000 ms |

Observation:
- Both algorithms produced the same output matrix.
- Due to the small matrix size, the execution times are very close.
- Blocking GEMM does not show a significant performance improvement for small matrices.

---

### 100 × 100 Matrix Multiplication

Input File:`Assignment_01/tests/gemm_test_100.txt`

| Algorithm | Execution Time |
|-----------|---------------:|
| Simple GEMM | 15.000000 ms |
| Blocking GEMM | 9.000000 ms |

**Observation:**
- Both algorithms produced identical results.
- The execution time increased because of the larger matrix size.
- Blocking GEMM generally performs better for larger matrices due to improved cache locality and reduced memory access overhead.

---

## Performance Summary

| Matrix Size | Simple GEMM | Blocking GEMM |
|-------------|------------:|--------------:|
| 10 × 10 | XX.XXXXXX ms | XX.XXXXXX ms |
| 100 × 100 | XX.XXXXXX ms | XX.XXXXXX ms |

### Conclusion

- The implementation of both **Simple GEMM** and **Blocking GEMM** was successfully verified.
- Both algorithms produced the same matrix multiplication results.
- For small matrices (10×10), the execution times are nearly identical.
- For larger matrices (100×100), Blocking GEMM is expected to perform more efficiently because it improves cache utilization during matrix multiplication.