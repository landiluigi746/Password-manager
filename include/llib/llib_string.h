/**
 * Header file for llib string-related stuff
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_STRING_H__
#define LLIB_STRING_H__

#include <stdint.h>
#include <stdbool.h>
#include <ctype.h>
#include <llib/llib_io.h>
#include <llib/llib_memory.h>

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

size_t strInput(char* string, size_t capacity);
size_t strLength(const char* string);
size_t strCopy(const char* srcStr, char* dstStr, size_t dstSize);
size_t strNCopy(const char* srcStr, size_t copyCount, char* dstStr, size_t dstSize);
int strCompare(const char* string1, const char* string2);
int strNCompare(const char* string1, const char* string2, size_t cmpCount);
char* strDuplicate(const char* string);
void strReverse(char* string, size_t length);
int strFind(const char* string, size_t length, const char* strToFind);
size_t strConcat(const char* string1, const char* string2, char* dest, size_t destSize);
void strCipher(char* string, size_t count);
void strDecipher(char* string, size_t count);

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !LLIB_STRING_H__