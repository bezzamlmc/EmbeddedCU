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
 * @file memory.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Alex Fosdick
 * @date April 1 2017
 *
 */
#include <stdlib.h>
#include "memory.h"

/***********************************************************
 Function Definitions
***********************************************************/
void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
	uint8_t sz = sizeof(uint8_t);
	long long shift = dst - src;
	if (shift == 0)
		return dst;
	if (dst < src || dst > src + sz*length)
		return my_memcopy(src, dst, length);
// memory overlap within interval
	uint8_t *ptr1 = src + sz*length;
	uint8_t *ptr2 = dst + sz*length;
	for (size_t i=0; i< length; i++) {
		*ptr2 = *ptr1;
		ptr1 -= sz;
		ptr2 -= sz;
	}
	return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
	return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
	uint8_t sz = sizeof(uint8_t);
	uint8_t *ptr = src;
	for (size_t i=0; i<length; i++) {
		*ptr = value;
		ptr += sz;
	}
	return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){

	return my_memset(src, length, (uint8_t)0);
}

uint8_t * my_reverse(uint8_t * src, size_t length){
	size_t l2 = length/2;
	uint8_t sz = sizeof(uint8_t);
	uint8_t *ptr1 = src;
	uint8_t *ptr2 = src + length*sz;
	for (size_t i=0; i<l2; i++) {
		uint8_t aux = *ptr2;
		*ptr2 = *ptr1;
	        *ptr1 = aux;
		ptr1 += sz;
		ptr2 -= sz;	
	}
	return src;
}

int32_t * reserve_words(size_t length){
	return malloc(length * sizeof(int32_t));
}

void free_words(uint32_t * src){
	free(src);
	return;
}
