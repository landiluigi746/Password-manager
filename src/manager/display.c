#include <manager/manager.h>

/**
 * @brief Displays the accounts
 * 
 * @param accounts The accounts to display
 * @param currentAccounts The number of accounts
 */
void displayAccounts(Account* accounts, size_t currentAccounts)
{
    system("cls || clear");

    if(currentAccounts == 0)
    {
        printf("There aren't accounts to show!\n\n");
        pause();
        return;
    }

    size_t i;

    printf("--------------------------------------------------------------\n");
    printf("|                                                            |\n");
    printf("|                    List of all accounts                    |\n");
    printf("|                                                            |\n");
    printf("--------------------------------------------------------------\n\n\n");

    printf("----------------------------------------------------------------------------------------\n");
    printf("| Number |               Username               |               Password               |\n");
    printf("----------------------------------------------------------------------------------------\n");

    for(i = 0; i < currentAccounts; i++)
        printf("|  %4lld  | %36s | %36s |\n", i + 1, (accounts + i)->username, (accounts + i)->password);

    printf("----------------------------------------------------------------------------------------\n");
    printf("\n\n");

    pause();
    return;
}