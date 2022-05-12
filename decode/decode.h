#ifndef DECODE_H
#define DECODE_H

int **matrix; //2d matrix that represents the QrCode.
size_t N; //Matrix size (of a side).
size_t V; //QrCode version.

size_t encodingMode;

size_t ECC; // Error Correction level
size_t mask; // Mask of the QrCode


size_t dataLength; //Length of the data in bits
char *data; // String representing our data in an bit-array form.


size_t charIndicatorLength; // Length of the charIndicator in bits
size_t charIndicator; // Length of the message in letters


void initFromFile(char *path);
void initFromChar(char* matrix, size_t len);
void freeMatrix();
void freeDecodeAll();
int getCharIndicatorLength();
void initPosition(size_t version);
int getYDir(int x, int y);
int isInAligmentPattern(size_t x, size_t y);
void printMatrix();
int dataSquares(int iStart, int jStart, int iEnd, int jEnd);
void getFormat();
int mustSkip();
int isModuleData(int x, int y);
void invert(int x, int y);
void unMask(int mask);
void extractData(int xDecrement, int startRow);
void getDataLength();
char alphaToChar(char alphaIndex);
char* getFinalMessage();
char* decode();

#endif
