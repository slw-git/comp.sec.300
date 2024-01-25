/*COMP.SEC.300 - Lesson 1
Heikki Metsäpuro hm25142

T1: Write a program that causes unlimited buffer overflow (0,5 points)

Sample run:
$ ./t1
L1.T1: A program that causes unlimited buffer overflow

Input a string with a length more than <12> asdfghjklqwertyuiozxcvbn
Input was <asdfghjklqwertyuiozxcvbn> of length <24>
About to copy input to buffer...
Input was copied to buffer_cpy

Done.

Segmentation fault (core dumped)
*/


#include <stdio.h>
#include <string.h>

#define BUF_IN 12
#define BUF_CPY 2

int main(int argc, char **argv) {

    char buffer_in[BUF_IN];
    char buffer_cpy[BUF_CPY];

    puts("L1.T1: A program that causes unlimited buffer overflow\n");
    printf("Input a string with a length more than <%d> ", BUF_IN);

    // gets(buffer_in);
    scanf("%s", buffer_in);
    printf("Input was <%s> of length <%lu>\n", buffer_in, strlen(buffer_in));

    puts("About to copy input to buffer...");
    strcpy(buffer_cpy, buffer_in);
    printf("Input was copied to buffer_cpy\n\n");

    puts("Done.\n");

    return 0;
}
