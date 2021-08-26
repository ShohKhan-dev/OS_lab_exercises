#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
	
	int i;
	float f;
	double d;
	
	i = INT_MAX;
	f = FLT_MAX;
	d = DBL_MAX;
	
	
	printf("SIZES:\nint: %lu\nfloat: %lu\ndouble:%lu\n\n", sizeof(i), sizeof(f), sizeof(d));
	printf("VALUES:\nint: %d\nfloat: %0.6f\ndouble:%0.6lf\n", i, f, d);

	
	
	
	return 0;
}
