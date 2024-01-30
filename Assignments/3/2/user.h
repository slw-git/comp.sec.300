/*
COMP.SEC.300 - Kevät 2024
Heikki Metsäpuro hm25142
--------------------------
Exercise 2 (2 points):
Implement a program that authenticates a user
with a user name and password.
Hashes of passwords are stored in a file.
Please notice to use random salt.
*/

// Defines a user

#ifndef __USER_H__
#define __USER_H__

#define MAX_USERNAME_LENGTH 12
#define SALT_LENGTH 32

struct USER {
    char user_name[MAX_USERNAME_LENGTH];
    char salt[SALT_LENGTH];
    char password_hash[256];
} ;

int addUser(char *userName, char *salt, FILE *db);
void buildUserPWRow(char *userName, char *userPW);

#endif