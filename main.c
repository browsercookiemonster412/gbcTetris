#include <gb/gb.h>
#include <gb/cgb.h> 
#include <stdio.h>
#include "Tetrominos.h"
#include "PieceManipulation.h"

UINT8 spawnPositionx = 80; //currently middle of screen
UINT8 spawnPositiony = 16; //not sure why there is an offset at the top
UBYTE keyDown = 0;

struct Tetromino activePiece;

const UWORD spritepalette[] = 
{
    TetrominosCGBPal0c0,
    TetrominosCGBPal0c1,
    TetrominosCGBPal0c2,
    TetrominosCGBPal0c3,

    TetrominosCGBPal1c0,
    TetrominosCGBPal1c1,
    TetrominosCGBPal1c2,
    TetrominosCGBPal1c3,

    TetrominosCGBPal2c0,
    TetrominosCGBPal2c1,
    TetrominosCGBPal2c2,
    TetrominosCGBPal2c3,

    TetrominosCGBPal3c0,
    TetrominosCGBPal3c1,
    TetrominosCGBPal3c2,
    TetrominosCGBPal3c3,

    TetrominosCGBPal4c0,
    TetrominosCGBPal4c1,
    TetrominosCGBPal4c2,
    TetrominosCGBPal4c3,

    TetrominosCGBPal5c0,
    TetrominosCGBPal5c1,
    TetrominosCGBPal5c2,
    TetrominosCGBPal5c3,

    TetrominosCGBPal6c0,
    TetrominosCGBPal6c1,
    TetrominosCGBPal6c2,
    TetrominosCGBPal6c3
};


void delayMethod(UINT8 numloops) {
    UINT8 i;
    for (i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}


void main()
{
    set_sprite_palette(0, 7, &spritepalette[0]);
    set_sprite_data(0, 2, Tetrominos);

    SHOW_SPRITES;
    DISPLAY_ON;

    spawnTetromino(&activePiece, 6, spawnPositionx, spawnPositiony);

    while (1) {
        if (keyDown) 
        {
            waitpadup();
            keyDown = 0;
        }

        switch (joypad())
        {
            case J_LEFT:
                moveTetromino(&activePiece, -8, 0);
                break;
            case J_RIGHT:
                moveTetromino(&activePiece, 8, 0);
                break;
            case J_A:
                rotateClockwise(&activePiece);
                keyDown = 1;
                break;
        }
        
        delayMethod(5);
    }

}