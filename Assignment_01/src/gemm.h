#ifndef GEMM_H
#define GEMM_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void simpleGEMM(int **A, int **B, int **C, int M, int K, int N);

void blockingGEMM(int **A, int **B, int **C, int M, int K, int N, int blockSize);

void printMatrix(int **matrix, int rows, int cols);
#endif