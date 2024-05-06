/**
 * Implementation file for llib algorithms
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_string.h>

/**
 * @brief Takes a string in input and stores every char
 * in string until it's full or the string ends.
 * Automatically clears the input buffer at the end if needed.
 * 
 * @param string String where the input is stored
 * @param capacity Capacity of the string
 * 
 * @returns The number of stored characters
 */
size_t strInput(char* string, size_t capacity)
{
    if(string == NULLPTR)
        return 0;

    int c;
    size_t count = 0;

    while(count < capacity - 1 && (c = getchar()) != EOF && c != '\n')
        *(string + count++) = (char)c;

    *(string + count) = '\0';

    if(count == capacity - 1)
        clearInBuf();

    return count;
}

/**
 * @brief Finds the length of string
 * 
 * @param string String to check
 * 
 * @returns Length of string
 */
size_t strLength(const char* string)
{
    if(string == NULLPTR)
        return 0;

    size_t count = 0;

    while(*string++ != '\0')
        ++count;

    return count;
}

/**
 * @brief Copies the content of a string into another string
 * 
 * @param srcStr Source string
 * @param dstStr Destination string
 * @param dstSize Size of the destination string
 * 
 * @returns Count of characters copied
 */
size_t strCopy(const char* srcStr, char* dstStr, size_t dstSize)
{
    if(srcStr == NULLPTR || dstStr == NULLPTR)
        return 0;
    
    size_t count = 0;

    while(*(srcStr + count) != '\0' && count < dstSize - 1)
    {
        *(dstStr + count) = *(srcStr + count);
        ++count;
    }

    *(dstStr + count) = '\0';

    return count;
}

/**
 * @brief Copies the n characters of a string into another string
 * 
 * @param srcStr Source string
 * @param copyCount Count of characters to copy
 * @param dstStr Destination string
 * @param dstSize Size of the destination string
 * 
 * @returns Count of characters copied
 */
size_t strNCopy(const char* srcStr, size_t copyCount, char* dstStr, size_t dstSize)
{
    if(srcStr == NULLPTR || dstStr == NULLPTR)
        return 0;

    size_t count = 0;

    while(*(srcStr + count) != '\0' && count < copyCount && count < dstSize)
    {
        *(dstStr + count) = *(srcStr + count);
        ++count;
    }

    *(dstStr + count) = '\0';

    return count;
}

/**
 * @brief Compare two strings alphabetically
 * 
 * @param string1 String 1
 * @param string2 String 2
 * 
 * @returns -1 if string1 < string2, 0 if string1 == string2, 1 if string1 > string2
 */
int strCompare(const char* string1, const char* string2)
{
    if(string1 != NULLPTR && string2 == NULLPTR)
        return 1;

    if(string1 == NULLPTR && string2 != NULLPTR)
        return -1;

    if((string1 == NULLPTR && string2 == NULLPTR) || string1 == string2)
        return 0;

    while(*string1 == *string2)
    {
        if(*string1 == '\0' || *string2 == '\0')
            return 0;

        ++string1;
        ++string2;
    }

    return ((*string1 - *string2) > 0) ? 1 : -1;

    return 0;
}

/**
 * @brief Compare n characters of two strings alphabetically
 * 
 * @param string1 String 1
 * @param string2 String 2
 * @param cmpCount Count of characters to compare
 * 
 * @returns -1 if string1 < string2, 0 if string1 == string2, 1 if string1 > string2
 */
int strNCompare(const char* string1, const char* string2, size_t cmpCount)
{
    if(string1 != NULLPTR && string2 == NULLPTR)
        return 1;

    if(string1 == NULLPTR && string2 != NULLPTR)
        return -1;

    if((string1 == NULLPTR && string2 == NULLPTR) || string1 == string2 || cmpCount == 0)
        return 0;
    
    size_t count = 0;

    while(count < cmpCount && *string1 == *string2)
    {
        if(*string1 == '\0' || *string2 == '\0')
            return 0;

        ++string1;
        ++string2;
    }

    return ((*string1 - *string2) > 0) ? 1 : -1;
}

/**
 * @brief Duplicates a string
 * 
 * @param string String to duplicate
 * 
 * @returns Pointer to the duplicated string
 */
char* strDuplicate(const char* string)
{
    checkNullPtr(string);

    size_t count = 0, len = strLength(string);
    char* duplicate = (char*) allocate(len + 1);

    while(*string != '\0')
    {
        *(duplicate + count) = *(string + count);
        ++count;
    }

    *(duplicate + count) = '\0';

    return duplicate;
}

/**
 * @brief Reverses a string of length characters
 * 
 * @param string String to reverse
 * @param limit Length of string (how far to reverse)
 */
void strReverse(char* string, size_t limit)
{
    if(string == NULLPTR)
        return;

    char* left = string;
    char* right = string + limit - 1;

    while(left < right)
    {
        swap(left, right, sizeof(char));

        ++left;
        --right;
    }

    return;
}

/**
 * @brief Finds the first occurrence of strToFind in string
 * 
 * @param string String to search in
 * @param length Length of string
 * @param strToFind String to search for
 * 
 * @returns Index of the first occurrence or -1 if not found
 */
int strFind(const char* string, size_t length, const char* strToFind)
{
    if(string == NULLPTR || strToFind == NULLPTR)
        return NOT_FOUND;

    size_t i;

    for(i = 0; i < length - 1 && *(string + i) != '\0'; i++)
    {
        if(strCompare((string + i), strToFind) == 0)
            return i;
    }

    return NOT_FOUND;
}

/**
 * @brief Concatenates two strings (string1 and string2) in dest
 * 
 * @param string1 String 1
 * @param string2 String 2
 * @param dest Destination string
 * @param destSize Size of destination string
 * 
 * @returns Length of the concatenated string
 */
size_t strConcat(const char* string1, const char* string2, char* dest, size_t destSize)
{
    if(string1 == NULLPTR || string2 == NULLPTR || dest == NULLPTR)
        return 0;
    
    size_t count = 0;

    while(count < destSize - 1 && *string1 != '\0')
        *(dest + count++) = *string1++;
    
    while(count < destSize - 1 && *string2 != '\0')
        *(dest + count++) = *string2++;
    
    *(dest + count) = '\0';

    return count;
}

/**
 * @brief Encrypts a string using Caesar's cipher
 * 
 * @param string String to encrypt
 * @param count Number of characters to shift
 */
void strCipher(char* string, size_t count)
{
    if(string == NULLPTR)
        return;

    //avoid useless operations if there is nothing to encrypt
    if(count == 0 || count % ('~' - '!' + 1) == 0)
        return;

    count = count % ('~' - '!' + 1);

    while(*string != '\0')
    {
        if(iscntrl(*string))
            goto next;

        if((*string >= '!' && *string <= '~' - count))
            *string += count;
        else
            *string -= 94 - count;

        next:
            ++string;
    }

    return;
}

/**
 * @brief Decrypts a string using Caesar's cipher
 * 
 * @param string String to decrypt
 * @param count Number of characters to unshift
 */
void strDecipher(char* string, size_t count)
{
    if(string == NULLPTR)
        return;

    //avoid useless operations if there is nothing to decrypt
    if(count == 0 || count % ('~' - '!' + 1) == 0)
        return;
    
    count = count % ('~' - '!' + 1);

    while(*string != '\0')
    {
        if(iscntrl(*string))
            goto next;

        if((*string >= '!' + count && *string <= '~'))
            *string -= count;
        else
            *string += 94 - count;

        next:
            ++string;
    }

    return;
}