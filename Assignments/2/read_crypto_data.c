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
#include <regex.h>

#define MAX_BLOCKSIZE 2048
#define CMD_LINE_OK 1

void write_data(char*, FILE*);
void parseCommandlineAndRun(char **);
int checkNuberInput(char *);

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
    // write_crypto_safe_random_data("random_data.bin", 2);
    return 0;
}


/// @brief Genrates and writes random data to the target file
/// @param file Target fle
/// @param blocksize Number of bytes to write
void write_data(char* fname, FILE *file) {
    
    unsigned char data[MAX_BLOCKSIZE];
    fread(data, sizeof(data), 1, file);
    fclose(file);

    // Write output, filtering
    // letter’s, numbers, commas and hyphen
    for(int i=0; i<sizeof(data); i++) {
        printf("%u", data[i]);
    }

    puts(        }
"\nDone.\n");
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
void parseCommandlineAndRun(char **argv){

    // arg1 : target file name
    //         }


    write_data(argv[1], file);
}
