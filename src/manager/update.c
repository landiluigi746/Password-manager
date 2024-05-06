#include <manager/manager.h>

/**
 * @brief Prompts the user to update an account.
 * The function first searches for the account in the array and then
 * if the user is found, prompts the user to select which account to 
 * update and which field of the account to update.
 * In the end the accounts are sorted again.
 * 
 * @param accounts The accounts where to search
 * @param currentAccounts The number of accounts
 * @param username The username to search
 * @param occurrences Array where to store the indexes of the occurrences of the username
 */
void updateAccount(Account* accounts, size_t currentAccounts, const char* username, size_t* occurrences)
{
    int i, searchResult = searchAccount(accounts, currentAccounts, username, occurrences);
    size_t choice, index;

    if(searchResult == NOT_FOUND)
        return;
    
    if(searchResult > 1)
    {
        do{
            printf("\n\nEnter the index of the user to update: ");
            input("%llu", &index);
        } while(index <= 0 || index > searchResult);
    }
    else
        index = 1;
    
    index = *(occurrences + index - 1);

    printf("What do you want to update?\n\n");

    printf("1. Username\n");
    printf("2. Password (insert new)\n");
    printf("3. Password (generate new)\n\n");

    do{
        printf("Enter your choice: ");
        input("%llu", &choice);

        switch(choice)
        {
            case 1:
                getValidString((accounts + index)->username, ACC_STR_SIZE, UPDATE_USR_PROMPT_MSG, USERNAME_ERROR_MSG, &validUsername);
                break;
            case 2:
                getValidString((accounts + index)->password, ACC_STR_SIZE, UPDATE_PWD_PROMPT_MSG, PASSWORD_ERROR_MSG, &validPassword);
                break;
            case 3:
                randomPassword((accounts + index)->password);
                break;
            default:
                printf("\nInvalid choice!\n\n");
                break;
        }
    } while(choice <= 0 || choice > 3);

    sort(accounts, sizeof(Account), currentAccounts, &compareAccountsGeneral, ASCENDING);

    pause();
    return;
}