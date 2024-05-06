#include <manager/manager.h>

/**
 * @brief Login with the admin account
 * The user is prompted to enter the admin username 
 * and password and has 3 chances to enter them correctly
 * 
 * @param adminAccount The admin account
 * 
 * @returns LOGIN_SUCCESS if login was successful, LOGIN_FAILURE otherwise
 */
int login(Account* adminAccount)
{
    Account account;
    int possibilities = 3;
    bool access = false;

    system("cls || clear");

    printf("-------------------------------------------------------------------\n");
    printf("|                                                                 |\n");
    printf("|           Welcome to landiluigi746's Password Manager           |\n");
    printf("|                                                                 |\n");
    printf("-------------------------------------------------------------------\n\n\n");
    
    printf("[LOGIN]:\n\n");

    do{
        printf("Enter admin username: ");
        strInput(account.username, ACC_STR_SIZE);

        printf("Enter admin password: ");
        strInput(account.password, ACC_STR_SIZE);

        access = strCompare(account.username, adminAccount->username) == 0 &&
        strCompare(account.password, adminAccount->password) == 0 &&
        strLength(account.username) == strLength(adminAccount->username) &&
        strLength(account.password) == strLength(adminAccount->password);

        if(access)
        {
            printf("\nAccess granted!\n\n");
            wait(1000);
            return LOGIN_SUCCESS;
        }
        else
        {
            printf("Wrong username or password!\n");
            printf("You have still %d attempts\n", --possibilities);
        }
    } while(possibilities > 0);

    printf("\nAccess denied!\n\n");
    wait(1000);
    return LOGIN_FAILURE;
}

/**
 * @brief Prompts the user to change admin credentials
 * 
 * @param adminAccount The admin account
 * @param activeAdmin Pointer to the admin status
 */
void setAdminAccount(Account* adminAccount, bool* activeAdmin)
{
    system("cls || clear");

    printf("-----------------------------\n");
    printf("|                           |\n");
    printf("|         Set admin         |\n");
    printf("|                           |\n");
    printf("-----------------------------\n\n");

    getValidString(adminAccount->username, ACC_STR_SIZE, ADMIN_USR_PROMPT_MSG, USERNAME_ERROR_MSG, &validUsername);
    getValidString(adminAccount->password, ACC_STR_SIZE, ADMIN_PWD_PROMPT_MSG, PASSWORD_ERROR_MSG, &validPassword);

    *activeAdmin = true;

    pause();
    return;
}