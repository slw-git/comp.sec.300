/*
COMP.SEC.300 - Kevät 2024
Heikki Metsäpuro hm25142
--------------------------
Exercise 2 (2 points):
Implement a program that authenticates a user
with a user name and password.
Hashes of passwords are stored in a file.
Please notice to use random salt.

https://www.gnu.org/software/libc/manual/html_node/Unpredictable-Bytes.html

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/random.h>
#include <errno.h>
#include <openssl/evp.h>

#include "crypt.h"

void ping() {
    puts("Ping from crypt.c");
}

int generateRandomSaltedAndHashedPW(char *userPW, char *hash) {

    int pwLen = strlen(userPW);
    char salt[KEY_LEN];
    char saltedPW[KEY_LEN+pwLen];
    char *hashedSaltedPW;

    // size_t i;
    // unsigned char *out;
    // out = (unsigned char *) malloc(sizeof(unsigned char) * KEK_KEY_LEN);

    // 1) Generate random salt
    int grslt = generateRandomSalt(salt);    

    // 2) Append salt + pw = sltpw
    strcpy(saltedPW, salt);
    strcat(saltedPW, userPW);

    if(! PKCS5_PBKDF2_HMAC_SHA1(userPW, strlen(userPW),
        saltedPW, sizeof(saltedPW), 
        ITERATION, KEY_LEN, hash) != 0 )
    {
        fprintf(stderr, "PKCS5_PBKDF2_HMAC_SHA1 failed\n");
    }
 
    // free(out);

    // 3) Hash (salpw)
    /*
    if( PKCS5_PBKDF2_HMAC_SHA1(userPW, strlen(userPW),
        saltedPW, sizeof(saltedPW), 
        ITERATION, KEK_KEY_LEN, hashedSaltedPW) != 0 )
    {
        printf("out: "); 
        for(int i=0;i<KEK_KEY_LEN;i++) { printf("%02x", hashedSaltedPW[i]); } printf("\n");
    }
    else
    {
        fprintf(stderr, "PKCS5_PBKDF2_HMAC_SHA1 failed\n");
    }
    */
    return 0;
}

int checkRandomSaltedAndHashedPW(char *userPW, char *salt, char *hash) {
    
    // 1) Concat salt + pw => spw
    // 2) Hash (pw) => chash
    // 3) Compare (chash, hash)

    return 0;
}

int generateRandomSalt(char *salt) {

    // Generate secure random data
    FILE* random = fopen("/dev/urandom", "r");
    if(random < 0) {
        return -1;
    }
    else {
        ssize_t r = fread(salt, sizeof(salt), 1, random);
        if(r < 0) {
            return -2;
        }
    }

    fclose(random);
    return 0;
}

/*
    // Generate secure random data
    unsigned char data[blocksize];
    FILE* random = fopen("/dev/urandom", "r");
    fread(data, sizeof(data), 1, random);
    fclose(random);
*/