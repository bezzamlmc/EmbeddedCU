#include "data.h"
#include "memory.h"

uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
//NOTE: it is assumed that ptr points to an area in memory large
//      enough to store the digits
	uint8_t sz = sizeof(uint8_t);
// Handle 0
	if (data == 0) {
		*ptr = '0';
		*(ptr + sz) = '\0';
		return 1;
	}
	uint8_t sign = 0;
	uint8_t *cptr = ptr;
	int32_t len = 0;
	int32_t ddata = data;
	if (data < 0) {
		ddata = -ddata;
		*cptr = '-';
		cptr += sz;
		sign = 1;
	}
	do {
		uint8_t dig = (uint8_t)(ddata % base); 
		*cptr = ditoa(dig);
		cptr += sz;
		len++;
		ddata /= base;
	} while (ddata > 0);
	*cptr = '\0';
	cptr = ptr + sign*sz;
	cptr = my_reverse(cptr,len);
	return (len+sign);
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
// NOTE: digits are not validated !!! 
        int8_t sign;
	uint8_t ibeg;
	int32_t accum = 0;
	int32_t pbase = 1;
	uint8_t sz = sizeof(uint8_t);
	uint8_t *pcurrent = ptr + sz*(digits-1);
	if (*ptr == '-') {
		sign = -1;
		ibeg = 1;
	}
	else if (*ptr == '+') {
		sign = 1;
		ibeg = 1;
	}
	else {
		sign = 1;
		ibeg = 0;
	}
	for (uint8_t i=ibeg; i<digits; i++) {
		int32_t idigit = (int32_t)datoi(*pcurrent);
		accum += pbase*idigit;
		pbase *= base;
		pcurrent -= sz;
	}
	return sign*accum;
}

char ditoa(uint8_t digit)
{
//NOTE: digits are not validated
	char a;
	switch (digit) {
		case 0:
			a = '0';	
			break;
		case 1:
			a = '1';	
			break;
		case 2:
			a = '2';
			break;
		case 3:
			a = '3';	
			break;
		case 4:
			a = '4';	
			break;
		case 5:
			a = '5';	
			break;
		case 6:
			a = '6';	
			break;
		case 7:
			a = '7';	
			break;
		case 8:
			a = '8';	
			break;
		case 9:
			a = '9';	
			break;
		case 10:
			a = 'A';	
			break;
		case 11:
			a = 'B';	
			break;
		case 12:
			a = 'C';	
			break;
		case 13:
			a = 'D';	
			break;
		case 14:
			a = 'E';
			break;
		case 15:
			a = 'F';
			break;
		default:
			a = '0';
			break;
	}
	return a;
}

uint8_t datoi(char digit)
{
//NOTE: No digit validation
	uint8_t idigit;
	switch (digit) {
		case '0':
			idigit = 0;
			break;
		case '1':
			idigit = 1;
			break;
		case '2':
			idigit = 2;
			break;
		case '3':
			idigit = 3;
			break;
		case '4':
			idigit = 4;
			break;
		case '5':
			idigit = 5;
			break;
		case '6':
			idigit = 6;
			break;
		case '7':
			idigit = 7;
			break;
		case '8':
			idigit = 8;
			break;
		case '9':
			idigit = 9;
			break;
		case 'a':
		case 'A':
			idigit = 10;
			break;
		case 'b':
		case 'B':
			idigit = 11;
			break;
		case 'c':
		case 'C':
			idigit = 12;
			break;
		case 'd':
		case 'D':
			idigit = 13;
			break;
		case 'e':
		case 'E':
			idigit = 14;
			break;
		case 'f':
		case 'F':
			idigit = 15;
			break;
		default:
			idigit = 0;
			break;
		}
		return idigit;
}

