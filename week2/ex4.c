#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_swap(int *n, int *m){
    int temp;
    temp = n;
    n = m;      
    m = temp;
    
    printf("\nn = %d, m = %d", n, m);
	
	return 0;	          
}

int main() {
   int n, m;
   
   printf("Enter two integers:\n");
   
   printf("n=");
   scanf("%d", &n);
   printf("nnn=%d", n);
   
   printf("\nm=");
   scanf("%d", &m);
   printf("\mmm=%d", m);
   
   int s = my_swap(n, m);
   
   return(0);
}


