/**
 * Implementation file for llib algorithms
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_utils.h>

/**
 * @brief Waits for (approximately) milliseconds milliseconds using
 * clock from time.h
 * 
 * @param milliseconds Milliseconds to wait
*/
void wait(uint32_t milliseconds)
{
    clock_t start = clock();
    while((clock() - start) < milliseconds);
    return;
}

/**
 * @brief Returns a FILE pointer to a file opened with given fileName
 * in given fileMode. If the opening fails, exits the program
 * 
 * @param fileName Name of the file to open
 * @param fileMode Mode of the file
*/
FILE* openFile(const char* fileName, const char* fileMode)
{
    FILE* filePtr = fopen(fileName, fileMode);

    if(filePtr == NULLPTR)
    {
        perror("Error while opening file!\n");
        exit(EXIT_FAILURE);
    }

    return filePtr;
}