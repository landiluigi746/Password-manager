/**
 * Header file for llib i/o stuff
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_IO_H__
#define LLIB_IO_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>

/**
 * llib defines
*/
#ifndef LLIB_UTIL_DEFINES
#define LLIB_UTIL_DEFINES

#define NULLPTR NULL
#define NOT_FOUND -1
#define min(a, b) (a) < (b) ? a : b
#define max(a, b) (a) > (b) ? a : b
typedef unsigned char byte;

#endif // !LLIB_UTIL_DEFINES

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

void clearInBuf(void);
int input(const char* format, void* address);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !LLIB_IO_H__