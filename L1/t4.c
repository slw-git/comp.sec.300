/*COMP.SEC.300 - Lesson 1
Heikki Metsäpuro hm25142

T4: Write a program that causes function pointer overflow (0,5 points)

gcc t4.c -o t4 -O0 -fmudflap -fmudflapth -fmudflapir -fno-stack-protector -z execstack -no-pie
gcc t4.c -o t4 -fno-stack-protector
gcc t4.c -o t4  -fstack-protector-strong

Sample runs:
$ ./t4
Enter some text: 12345
You have been hacked!

$ ./t4
Enter some text: 123456789
You have been hacked!
Segmentation fault (core dumped)

*/

#include <stdio.h>

void vulnerable_function(void (*function_pointer)(void)) {
    char buffer[8];
    printf("Enter some text: ");
    gets(buffer);
    function_pointer();
}

void malicious_function() {
    printf("You have been hacked!\n");
}

int main() {
    void (*function_pointer)(void) = &malicious_function;
    vulnerable_function(function_pointer);
    return 0;
}
