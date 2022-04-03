#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void printMatrix(int *matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%i ", matrix[i * N + j]);
        printf("\n");
    }
    printf("\n");
}

void invert(int *matrix, int i, int j, int N)
{
    matrix[i * N + j] = (matrix[i * N + j] == 0 ? 1 : 0);
}

void unMask(int mask, int *matrix, int N)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (mask == 0 && ((i + j) % 2 == 0))
                invert(matrix, i, j, N);
            else if (mask == 1 && (i % 2 == 0))
                invert(matrix, i, j, N);
            else if (mask == 2 && (j % 3 == 0))
                invert(matrix, i, j, N);
            else if (mask == 3 && ((i + j) % 3 == 0))
                invert(matrix, i, j, N);
            else if (mask == 4 && ((i / 2 + j / 3) % 2 == 0))
                invert(matrix, i, j, N);
            else if (mask == 5 && ((((i * j) % 2) + ((i * j) % 3)) == 0))
                invert(matrix, i, j, N);
            else if (mask == 6 && (((((i * j) % 2) + ((i * j) % 3)) % 2) == 0))
                invert(matrix, i, j, N);
            else if (mask == 7 && (((((i + j) % 2) + ((i * j) % 3)) % 2) == 0))
                invert(matrix, i, j, N);
        }
    }
}

int toDecimal(int bitArray[], int length)
{
    int res = 0;
    for (int i = 0; i < length; i++)
        res = (res << 1) + bitArray[i];
    return res;
}


int dataSquares(int iStart, int jStart, int iEnd, int jEnd, int *matrix, int N)
{
    int res = 0;
    int iIncrement = iEnd > iStart ? 1 : -1;
    int jIncrement = jEnd > jStart ? 1 : -1;

    for (int i = iStart; i != (iEnd + iIncrement); i += iIncrement)
    {
        for (int j = jStart; j != (jEnd + jIncrement); j += jIncrement)
        {
            res = (res << 1) + matrix[i * N + j];
        }
    }
    return res;
}

void decode(char *path)
{
    FILE *file = fopen(path, "r");
    int *matrix;
    size_t total = 0;
    int c;

    // ---------------------------------------------
    // FILL THE MATRIX
    if (file == NULL) return; //could not open file
    fseek(file, 0, SEEK_END);
    long f_size = ftell(file);
    fseek(file, 0, SEEK_SET);
    matrix = malloc(f_size);

    while ((c = fgetc(file)) != EOF) {
        if (c == '1' || c == '0') 
        {
                matrix[total++] = c - '0';
        }
    }
    fclose(file);
    // ---------------------------------------------
    
    size_t N = (size_t) sqrt((double) total);

    printMatrix(matrix, N);
    printf("QrCode is size N*N, with N = %lu\n", N);
        
    /*
    ** Knowing the equation N = (((V-1)*4)+21)
    ** We can compute the version V
    */

    size_t V = (N-21) / 4 + 1;

    printf("QrCode is version V, with V = %lu\n", V);

    int errorCorrection = (matrix[8*N + 0] << 1) + matrix[8 * N + 1];

    printf("QrCode has an error correction of  %i\n", errorCorrection);

    int mask = (matrix[8 * N + 2] << 2) + (matrix[8 * N + 3] << 1) + (matrix[8 * N + 4]);

    printf("QrCode has a mask pattern of %i\n", mask);
     
    printf("UnMasking QrCode... \n");
    unMask(mask, matrix, N);
    printf("UnMasking Done !\n");

    printMatrix(matrix, N);

    int encodingMode = dataSquares(N-1, N-1, N-2, N-2, matrix, N);

    printf("QrCode has an encoding mode of %i\n", encodingMode);
    
    int messageLength = dataSquares(N-3, N-1, N-6, N-2, matrix, N);
    printf("QrCode has a message length of %i\n", messageLength);


    int firstLetter = dataSquares(N-7, N-1, N-4, N-2, matrix, N);
    firstLetter += 1;

    printf("First letter is H\n");

    free(matrix);
}


int main()
{
    decode("matrix.txt");
    return 0;
}
