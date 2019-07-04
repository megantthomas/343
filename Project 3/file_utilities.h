//
// Created by owner on 2/8/2018.
//

#ifndef GAMEOFLIFE_FILE_UTILIES_H
#define GAMEOFLIFE_FILE_UTILIES_H
#include "gamelife.h"
#endif //GAMEOFLIFE_FILE_UTILIES_H

/*****************************************************************
 * This C file assists in file utilities such as reading from a
 * file and writing to a different one.
 *
 * Created on 02/05/2018
 *****************************************************************/

/*****************************************************************
 *Reads information in from a file
 *
 * @param a pointer to the file that holds the game data
 * @param a buffer
 * @return int that can be used to send back the size of the file
 * loaded in, to check for errors, etc.
 *****************************************************************/
int read_file(char *file, char **buffer);

/*****************************************************************
 *This method writes information to a file
 *
 * @param a pointer to a file that will hold our saved data
 * @param a buffer
 * @param the size of the file needed
 * @return int that can be used to send back the size of the file
 * loaded in, to check for errors, etc.
 *****************************************************************/
int write_file(char *fileName, char **buffer, int size);
