#include <manager/manager.h>

/**
 * @brief Saves the given accounts to the file
 * 
 * @param accounts The accounts to save
 * @param currentAccounts The number of accounts to save
 * @param adminAccount The admin account
 * @param activeAdmin Whether the admin account is active
 */
void save(Account* accounts, size_t currentAccounts, Account* adminAccount, bool activeAdmin)
{
    FILE* fptr = openFile(FILE_NAME, "wb");
    size_t i;
    
    for(i = 0; i < currentAccounts; i++)
        cipherAccount((accounts + i));

    cipherAccount(adminAccount);

    fwrite(&currentAccounts, sizeof(size_t), 1, fptr); //save the number of current accounts
    fwrite(accounts, sizeof(Account), currentAccounts, fptr); //save the accounts
    fwrite(adminAccount, sizeof(Account), 1, fptr); //save the admin account
    fwrite(&activeAdmin, sizeof(bool), 1, fptr); //save the admin status

    fprintf(fptr, "\n");

    fclose(fptr);

    return;
}

/**
 * @brief Loads the accounts from the file
 * 
 * @param accounts Where to store the loaded accounts
 * @param currentAccounts Where to store the number of accounts
 * @param adminAccount Where to store the admin account
 * @param activeAdmin Where to store the admin status
 */
void load(Account* accounts, size_t* currentAccounts, Account* adminAccount, bool* activeAdmin)
{
    FILE* fptr = openFile(FILE_NAME, "ab+");
    
    rewind(fptr);

    if(feof(fptr))
        goto end;

    size_t i;

    fread(currentAccounts, sizeof(size_t), 1, fptr); //load the number of current accounts
    fread(accounts, sizeof(Account), *currentAccounts, fptr); //load the accounts
    fread(adminAccount, sizeof(Account), 1, fptr); //load the admin account
    fread(activeAdmin, sizeof(bool), 1, fptr); //load the admin status

    decipherAccount(adminAccount);

    for(i = 0; i < *currentAccounts; i++)
        decipherAccount((accounts + i));

    end:
        fclose(fptr);
        return;
}