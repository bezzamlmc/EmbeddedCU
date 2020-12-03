/**
 * @file data.h
 * @brief Basic data manipulation functions
 *
 * This header file basic data manipulation functions
 *
 * @author Laura B
 * @date November 30 2020
 *
 */
#ifndef __DATA_H__
#define __DATA_H__

#include <stdint.h>

/**
 * @brief Integer to Ascii
 *
 * Converts data from standard integer to ASCII string
 * This function supports bases 2 to 16
 *
 * @param data The number to be converted (int32_t).
 * @param ptr Pointer to location where the string will be stored, 
 * the string is 0 terminated following C standard.
 * @param base number base, any from 2 to 16
 *
 * @return len the length of the converted data (uint8_t)
 */
uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base);

/**
 * @brief ASCII to Integer
 *
 * Convert a string to integer type - This function supports bases
 * 2 to 16
 *
 * @param ptr Pointer to string
 * @param digits Number of digits in the character set (uint8_t)
 * @param index Index into pointer array to set value
 *
 * @return num the converted integer (int32_t).
 */
int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base);

/**
 * @brief Integer to ASCII  digit representation
 *
 * Return the ASCII representation of an integer in [0,base)
 *
 * @param digit integer between [0,16)
 *
 * @return the ASCII character.
 */
char ditoa(uint8_t digit);

/**
 * @brief Integer to ASCII  digit representation
 *
 * Return the integer representation of an ASCII digit in [0,16)
 *
 * @param character in [0,16)
 *
 * @return the digit as represented by uint8_t
 */
uint8_t datoi(char digit);

#endif /* __DATA_H__ */
