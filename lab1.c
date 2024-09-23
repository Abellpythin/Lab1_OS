#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lab1.h"
/*
 * readString - reads a line from a file given by
 * fileName and returns it as a c-string.  The line
 * return is removed from the string.
 * 
 * fileName is c-string representing the file to read.
 * 
 */

#define MAX_LINE_LENGTH 1024 // Define the maximum length for a line
char* readString(char* fileName){
    // Open the specified file in read mode
    FILE *file = fopen(fileName, "r");
    // Check if the file was successfully opened
    if (!file) {
        error("Could not open file"); // Print error message
        return NULL; // Return NULL if the file could not be opened
    }

    // Allocate memory for the line to be read
    char *line = (char*)malloc(MAX_LINE_LENGTH);
    // Check if memory allocation was successful
    if (!line) {
        error("Memory allocation failed"); // Print error message
        fclose(file); // Close the opened file
        return NULL; // Return NULL if memory allocation fails
    }

    // Read the first line from the file
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line); // Free allocated memory if reading fails
        fclose(file); // Close the opened file
        return NULL; // Return NULL if no line was read
    }

    // Create a temporary file to store the remaining lines
    FILE *tempFile = fopen("temp.txt", "w");
    // Check if the temporary file was successfully opened
    if (!tempFile) {
        perror("Could not open temporary file"); // Print error message
        free(line); // Free allocated memory
        fclose(file); // Close the opened file
        return NULL; // Return NULL if the temporary file cannot be opened
    }

    char buffer[MAX_LINE_LENGTH]; // Buffer to hold lines from the original file
    // Write all lines except the first one to the temporary file
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        fputs(buffer, tempFile); // Write the buffer to the temporary file
    }

    // Close the original and temporary files
    fclose(file);
    fclose(tempFile);

    // Remove the original file from the filesystem
    remove(fileName);
    // Rename the temporary file to the original file's name
    rename("temp.txt", fileName);

    return line; // Return the line read from the file
}



/*
 * mysteryExplode - takes a string of characters and explodes it
 * as follows:
 * 
 * A non-empty string such as "Code" is turned into "CCoCodCode".
 *
 *   Return a new string similar to the string given above.
 *
 *  Example:
 *   mysteryExplosion("Code") --> "CCoCodCode"
 *   mysteryExplosion("abc") --> "aababc"
 *   mysteryExplosion(":)") --> "::)"
 * 
 */
char* mysteryExplode(const char* str){
    //TODO: Replace this line with your code
}