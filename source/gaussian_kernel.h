
//		+------------------------------------------+
//		| Generate a gaussian kernel (header file) |
//		| Implemented by Haldo Spontón		       |
//		+------------------------------------------+


double *gaussian_kernel(int n, float sigma);
// input:
//			int n			-	size of kernel
//			float sigma		-	standard deviation of gaussian function
// output:
//			double *xxxx	-	n*n kernel array

void free_gaussian_kernel(double* kernel);
// input:
//			double* kernel	-	n*n kernel array, generated with function
//								gaussian_kernel.
