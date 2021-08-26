#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main () {
   int n, m;
   char input[100];
   
   printf("Enter height of pyramid, n=");
   
   fgets(input, 100, stdin);

   
   sscanf(input, "%d", &n );
   int i, j, k;
   
   m=n;  
   
   printf("\nPyramid:\n");
   for(i=1;i<=n;i++)  
   {  
       for(j=1;j<=m-1;j++)  
       {  
           printf(" ");  
       }  
       for(k=1;k<=2*i-1;k++)  
       {  
         printf("*");  
       }  
       m--;  
     
      printf("\n");  
    }  
   
   return(0);
}
