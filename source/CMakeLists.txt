SET(LIBS iio gaussian_kernel 2dconvolution)
ADD_LIBRARY(iio SHARED iio.c iio.h)
ADD_LIBRARY(gaussian_kernel SHARED gaussian_kernel.c gaussian_kernel.h)
ADD_LIBRARY(2dconv SHARED 2dconvolution.c 2dconvolution.h)
