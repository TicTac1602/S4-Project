#include "data_masking.h"

struct mask *init_mask(char *qr, size_t size)
{
    struct mask *mask = malloc(sizeof(struct mask));
    if (mask == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask0 = malloc(size * size);
    if (mask->mask0 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask1 = malloc(size * size);
    if (mask->mask1 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask2 = malloc(size * size);
    if (mask->mask2 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask3 = malloc(size * size);
    if (mask->mask3 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask4 = malloc(size * size);
    if (mask->mask4 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask5 = malloc(size * size);
    if (mask->mask5 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask6 = malloc(size * size);
    if (mask->mask6 == NULL)
        err(EXIT_FAILURE, "mask");

    mask->mask7 = malloc(size * size);
    if (mask->mask7 == NULL)
        err(EXIT_FAILURE, "mask");

    for (size_t i = 0; i < size * size; i++)
    {
        if (qr[i] == 3)
        {
            mask->mask0[i] = 1;
            mask->mask1[i] = 1;
            mask->mask2[i] = 1;
            mask->mask3[i] = 1;
            mask->mask4[i] = 1;
            mask->mask5[i] = 1;
            mask->mask6[i] = 1;
            mask->mask7[i] = 1;
        }
        else
        {
            mask->mask0[i] = qr[i];
            mask->mask1[i] = qr[i];
            mask->mask2[i] = qr[i];
            mask->mask3[i] = qr[i];
            mask->mask4[i] = qr[i];
            mask->mask5[i] = qr[i];
            mask->mask6[i] = qr[i];
            mask->mask7[i] = qr[i];
        }
    }

    return mask;
}

void apply_mask(struct mask *mask, char *m, size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        for (size_t j = 0; j < size; j++)
        {
            if (mask->mask0[i * size + j] == 2)
            {
                if ((i + j) % 2 == 0)
                {
                    mask->mask0[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask0[i * size + j] = m[i * size + j];
                }

                if (i % 2 == 0)
                {
                    mask->mask1[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask1[i * size + j] = m[i * size + j];
                }

                if (j % 3 == 0)
                {
                    mask->mask2[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask2[i * size + j] = m[i * size + j];
                }

                if ((i + j) % 3)
                {
                    mask->mask3[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask3[i * size + j] = m[i * size + j];
                }

                if (((i / 2) + (j / 3)) % 2 == 0)
                {
                    mask->mask4[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask4[i * size + j] = m[i * size + j];
                }

                if ((i * j) % 2 + (i * j) % 3 == 0)
                {
                    mask->mask5[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask5[i * size + j] = m[i * size + j];
                }

                if (((i * j) % 2 + (i * j) % 3) % 2 == 0)
                {
                    mask->mask6[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask6[i * size + j] = m[i * size + j];
                }

                if (((i * j) % 3 + (i + j) % 2) % 2 == 0)
                {
                    mask->mask7[i * size + j] = (m[i * size + j] + 1) % 2;
                }
                else
                {
                    mask->mask7[i * size + j] = m[i * size + j];
                }
            }
        }
    }
}

void free_mask(struct mask *mask)
{
    free(mask->mask0);
    free(mask->mask1);
    free(mask->mask2);
    free(mask->mask3);
    free(mask->mask4);
    free(mask->mask5);
    free(mask->mask6);
    free(mask->mask7);
    free(mask);
}
