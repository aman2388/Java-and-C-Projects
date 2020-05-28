#include <stdio.h>

//global variable
int i,j;
int row1, col1, row2, col2;
#define MAX_SIZE 10


void multiply();

void addition();

void determinant();

void transpose();

int main() {
    char input;

    printf("Enter A for Addition, M for Multiplication, D for Determinant, T for Transpose, R for RREf and I for Inverse\n");
    scanf("%c", &input);

    switch (input) {
        case 'M':
            multiply();
            break;
        case 'A':
            addition();
            break;
        case 'D':
            determinant();
            break;
        case 'T':
            transpose();
            break;

        default:
            printf("Not an input");

    }
    return 0;
}

void transpose() {
    int row, col;
    int A[MAX_SIZE][MAX_SIZE], transpose[MAX_SIZE][MAX_SIZE];

    printf("Enter the number of row and columns for the first matrix (Eg. 2 2)\n");
    scanf("%d %d", &row, &col);

    printf("Enter the numbers for the matrix\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Your original matrix:\n");
    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < row; ++i) {
        for (j = 0; j < col; ++j) {
            transpose[j][i] = A[i][j];
        }
    }

    printf("Transpose matrix:\n");
    for (i = 0; i < col; ++i) {
        for (j = 0; j < row; ++j) {
            printf("%d ", transpose[i][j]);
        }
        printf("\n");
    }
}

void determinant() {
    int size;
    long det;
    int A[3][3];

    printf("Enter the matrix dimension (Eg. 2 or 3)\n");
    scanf("%d", &size);

    if (size == 2){
        printf("Enter the numbers for the matrix\n");
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                scanf("%d", &A[i][j]);
            }
        }

        det = (A[0][0] * A[1][1]) - (A[0][1] * A[1][0]);
        printf("Det of A is = %ld", det);
    }
    else{
        printf("Enter the numbers for the matrix\n");
        for (i = 0; i < size; ++i) {
            for (j = 0; j < size; ++j) {
                scanf("%d", &A[i][j]);
            }
        }

        det = A[0][0] * ((A[1][1] * A[2][2]) - (A[2][1] * A[1][2])) - A[0][1] * (A[1][0] * A[2][2] - A[2][0] * A[1][2]) + A[0][2] * (A[1][0] * A[2][1] - A[2][0] * A[1][1]);

        printf("Det of A is = %ld", det);
    }

}

void addition() {
    int A[MAX_SIZE][MAX_SIZE];//First matrix
    int B[MAX_SIZE][MAX_SIZE];//Second matrix
    int C[MAX_SIZE][MAX_SIZE]; //Resulting matrix


    printf("Enter the number of row and columns for the first matrix (Eg. 2 2)\n");
    scanf("%d %d", &row1, &col1);

    printf("Enter the number of row and columns for the second matrix (Eg. 2 2)\n");
    scanf("%d %d", &row2, &col2);
        printf("Enter the numbers for the first matrix\n");
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col1; ++j) {
                scanf("%d", &A[i][j]);
            }
        }

        printf("Enter the numbers for the second matrix\n");
        for (i = 0; i < row2; ++i) {
            for (j = 0; j < col2; ++j) {
                scanf("%d", &B[i][j]);
            }
        }

        printf("The result of your matrix is: \n");
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col2; ++j) {
                C[i][j] = A[i][j] + B[i][j];
            }

        }

        //print the resulting matrix
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col2; ++j) {
                printf("%d\t", C[i][j]);
            }
            printf("\n");
        }

}

void multiply() {
    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];


    printf("Enter the number of row and columns for the first matrix (Eg. 2 2)\n");
    scanf("%d %d", &row1, &col1);

    printf("Enter the number of row and columns for the second matrix (Eg. 2 2)\n");
    scanf("%d %d", &row2, &col2);

    //check if 2 matrices are well defined
    if (col1 == row2){
        printf("Enter the numbers for the first matrix\n");
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col1; ++j) {
                scanf("%d", &A[i][j]);
            }
        }

        printf("Enter the numbers for the second matrix\n");
        for (i = 0; i < row2; ++i) {
            for (j = 0; j < col2; ++j) {
                scanf("%d", &B[i][j]);
            }
        }

        printf("The result of your matrix is: \n");
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col2; ++j) {
                C[i][j] = 0;
                for (int k = 0; k < col1; ++k) {
                    C[i][j] = C[i][j] + A[i][k] * B[k][j];
                }
            }

        }

        //print the resulting matrix
        for (i = 0; i < row1; ++i) {
            for (j = 0; j < col2; ++j) {
                printf("%d\t", C[i][j]);
            }
            printf("\n");
        }

    } else{
        printf("The matrices are not well defined");
    }

}
