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


void finder(char* mat, size_t size_p)
{
    __finder(mat, 0, 0, size_p);
    __finder(mat, size_p-7, 0, size_p);
    __finder(mat, 0, size_p-7, size_p);
}

void __finder(char* , size_t i, size_t j, size_t size_p)
{
    for(size_t x, x<=7, x++)
    {
        for(size_t y, y<=7, y++)
        {
            if(i == 0 || i == 7 || j == 0 || j == 7 ||
            (2 <= i && i <= 5 && j>=2 && j <= 5))
            {
                mat[(x+i)*size_p+y+j]=1;
            }

            else
            {
                mat[(x+i)*size_p+y+j]=0;
            }


        }

    }



}