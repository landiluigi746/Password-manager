# Password Manager in C

This program is a simple console-based password manager written in C.
It allows you to store usernames and passwords and manage them.
You can also set an admin account to protect your data.

## Features

- Store usernames and passwords
- Display all credentials
- Update, search and delete credentials
- Set an admin account (if you do so, the program will ask you to enter the admin credentials on startup)
- Data encryption

## Installation

You have two ways to install this program:
1. Download the latest version of the program
2. Clone the repository and use `make` to build and run the program

## Usage

1. Open the program
2. The program will display a menu with the following options

```
add - Insert a new password
display - Display all passwords
search - Search an account by username
delete - Delete a password
update - Update an existing account
set - Set admin account
exit - Exit program
```

3. Choose the desired option
4. Follow the prompts

Note: The program saves on exit and uses a binary file to store the data.