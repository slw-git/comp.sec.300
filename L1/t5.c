/*COMP.SEC.300 - Lesson 1
Heikki Metsäpuro hm25142

T5: Write a program that contains printf vulnerability (0,5 points)

Sample run:
$ ./t5
Enter your name: 12345679
Hello, 12345679!

$ ./t5
Enter your name: 123456789987654
Hello, 123456789987654!
*** stack smashing detected ***: terminated
Aborted (core dumped)

$ ./t5
Element <3> = <(null)>

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void printElem(char **elems, int i ) {
	printf("Element <%d> = <%s>\n", i, elems[i] );
}

int main(int argc, char **argv ) {
/*
    char buffer[8];
    printf("Enter your name: ");
    scanf("%s", buffer);
    printf("Hello, ");
    printf(buffer);
    printf("!\n");
    return 0;
*/    	
	char *elements[3];
	elements[0] = "00000";
	elements[1] = "11111";
	elements[2] = "22222";

	printElem(elements, 3);

	return 0;
}
