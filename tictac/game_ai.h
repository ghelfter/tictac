/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------    game_ai.h    --------------  */

#ifndef _GAME_AI_H_
#define _GAME_AI_H_

/* This file contains all the functions for the AI, as well as the other
 * core game logic functionality 
 * */

/* This function will return the place where the AI chooses to play */
char ai_make_play(char *board, int turn);

int end_turn();
int get_current_player();
void make_turn();

/* This function will return 0 for no win, 1 for player 1, and 2 for player 2 */
char game_won(char *board);

#endif
