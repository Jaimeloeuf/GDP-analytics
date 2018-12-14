#include <stdlib.h>
#include <stdio.h>

int main() 
{
   int **mat;
   int rows, cols, i, j;
   printf("Enter the no. of rows : ");
   scanf("%d", &rows);
   printf("Enter the no. of columns : ");
   scanf("%d", &cols);
   
   /* dynamically allocate memory for a matrix of size rows by columns */
   mat = calloc( rows, sizeof(char*) );
   for ( i = 0; i < rows; i++ ) {
      mat[i] = calloc( cols, sizeof(char) );
   }

   /* input matrix elements */
   for ( i = 0; i < rows; i++ ) {
      for ( j = 0; j < cols; j++ ) {
         printf("mat[%d][%d] : ", i, j);
         scanf("%c", &mat[i][j]);
      }
   }
   /* display matrix */
   printf("\nYou have entered :- \n");
   for ( i = 0; i < rows; i++ ) {
      for ( j = 0; j < cols; j++ ) {
         printf("%c  ", mat[i][j]);
      }
      printf("\n");
   }
   /* deallocate (free) the memory */
   for ( i = 0; i < rows; i++ ) {
      free(mat[i]);
   }

   free(mat);
   mat = NULL;
   if(mat == NULL)
      printf("pointer is freed and points to NULL\n");

   return 0;
}

First you have to create an array of char pointers, one for each string (char *):

char **array = malloc(totalstrings * sizeof(char *));

Next you need to allocate space for each string:

int i;
for (i = 0; i < totalstrings; ++i) {
    array[i] = (char *)malloc(stringsize+1);
}


T **a = malloc(N * sizeof *a);
if (a)
  for (i = 0; i < N; i++)
    a[i] = malloc(M * sizeof *a[i]);

char** stringList = (char**)malloc(totalStrings * sizeof(char*));

for( i=0; i<totalStrings; i++ ) {
  stringList[i] = (char*)malloc(stringSize[i]+1);
}


char **string = malloc(nlines * sizeof(char *));
string[0] = malloc(nlines * nletters);
for(i = 1; i < nlines; i++)
    string[i] = string[0] + i * nletters;  



{
//r=number of rows
//c=number of columns
char **arr = calloc(r, sizeof(char *));
for (i=0; i<r; i++)
     arr[i] = calloc(r, sizeof(char));
}



{
   //get input for the number of strings, which is basically numberOfSectors
   char** sectornames = /*(char**)*/ malloc(sizeof(char*) * numberOfSectors);
   for(int i = 0; i<numberOfSectors; i++) // allocating memory space
   {
      //then iterate through and allocate 'max_line_length' number of characters to each pointer in the array
      sectornames[i] = malloc(sizeof(char) * max_line_length);
      if(sectornames[i] != NULL)
         printf("memory allocated\n");
   }

   for(int i = 0; i<numberOfSectors; i++)
   {
      // assigning strings to each one of the pointer in the array
      sectornames[i] = "hello ";
   }

   for(int i = 0; i<numberOfSectors; i++)
   {
      // Printing out the strings by one pointer at a time
      printf("The string at position %d is %s\n", i, sectornames[i]);
   }

   //iterate again, freeing each index
   for(int i = 0; i<numberOfSectors; i++)
      free(sectornames[i]);

   //free the main handle
   free(sectornames);
}