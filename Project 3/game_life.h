#ifndef GAMEOFLIFE_GAMELIFE_H
#define GAMEOFLIFE_GAMELIFE_H
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "file_utilities.h"
#endif //GAMEOFLIFE_GL_H

/*****************************************************************
 *Conway's Game of Life. Includes dynamic memory allocation, import
 * and exporting files, and a TextUI as a display. In this game
 * 0 represents an empty cell, 1 represents the living, and an empty
 * cell can be any other number 2-9. The sources used are:
 *
 * http://web.stanford.edu/~cdebs/GameOfLife/
 * for the overall logic of the game
 *
 * https://www.geeksforgeeks.org/dynamically-allocate-2d-array-c/
 * for information on how it initialize and access 2D arrays
 *
 * Created on on 02/05/2018
 *****************************************************************/

/*The pointer to the gameBoard*/
int **gameBoard;

/*The buffer holds values of the gameBoard*/
char **buffer;



/*****************************************************************
 *Prints the current gameBoard to display the screen
 *****************************************************************/
void printBoard(int, int);

/*****************************************************************
 *With help from the countLiveNeighbor function this method applies
 * the logically rules of Conway's Game of life to the current
 * gameBoard and produces the next generation/iteration of cells.
 *****************************************************************/
void evolve(int, int);

/*****************************************************************
 *This method is designed to determine the number of of living
 * neighbors any given cell has to help calculate the next
 * generation
 *
 * @param col is the col of the cell that needs to have its
 *  neighbours sums calculated
 * @param row is the row of the cell that needs to have its
 *  neighbours sums calculated
 *  @return sum of all the living neighbors
 *****************************************************************/
int countLiveNeighbor(int, int, int, int);

/*****************************************************************
 *Prints the option for the user to manipulate the game. Their
 * options include save to a file, load a new file for a game,
 * continue to create iterations of the current gameBoard or
 * quit. This works with the printBoard method to create the
 * textUI.
 *****************************************************************/
void menu(int, int);

/*****************************************************************
 * Takes in the information from the file and uses it to create
 * the gameBoard.
 *
 * @param rowstr
 * @param colstr
 * @param grid
 ****************************************************************/
void createBoard();

/*****************************************************************
 *This method controls the overall game play of the Game of Life.
 *
 * @return int for error catching
 *****************************************************************/
int main(int argc, char **argv) ;
