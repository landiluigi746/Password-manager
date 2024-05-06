/**
 * Header file for llib memory stuff
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#ifndef LLIB_MEMORY_H__
#define LLIB_MEMORY_H__

#include <stdint.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
#endif

void checkNullPtr(const void* ptr);
void* allocate(size_t size);
void deallocate(void* ptr);
void* reallocate(void* ptr, size_t size);
void setMemory(void* ptr, size_t size, uint8_t value);
void copyMemory(const void* src, void* dst, size_t srcSize, size_t dstSize);
void copyArray(const void* src, void* dst, size_t sizeof_t, size_t size);
void* allocateInit(size_t size, uint8_t value);
void swap(void* a, void* b, size_t sizeof_t);

/**
 * @brief Macro that simulates dst = src.
 * Intended to use instead of a copyMemory(src, dst, size, size)
 * 
 * @param dst Destination pointer
 * @param src Source pointer
 * @param size Number of bytes
 */
#define ASSIGN(dst, src, size) copyMemory(src, dst, size, size)

#ifdef __cplusplus
}
#endif

#endif // !LLIB_MEMORY_H__