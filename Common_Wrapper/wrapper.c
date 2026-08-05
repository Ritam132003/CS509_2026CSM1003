#include <stdio.h>
#include <stdlib.h>

int main()
{
    int choice;

    printf("=====================================\n");
    printf("      CS509 Laboratory Wrapper\n");
    printf("=====================================\n");
    printf("1. Run Assignment 1 (GEMM)\n");
    printf("2. Exit\n");
    printf("=====================================\n");
    printf("Enter your choice: ");

    scanf("%d", &choice);

    switch(choice)
    {
        case 1:
            system("gemm.exe");
            break;

        case 2:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid Choice!\n");
    }

    return 0;
}