#include <stdio.h>     
#include <string.h> 
#include <stdio.h> 
#include <stdlib.h> 

#include <malloc.h> 

#include <openssl/hmac.h> 
#include <openssl/evp.h> 
#include <openssl/engine.h> 
#include <openssl/aes.h>
#include <openssl/rand.h> 

#define KEY_LEN      32
#define KEK_KEY_LEN  20
#define ITERATION     1 

int test()
{
    size_t i;
    unsigned char *out;
    const char pwd[] = "password";
    unsigned char salt_value[] = {'s','a','l','t'};

    out = (unsigned char *) malloc(sizeof(unsigned char) * KEK_KEY_LEN);

    printf("pass: %s\n", pwd);
    printf("ITERATION: %u\n", ITERATION);
    printf("salt: "); for(i=0;i<sizeof(salt_value);i++) { printf("%02x", salt_value[i]); } printf("\n");

    // int x = PKCS5_PBKDF2_HMAC_SHA1("", 0, "", 0, 1, 1, "");

    if( PKCS5_PBKDF2_HMAC_SHA1(pwd, strlen(pwd),
        salt_value, sizeof(salt_value), 
        ITERATION, KEK_KEY_LEN, out) != 0 )
    {
        printf("out: "); for(i=0;i<KEK_KEY_LEN;i++) { printf("%02x", out[i]); } printf("\n");
    }
    else
    {
        fprintf(stderr, "PKCS5_PBKDF2_HMAC_SHA1 failed\n");
    }
 
    free(out);

    return 0;
}
