/*COMP.SEC.300 - Lesson 1
Heikki Metsäpuro hm25142

T2: Write a program that causes off by one overflow (0,5 points)

Sample run:
$ ./t2
L1.T2: A program that causes off by one overflow

Calling OffByOne
I am just a poor

Done.

Segmentation fault (core dumped)
 */


#include <stdio.h>
#include <string.h>

void offByOne(char*);

int main(int argc, char **argv) {


    puts("L1.T2: A program that causes off by one overflow\n");
    puts("Calling OffByOne");
    offByOne("I am just a poor boy, though my story's seldom told");
    puts("\nDone.\n");

    return 0;
}

void offByOne (char *s)
{
    char buffer[17];
    memset(buffer, 0, sizeof(buffer));
    strncat(buffer, s, sizeof(buffer));
    puts(buffer);
}