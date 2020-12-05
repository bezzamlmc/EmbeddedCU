/******************************************************************************
 * Copyright (C) 2017 by Alex Fosdick - University of Colorado
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain this copyright. Users are 
 * permitted to modify this and use it to learn about the field of embedded
 * software. Alex Fosdick and the University of Colorado are not liable for any
 * misuse of this material. 
 *
 *****************************************************************************/
/**
 * @file stats.c
 * @brief Implementation of the statistical analytics function
 *
 * Statistical analytics library that operates on arrays of unsigned char data
 * The main application reports statistics to the command line: minimum, 
 * maximum, mean and median
 *
 * @author Laura Bezzam
 * @date November 16 2020
 *
 */



#include <stdio.h>
#include <stdlib.h>
#include "platform.h"
#include "stats.h"

/* Size of the Data Set */
#define SIZE (40)

#if defined M1
void main() {

  unsigned char test[SIZE] = { 34, 201, 190, 154,   8, 194,   2,   6,
                              114, 88,   45,  76, 123,  87,  25,  23,
                              200, 122, 150, 90,   92,  87, 177, 244,
                              201,   6,  12,  60,   8,   2,   5,  67,
                                7,  87, 250, 230,  99,   3, 100,  90};

	PRINTF("The unsorted array has %d elements and values:\n",SIZE);
	print_array(test, SIZE);
	PRINTF("\n");
	print_statistics(test, SIZE);
//NOTE: decided not implement sort in place
	unsigned char *sorted = sort(test,SIZE);
	PRINTF("\nThe sorted array has %d elements and values:\n",SIZE);
	print_array(sorted,SIZE);
}
#endif


/* stats implementation */

/* Compare function for qsort */
int compare (const void *a, const void *b) 
{
	unsigned char val1 = *(unsigned char*)a;
	unsigned char val2 = *(unsigned char*)b;
	if (val1 < val2)
		return 1;
	if (val1 > val2)
		return -1;
	return 0;
}

void print_statistics(unsigned char *dataset, const int len)
{
	PRINTF("Minimum: %hhu\n",find_minimum(dataset,len));
	PRINTF("Maximum: %hhu\n",find_maximum(dataset,len));
	PRINTF("Mean   : %hhu\n",find_mean(dataset,len));
	PRINTF("Median : %hhu\n",find_median(dataset,len));
}

void print_array(unsigned char *dataset, const int len)
{
#if defined VERBOSE
	for(int i=0; i<len; i++) {
		PRINTF("%d: %hhu",i,dataset[i]);
		if ((i>0 && i%8==0) || i==(len-1))
			PRINTF("\n");
		else
			PRINTF(", ");
	}
#endif
}

unsigned char find_median(unsigned char *dataset, const int len)
{
	unsigned char *sorted = sort(dataset,len);
	int i = len/2;
	return sorted[i];
	free(sorted);
}

unsigned char find_mean(unsigned char *dataset, const int len)
{
	short int mean = 0;
	for(int i=0; i<len; i++)
		mean = mean + dataset[i];
	mean = mean/len;
	return (unsigned char)mean;
}

unsigned char find_maximum(unsigned char *dataset, const int len)
{
	unsigned char max=0;
	for(int i=0; i<len; i++) {
		if (dataset[i] > max)
			max = dataset[i];
	}
	return max;
}

unsigned char find_minimum(unsigned char *dataset, const int len)
{
	unsigned char min=255;
	for(int i=0; i<len; i++) {
		if (dataset[i] < min)
			min = dataset[i];
	}
	return min;
}

unsigned char *sort(unsigned char *dataset, const int len)
{
//Copy array into array to be sorted
	unsigned char *sorted_dataset = (unsigned char*)malloc(len*sizeof(unsigned char*));
	for(int i=0;i<len;i++)
		sorted_dataset[i] = dataset[i];
#if defined HOST
	qsort(sorted_dataset, len, sizeof(unsigned char), compare);
#else
	unsigned char aux;
        unsigned int i = 0;

        while (i<len-1) {
                if (sorted_dataset[i] < sorted_dataset[i+1]) {
                        aux = sorted_dataset[i+1];
                        sorted_dataset[i+1] = sorted_dataset[i];
                        sorted_dataset[i] = aux;
                        i = 0;
                }
                else {
                        i++;
                }
        }
#endif

	return sorted_dataset;
}
