#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../src/gemm.h"

int main()
{
    FILE *fp;
    int M, K, N;
    int i, j;
    int blockSize = 2;
    char filename[100];
    printf("Enter input file path: ");
    scanf("%99s", filename);
    fp = fopen(filename, "r");
    if (fp == NULL)
      {
        printf("Error: Cannot open input file.\n");
        return 1;
      }

    // Read matrix dimensions
    fscanf(fp, "%d %d %d", &M, &K, &N);

    //Allocate Matrix A
    int **A = (int **)malloc(M * sizeof(int *));
    for (i = 0; i < M; i++)
        A[i] = (int *)malloc(K * sizeof(int));

    // Allocate Matrix B
    int **B = (int **)malloc(K * sizeof(int *));
    for (i = 0; i < K; i++)
        B[i] = (int *)malloc(N * sizeof(int));

    // Allocate Result Matrix C
    int **C = (int **)malloc(M * sizeof(int *));
    for (i = 0; i < M; i++)
        C[i] = (int *)malloc(N * sizeof(int));

    // Read Matrix A
    for (i = 0; i < M; i++)
        for (j = 0; j < K; j++)
            fscanf(fp, "%d", &A[i][j]);

    // Read Matrix B
    for (i = 0; i < K; i++)
        for (j = 0; j < N; j++)
            fscanf(fp, "%d", &B[i][j]);

    fclose(fp);

    // ---------- Start Timer ----------
    clock_t start = clock();

    simpleGEMM(A, B, C, M, K, N);

    clock_t end = clock();
    // ---------- Stop Timer ----------

    double timeTaken = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
     printf("\n=====================================\n");
    printf("      Simple GEMM\n");
    printf("=====================================\n");

    printf("Result Matrix:\n");
    printMatrix(C, M, N);

    printf("\nExecution Time : %.6f ms\n", timeTaken);

     
    // BLOCKING GEMM

    start = clock();

    blockingGEMM(A, B, C, M, K, N, blockSize);

    end = clock();

    double blockTime =
        ((double)(end - start) * 1000) / CLOCKS_PER_SEC;

    printf("\n=====================================\n");
    printf("      BLOCKING GEMM\n");
    printf("=====================================\n");

    printMatrix(C, M, N);

    printf("\nExecution Time : %.6f ms\n", blockTime);

    // Free Memory
    for (i = 0; i < M; i++)
    {
        free(A[i]);
        free(C[i]);
    }

    for (i = 0; i < K; i++)
        free(B[i]);

    free(A);
    free(B);
    free(C);

    return 0;
}