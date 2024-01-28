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

#ifndef __CRYPT_H__
#define __CRYPT_H__

#define KEY_LEN      256
#define KEK_KEY_LEN  20
#define ITERATION     1 


void ping();
    
int generateRandomSalt(char*);    
int generateRandomSaltedAndHashedPW(char *userPWHash);
int checkRandomSaltedAndHashedPW(char *userPW, char *salt, char *hash);

#endif