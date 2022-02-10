#include "makeqrcode.h"


char *init_matrix(int version, size_t *size_p)
{
    size_t nb_pixels = 21 + 4 * (version - 1);
    *size_p = nb_pixels;
    char *matrix = malloc(nb_pixels * nb_pixels * sizeof(char));
    if (matrix == NULL)
    {
        err(EXIT_FAILURE, "init_matrix: malloc()");
    }
    size_t size = nb_pixels * nb_pixels;
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = '2';
    }
    return matrix;
} 


void finderpath(struct encdata *qr, int mat[][], int i, int j)
{
    int V = qr->version;

    //first square
    for (size_t i = 0; i < count; i++)
    {
        break;
    }
    
}