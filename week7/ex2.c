#include <stdlib.h>
#include<stdio.h>


int main(){

	// Allows user to specify the original array size, stored in variable n1.
	printf("Enter Array size:");
	int N;
	scanf("%d",&N);
	
	int arr[N];
	
	int* m = malloc(N*sizeof(int));
	
	printf("Array is allocated with address %p\n",m);
	for(int i=0;i<N;++i)
	{
		m[i] = i;
		printf("Index: #%d element in memory address: %p with value = %d\n",i,(m+i),m[i]);
	}
	free(m);

	
	return 0;
	
}
	
	
