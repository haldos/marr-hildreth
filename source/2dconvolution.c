
//		+-------------------------------------+
//		| Convolve image with kernel (c file) |
//		| Implemented by Haldo Spontón		  |
//		+-------------------------------------+

#include <stdlib.h> // malloc, calloc, free
#include <stdio.h> // fprintf

void free_neighborhood(double* neighborhood){
	
	free(neighborhood);

}

void free_neighbors_offsets(int* offsets){

	free(offsets);

}

int *get_neighbors_offset(int w, int n){
	
	int *aux = malloc(n*n*sizeof(int));
	int i, delta_fila, delta_col;
	int imax = n*n;
	int dif_fila_col = (n-1)/2;
	for (i=0;i<imax;i++){
		delta_fila = (int)(i/n)-dif_fila_col;
		delta_col = i-n*((int)(i/n))-dif_fila_col;
		aux[i] = delta_fila*w+delta_col;
	}

	return aux;
}

double *get_neighborhood(double *im, int pos, int n, int* offsets){
	
	double *aux = malloc(n*n*sizeof(double));

	if (aux == NULL){
		fprintf(stderr, "Out of memory...\n");
		exit(EXIT_FAILURE);
	}

	int i;
	int imax = n*n;
	for (i=0;i<imax;i++){
		aux[i] = im[pos+offsets[i]];
	}
	
	return aux;
}

double *conv2d(double *input, int w, int h, double *kernel, int n){
	
	// Zero-padding
	int wx = (w+2*(n-1));
	int hx = (h+2*(n-1));
	double *aux = calloc(wx*hx,sizeof(double));

	if (aux == NULL){
		fprintf(stderr, "Out of memory...\n");
		exit(EXIT_FAILURE);
	}

	int i,j,fila,col;
	int imax = wx*hx;
	for(i=0;i<imax;i++){
		fila = (int)(i/wx);
		col = i-(wx*fila);
		if ( (fila>=n-1)&&(col>=n-1)&&(fila<h+n-1)&&(col<w+n-1) ) {
			aux[i] = input[(col-n+1)+(w*(fila-n+1))];
		}
	}

	double *out = malloc((w+n-1)*(h+n-1)*sizeof(double));

	if (out == NULL){
		fprintf(stderr, "Out of memory...\n");
		exit(EXIT_FAILURE);
	}

	double acum = 0;
	int pos;
	// Convolution
	imax = (w+n-1)*(h+n-1);
	int jmax = n*n;
	int *offsets = get_neighbors_offset(wx, n);
	int dif_fila_col = (n-1)/2;
	for(i=0;i<imax;i++){
		fila = (int)(i/(w+n-1));
		col = i-((w+n-1)*fila);
		fila += dif_fila_col;
		col += dif_fila_col;
		pos = wx*fila + col;
		//double *neighborhood = get_neighborhood(aux, pos, n, offsets);
	
		// modificacion 1: hacer la funcion get_neighborhood in line en el bucle.
		// cambio adentro del for: en vez de pedir neighborhood[j] pido im[pos + offset[j]]
	
		acum = 0;
		for (j=0;j<jmax;j++){
			//acum += neighborhood[j]*kernel[j];
			acum += aux[pos+offsets[j]]*kernel[j];
		}
		out[i] = acum;
		//free_neighborhood(neighborhood);
	}
	
	free(aux);
	free_neighbors_offsets(offsets);
	return out;

}
