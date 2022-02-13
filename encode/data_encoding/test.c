#include "encode_string.h"
#include "polynomial.h"
#include "makeqrcode.h"

void print_struct(struct encdata *qr){
    printf("version = %d\n", qr->version);
    printf("mode indicator = %d\n", qr->mi);
    printf("size of input string = %lu\n", qr->size);
    printf("corection_level = %c\n", qr->correction_level);
    printf("length of data = %ld\n", qr->len);
    printf("necessary length of data = %ld\n", qr->nlen);
    printf("data = %s\n", qr->data);
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


int main(int argc,char *argv[]){
    if(argc != 2){
	errx(EXIT_FAILURE,"Too few/much argument");
    }
    char* s=argv[1] ;
    struct encdata *qr = data_encoding(s, "M");
    print_struct(qr);
    // Encode Message polynomial
    int message[qr->nlen/8];
    message_polynomial(qr,message);
    //Encode Generator polynomial 
    //int generator[qr->ec];
    //generator_polynomial(qr->ec,generator); 

    size_t test1;
    char* matrixtest = init_matrix(qr->version, &test1);

    print_matrix(matrixtest, &test1);

    finder(matrixtest, test1);

    alignement(qr->version, matrixtest,test1);


    print_matrix(matrixtest, &test1);



    return 1;
}
