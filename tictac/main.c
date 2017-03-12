/*  --------------  Galen Helfter  --------------  */
/*  --------------     tictac      --------------  */
/*  --------------     main.c      --------------  */

/*
 * Basic tic-tac-toe game
 * */
#include <SDL2/SDL.h>

#include <stdio.h>
#include <stdlib.h>

#include "initialize.h"
#include "renderer.h"
#include "game_ai.h"
#include "input.h"

#define PLAYER 1

unsigned int w = 512;
unsigned int h = 512;

struct vector2 dim;       /* Store a vector of our dimensions */
struct vector2 mpos_norm; /* Store our mouse position when clicked */
struct vector2 mpos;
int m_x = 0;
int m_y = 0;
char board[9] = {0};

int main(int argc, char **argv)
{
    char running = 1; /* variable to store the running state */
    char initialize = 0; /* Store the result of initialization */
    char winner = 0;
    int cell = 0;

    /* Store any event information */
    SDL_Event event;

    /* Acquire any command line parameters */
    if(argc > 1)
    {
        /* We'll check if they've provided any w/h dimensions for now */
        if(!strncmp(argv[1], "-d", 2))
        {
            w = h = (unsigned int) atoi(argv[2]);
        }
    }

    dim.x = w;
    dim.y = h;

    /* If we were to build a more developed game, we would have a
     * configuration file to store any kind of parameters to make
     * it more data-driven */

    /* Run initialization code */
    initialize = tictac_init(w, h);

    /* Perform any error checks on the initialization */
    if(initialize != 0)
    {
        fprintf(stderr, "Failed to iniitialize game!\n");
    }

    /* Acquire any assets */
    load_assets();

    /* Fake the setup of the board */
    board[0] = 1; board[1] = 2;
    board[4] = 1; board[2] = 2;

    /* Run through main game loop */
    while(running)
    {
        /* Acquire any input */
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                running = 0;
                break;
            }
            else if(event.type == SDL_MOUSEBUTTONDOWN)
            {
                /* Acquire mouse position */
                SDL_GetMouseState(&m_x, &m_y);

                mpos.x = (double) m_x;
                mpos.y = (double) m_y;

                /* Normalize mouse position */
                get_mouse_norm(&mpos, &dim, &mpos_norm);
            }
            else if(event.type  == SDL_MOUSEBUTTONUP)
            {
                fprintf(stdout, "Cell: %d\n", get_cell(&mpos_norm));
                /* Check whose turn it is */
                if(get_current_player() == PLAYER)
                { 
                    cell = get_cell(&mpos_norm);
                    fprintf(stdout, "Player turn!\n");
                    if(!is_placed(board, cell))
                    {
                        make_turn(board, cell);
                        end_turn();
                    }
                }
            }
        }
    
        /* Update the state and perform any game logic */

        /* Run through the AI and update their state */

        /* Check for wins */
        winner = game_won(board);
        if(winner)
        {
            running = 0;
            fprintf(stdout, "player %d won the game!\n", winner);
        }

        /* Clear the renderer */
        SDL_RenderClear(tictac_renderer);

        /* Render images */
        SDL_RenderCopy(tictac_renderer, board_tex, NULL, NULL);
        render_board(board);

        /* Render to the screen */
        SDL_RenderPresent(tictac_renderer);
        SDL_Delay(25);
    }

    /* Perform any cleanup operations */
    cleanup_renderer();
    tictac_close();

    /* Exit application */
    return 0;
}
