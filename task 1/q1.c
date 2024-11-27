#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define GRID_SIZE 3
#define TREASURE_COUNT 6
#define MIN_TREASURE_COUNT 5
#define MAX_MOVES 10

char getInput()
/*
      This function take a valid input from the user
*/
{
    char input;
    int c;

    do {
        input = getchar();
        //CLEAN THE BUFFER
        while ((c = getchar()) != '\n' && c != EOF);

    } while (input == '\n' || input == '\t' || input == ' ');
    return input;
}

void initialize_(int  arr[GRID_SIZE][GRID_SIZE])
/*
      This function gets an int array
      and put _ in every cell
*/
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            arr[i][j] = '_';
        }
    }
}


void rand_locations_treasures(int arr[GRID_SIZE][GRID_SIZE])
/*
      This function gets an int array
      and put 6 T in random places
*/
{

    int num_of_treasures = 0;
    int i_location, j_location;
    initialize_(arr);

    while (num_of_treasures < TREASURE_COUNT)
    {
        i_location = rand() % 3;
        j_location = rand() % 3;
        if (arr[i_location][j_location] == '_')
        {
            arr[i_location][j_location] = 'T';
            num_of_treasures++;
        }
    }
}

int move (int arr[GRID_SIZE][GRID_SIZE], int arr1[2], int is_T)
/*
      This function gets a move: two dimensial array (the grid), int array that contains counter of moves and treasures, an integer that check if there is a T in P loc
      and change the place of the player on the grid,
      collect the treasures, count the numbers of the moves
*/
{
    char direction;
    if(arr[0][0] == 'P') //check if the player currently in cell number 1
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;  //its a move
        direction = getInput();
        if (direction == 'R'){
            if (arr[0][1] == 'T')
                arr1[0]++;
            arr[0][1] = 'P';
            if(is_T == 1)
            {
                arr[0][0] = 'T';
            }
            else arr[0][0] = '_';
            return arr1[0];
        }

        else if (direction == 'D') {
            if (arr[1][0] == 'T')
                arr1[0]++;
            arr[1][0] = 'P';
            if(is_T == 1)
            {
                arr[0][0] = 'T';
            }
            else arr[0][0] = '_';
            return arr1[0];

        }
        if (direction != 'D' && direction != 'R')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }

    //-----------------------------------------------------------

    if(arr[0][1] == 'P')//check if the player currently in cell number 2
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'R') {
            if (arr[0][2] == 'T')
                arr1[0]++;
            arr[0][2] = 'P';
            if(is_T == 1)
            {
                arr[0][1] = 'T';
            }
            else arr[0][1] = '_';
            return arr1[0];
        }

        else if (direction == 'D') {
            if (arr[1][1] == 'T')
                arr1[0]++;
            arr[1][1] = 'P';
            if(is_T == 1)
            {
                arr[0][1] = 'T';
            }
            else arr[0][1] = '_';
            return arr1[0];

        }
        else if (direction == 'L')
        {
            if (arr[0][0] == 'T')
                arr1[0]++;
            arr[0][0] = 'P';
            if(is_T == 1)
            {
                arr[0][1] = 'T';
            }
            else arr[0][1] = '_';
            return arr1[0];
        }
        if (direction != 'D' && direction!='R' && direction!= 'L')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;

        }
    }
    //-----------------------------------------------------------------------------
    if(arr[0][2] == 'P')//check if the player currently in cell number 3
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'L')
        {
            if (arr[0][1] == 'T')
                arr1[0]++;
            arr[0][1] = 'P';
            if(is_T == 1)
            {
                arr[0][2] = 'T';
            }
            else arr[0][2] = '_';
            return arr1[0];
        }

        else if (direction == 'D') {
            if (arr[1][2] == 'T')
                arr1[0]++;
            arr[1][2] = 'P';
            if(is_T == 1)
            {
                arr[0][2] = 'T';
            }
            else arr[0][2] = '_';
            return arr1[0];

        }
        if (direction != 'D' && direction!='L')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }

    //------------------------------------------------------------------
    if(arr[1][0] == 'P')//check if the player currently in cell number 4
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'R') {
            if (arr[1][1] == 'T')
                arr1[0]++;
            arr[1][1] = 'P';
            if(is_T == 1)
            {
                arr[0][0] = 'T';
            }
            else arr[1][0] = '_';
            return arr1[0];
        }

        else if (direction == 'D') {
            if (arr[2][0] == 'T')
                arr1[0]++;
            arr[2][0] = 'P';
            if(is_T == 1)
            {
                arr[1][0] = 'T';
            }
            else arr[1][0] = '_';
            return arr1[0];

        }
        else if (direction == 'U')
        {
            if (arr[0][0] == 'T')
                arr1[0]++;
            arr[0][0] = 'P';
            if(is_T == 1)
            {
                arr[1][0] = 'T';
            }
            else arr[1][0] = '_';
            return arr1[0];
        }
        if (direction != 'D' && direction!='R' && direction!='U')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }
    //---------------------------------------------------------------------

    if(arr[1][1] == 'P')//check if the player currently in cell number 5
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'R') {
            if (arr[1][2] == 'T')
                arr1[0]++;
            arr[1][2] = 'P';
            if(is_T == 1)
            {
                arr[1][1] = 'T';
            }
            else arr[1][1] = '_';
            return arr1[0];
        }

        else if (direction == 'D') {
            if (arr[2][1] == 'T')
                arr1[0]++;
            arr[2][1] = 'P';
            if(is_T == 1)
            {
                arr[1][1] = 'T';
            }
            else arr[1][1] = '_';
            return arr1[0];

        }
        else if (direction == 'U')
        {
            if (arr[0][1] == 'T')
                arr1[0]++;
            arr[0][1] = 'P';
            if(is_T == 1)
            {
                arr[1][1] = 'T';
            }
            else arr[1][1] = '_';
            return arr1[0];
        }
        else if (direction == 'L')
        {
            if (arr[1][0] == 'T')
                arr1[0]++;
            arr[1][0] = 'P';
            if(is_T == 1)
            {
                arr[1][1] = 'T';
            }
            else arr[1][1] = '_';
            return arr1[0];
        }
        if (direction != 'D' && direction!='R' && direction!='U' && direction!='L')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }

    //--------------------------------------------------------------------------------

    if(arr[1][2] == 'P')//check if the player currently in cell number 6
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'U') {
            if (arr[0][2] == 'T')
                arr1[0]++;
            arr[0][2] = 'P';
            if(is_T == 1)
            {
                arr[1][2] = 'T';
            }
            else arr[1][2] = '_';
            return arr1[0];
        }

        else if (direction == 'D') {
            if (arr[2][2] == 'T')
                arr1[0]++;
            arr[2][2] = 'P';
            if(is_T == 1)
            {
                arr[1][2] = 'T';
            }
            else arr[1][2] = '_';
            return arr1[0];

        }
        else if (direction == 'L')
        {
            if (arr[1][1] == 'T')
                arr1[0]++;
            arr[1][1] = 'P';
            if(is_T == 1)
            {
                arr[1][2] = 'T';
            }
            else arr[1][2] = '_';
            return arr1[0];
        }
        if (direction != 'D' && direction!='L' && direction!='U')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }

    //--------------------------------------------------------------------------------

    if(arr[2][0] == 'P')//check if the player currently in cell number 7
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'R') {
            if (arr[2][1] == 'T')
                arr1[0]++;
            arr[2][1] = 'P';
            if(is_T == 1)
            {
                arr[2][0] = 'T';
            }
            else arr[2][0] = '_';
            return arr1[0];
        }

        else if (direction == 'U') {
            if (arr[1][0] == 'T')
                arr1[0]++;
            arr[1][0] = 'P';
            if(is_T == 1)
            {
                arr[2][0] = 'T';
            }
            else arr[2][0] = '_';
            return arr1[0];

        }
        if (direction != 'U' && direction!='R')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }

    //--------------------------------------------------------------------

    if(arr[2][1] == 'P')//check if the player currently in cell number 8
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'U') {
            if (arr[1][1] == 'T')
                arr1[0]++;
            arr[1][1] = 'P';
            if(is_T == 1)
            {
                arr[2][1] = 'T';
            }
            else arr[2][1] = '_';
            return arr1[0];
        }

        else if (direction == 'R') {
            if (arr[2][2] == 'T')
                arr1[0]++;
            arr[2][2] = 'P';
            if(is_T == 1)
            {
                arr[2][1] = 'T';
            }
            else arr[2][1] = '_';
            return arr1[0];

        }

        else if (direction == 'L')
        {
            if (arr[2][0] == 'T')
                arr1[0]++;
            arr[2][0] = 'P';
            if(is_T == 1)
            {
                arr[2][1] = 'T';
            }
            else arr[2][1] = '_';
            return arr1[0];
        }
        if (direction != 'R' && direction!='L' && direction!='U')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }

    //---------------------------------------------------------------------------

    if(arr[2][2] == 'P')//check if the player currently in cell number 9
    {
        printf("Enter move (D/L/U/R):\n");
        arr1[1]++;//its a move
        direction = getInput();
        if (direction == 'U') {
            if (arr[1][2] == 'T')
                arr1[0]++;
            arr[1][2] = 'P';
            if(is_T == 1)
            {
                arr[2][2] = 'T';
            }
            else arr[2][2] = '_';
            return arr1[0];
        }

        else if (direction == 'L') {
            if (arr[2][1] == 'T')
                arr1[0]++;
            arr[2][1] = 'P';
            if(is_T == 1)
            {
                arr[2][2] = 'T';
                if (is_T == 1)
                    arr1[0]++;
            }
            else arr[2][2] = '_';
            return arr1[0];

        }
        if (direction != 'U' && direction!='L')
        {
            if (is_T == 1)
                arr1[0]++;
            return 0;
        }
    }
}



int main() {
    int is_T = 0;   // 0 if first loc of P is T or 1 if not
    int treasures_and_count[2] = {0,0};
    int i_first, j_first;
    char first_loc;
    srand(2024);
    int arr[GRID_SIZE][GRID_SIZE];
    rand_locations_treasures(arr);
    i_first = rand() % 3; //loc of P
    j_first = rand() % 3;
    first_loc = arr[i_first][j_first]; //initialize location of player
    if (first_loc == 'T')
        is_T = 1;
    arr[i_first][j_first] = 'P';
    for (int i = 0; i < GRID_SIZE; i++) // print the current GRID
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            printf("%c  ", arr[i][j]);
        }
        printf("\n");
    }
    while (treasures_and_count[1] < MAX_MOVES && treasures_and_count[0] < TREASURE_COUNT)
    {
        move(arr, treasures_and_count, is_T); //move D/U/L/R
        is_T = 0;
        for (int i = 0; i < GRID_SIZE; i++)  // print the current GRID
        {

            for (int j = 0; j < GRID_SIZE; j++)
            {
                printf("%c  ", arr[i][j]);
            }
            printf("\n");
        }
        printf("\n");
        printf("moves = %d Treasures Found = %d\n", treasures_and_count[1], treasures_and_count[0]);
        printf("\n");
    }


    if (treasures_and_count[0] >= TREASURE_COUNT)
        printf("\nCongratulations! You found all the treasures.\n");
    else
        printf("\nSorry, you ran out of moves.\n");
    return 0;
}
