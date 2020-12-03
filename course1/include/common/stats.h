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
 * @file stats.h 
 * @brief Statistical analytics functions
 *
 * The stats library implements statistical analytics on 
 * a given dataset. The functions operate on arrays of unsigned char data
 * Results are rounded to the nearest integer.
 *
 * @author Laura Bezzam
 * @date November 16 2020
 *
 */
#ifndef __STATS_H__
#define __STATS_H__

/* Function declarations */ 

/**
 * @brief Prints the statistics of an unsigned char array
 *
 * This function computes the minimum, maximum, mean and median of 
 * a given unsigned char array.The results are printed to the screen.
 *
 * @param Pointer to unsigned char array
 * @param Length of the input array
 *
 * @return void
 */
void print_statistics(unsigned char *dataset, const int len);

/**
 * @brief Print array
 *
 * Given and array of unsigned char and its length, this function
 * prints the array to the screen.
 *
 * @param Pointer to unsigned char dataset
 * @param Length of the input array
 *
 * @return void
 */
void print_array(unsigned char *dataset, const int len);

/**
 * @brief Compute the median of an unsigned char array
 *
 * Given and array of unsigned char and its length, this function
 * computes the median of the array.
 *
 * @param Pointer to unsigned char dataset
 * @param Length of the input array
 *
 * @return The median of the array as unsigned char
 */
unsigned char find_median(unsigned char *dataset, const int len);

/**
 * @brief Compute the mean of an unsigned char array
 *
 * Given and array of unsigned char and its length, this function
 * computes the mean of the array.
 *
 * @param Pointer to unsigned char dataset
 * @param Length of the input array
 *
 * @return The mean of the array as unsigned char rounded to the closest integer
 */
unsigned char find_mean(unsigned char *dataset, const int len);

/**
 * @brief Compute the maximum of an unsigned char array
 *
 * Given and array of unsigned char and its length, this function
 * computes the maximum of the array.
 *
 * @param Pointer to unsigned char dataset
 * @param Length of the input array
 *
 * @return The maximum of the array as unsigned char
 */
unsigned char find_maximum(unsigned char *dataset, const int len);

/**
 * @brief Compute the minimum of an unsigned char array
 *
 * Given and array of unsigned char and its length, this function
 * computes the minimum of the array.
 *
 * @param Pointer to unsigned char dataset
 * @param Length of the input array
 *
 * @return The minimum of the array as unsigned char
 */
unsigned char find_minimum(unsigned char *dataset, const int len);

/**
 * @brief Sort an unsigned char array from largest to smallest.
 *
 * Given and array of unsigned char and its length, this function
 * returns the sorted array from largest to smallest.
 *
 * @param Pointer to unsigned char dataset. 
 * @param Length of the input array
 *
 * @return unsigned char * sorted array 
 */
unsigned char *sort(unsigned char *dataset, const int len);

#endif
