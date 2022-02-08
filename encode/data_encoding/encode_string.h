#ifndef ENCODE_STRING_H
#define ENCODE_STRING_H

#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct encdata
{
    // Version of the QR code.
    int version;

    // Mode indicator.
    // 1 -> byte mode
    char mi;

    // Length of the input string.
    size_t size;

    // Error correction level.
    char correction_level;

    // Length of the encoded data.
    size_t len;

    // Length necessary for the encoded data.
    size_t nlen;

    // Encoded data (binary).
    char *data;

    // Error correction Codewords Per Block
    size_t ec;

    // Number of blocks in group 1
    size_t block1;

    // Number of Data Codewords in Each of Group 1's Blocks
    size_t group1;

    // Number of Blocks in Group 2
    size_t block2;

    // Number of Data Codewords in Each of Group 2's Blocks
    size_t group2;
};

// Return (1) if the input can be encoded in byte mode.
// Otherwise return (0).
int check_input(char *input);

#endif