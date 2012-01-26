// Copyright (C) 2011-2012, Haldo Spontón <haldos@fing.edu.uy>
// Copyright (C) 2011-2012, Juan Cardelino <juanc@fing.edu.uy>

//		+-------------------------------------+
//		| Generate a gaussian kernel (c file) |
//		| Implemented by Haldo Spontón		  |
//		+-------------------------------------+

#include <math.h> // exp
#include <stdlib.h> // malloc, calloc, free
#include <stdio.h> // fprintf

double *gaussian_kernel(int n, float sigma){
	
	double *kernel = malloc(n*n*sizeof(double));

	if (kernel == NULL){
		fprintf(stderr, "Out of memory...\n");
		exit(EXIT_FAILURE);
	}
	
	// Generation of the kernel
	int i;
	int fila, col, x, y;
	double suma = 0;
	int imax = n*n;
	for(i=0;i<imax;i++){
		fila = (int)(i/n);
		col = i-(n*fila);
		y = ((int)(n/2))-fila;
		x = col-((int)(n/2));
		kernel[i] = exp(-(x*x + y*y)/(2*sigma*sigma));
		suma += kernel[i];
	}

	for(i=0;i<n*n;i++){
		kernel[i] = kernel[i]/suma;
	}
	
	return kernel;
}

void free_gaussian_kernel(double* kernel){

	free(kernel);

}

double *LoG_kernel(int n, float sigma){
	
	double *kernel = malloc(n*n*sizeof(double));

	if (kernel == NULL){
		fprintf(stderr, "Out of memory...\n");
		exit(EXIT_FAILURE);
	}
	
	// Generation of the kernel
	int i;
	int fila, col, x, y;
	double suma = 0;
	int imax = n*n;
	for(i=0;i<imax;i++){
		fila = (int)(i/n);
		col = i-(n*fila);
		y = ((int)(n/2))-fila;
		x = col-((int)(n/2));
		kernel[i] = ( (x*x + y*y - 2*sigma*sigma)/(sigma*sigma*sigma*sigma) )*exp(-(x*x + y*y)/(2*sigma*sigma));
		suma += kernel[i];
	}

	//for(i=0;i<n*n;i++){
	//	kernel[i] = kernel[i]/suma;
	//	fprintf(stderr, "kernel[%d] = %f \n", i, kernel[i]);
	//}
	
	return kernel;
}
