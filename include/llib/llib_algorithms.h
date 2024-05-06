/**
 * Header file for llib algorithms
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_ALGORITHMS_H__
#define LLIB_ALGORITHMS_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include "llib_memory.h"

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

#define ASCENDING 0
#define DESCENDING 1

int lSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*));
int bSearch(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), int order);
size_t lSearchOccurrences(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), size_t* occurrences, size_t occurrencesSize);
size_t bSearchOccurrences(const void* base, size_t sizeof_t, size_t size, const void* value, int (*compare)(const void*, const void*), int order, size_t* occurrences, size_t occurrencesSize);
void sort(void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*), int order);
void reverse(void* base, size_t sizeof_t, size_t size);
int isSorted(const void* base, size_t sizeof_t, size_t size, int (*compare)(const void*, const void*), int order);
void shuffle(void* base, size_t sizeof_t, size_t size);

#ifdef __cplusplus
}
#endif

#endif // !LLIB_ALGORITHMS_H__