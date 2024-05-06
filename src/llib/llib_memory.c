/**
 * Implementation file for llib memory
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_memory.h>

/**
 * @brief Checks if the given pointer is null
 * If yes, exits the program with an error message.
 * Intended to use when a null pointer is fatal.
 * 
 * @param ptr The pointer to check
 */
void checkNullPtr(const void* ptr)
{
    if(ptr == NULLPTR)
    {
        printf("Error! Null pointer caught by checkNullPtr()!\n");
        exit(EXIT_FAILURE);
    }

    return;
}

/**
 * @brief Allocates size bytes and returns a pointer to it
 * If the allocation fails, exits the program.
 * 
 * @param size Number of bytes to allocate
 * 
 * @returns Pointer to the allocated memory
 */
void* allocate(size_t size)
{
    void* ptr = malloc(size);
    checkNullPtr(ptr);
    return ptr;
}

/**
 * @brief Deallocates the memory pointer by ptr
 * 
 * @param ptr Pointer to the memory to deallocate
 */
void deallocate(void* ptr)
{
    free(ptr);
    return;
}

/**
 * @brief Allocates size bytes, copies the content from the memory
 * pointer by ptr to the new allocated memory, frees the memory pointed by ptr
 * and returns a pointer to the new allocated memory.
 * 
 * If the allocation fails, exits the program.
 * 
 * @param ptr Pointer to the memory to reallocate
 * @param size Number of bytes of the new allocated memory
 * @returns Pointer to the new allocated memory
 */
void* reallocate(void* ptr, size_t size)
{
    void* newPtr = realloc(ptr, size);
    checkNullPtr(newPtr);
    return newPtr;
}

/**
 * @brief Sets the content of the memory pointed by ptr to value
 * 
 * @param ptr Pointer to the memory
 * @param size Size of the memory
 * @param value Value to set
 */
void setMemory(void* ptr, size_t size, uint8_t value)
{
    if(ptr == NULLPTR)
        return;

    byte* start = (byte*) ptr;

    while(size--)
        *start++ = value;
    
    return;
}

/**
 * @brief Copies the content of the segment srcStart-srcEnd in the segment
 * dstStart-dstEnd.
 * 
 * @param src Source segment
 * @param dst Destination segment
 * @param srcSize Size of the source segment
 * @param dstSize Size of the destination segment
 */
void copyMemory(const void* src, void* dst, size_t srcSize, size_t dstSize)
{
    if(src == NULLPTR || dst == NULLPTR || src == dst || srcSize == 0 || dstSize == 0)
        return;

    const byte* s = (const byte*) src;
    byte* d = (byte*) dst;

    while(srcSize-- > 0 && dstSize-- > 0 && s != d)
        *d++ = *s++;

    return;
}

/**
 * @brief Copies the content of the array src to the array dst.
 * 
 * @param src Source array
 * @param dst Destination array
 * @param sizeof_t Size of each element in the array
 * @param size Number of elements in the array
 */
void copyArray(const void* src, void* dst, size_t sizeof_t, size_t size)
{
    if(src == NULLPTR || dst == NULLPTR)
        return;
    
    const byte* s = (const byte*) src;
    byte* d = (byte*) dst;

    while(size--)
    {
        ASSIGN(d, s, sizeof_t);
        d += sizeof_t;
        s += sizeof_t;
    }

    return;
}

/**
 * @brief Allocates size bytes, initializes it with value and returns a pointer to it
 * 
 * @param size Number of bytes to allocate
 * @param value Value to initialize
 * 
 * @returns Pointer to the allocated memory
 */
void* allocateInit(size_t size, uint8_t value)
{
    void* ptr = allocate(size);
    byte* start = (byte*) ptr;

    while(size--)
        *start++ = value;

    return ptr;
}

/**
 * @brief Swaps the content of two pointers
 * Assumes that the size of the elements by the pointers is the same
 * 
 * @param a First pointer
 * @param b Second pointer
 * @param sizeof_t Size of the element pointed by the pointers
 */
void swap(void* a, void* b, size_t sizeof_t)
{
    if(a == NULLPTR || b == NULLPTR)
        return;

    byte* a_ptr = (byte*) a;
    byte* b_ptr = (byte*) b;
    byte* temp_ptr = (byte*) allocate(sizeof_t);

    ASSIGN(temp_ptr, a_ptr, sizeof_t); //storing value of a in temp
    ASSIGN(a_ptr, b_ptr, sizeof_t); //storing value of b in a
    ASSIGN(b_ptr, temp_ptr, sizeof_t); //storing value of temp in b

    deallocate(temp_ptr);

    return;
}