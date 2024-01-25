/*
COMP.SEC.300 - Kevät 2024
Heikki Metsäpuro hm25142
--------------------------
3. (1 point, C/C++)
Implement a program, that writes crypto safe random data
and writes it on a file.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define MAX_BLOCKSIZE 2048
#define CMD_LINE_OK 1

void read_data(char*, FILE*, int);
void parseCommandlineAndRun(char **);
int checkNumberInput(char *);

void printUsage();
void reportErrorAndExit(int);

// Entry point
int main(int argc, char**argv) {

    switch(argc){
        case 1:
        case 2:
            printUsage();
            break;
        case 3:
            parseCommandlineAndRun(argv);
            break;
        default:
            printUsage();
            reportErrorAndExit(1);
            break;
    }
}
/// @brief Genrates and writes random data to the target file
/// @param file Target fle
/// @param blocksize Number of bytes to write
void read_data(char* fname, FILE *file, int blocksize) {
    
    // Generate secure random data
    unsigned char data[blocksize];
    FILE* random = fopen("/dev/urandom", "r");
    fread(data, sizeof(data), 1, random);
    fclose(random);

    // Write data to the file
    fwrite(data, sizeof(data), 1, file);
    fclose(file);

    printf("Random data was written to %s.\n", fname);
}

/// @brief Prints usage instructionswrite
void printUsage() {
    puts("\nUsage:");
    puts("\twrite_crypto_data output_file number_of_blocks\n");
    puts("\t\toutput_file: File to receive data");
    puts("\t\tnumber_of_blocks: Size in bytes to write to the file\n");
}

/// @brief Prints out error messages
void reportErrorAndExit(int error){

    switch(error) {
        case 1:
            puts("");
            break;
        case 2:
            printf("\nError opening output file!\n");
            break;
        case 3:
            printf("\nError parsing command line arguments!\n");
            break;
        case 4:
            printf("\nError: too many blocks requested!\n");
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
    // 
    // Try to open the file [binary write mode]
    FILE* file = fopen(argv[1], "wb");
    if (file == NULL) {
        reportErrorAndExit(2);
    }

    // Check number of blocks
    int blocksize = 0;
    if (checkNumberInput(argv[2]) == CMD_LINE_OK) {
        blocksize = atoi(argv[2]);
        if(blocksize < 1 || blocksize > MAX_BLOCKSIZE) {
            reportErrorAndExit(4);
        }
    }
    else {
        reportErrorAndExit(3);
    }

    read_data(argv[1], file, blocksize);

}

int checkNumberInput(char * input) {

    int success = 0;

    regex_t r_exp;
    int comp_r_ex = regcomp(&r_exp, "^[0-9]*$", 0);
    
    if(comp_r_ex) {
        // Failed to build regexp
        reportErrorAndExit(3);
    }

    comp_r_ex = regexec(&r_exp, input, 0, NULL, 0);
    switch(comp_r_ex) {
        case 1:
            success = 0;
            break;
        case 0:
            success = CMD_LINE_OK;
            break;
        default:
            // Failed to build regexp
            success = 3;
            break;
    }
    regfree(&r_exp);

    if(success>1)
        // Report and exit
        reportErrorAndExit(success);

    return success;
}