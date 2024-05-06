#include <manager/manager.h>

/**
 * @brief Prompts the user to add an account
 * First ask the user to enter the username and then ask if he wants
 * to manually insert the password or generate one
 * 
 * N.B. The account is inserted in order in the accounts array
 * 
 * @param accounts The accounts where to store the new account
 * @param currentAccounts The number of accounts
 */
void addAccount(Account* accounts, size_t* currentAccounts)
{
    system("cls || clear");

    int i, choice;
    Account account;

    printf("-----------------------------\n");
    printf("|                           |\n");
    printf("|        New account        |\n");
    printf("|                           |\n");
    printf("-----------------------------\n\n");

    if(*currentAccounts >= MAX_ACCOUNTS)
    {
        printf("\nCan't store more accounts!\n\n");
        goto end;
    }

    getValidString(account.username, ACC_STR_SIZE, USERNAME_PROMPT_MSG, USERNAME_ERROR_MSG, &validUsername);

    do{
        printf("\nDo you want to manually insert the password [1] or do you want to generate one [2] ?\n");
        printf("Enter your choice: ");
        input("%d", &choice);
    } while(choice < 1 || choice > 2);

    if(choice == 1)
        getValidString(account.password, ACC_STR_SIZE, PASSWORD_PROMPT_MSG, PASSWORD_ERROR_MSG, &validPassword);
    else
        randomPassword(account.password);

    i = *currentAccounts;

    while(i > 0 && compareAccountsGeneral((accounts + i - 1), &account) > 0)
    {
        *(accounts + i) = *(accounts + i - 1);
        i--;
    }

    *(accounts + i) = account;

    printf("\nAccount added successfully!\n\n");
    (*currentAccounts)++;

    end:
        pause();
        return;

    return;
}