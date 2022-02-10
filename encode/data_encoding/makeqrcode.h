#ifndef MAKEQRCODE_H
#define MAKEQRCODE_H

#include "encode_string.h"

char *init_matrix(int version, size_t *size_p);

void finder(char* mat, size_t size_p);

void __finder(char* , size_t i, size_t j, size_t size_p);



#endif
