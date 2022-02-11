#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#define _GNU_SOURCE
#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encode_string.h"

// Conversion from binary to decimal
unsigned int bin_to_dec(char *data);

// Main function for build the error correction
int* message_polynomial(struct encdata* qr,int* dec_data);

//Function that give generator poly based on nb error codewords needed
int* generator_polynomial(size_t error_codewords, int* gen_data);

#endif
