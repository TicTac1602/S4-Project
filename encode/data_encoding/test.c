#include "encode_string.h"

int main(char* argv){
    struct encdata *qr = data_encoding(s, "M");
    print_struct(qr);
    return 1;
}

void print_struct(struct encdata *qr){
    printf("version = %d\n", qr->version);
    printf("mode inficator = %c\n", qr->mi);
    printf("size of input string = %lu\n", qr->size);
    printf("corection_level = %c\n", qr->correction_level);
    printf("length of data = %d\n", qr->len;
    printf("necessary length of data = %d\n", qr->nlen);
    printf("data = %c\n", qr->data);
    //more later;
}