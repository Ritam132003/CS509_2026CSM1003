#include "gemm.h"

// Print a matrix
void printMatrix(int **matrix, int rows, int cols)
{
    int i, j;

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Simple GEMM Implementation
void simpleGEMM(int **A, int **B, int **C, int M, int K, int N)
{
    int i, j, k;

    // Initialize result matrix
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
        }
    }

    // Matrix Multiplication
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            for (k = 0; k < K; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}
// Blocking GEMM
void blockingGEMM(int **A, int **B, int **C,
                  int M, int K, int N,
                  int blockSize)
{
    int i, j, k;
    int ii, jj, kk;

    // Initialize result matrix
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            C[i][j] = 0;
        }
    }

    // Blocked Matrix Multiplication
    for (ii = 0; ii < M; ii += blockSize)
    {
        for (jj = 0; jj < N; jj += blockSize)
        {
            for (kk = 0; kk < K; kk += blockSize)
            {

                int iMax = (ii + blockSize < M) ? ii + blockSize : M;
                int jMax = (jj + blockSize < N) ? jj + blockSize : N;
                int kMax = (kk + blockSize < K) ? kk + blockSize : K;

                for (i = ii; i < iMax; i++)
                {
                    for (j = jj; j < jMax; j++)
                    {
                        for (k = kk; k < kMax; k++)
                        {
                            C[i][j] += A[i][k] * B[k][j];
                        }
                    }
                }
            }
        }
    }
}