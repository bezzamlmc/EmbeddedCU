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
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */

#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stddef.h>
#include <stdint.h>

/**
 * @brief Sets a value of a data array 
 *
 * Given a pointer to a char data set, this will set a provided
 * index into that data set to the value provided.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 * @param value value to write the the locaiton
 *
 * @return void.
 */
void set_value(char * ptr, unsigned int index, char value);

/**
 * @brief Clear a value of a data array 
 *
 * Given a pointer to a char data set, this will clear a provided
 * index into that data set to the value zero.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return void.
 */
void clear_value(char * ptr, unsigned int index);

/**
 * @brief Returns a value of a data array 
 *
 * Given a pointer to a char data set, this will read the provided
 * index into that data set and return the value.
 *
 * @param ptr Pointer to data array
 * @param index Index into pointer array to set value
 *
 * @return Value to be read.
 */
char get_value(char * ptr, unsigned int index);

/**
 * @brief Sets data array elements to a value
 *
 * Given a pointer to a char data set, this will set a number of elements
 * from a provided data array to the given value. The length is determined
 * by the provided size parameter.
 *
 * @param ptr Pointer to data array
 * @param value value to write the the locaiton
 * @param size Number of elements to set to value
 *
 * @return void.
 */
void set_all(char * ptr, char value, unsigned int size);

/**
 * @brief Clears elements in a data array
 *
 * Given a pointer to a char data set, this will set a clear a number
 * of elements given the size provided. Clear means to set to zero. 
 *
 * @param ptr Pointer to data array
 * @param size Number of elements to set to zero
 *
 * @return void.
 */
void clear_all(char * ptr, unsigned int size);

/**
 * @brief Memory move
 *
 * Given two memory pointers for source and destination and
 * a number of bytes, this function moves the specified
 * number of bytes from source to destination. This function
 * allows for overlaps and full copy of the contents to the new 
 * memory location.
 *
 * @param src Pointer to source location, represented as unsigned 
 *            8 bits (uint8_t)
 * @param dst Pointer to source location, represented as unsigned 
 *            8 bits (uint8_t)
 * @param length Number of bytes to be moved to the new location
 *
 * @return dst - a uint8_c pointing to destination, the new memory location.
 */
uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Memory copy
 *
 * Given two memory pointers for source and destination and
 * a number of bytes, this function copies the specified
 * number of bytes from source to destination. The behavior is
 * undefined if there is an overlap of source and destination - 
 * data will be corrupted
 *
 * @param src Pointer to source location, represented as unsigned 
 *            8 bits (uint8_t)
 * @param dst Pointer to source location, represented as unsigned 
 *            8 bits (uint8_t)
 * @param length Number of bytes to be copied to the new location
 *
 * @return dst - a uint8_c pointing to destination, the location of
 *               the copied data.
 */
uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

/**
 * @brief Set memory to a given value
 *
 * Given a memory pointer, length and value, set the memory
 * to the given value
 *
 * @param src Pointer to source location, represented as unsigned 
 *            8 bits (uint8_t)
 * @param length Number of bytes to be initialized
 * @param value A 1 byte unsigned value, used to initialize the memory (uint8_t)
 *
 * @return src - a uint8_c pointing to the initialized memory
 */
uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

/**
 * @brief Zero out memory
 *
 * Given a memory pointer, length and value, set the memory to zero
 *
 * @param src Pointer to source location, represented as unsigned 
 *            8 bits (uint8_t)
 * @param length Number of bytes to be zero out
 *
 * @return src - a uint8_c pointing to the zero initialized memory
 */
uint8_t * my_memzero(uint8_t * src, size_t length);

/**
 * @brief Reverse bytes
 *
 * Given a memory pointer and length,  reverse the order of bytes
 *
 * @param src Pointer to source location, represented as unsigned 
 *              bits (uint8_t)
 * @param length Number of bytes to be reversed
 *
 * @return src - a uint8_c pointing to the reversed memory data
 */
uint8_t * my_reverse(uint8_t * src, size_t length);

/**
 * @brief Allocate a given number of words
 *
 * Given a length, allocate the specified number of words
 *
 * @param length Number of words to be allocated
 *
 * @return ptr - a pointer to the memory allocated, NULL if 
 * unsuccessful
 */
int32_t * reserve_words(size_t length);

/**
 * @brief Free dynamic memory
 *
 * Given a memory pointer, free the memory location
 *
 * @param src The memory pointer (uint32_t*)
 *
 * @return void
 */
void free_words(uint32_t * src);

#endif /* __MEMORY_H__ */
