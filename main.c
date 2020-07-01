#include <gb/gb.h>
#include <gb/cgb.h> 
#include <stdio.h>
#include <stdlib.h>

#include "Tetrominos.h"
#include "PieceManipulation.h"
#include "BackgroundMap.h"
#include "BackgroundTiles.h"

const UBYTE descendRate = 10;
UINT8 spawnPositionx = 80; //currently middle of screen
UINT8 spawnPositiony = 16; //not sure why there is an offset at the top
UBYTE keyDown = 0;
UINT8 descendTimer;

struct Tetromino activePiece;
struct Tetromino nextPiece;

const UWORD spritePalette[] = 
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

const UWORD backgroundPalette[] =
{
    BackgroundTilesCGBPal0c0,BackgroundTilesCGBPal0c1,BackgroundTilesCGBPal0c2,BackgroundTilesCGBPal0c3,
    BackgroundTilesCGBPal1c0,BackgroundTilesCGBPal1c1,BackgroundTilesCGBPal1c2,BackgroundTilesCGBPal1c3,
    BackgroundTilesCGBPal2c0,BackgroundTilesCGBPal2c1,BackgroundTilesCGBPal2c2,BackgroundTilesCGBPal2c3,
    BackgroundTilesCGBPal3c0,BackgroundTilesCGBPal3c1,BackgroundTilesCGBPal3c2,BackgroundTilesCGBPal3c3,
    BackgroundTilesCGBPal4c0,BackgroundTilesCGBPal4c1,BackgroundTilesCGBPal4c2,BackgroundTilesCGBPal4c3,
    BackgroundTilesCGBPal5c0,BackgroundTilesCGBPal5c1,BackgroundTilesCGBPal5c2,BackgroundTilesCGBPal5c3,
    BackgroundTilesCGBPal6c0,BackgroundTilesCGBPal6c1,BackgroundTilesCGBPal6c2,BackgroundTilesCGBPal6c3,
};


void delayMethod(UINT8 numloops) {
    UINT8 i;
    for (i = 0; i < numloops; i++) {
        wait_vbl_done();
    }
}


void main()
{
    set_bkg_palette(0, 7, &backgroundPalette[0]);
    set_bkg_data(0, 6, BackgroundTiles);

    // switch to 2nd video memory bank
    VBK_REG = 1;

    // set background color palette map, do this first
    set_bkg_tiles(0, 0, BackgroundMapWidth, BackgroundMapHeight, BackgroundMapPLN1);

    // switch back to 1st video memory bank
    VBK_REG = 0;

    // set background map
    set_bkg_tiles(0, 0, BackgroundMapWidth, BackgroundMapHeight, BackgroundMapPLN0);

    set_sprite_palette(0, 7, &spritePalette[0]);
    set_sprite_data(0, 2, Tetrominos);

    descendTimer = descendRate;

    SHOW_BKG;
    SHOW_SPRITES;
    DISPLAY_ON;

    spawnTetromino(&activePiece, 1, spawnPositionx, spawnPositiony);

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
        
        //automatically descend tetromino every 10 loops
        if (descendTimer == 0)
        {
            moveTetromino(&activePiece, 0, 8);
            descendTimer = descendRate;
        }
        else
        {
            descendTimer--;
        }

        if (activePiece.T0y > 144)
        {
            spawnTetromino(&activePiece, 5, spawnPositionx, spawnPositiony);
        }

        delayMethod(5);
    }

}