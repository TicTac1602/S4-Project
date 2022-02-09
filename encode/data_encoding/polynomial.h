#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "encode_string.h"

// Conversion from binary to decimal
unsigned int bin_to_dec(char *data);

// Main function for build the error correction
void message_polynomial(struct encdata *qr);

#endif
