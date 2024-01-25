/*
COMP.SEC.300 - Kevät 2024
Heikki Metsäpuro hm25142
--------------------------
4. (1 point, Python or C/C++)
Write a program that reads a file and filters
all characters except letter’s, numbers, commas and hyphen.
Print the result on the screen.
If you made exercise 3, use the encrypted file to test the program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_BLOCKSIZE 2048
#define CMD_LINE_OK 1

void read_data(char*, FILE*);
void parseCommandlineAndRun(char **);
int isOtherChar(char);

void printUsage();
void reportErrorAndExit(int);

// Entry point
int main(int argc, char**argv) {

    switch(argc){
        case 1:
            printUsage();
            break;
        case 2:
            parseCommandlineAndRun(argv);
            break;
        default:
            printUsage();
            reportErrorAndExit(1);
            break;
    }

    return 0;
}


/// @brief Reads random data from the source file
/// @param file Source fle
void read_data(char* fname, FILE *file) {
    
    unsigned char data[MAX_BLOCKSIZE];
    fread(data, sizeof(data), 1, file);
    fclose(file);

    // Write output, filtering
    // letter’s, numbers, commas and hyphen
    for(int i=0; i<sizeof(data); i++) {
        if(isalnum(data[i]))
            printf("%c", data[i]);
        else if(isOtherChar(data[i]))
            printf("%c", data[i]);
    }

    puts("\nDone.\n");
}

/// @brief Prints usage instructionswrite
void printUsage() {
    puts("\nUsage:");
    puts("\tread_crypto_data input_file\n");
    puts("\t\tinput_file: File to read data from\n");
}

/// @brief Prints out error messages
void reportErrorAndExit(int error){

    switch(error) {
        case 1:
            printUsage();
            break;
        case 2:
            printf("\nError opening input file!\n");
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

    // arg1 : target file name
    // 
    // Try to open the file [binary write mode]
    FILE* file = fopen(argv[1], "rb");
    if (file == NULL) {
        reportErrorAndExit(2);
    }

    read_data(argv[1], file);
}

int isOtherChar(char c) {

    int ok = 0;
    
    switch (c) {
    case ',':
    case '-':
        ok = 1;
        break;
    default:
        ok = 0;
        break;
    }

    return ok;
}