/**
 * Header file for the password manager
 * 
 * Author: landiluigi746
 * Date: 2024-04-28
 * Github: https://github.com/landiluigi746
 */

#ifndef MANAGER_H__
#define MANAGER_H__

#include <llib/llib.h>
#include <manager/account.h>

//useful macros

#define LOGIN_SUCCESS 0
#define LOGIN_FAILURE 1

#define MAX_ACCOUNTS 1024

#define FILE_NAME "pwd-manager.bin"

#define USERNAME_PROMPT_MSG "\nEnter username for the new account\n\
The username must be of at least 6 valid ASCII characters\n\nUsername: "

#define PASSWORD_PROMPT_MSG "\nEnter password for the new account:\n\
The password must be of at least 8 valid ASCII characters and digits must not be consecutive\n\nPassword: "

#define USERNAME_ERROR_MSG "\nError! Invalid username!\n\n"
#define PASSWORD_ERROR_MSG "\nError!Invalid password!\n\n"

#define ADMIN_USR_PROMPT_MSG "\nEnter new admin username\nUsername: "
#define ADMIN_PWD_PROMPT_MSG "\nEnter new amdin password\nPassword: "

#define SEARCH_PROMPT_MSG "\nEnter username to search\n\nUsername: "
#define DELETE_PROMPT_MSG "\nEnter username to delete\n\nUsername: "

#define UPDATE_PROMPT_MSG "\nEnter username to update\n\nUsername: "
#define UPDATE_USR_PROMPT_MSG "\nEnter new username\n\nUsername: "
#define UPDATE_PWD_PROMPT_MSG "\nEnter new password\n\nPassword: "

int login(Account* adminAccount);

void save(Account* accounts, size_t currentAccounts, Account* adminAccount, bool activeAdmin);
void load(Account* accounts, size_t* currentAccounts, Account* adminAccount, bool* activeAdmin);

void addAccount(Account* accounts, size_t* currentAccounts);
void displayAccounts(Account* accounts, size_t currentAccounts);
int searchAccount(Account* accounts, size_t currentAccounts, const char* usernameToSearch, size_t* occurrences);
void deleteAccount(Account* accounts, size_t* currentAccounts, const char* usernameToDelete, size_t* occurrences);
void updateAccount(Account* accounts, size_t currentAccounts, const char* username, size_t* occurrences);
void setAdminAccount(Account* adminAccount, bool* activeAdmin);

void getValidString(char* string, size_t stringSize, const char* promptMsg, const char* errorMsg, bool (*valid)(const char*));
void pause(void);

#endif // !MANAGER_H__