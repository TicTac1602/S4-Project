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

    //separator

    for(size_t y=8; y<size_p-8; y++)
    {
	size_t x= 6;
	if(y%2==0)
		mat[(size_p*y+x)]='1';

	if(y%2==1)
		mat[(size_p*y+x)]='0';	
    }

    for(size_t x=8; x<size_p-8; x++)
    {
	size_t y= 6;
	if(x%2==0)
		mat[(size_p*y+x)]='1';

	if(x%2==1)
		mat[(size_p*y+x)]='0';

    }

    for(size_t y=0; y<8; y++)
    {
	size_t x=7;
	mat[(size_p*y+x)]='0';
	mat[(size_p*x+y)]='0';
	mat[size_p*x+y+size_p-8]='0';
	mat[size_p*(y+size_p-8)+x]='0';
    }

    //dark module
    
    mat[size_p*(size_p-8)+8]='1';

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
	    	   	    
	    else
	    {
		    if(y == 0 || y == 6 || x == 0 || x == 6)
			mat[(x+i)*size_p+y+j]='1'; 

	    
	    		else
			  mat[(x+i)*size_p+y+j]='0';
	    }			    
        }
    }
    //separator 
    
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
   
}


void alignement(int version, char* mat, size_t size_p)
{

int tab[][8]={{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{6,18,0,0,0,0,0,0},{6,22,0,0,0,0,0,0},{6,26,0,0,0,0,0,0},{6,30,0,0,0,0,0,0},{6,34,0,0,0,0,0,0},{6,22,38,0,0,0,0,0},{6,24,42,0,0,0,0,0},{6,26,46,0,0,0,0,0},{6,28,50,0,0,0,0,0},{6,30,54,0,0,0,0,0},{6,32,58,0,0,0,0,0},{6,34,62,0,0,0,0,0},{6,26,46,66,0,0,0,0},{6,26,48,70,0,0,0,0},{6,26,50,74,0,0,0,0},{6,30,54,78,0,0,0,0},{6,30,56,82,0,0,0,0},{6,30,58,86,0,0,0,0},{6,34,62,90,0,0,0,0}};

for(int i=0; tab[version][i]>0;i++)
{
	for(int j= 0; tab[version][j]>0;j++)
	{
		int a = tab[version][i];
		int b = tab[version][j];

		/*_align(a, b, mat, size_p);

		if(mat[size_p*b+a-2]=='2' && mat[size_p*b+a-1]=='2' && mat[size_p*b+a+1]=='2' && mat[size_p*b+a+2]=='2' && mat[size_p*b+a]=='2')
		{
			_align(a, b, mat, size_p);	

		}

		if(mat[size_p*b+a-2]=='1' && mat[size_p*b+a-1]=='0' && mat[size_p*b+a+1]=='0' && mat[size_p*b+a+2]=='1' && mat[size_p*b+a]=='1')
		{
			_align(a, b, mat, size_p);	

		}

		if(mat[size_p*b+a-2]=='0' && mat[size_p*b+a-1]=='1' && mat[size_p*b+a+1]=='1' && mat[size_p*b+a+2]=='0' && mat[size_p*b+a]=='0')
		{
			_align(a, b, mat, size_p);	
	
		}
		*/

		//int size;
		//size = (int) size_p;

		if( mat[size_p*(a+2)+(b+2)] =='2' && mat[size_p*(a+2)+(b-2)] == '2' && mat[size_p*(a-2)+(b-2)] =='2' && mat[size_p*(a-2)+(b+2)] == '2')
			_align(a, b, mat, size_p);
		/*else
		{
			if((a!=6 && b!=6) && (a != size-6 && b!=6) && (a!=6 && b!= size-6))
				_align(a, b, mat, size_p);	
			

		}	
		*/




	}
	
}

}

void _align(int i, int j, char* mat, size_t size_p)
{

j=j-2;
i=i-2;

for(size_t x=0; x<5; x++)
    {
        for(size_t y=0; y<5; y++)
        {	    		
            
		 if(y == 0 || y == 4 || x == 0 || x == 4)
		 {
			mat[(x+i)*size_p+y+j]='1'; 
			
		 }

		 else
		 {
		 	if(x == 2 && y == 2)
			 	mat[(x+i)*size_p+y+j]='1';

		 	else
				mat[(x+i)*size_p+y+j]='0';

	 	 }	 	 			    
        }
    }
}


void reserved(int version, char* mat, size_t size_p){









}

void fill_matrix(int* data,size_t size){
	
}


