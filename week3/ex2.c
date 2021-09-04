#include <stdio.h>

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}


void bubble_sort(int arr[], int n)
{
	int i, j;
	for (i = 0; i < n-1; i++)	
		for (j = 0; j < n-i-1; j++)
			if (arr[j] > arr[j+1])
				swap(&arr[j], &arr[j+1]);
}

void print_array(int arr[], int arr_size)
{
	int i;
	for (i=0; i < arr_size; i++)
		printf("%d ", arr[i]);
	printf("\n\n");
}

int main()
{
	int arr[] = {64, 34, 25, 12, 22, 11, 90};
	int n = sizeof(arr)/sizeof(arr[0]);
	
	printf("Initial array:\n");
	print_array(arr, n);
	
	bubble_sort(arr, n);
	printf("Array after bubble sort: \n");
	
	print_array(arr, n);

	return 0;
}

