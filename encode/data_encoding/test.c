#include "encode_string.h"
#include "polynomial.h"

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

int main(int argc,char *argv[]){
    if(argc != 2){
	errx(EXIT_FAILURE,"Too few/much argument");
    }
    char* s=argv[1] ;
    struct encdata *qr = data_encoding(s, "M");
    print_struct(qr);
    // Encode Message polynomial
    message_polynomial(qr);
	
    return 1;
}
