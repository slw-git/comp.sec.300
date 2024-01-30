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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user.h"
#include "crypt.h"

int addUser(char *userName, char *salt, FILE *db) {

}

void buildUserPWRow(char *userName, char *userPW) {
    
    unsigned char *hash = malloc(sizeof(unsigned char) * KEK_KEY_LEN);
    generateRandomSaltedAndHashedPW(userPW, hash);

    printf("%s", userName);

    for(int i=0; i<KEK_KEY_LEN; i++)
        printf("%02x", hash[i]);
    puts(":::");
    puts("");
    free(hash);


}