/*COMP.SEC.300 - Lesson 1
Heikki Metsäpuro hm25142

T3: Write a program that causes heap overflow (0,5 points)

Sample run:
$ ./t3
L1.T3: A program that causes heap overflow

Calling heapOverFlow...
0
100000
200000
300000
400000
500000
600000
700000
800000
900000
1000000
1100000
1200000
1300000
1400000
1500000
1600000
1700000
1800000
1900000
2000000
2100000
Killed
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void heapOverFlow();

int main(int argc, char **argv) {

    puts("L1.T3: A program that causes heap overflow\n");
    puts("Calling heapOverFlow...");
    heapOverFlow();
    puts("\nDone.\n");

    return 0;
}

void heapOverFlow()
{
    for (long i=0; i<10000000000; i++)
    {
        // Allocating memory without freeing it
        // printf("%lu\n", l);
        if(i % 100000 == 0)
            printf("%lu\n", i);
        long *ptr = (long *)malloc(i);
        // free(ptr);
    }
}