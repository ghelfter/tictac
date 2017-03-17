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
#include "text_render.h"

#define PLAYER 1
#define AI     2

unsigned int w = 512;
unsigned int h = 512;

struct vector2 dim;       /* Store a vector of our dimensions */
struct vector2 mpos_norm; /* Store our mouse position when clicked */
struct vector2 mpos;

struct vector2 msg_pos;
struct vector2 msg_dim;

int m_x = 0;
int m_y = 0;
int player_went = 0;
char board[9] = {0};

/*
 * This will contain our game state. The state is as follows:
 *    0 - Game is initializing
 *    1 - Game is currently running
 *    2 - Game is won
 */
int game_state = 0;

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


    game_state = 1;

    msg_dim.x = dim.x / 2;
    msg_dim.y = dim.y / 4;

    msg_pos.x = dim.x / 4;
    msg_pos.y = dim.y / 8 * 3;

    /* Run through main game loop */
    while(running)
    {
        if(player_went)
            player_went = 0;
        /* Acquire any input */
        while(SDL_PollEvent(&event) != 0)
        {
            if(event.type == SDL_QUIT)
            {
                running = 0;
                break;
            }
            else if(event.type == SDL_KEYDOWN)
            {
                fprintf(stdout, "Key pressed!\n");
                if(event.key.keysym.sym == SDLK_q &&
                   game_state == 2)
                {
                    running = 0;
                    break;
                }
                /*
                 * We can add some logic for restarting as well
                 * */
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
                if(get_current_player() == PLAYER && game_state == 1
                   && player_went == 0)
                { 
                    cell = get_cell(&mpos_norm);
                    if(!is_placed(board, cell))
                    {
                        make_turn(board, cell);
                        end_turn();
                        player_went = 1;
                    }
                }
            }
        }
    
        /* Update the state and perform any game logic */

        /* Run through the AI and update their state */
        if(get_current_player() == AI && game_state  == 1
           && player_went == 0)
        {
            /* Have the AI make its turn */

            /* Have an SDL Delay */
            SDL_Delay(400);

            /* AI places piece */
            cell = ai_make_play(board, 0);
            make_turn(board, cell);
            end_turn();
        }

        /* Check for wins */
        winner = game_won(board);
        if(winner && game_state == 1)
        {
            game_state = 2;
        }

        /* Clear the renderer */
        SDL_RenderClear(tictac_renderer);

        /* Render images */
        SDL_RenderCopy(tictac_renderer, board_tex, NULL, NULL);
        render_board(board);

        if(game_state == 2)
        {
            render_text(tictac_renderer, "Game has been won!",
                        &msg_pos, &msg_dim);
        }

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
