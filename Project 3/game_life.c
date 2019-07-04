#include "gamelife.h"


//Rows and cols used by printBoard, evolve, countLiveNeighbor and createBoard
int **gameBoard;
char **buffer;

void printBoard(int rows, int cols){
    printf("\n");
    int i = 0;
    int k = 0;

    //traverse the entire gameBoard printing all values
    for (i = 0; i < rows; i++) {
        printf("\n");
        for (k = 0; k < cols; k++){
            printf("%d", gameBoard[i][k]);
        }
    }
}

void evolve(int rows, int cols) {

    //temporary gameBoard
    int **newBoard;

    //hold the sum of a cell alive neighbours
    int sum;

    //counter variable
    int i = 0;

    //counter variable
    int k = 0;

    //counter for the columns
    int  colCounter = 0;

    //dynamic allocation of memory for the temporary gameBoard
    newBoard = (int **) malloc(sizeof(int *) * rows);

    for(i = 0; i < rows; ++i) {
        newBoard[i] = malloc(cols * sizeof *newBoard[i]);
    }

    //loops through each cell in the board
    for (i = 0; i < rows; i++) {
        for (k = 0; k < cols; k++) {

            //calculates the sum of living neighbors
            sum = countLiveNeighbor(i, k,rows, cols);

            //if the cell has 3 live neighbor cells it is alive
            if (sum == 3) {
                newBoard[i][k] = 1;
            }
            //if the cell has less than 2 or more than 3 live neighbor cells it dies
            else if (gameBoard[i][k] == 1 && (sum < 2 || sum > 3)) {
                newBoard[i][k] = 0;
            }
            //if the current cell is 1 and has 2 live neighbor cells it lives
            else if (gameBoard[i][k] == 1 && sum == 2) {
                newBoard[i][k] = 1;
            }
            //any other situation the cell remains the same
            else {
                newBoard[i][k] = gameBoard[i][k];
            }
        }
    }

    //updates the gameboard and the buffer
    k = 0;
    for(i = 0; i < rows*cols; i++){
        if (!(colCounter-cols)) {
            colCounter = 0;
            k++;
        }
        if(k < rows){
            gameBoard[k][colCounter] = newBoard[k][colCounter];
            buffer[2][i]  = gameBoard[k][colCounter] + 48;
            colCounter++;
        }
    }

    //free the newboard memory
    for (i = 0; i < rows; i++) {
        free(newBoard[i]);
    }
    free(newBoard);

    printBoard(rows, cols);
}

int countLiveNeighbor(int row, int col, int rows, int cols) {
    //sum of neighbors
    int sum = 0;

    //allows for the neighbors to be searched
    int i = -1;
    int k = -1;
    int iN = 2;
    int kN = 2;

    //each if statement checks if the cell is on the edge
    if( row == 0){
        i++;
    }else if(row == rows-1) {
        iN--;
    }

    if( col == 0){
        k++;
    }else if (col == cols-1) {
        kN--;
    }

    int j;
    //collects sum of all neighbor cells
    for (; i < iN; i++) {
        for (j = k; j < kN; j++) {
            if(gameBoard[i + row][j + col] == 1) {
                sum++;
            }
        }
    }

    //makes sure to not count itself
    if(gameBoard[row][col] == 1){
        sum --;
    }

    return sum;
}

void menu(int rows, int cols){

    //users pick on which function they want
    char option;

    //file name to be saved or loaded
    char fileName[100];

    printf("\nPlease enter s to save, l to load a new file, c to continue, or q to quit \n");
    scanf(" %c", &option);

    switch (option) {

        //save
        case 's':
            printf("Enter file you would like to save to\n");
            scanf(" %s", fileName);
	        write_file(fileName, buffer, (rows)*cols);
            printf("Saved\n");
            break;
        //load
        case 'l':
            printf("Enter the name of the file you would like to load\n");
            scanf(" %s", fileName);
            int i;
            for (i = 0; i < rows; i++) {
                free(gameBoard[i]);
            }
            free(gameBoard);
            read_file(fileName, buffer);
            printf("Loaded\n");
            createBoard();
            break;
        //continue
        case 'c':
            printf("How many iterations would you like to complete?\n");
            int numIts, iterations;
            scanf(" %d", &numIts);
            iterations = numIts;
            while (numIts > 0) {
                evolve(rows, cols);
                numIts--;
            }
            printf("\n%d iterations were just made\n", iterations);
            menu(rows, cols);
            break;
        //quit
        case 'q':
            printf("Good Bye\n");
            exit(0);
        //default
        default:
            break;
    }
}

void createBoard(){
    //counts the rows
    int rowCounter = 0;
    //counts the columns
    int colCounter = 0;
    //counter variable
    int i = 0;
    int rows, cols;
    //set the values for row and col
    rows = atoi(buffer[0]);
    cols = atoi(buffer[1]);

    //makes sure they are possible dimensions
    if( rows <= 0 || cols <= 0){
        printf("Game Board must have more than 0 rows or 0 columns");
        exit(0);
    }

    //allocates memory for the gameboard
    gameBoard = (int **) malloc(sizeof(int *) * rows);

    for(i = 0; i < rows; ++i) {
        gameBoard[i] = malloc(cols * sizeof *gameBoard[i]);
    }

    //populated gameBoard with the values from the file
    int gridSize = (rows)*cols;
    for(i = 0; i < gridSize; i++){
        if (!(colCounter-cols)) {
            colCounter = 0;
            rowCounter++;
        }
        if(rowCounter < rows){
            if(buffer[2][i] == 0){
                gameBoard[rowCounter][colCounter] = buffer[2][i];
            }else{
                gameBoard[rowCounter][colCounter] = (int) buffer[2][i] -48;
            }
            colCounter++;
        }
    }

    printBoard(rows, cols);
    printf("\nOriginal Board\n");
    }

int main(int argc, char **argv) {

    int i, k, rows, cols;

    //dynamic allocation of memory for the temporary gameBoard
    buffer = malloc(sizeof(int *) * 3);

    for(i = 0; i < 3; ++i) {
        buffer[i] = malloc(200 * sizeof *buffer[i]);
    }

    //initialize all buffer values
    for (i = 0; i < 3; i++) {
        for (k = 0; k < 200; k++){
            buffer[i][k] = ' ';
        }
    }

    //checks there is a file to read from
    if (argc == 1) {
        printf("Must supply file name\n");
        exit(0);
    }

    //open and read the file containing the gameBoard
    read_file(argv[1], buffer);

    rows = atoi(buffer[0]);
    cols = atoi(buffer[1]);
    
    //creates the gameBoard
    createBoard();

    //run the prompt for the user to change game
    menu(rows, cols);

    //free the memory for the gameBoard
    for (i = 0; i < rows; i++) {
        free(gameBoard[i]);
    }
    free(gameBoard);

    //free the memory for buffer
    for (i = 0; i < 3; i++) {
        free(buffer[i]);
    }
    free(buffer);

}
