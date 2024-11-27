#include <stdio.h>

#define MAX 10

void multiplyMatrices(int first[][MAX], int second[][MAX], int result[][MAX], int firstRow, int firstCol, int secondRow, int secondCol)
{
    for (int i = 0; i < firstRow; i++)
    {
        for (int j = 0; j < secondCol; j++)
        {
            result[i][j] = 0;
        }
    }

    for (int i = 0; i < firstRow; i++)
    {
        for (int j = 0; j < secondCol; j++)
        {
            for (int k = 0; k < firstCol; k++)
            {
                result[i][j] += first[i][k] * second[k][j];
            }
        }
    }
}

void printMatrix(int matrix[][MAX], int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int first[MAX][MAX], second[MAX][MAX], result[MAX][MAX];
    int firstRow, firstCol, secondRow, secondCol;

    printf("Enter number of rows and columns of first matrix: ");
    scanf("%d %d", &firstRow, &firstCol);

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < firstRow; i++)
    {
        for (int j = 0; j < firstCol; j++)
        {
            scanf("%d", &first[i][j]);
        }
    }

    printf("Enter number of rows and columns of second matrix: ");
    scanf("%d %d", &secondRow, &secondCol);
    if (firstCol != secondRow)
    {
        printf("Matrix multiplication is not possible.\n");
        return 0;
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < secondRow; i++)
    {
        for (int j = 0; j < secondCol; j++)
        {
            scanf("%d", &second[i][j]);
        }
    }

    // Multiply matrices
    multiplyMatrices(first, second, result, firstRow, firstCol, secondRow, secondCol);

    // Print the result
    printf("Resultant Matrix:\n");
    printMatrix(result, firstRow, secondCol);

    return 0;
}
