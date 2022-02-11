#include "polynomial.h"

unsigned int bin_to_dec(char *data)
{
    unsigned int s = 0;
    unsigned int compt = 1;
    for (unsigned int i = 8; i > 0; i--)
    {
        s += (data[i - 1]-48) * compt;
        compt *= 2;
    }
    return s;
}

int* message_polynomial(struct encdata* qr,int* dec_data){
	char* tmp=qr->data;
	printf("POLYNOMIAL MESSAGE\n");
	for(size_t i=0;i<qr->nlen/8;i++){
		dec_data[i] = bin_to_dec(tmp);
		tmp += 8;
		printf("%d ",dec_data[i]);	
	}
	printf("\n");
	printf("================================\n");
	return dec_data;
}

int* generator_polynomial(size_t error_codewords, int* gen_data){
    char *line = NULL;
    size_t buf_len = 132;
    FILE *file = fopen("./generator", "r");
    if (file == NULL)
        errx(EXIT_FAILURE, "path doesn't exist");
    printf("POLYNOMIAL GENERATOR\n");
    while (getline(&line, &buf_len, file) != -1)
    {
	char start[2];
	char* temp =line;
	sscanf(temp,"%2c",start);
	temp += 2;
	if((size_t)atoi(start) == error_codewords){
		int red;		
		for(size_t i=0; i<=error_codewords;i++){
			sscanf(temp,"%d ",&red);
			temp+=4;
			gen_data[i] = red;
			printf("%d ",gen_data[i]);
		}
	}
    }
    printf("\n");
    free(line);
    fclose(file);
    return gen_data;
}
