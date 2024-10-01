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

char* readString(char* fileName){
    // Open the specified file in read mode
    FILE *file = fopen(fileName, "r");
    // Check if the file was successfully opened
    if (!file) {
        perror("Could not open file"); // Print error message
        return NULL; // Return NULL if the file could not be opened
    }

    // Allocate memory for the line to be read
    char *line = (char*)malloc(MAX_LINE_LEN);
    // Check if memory allocation was successful
    if (!line) {
        perror("Memory allocation failed"); // Print error message
        fclose(file); // Close the opened file
        return NULL; // Return NULL if memory allocation fails
    }

    // Read the first line from the file
    if (fgets(line, MAX_LINE_LEN, file) == NULL) {
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

    char buffer[MAX_LINE_LEN]; // Buffer to hold lines from the original file
    // Write all lines except the first one to the temporary file
    while (fgets(buffer, MAX_LINE_LEN, file) != NULL) {
        fputs(buffer, tempFile); // Write the buffer to the temporary file
    }

    // Close the original and temporary files
    fclose(file);
    fclose(tempFile);
    line[strcspn(line, "\n")] = 0; //(removes new line)- removes the newline character 
    //from the end of the string line by:replacing it with a null terminator.

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
  int len = strlen(str); // calculate the length of the input string str using the strlen function, 
  //which returns the number of characters in the string excluding the null terminator.
    // Calculate the length of the resulting string
    int resultLen = 0; 
    for (int i = 1; i <= len; i++) {
        resultLen += i;  // Add lengths of "string"
    }//loop calculates the total length of the resulting string. Add the lengths of progressively longer prefixes of str. 
    //For each i from 1 to len, we add i to resultLen. (Above)

    // Allocate memory for the result string
    char* result = (char*)malloc((resultLen + 1) * sizeof(char));
    if (!result) {
        return NULL;  // Handle memory allocation failure
    }
    int pos = 0;
    for (int i = 1; i <= len; i++) {
        // Copy the first 'i' characters from the input string
        strncpy(result + pos, str, i);
        pos += i;  // Move the position forward by 'i'
    }
    result[resultLen] = '\0';  // Null-terminate the string 
    // substrings have been copied, we add a null terminator at the end of the result string to mark its end.

    return result;
}
