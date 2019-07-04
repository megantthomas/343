//
// Created by owner on 2/8/2018.
//

#include "file_utilities.h"

int read_file(char *file, char **buffer) {


    //character array to hold the current life from the file
    char line[200];

    //counter variable
    int counter =0 ;

    //open the given file
    FILE *inputFile;
    inputFile = fopen(file, "r");

    //checks input file
    if (file == NULL) {
        printf("Cannot open file or file does not exist\n");
        exit(0);
    }

    //sets rows and columns to the values provided
    int i;
    while (fgets(line, 200,inputFile )) {
        if (counter == 0) {
            for(i = 0; i <  200; i++ ) {
                if(line[i] != '\0') {
                    buffer[0][i] = line[i];
                }else{
                    i = 200;
                }
                            }
        } else if (counter == 1){
            for(i = 0; i <  200; i++ ) {
                if (line[i] != '\0') {
                    buffer[1][i] = line[i];
                } else {
                    i = 200;
                }
            }
        }else{
           break;
        }
        counter++;
    }

    //copies the numbers for the board into the buffer variable
    for(i = 0; i <  200; i++ ) {
        buffer[2][i] = line[i];
    }

    //closes the file
    fclose(inputFile);
    return 0;
}

int write_file(char *fileName, char **buffer, int size){
    int i;

    //opens the provided file
    FILE *file;
    file = fopen(fileName, "w");

    //checks file
    if (file == NULL) {
        printf("Cannot open file or file does not exist\n");
        exit(0);
    }

    //prints the row size to the file
    for(i = 0; i < size; i++){
        if( isdigit(buffer[0][i])) {
            fprintf(file, "%c", buffer[0][i]);
        }
    }

    fprintf(file, "\n");
     //prints the column size to the file
    for(i = 0; i < size; i++) {
        if( isdigit(buffer[1][i])) {
            fprintf(file, "%c", buffer[1][i]);
        }
    }

    fprintf(file, "\n");
    // /prints the current board to the file
    for(i = 0; i < size; i++){
        fprintf(file, "%c", buffer[2][i]);
    }

    //closes the file
    fclose(file);
    return 0;

};
