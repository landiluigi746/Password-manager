#include <manager/manager.h>

#define CMD_STR_SIZE 64

int main(void)
{
    Account adminAccount;
    Account accounts[MAX_ACCOUNTS] = {0};
    size_t occurrences[MAX_ACCOUNTS] = {0}, currentAccounts = 0;
    char buf[CMD_STR_SIZE];
    bool adminActive = false;

    srand(time(NULLPTR));

    load(accounts, &currentAccounts, &adminAccount, &adminActive);

    if(adminActive && login(&adminAccount) == LOGIN_FAILURE)
        exit(LOGIN_FAILURE);

    while(true)
    {
        system("cls || clear");

        printf("--------------------------------------------------------------------\n");
        printf("|                                                                  |\n");
        printf("|                         Password Manager                         |\n");
        printf("|                                                                  |\n");
        printf("--------------------------------------------------------------------\n\n\n");

        printf("!!!All changes are saved on exit!!!\n\n");

        printf("[Menu]\n\n");

        printf("add - Insert a new password\n");
        printf("display - Display all passwords\n");
        printf("search - Search an account by username\n");
        printf("delete - Delete a password\n");
        printf("update - Update an existing account\n");
        printf("admin - Set admin account\n");
        printf("exit - Exit program\n\n");

        printf("Enter a command:\n");
        printf("> ");
        strInput(buf, CMD_STR_SIZE);

        if(strCompare(buf, "add") == 0)
            addAccount(accounts, &currentAccounts);
        else if(strCompare(buf, "display") == 0)
            displayAccounts(accounts, currentAccounts);
        else if(strCompare(buf, "search") == 0)
        {
            getValidString(buf, ACC_STR_SIZE, SEARCH_PROMPT_MSG, USERNAME_ERROR_MSG, &validUsername);
            searchAccount(accounts, currentAccounts, buf, occurrences);
        }
        else if(strCompare(buf, "delete") == 0)
        {
            getValidString(buf, ACC_STR_SIZE, SEARCH_PROMPT_MSG, USERNAME_ERROR_MSG, &validUsername);
            deleteAccount(accounts, &currentAccounts, buf, occurrences);
        }
        else if(strCompare(buf, "update") == 0)
        {
            getValidString(buf, ACC_STR_SIZE, UPDATE_PROMPT_MSG, USERNAME_ERROR_MSG, &validUsername);
            updateAccount(accounts, currentAccounts, buf, occurrences);
        }
        else if(strCompare(buf, "admin") == 0)
            setAdminAccount(&adminAccount, &adminActive);
        else if(strCompare(buf, "exit") == 0)
            break;
        else
        {
            system("cls || clear");
            printf("Unknown command\n\n");
            pause();
        }
    }

    save(accounts, currentAccounts, &adminAccount, adminActive);

    return 0;
}