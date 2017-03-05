/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------    game_ai.c    --------------  */

#include "game_ai.h"

#define N_COMBINATIONS 8

/* Our board will be ordered row-major, so that it inlines the rows */

/* What we'll do is cash the directions for our traversal */
static int r1[3] = { 0, 1, 2 };
static int r2[3] = { 3, 4, 5 };
static int r3[3] = { 6, 7, 8 };

static int c1[3] = { 0, 3, 6 };
static int c2[3] = { 1, 4, 7 };
static int c3[3] = { 2, 5, 8 };

static int d1[3] = { 0, 4, 8 };
static int d2[3] = { 2, 4, 6 };

static int* combinations[N_COMBINATIONS] =  { r1, r2, r3, c1, c2, c3,
                                              d1, d2 };

static int current_player = 1; /* Start with player one */
static int turn_change = 1;    /* We'll use a hack of flipping the sign to
                                * alternate between adding and subtracting
                                * one, so that we can remove branching */

int end_turn()
{
    current_player = current_player + turn_change;
    turn_change = -turn_change;

    return current_player;
}

int get_current_player()
{
    return current_player;
}

void make_turn(char *game_board, int loc)
{
    game_board[loc] = current_player;
}

/* Check to see if the game is won */
char game_won(char *game_board)
{
    int i = 0;
    int retval = 0;
    for(i = 0; i < N_COMBINATIONS; ++i)
    {
        /* Check if a player has won */
        if(game_board[combinations[i][0]] == game_board[combinations[i][1]] &&
           game_board[combinations[i][1]] == game_board[combinations[i][2]])
        {
            retval = game_board[combinations[i][0]];
            break;
        }
    }
    return retval;
}
