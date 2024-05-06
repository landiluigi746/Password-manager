#include <manager/account.h>
#include <assert.h>

/**
 * @brief Compares two accounts in general
 * 
 * @param A Pointer to the first account
 * @param B Pointer to the second account
 * 
 * @returns 1 if A > B, 0 otherwise
 */
int compareAccountsGeneral(const void* A, const void* B)
{
    int usernameResult = strCompare(((Account*)A)->username, ((Account*)B)->username);
    int passwordResult = strCompare(((Account*)A)->password, ((Account*)B)->password);

    if(usernameResult > 0 || (usernameResult == 0 && passwordResult > 0))
        return 1;
    else if(usernameResult == 0 && passwordResult == 0)
        return 0;
    else
        return -1;
}

/**
 * @brief Compares two accounts by username
 * 
 * @param A Pointer to the first account
 * @param B Pointer to the second account
 * 
 * @returns 1 if A > B, 0 if A == B, -1 if A < B
 */
int compareAccountsByUsername(const void* A, const void* B)
{
    return strCompare(((Account*)A)->username, ((Account*)B)->username);
}

/**
 * @brief Checks if the given username is valid
 * The username is valid if:
 * - It has at least MIN_USERNAME_LENGTH characters
 * - It has no control characters
 * 
 * @param username Username to check
 * 
 * @return True if the username is valid, false otherwise
 */
bool validUsername(const char* username)
{
    if(strLength(username) < MIN_USERNAME_LENGTH)
        return false;

    while(*username != '\0')
        if(iscntrl(*username++))
            return false;
    
    return true;
}

/**
 * @brief Checks if the given password is valid
 * The password is valid if:
 * - It has at least MIN_PASSWORD_LENGTH characters
 * - It has no control characters
 * - It has no consecutive digits
 * 
 * @param password Password to check
 * 
 * @return True if the password is valid, false otherwise
 */
bool validPassword(const char* password)
{
    size_t len = strLength(password);
    size_t i;
    char c1, c2;

    if(len < MIN_PASSWORD_LENGTH)
        return false;

    for(i = 0; i < len; i++)
    {
        c1 = *(password + i);
        
        if(i + 1 < len)
            c2 = *(password + i + 1);
        
        //if current char is a control character or is a digit and the next one is a digit and the difference is 1 or -1
        //then the password is invalid
        if(iscntrl(c1) || iscntrl(c2) || (isdigit(c1) && isdigit(c2) && (c1 == c2 - 1 || c1 == c2 + 1)))
            return false;
    }

    return true;
}

//  static function to get user preferences.
static void getUserPreferences(size_t* len, bool* upperChars, bool* numbers, bool* specialChars);
// static function to generate charset
static char* generateCharset(size_t* len, bool upperChars, bool numbers, bool specialChars);

/**
 * @brief Generates a random password
 * The password has the following characteristics:
 * - It has at least MIN_PASSWORD_LENGTH characters
 * - It has no control characters
 * - It has no consecutive digits
 * 
 * @param password Password to generate
 */
void randomPassword(char* password)
{
    size_t i, pswlen = 0, chsetlen = 0;
    bool upperChars, numbers, specialChars;
    char* charset, c, n;

    getUserPreferences(&pswlen, &upperChars, &numbers, &specialChars); // get user preferences
    charset = generateCharset(&chsetlen, upperChars, numbers, specialChars); // generate charset based on user preferences

    for(i = 0; i < pswlen;)
    {
        *(password + i) = *(charset + rand() % chsetlen);
        c = *(password + i);
        n = *(password + i - 1);

        //check if the generated char can fit in the password
        if(i == 0 || !(isdigit(c) && isdigit(n) && (c == n + 1 || c == n - 1)))
            i++;
    }

    *(password + i) = '\0';

    deallocate(charset);

    return;
}

/**
 * @brief Ciphers an account
 * 
 * @param account Account to cipher
 */
void cipherAccount(Account* account)
{
    strCipher(account->username, CIPHER_COUNT);
    strCipher(account->password, CIPHER_COUNT);
    strReverse(account->username, strLength(account->username));
    strReverse(account->password, strLength(account->password));

    return;
}

/**
 * @brief Deciphers an account
 * 
 * @param account Account to decipher
 */
void decipherAccount(Account* account)
{
    strReverse(account->username, strLength(account->username));
    strReverse(account->password, strLength(account->password));
    strDecipher(account->username, CIPHER_COUNT);
    strDecipher(account->password, CIPHER_COUNT);

    return;
}

// static functions implementation
static char* generateCharset(size_t* len, bool upperChars, bool numbers, bool specialChars)
{
    char* charset = (char*) allocate(sizeof(char) * 100);
    *len = strCopy("abcdefghijklmnopqrstuvwxyz", charset, 100);

#define EXPAND_CHARSET(str) *len = strConcat(charset, str, charset, 100)

    if(upperChars) EXPAND_CHARSET("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    if(numbers) EXPAND_CHARSET("0123456789");
    if(specialChars) EXPAND_CHARSET("~`!@#$%^&*()_-+=[]{}|\\,:;'\"<>.?/");

    assert(*len == strLength(charset));

#undef EXPAND_CHARSET

    return charset;
}

static void getUserPreferences(size_t* len, bool* upperChars, bool* numbers, bool* specialChars)
{
    char choice;

    do{
        printf("How long should the password be? (An integer between 8 and 35) ");
        input("%llu", len);
    } while(*len < MIN_PASSWORD_LENGTH || *len >= ACC_STR_SIZE);

    do{
        printf("\nDo you want upper characters in the password [Y/N]? ");
        input("%c", &choice);
    } while(choice != 'n' && choice != 'N' && choice != 'Y' && choice != 'y');

    *upperChars = (choice == 'Y' || choice == 'y');

    do{
        printf("\nDo you want numbers in the password [Y/N]? ");
        input("%c", &choice);
    } while(choice != 'n' && choice != 'N' && choice != 'Y' && choice != 'y');

    *numbers = (choice == 'Y' || choice == 'y');

    do{
        printf("\nDo you want special characters in the password [Y/N]? ");
        input("%c", &choice);
    } while(choice != 'n' && choice != 'N' && choice != 'Y' && choice != 'y');

    *specialChars = (choice == 'Y' || choice == 'y');

    return;
}