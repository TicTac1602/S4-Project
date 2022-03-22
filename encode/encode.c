#include "encode.h"

void setPixel(SDL_Surface *surface, Uint8 r, Uint8 g, Uint8 b, size_t x,
              size_t y)
{
    Uint32* pixels = surface->pixels; 
    Uint32 couleur = SDL_MapRGB(surface->format, r, g, b);
    pixels[y * surface->w + x] = couleur;
}

void print_struct(struct encdata *qr){
    printf("version = %d\n", qr->version);
    printf("mode indicator = %d\n", qr->mi);
    printf("size of input string = %lu\n", qr->size);
    printf("corection_level = %c\n", qr->correction_level);
    //more later;
}

void print_matrix(char *matrix, size_t *size_p)
{
    printf("=================================================\n");
    size_t size = *size_p;
    for (size_t i = 0; i < *size_p; i++)
    {
        for (size_t j = 0; j < *size_p; j++)
        {
            if (matrix[i * size + j] == '0')
                printf(" 0");
            else if (matrix[i * size + j] == '1')
            {
                printf(" 1");
            }
            else
            {
                printf(" 2" );
            }
        }
        printf("\n");
    }
    printf("=================================================\n");
}


int main(int argc,char *argv[])
{
    if(argc != 2){
	errx(EXIT_FAILURE,"Too few/much argument");
    }
    char* s=argv[1] ;

    // Data encoding
    struct encdata *qr = data_encoding(s, "M");
    printf("================= Encode message =================\n");

    int *final = final_struct(qr);
    size_t t = qr->block1 + qr->block2;
    size_t f = final_byte(qr->version);
    size_t all =
        (qr->block1 * qr->group1 + qr->block2 * qr->group2 + t * qr->ec) * 8
        + f;
    print_struct(qr);
    for (size_t i = 0; i < all; i++)
    {
        printf("%d", final[i]);
    }
    printf("\n");

    size_t size_matrix;
    char* matrix = init_matrix(qr->version, &size_matrix);
    finder(matrix, size_matrix);
    alignement(qr->version, matrix,size_matrix);
     
    
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        errx(1, "Could not initialize SDL: %s.\n", SDL_GetError());
    //Create surface
    SDL_Surface *surface = SDL_CreateRGBSurface(0,size_matrix,size_matrix,
            32, 0, 0, 0, 0);
    if (surface == NULL) {
        errx(1,"SDL_CreateRGBSurface() failed: %s\n", SDL_GetError());
        exit(1);
    }
    //Make surface all white
    SDL_FillRect(surface, NULL, SDL_MapRGB(surface->format, 255, 255, 255));
    //Lock the surface to set manually the dark spot
    SDL_LockSurface(surface);

    for (size_t x = 0; x < size_matrix; x++){
        for (size_t y = 0; y < size_matrix; y ++)
        {
            if (matrix[x * size_matrix + y] == '1')
            {
                setPixel(surface, 0, 0, 0, x, y);
            }
        }
    }
    SDL_SaveBMP(surface, "out.bmp");
    SDL_FreeSurface(surface);
    return 0;
}
