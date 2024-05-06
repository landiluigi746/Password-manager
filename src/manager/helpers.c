#include <manager/manager.h>

//  helper functions

/**
 * @brief Prompts the user to enter a valid string until it is valid for the given function
 * 
 * @param string The string where to store the input
 * @param stringSize Size of the string
 * @param promptMsg Prompt message
 * @param errorMsg Error message
 * @param valid Function to validate the string
 */
void getValidString(char* string, size_t stringSize, const char* promptMsg, const char* errorMsg, bool (*valid)(const char*))
{
    bool flag;

    do{
        printf("%s", promptMsg);
        strInput(string, stringSize);

        flag = valid(string);

        if(!flag)
            printf("%s", errorMsg);
    } while(!flag);

    return;
}

//  prompt the user for enter any char to continue and pause
void pause(void)
{
    printf("Enter any char to continue\n");
    system("pause > nul");
    printf("\n");

    return;
}