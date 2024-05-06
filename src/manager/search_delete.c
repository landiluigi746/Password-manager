#include <manager/manager.h>

//  static functions that displays the accounts at the indexes stored in the occurrences array
static void printOccurrences(Account* accounts, size_t* occurrences, size_t occurrencesCount)
{
    size_t i, currIdx;

    printf("Found %llu occurrences.\n\n", occurrencesCount);

    printf("----------------------------------------------------------------------------------------\n");
    printf("| Number |               Username               |               Password               |\n");
    printf("----------------------------------------------------------------------------------------\n");

    for(i = 0; i < occurrencesCount; i++)
    {
        currIdx = *(occurrences + i);
        printf("|  %4lld  | %36s | %36s |\n", i + 1, (accounts + currIdx)->username, (accounts + currIdx)->password);
    }

    printf("----------------------------------------------------------------------------------------\n");
    printf("\n\n");

    return;
}

/**
 * @brief Searches for an account by username
 * 
 * @param accounts The accounts where to search
 * @param currentAccounts The number of accounts
 * @param usernameToSearch The username to search
 * @param occurrences Array where to store the indexes of the occurrences of the username
 */
int searchAccount(Account* accounts, size_t currentAccounts, const char* usernameToSearch, size_t* occurrences)
{
    system("cls || clear");

    if(currentAccounts == 0)
    {
        printf("There aren't accounts to show!\n");
        pause();
        return NOT_FOUND;
    }

    Account account;
    size_t occurrencesCount;

    strCopy("", account.password, ACC_STR_SIZE);
    strCopy(usernameToSearch, account.username, ACC_STR_SIZE);

    printf("Searching for username: %s\n\n", account.username);
    
    occurrencesCount = bSearchOccurrences(accounts, sizeof(Account), currentAccounts, &account, &compareAccountsByUsername, ASCENDING, occurrences, MAX_ACCOUNTS);
    
    if(occurrencesCount == 0)
    {
        printf("Username not found\n");
        pause();
        return NOT_FOUND;
    }
    else
    {
        printOccurrences(accounts, occurrences, occurrencesCount);
        pause();
        return occurrencesCount;
    }
}

/**
 * @brief Prompts the user to delete an account.
 * The function first searches for the account in the array and then,
 * if the user is found, prompts the user to select which account to delete.
 * 
 * @param accounts The accounts where to search
 * @param currentAccounts The number of accounts
 * @param username The username to search
 * @param occurrences Array where to store the indexes of the occurrences of the username
 */
void deleteAccount(Account* accounts, size_t* currentAccounts, const char* usernameToDelete, size_t* occurrences)
{
    int searchResult = searchAccount(accounts, *currentAccounts, usernameToDelete, occurrences);
    size_t i, index;

    if(searchResult == NOT_FOUND)
        return;

    if(searchResult > 1)
    {
        do{
            printf("\n\nEnter the index of the user to delete: ");
            input("%d", &index);
        } while(index <= 0 || index > searchResult);
    }

    index = *(occurrences + index - 1);

    for(i = index; i < *currentAccounts; i++)
        *(accounts + i) = *(accounts + i + 1);

    (*currentAccounts)--;

    printf("\nAccount deleted successfully!\n\n");
    pause();
    return;
}