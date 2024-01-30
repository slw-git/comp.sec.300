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
#include <ctype.h>

#include "user.h"
#include "crypt.h"

// void parseCommandlineAndRun(char **);
void printUsage();
void reportErrorAndExit(int, char*);
int test();

int main(int argc, char **argv) {



    switch(argc){
        case 1:
        case 2:
        case 3:
            printUsage();
            break;
        case 4:
            char hash[KEK_KEY_LEN];
            buildUserPWRow(argv[1], argv[2]);
            // printf("Hash <%s>", hash);
            // generateRandomSaltedAndHashedPW(argv[2], hash);
            // printf("Hash: <%d>\n", generateRandomSaltedAndHashedPW(argv[2]));
            // test();
            break;
        default:
            printUsage();
            reportErrorAndExit(1, "");
            break;
    }

    return 0;    
}

/// @brief Prints out error messages
void reportErrorAndExit(int error, char *msg){

    switch(error) {
        case 1:
            printUsage();
            break;
        case 2:
            printf("\nError opening db file!\n");
            break;
        case 3:
            // Key generetion error
            printf("Error generating key <%s>", msg);
            break;
        default:
            puts("Unknown error!");
            break;
    }
    printUsage();
    exit(error);
}

/// @brief Parses and checks command line arguments and executes the generator
/// @brief If everythoing is ok, executes the generator
/// @param argv 
/// @brief If everythoing is ok, executes the generator
/// @param argv 
void parseCommandlineAndRun(char **argv){

}

/// @brief Prints usage instructions
void printUsage() {
    puts("\nUsage (v1.0.0):");
    puts("\tAuthenticate username password userdb\n");
    puts("\t\tusername: Name for the user to be autheticated (max 12 chars)");
    puts("\t\tpassword: Password for the user (max 12 chars)");
    puts("\t\tuserdb: File name of the user database");
    puts("\tReturns:");
    puts("\t\t 0: User exists and password was ok");
    puts("\t\t 1: User was added");
    puts("\t\t 2: User's authetication was denied (wrong passord)\n");
}

void createKey() {
    
/*     int result = generateRandomSaltedAndHashedPW();
    if(result > 0) {
        reportErrorAndExit(3, "itoa(result)");
    }
 */
}