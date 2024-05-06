/**
 * Header file for the Account struct and related functions
 * 
 * Author: landiluigi746
 * Date: 2024-04-28
 * Github: https://github.com/landiluigi746
 */

#ifndef ACCOUNT_H__
#define ACCOUNT_H__

#include <llib/llib.h>

#define ACC_STR_SIZE 36
#define CIPHER_COUNT 45
#define MIN_USERNAME_LENGTH 6
#define MIN_PASSWORD_LENGTH 8

typedef struct Account
{
    char username[ACC_STR_SIZE];
    char password[ACC_STR_SIZE];
} Account;

int compareAccountsGeneral(const void* A, const void* B);
int compareAccountsByUsername(const void* A, const void* B);
bool validUsername(const char* username);
bool validPassword(const char* password);
void randomPassword(char* password);
void cipherAccount(Account* account);
void decipherAccount(Account* account);

#endif // !ACCOUNT_H__