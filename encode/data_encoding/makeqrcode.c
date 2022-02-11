#include "makeqrcode.h"


char *init_matrix(int version, size_t *size_p)
{
    size_t nb_pixels = 21 + 4 * (version - 1);
    *size_p = nb_pixels;
    char *matrix = malloc(nb_pixels * nb_pixels * sizeof(char));
    if (matrix == NULL)
    {
        err(EXIT_FAILURE, "init_matrix: malloc()");
    }
    size_t size = nb_pixels * nb_pixels;
    for (size_t i = 0; i < size; i++)
    {
        matrix[i] = '2';
    }
    return matrix;
} 


void finder(char* mat, size_t size_p)
{
    __finder(mat, 0, 0, size_p);
    __finder(mat, size_p-7, 0, size_p);
    __finder(mat, 0, size_p-7, size_p);
}

void __finder(char* mat, size_t i, size_t j, size_t size_p)
{
    for(size_t x=0; x<7; x++)
    {
        for(size_t y=0; y<7; y++)
        {	    		
            if( x>=2 && x <= 4 && y>=2 && y <= 4)
            {
                mat[(x+i)*size_p+y+j]='1';
            }
	    	   	    
	    else{
		    if(y == 0 || y == 6 || x == 0 || x == 6)
			mat[(x+i)*size_p+y+j]='1'; 

	    
	    		else
			  mat[(x+i)*size_p+y+j]='0';
	    }			    
        }
    }
    /*
    for(size_t x=0; x<8; x++)
    {
	for(size_t y=0; y<8; y++)
	{
		if( x == 7 || y == 7)
			mat[(x+i)*size_p+y+j]='0'; 
	}


    }
    */
   if( j == 0 && i == 0)
   {
    
    for(size_t x = 0; x<8; x++)
    {
	size_t y = size_p-8;
	mat[(x+i)*size_p+y+j]='0';
    }
    for(size_t y = 0; y<8; y++)
    {
	size_t x = size_p-8;
	mat[(x+i)*size_p+y+j]='0';
    }
   }
   /*
   else
   {
	   
	if( j==0 && i == size_p-7)
	{
		for(size_t x = 0; x<8; x++)
    			{
			size_t y = size_p-8;
			mat[(x+i)*size_p+y+j]='0';
    			}
    			for(size_t y = 0; y<8; y++)
    			{	
			size_t x = size_p-8;
			mat[(x+i)*size_p+y+j]='0';
    			}


	}


   }
   */
    


}

