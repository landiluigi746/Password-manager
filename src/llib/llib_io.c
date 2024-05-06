/**
 * Implementation file for llib i/o
 * 
 * Author: landiluigi746
 * Date: 2024-04-24
 * Github: https://github.com/landiluigi746
 */

#include <llib/llib_io.h>

/**
 * @brief Clears stdin by discarding every 
 * character until a '\n' or EOF is detected
 */
void clearInBuf(void)
{
    int c;
    while((c = getchar()) != EOF && c != '\n');
    return;
}

/**
 * @brief Reads input from stdin based on the specified format and stores it at the provided address.
 * Automatically clears the buffer at the end.
 *
 * @param format The format string for reading input.
 * @param address Pointer to the memory location where the input will be stored.
 *
 * @return The number of input items successfully matched and assigned.
 */
int input(const char* format, void* address)
{
    int result = scanf(format, address);
    clearInBuf();

    return result;
}