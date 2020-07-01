#include <gb/gb.h>
#include <gb/cgb.h>

/*
Type Definitions
	O = 0,
	L = 1,
	Z = 2,
	J = 3,
	I = 4,
	S = 5,
	T = 6
Orientation Definitions
	Starting point = 0
	90 degrees = 1
	180 degrees = 2
	270 degrees = 3
*/
struct Tetromino 
{
	UINT8 tetrominoType;	//type of piece
	UINT8 orientation;			//current orientation
	UBYTE spriteIds[4];
	//location of 4 tiles
	UINT8 T0x;
	UINT8 T0y;
	UINT8 T1x;
	UINT8 T1y;
	UINT8 T2x;
	UINT8 T2y;
	UINT8 T3x;
	UINT8 T3y;
};

void spawnTetromino(struct Tetromino* piece, UINT8 pieceType, UINT8 spawnPositionx, UINT8 spawnPositiony)
{
	piece->tetrominoType = pieceType;
	piece->orientation = 0;

	switch (pieceType)
	{
		case 0:							//O
			piece->spriteIds[0] = 0;	//top left
			piece->spriteIds[1] = 1;	//top right
			piece->spriteIds[2] = 2;	//bottom left
			piece->spriteIds[3] = 3;	//bottom right

			piece->T0x = spawnPositionx - 8;
			piece->T0y = spawnPositiony;
			piece->T1x = spawnPositionx;
			piece->T1y = spawnPositiony;
			piece->T2x = spawnPositionx - 8;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 0);
			set_sprite_prop(1, 0);
			set_sprite_prop(2, 0);
			set_sprite_prop(3, 0);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;
		
		case 1:							//L
			piece->spriteIds[0] = 0;	//bottom right of L
			piece->spriteIds[1] = 1;	//top of L
			piece->spriteIds[2] = 2;	//middle of L
			piece->spriteIds[3] = 3;	//bottom of L

			piece->T0x = spawnPositionx;
			piece->T0y = spawnPositiony;
			piece->T1x = spawnPositionx - 16;
			piece->T1y = spawnPositiony + 8;
			piece->T2x = spawnPositionx - 8;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 1);
			set_sprite_prop(1, 1);
			set_sprite_prop(2, 1);
			set_sprite_prop(3, 1);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;

		case 2:							//Z
			piece->spriteIds[0] = 0;	//top left of Z
			piece->spriteIds[1] = 1;	//top right of Z
			piece->spriteIds[2] = 2;	//bottom left of Z
			piece->spriteIds[3] = 3;	//bottom right of Z

			piece->T0x = spawnPositionx - 16;
			piece->T0y = spawnPositiony;
			piece->T1x = spawnPositionx - 8;
			piece->T1y = spawnPositiony;
			piece->T2x = spawnPositionx - 8;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 2);
			set_sprite_prop(1, 2);
			set_sprite_prop(2, 2);
			set_sprite_prop(3, 2);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;

		case 3:							//J
			piece->spriteIds[0] = 0;	//bottom left of J
			piece->spriteIds[1] = 1;	//bottom of J
			piece->spriteIds[2] = 2;	//middle of J
			piece->spriteIds[3] = 3;	//top of J

			piece->T0x = spawnPositionx - 16;
			piece->T0y = spawnPositiony;
			piece->T1x = spawnPositionx - 16;
			piece->T1y = spawnPositiony + 8;
			piece->T2x = spawnPositionx - 8;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 3);
			set_sprite_prop(1, 3);
			set_sprite_prop(2, 3);
			set_sprite_prop(3, 3);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;

		case 4:							//I
			piece->spriteIds[0] = 0;	//top of I
			piece->spriteIds[1] = 1;	//top middle of I
			piece->spriteIds[2] = 2;	//bottom middle of I
			piece->spriteIds[3] = 3;	//bottom of I

			piece->T0x = spawnPositionx - 16;
			piece->T0y = spawnPositiony + 8;
			piece->T1x = spawnPositionx - 8;
			piece->T1y = spawnPositiony + 8;
			piece->T2x = spawnPositionx;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx + 8;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 4);
			set_sprite_prop(1, 4);
			set_sprite_prop(2, 4);
			set_sprite_prop(3, 4);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;

		case 5:							//S
			piece->spriteIds[0] = 0;	//top left of S
			piece->spriteIds[1] = 1;	//top right of S
			piece->spriteIds[2] = 2;	//bottom left of S
			piece->spriteIds[3] = 3;	//bottom right of S

			piece->T0x = spawnPositionx - 8;
			piece->T0y = spawnPositiony;
			piece->T1x = spawnPositionx;
			piece->T1y = spawnPositiony;
			piece->T2x = spawnPositionx - 16;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx - 8;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 5);
			set_sprite_prop(1, 5);
			set_sprite_prop(2, 5);
			set_sprite_prop(3, 5);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;

		case 6:							//T
			piece->spriteIds[0] = 0;	//bottom of T
			piece->spriteIds[1] = 1;	//right of T
			piece->spriteIds[2] = 2;	//middle of T
			piece->spriteIds[3] = 3;	//left of T

			piece->T0x = spawnPositionx - 8;
			piece->T0y = spawnPositiony;
			piece->T1x = spawnPositionx - 16;
			piece->T1y = spawnPositiony + 8;
			piece->T2x = spawnPositionx - 8;
			piece->T2y = spawnPositiony + 8;
			piece->T3x = spawnPositionx;
			piece->T3y = spawnPositiony + 8;

			set_sprite_tile(0, 0);
			set_sprite_tile(1, 0);
			set_sprite_tile(2, 0);
			set_sprite_tile(3, 0);

			set_sprite_prop(0, 6);
			set_sprite_prop(1, 6);
			set_sprite_prop(2, 6);
			set_sprite_prop(3, 6);

			move_sprite(piece->spriteIds[0], piece->T0x, piece->T0y);
			move_sprite(piece->spriteIds[1], piece->T1x, piece->T1y);
			move_sprite(piece->spriteIds[2], piece->T2x, piece->T2y);
			move_sprite(piece->spriteIds[3], piece->T3x, piece->T3y);

			break;
	}

}

void moveTetromino(struct Tetromino* piece, INT8 x, INT8 y)
{
	move_sprite(piece->spriteIds[0], piece->T0x + x, piece->T0y + y);
	move_sprite(piece->spriteIds[1], piece->T1x + x, piece->T1y + y);
	move_sprite(piece->spriteIds[2], piece->T2x + x, piece->T2y + y);
	move_sprite(piece->spriteIds[3], piece->T3x + x, piece->T3y + y);

	piece->T0x += x;
	piece->T0y += y;
	piece->T1x += x;
	piece->T1y += y;
	piece->T2x += x;
	piece->T2y += y;
	piece->T3x += x;
	piece->T3y += y;
}

void rotateClockwise(struct Tetromino* piece)
{
	switch (piece->tetrominoType)
	{
		case 0:		//O
			switch (piece->orientation)
			{
				case 0:
					set_sprite_tile(piece->spriteIds[0], 1);
					set_sprite_tile(piece->spriteIds[1], 1);
					set_sprite_tile(piece->spriteIds[2], 1);
					set_sprite_tile(piece->spriteIds[3], 1);

					scroll_sprite(piece->spriteIds[0], 8, 0);
					scroll_sprite(piece->spriteIds[1], 0, 8);
					scroll_sprite(piece->spriteIds[2], 0, -8);
					scroll_sprite(piece->spriteIds[3], -8, 0);

					piece->T0x += 8;
					piece->T1y += 8;
					piece->T2y -= 8;
					piece->T3x -= 8;

					piece->orientation = 1;
					
					break;

				case 1:
					set_sprite_tile(piece->spriteIds[0], 0);
					set_sprite_tile(piece->spriteIds[1], 0);
					set_sprite_tile(piece->spriteIds[2], 0);
					set_sprite_tile(piece->spriteIds[3], 0);

					set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
					set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
					set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
					set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

					scroll_sprite(piece->spriteIds[0], 0, 8);
					scroll_sprite(piece->spriteIds[1], -8, 0);
					scroll_sprite(piece->spriteIds[2], 8, 0);
					scroll_sprite(piece->spriteIds[3], 0, -8);
					
					piece->T0y += 8;
					piece->T1x -= 8;
					piece->T2x += 8;
					piece->T3y -= 8;

					piece->orientation = 2;

					break;

				case 2:
					set_sprite_tile(piece->spriteIds[0], 1);
					set_sprite_tile(piece->spriteIds[1], 1);
					set_sprite_tile(piece->spriteIds[2], 1);
					set_sprite_tile(piece->spriteIds[3], 1);

					set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
					set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
					set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
					set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

					scroll_sprite(piece->spriteIds[0], -8, 0);
					scroll_sprite(piece->spriteIds[1], 0, -8);
					scroll_sprite(piece->spriteIds[2], 0, 8);
					scroll_sprite(piece->spriteIds[3], 8, 0);

					piece->T0x -= 8;
					piece->T1y -= 8;
					piece->T2y += 8;
					piece->T3x += 8;

					piece->orientation = 3;

					break;

				case 3:
					set_sprite_tile(piece->spriteIds[0], 0);
					set_sprite_tile(piece->spriteIds[1], 0);
					set_sprite_tile(piece->spriteIds[2], 0);

					set_sprite_tile(piece->spriteIds[3], 0);

					set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
					set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
					set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
					set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

					scroll_sprite(piece->spriteIds[0], 0, -8);
					scroll_sprite(piece->spriteIds[1], 8, 0);
					scroll_sprite(piece->spriteIds[2], -8, 0);
					scroll_sprite(piece->spriteIds[3], 0, 8);

					piece->T0y -= 8;
					piece->T1x += 8;
					piece->T2x -= 8;
					piece->T3y += 8;

					piece->orientation = 0;

					break;
			}
			
			break;
		
		case 1:		//L
			switch (piece->orientation)
			{
				case 0:
					set_sprite_tile(piece->spriteIds[0], 1);
					set_sprite_tile(piece->spriteIds[1], 1);
					set_sprite_tile(piece->spriteIds[2], 1);
					set_sprite_tile(piece->spriteIds[3], 1);

					scroll_sprite(piece->spriteIds[0], 0, 16);
					scroll_sprite(piece->spriteIds[1], 8, -8);
					scroll_sprite(piece->spriteIds[2], 0, 0);
					scroll_sprite(piece->spriteIds[3], -8, 8);

					piece->T0y += 16;
					piece->T1x += 8;
					piece->T1y -= 8;
					piece->T3x -= 8;
					piece->T3y += 8;

					piece->orientation = 1;

					break;

				case 1:
					set_sprite_tile(piece->spriteIds[0], 0);
					set_sprite_tile(piece->spriteIds[1], 0);
					set_sprite_tile(piece->spriteIds[2], 0);
					set_sprite_tile(piece->spriteIds[3], 0);

					set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
					set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
					set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
					set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

					scroll_sprite(piece->spriteIds[0], -16, 0);
					scroll_sprite(piece->spriteIds[1], 8, 8);
					scroll_sprite(piece->spriteIds[2], 0, 0);
					scroll_sprite(piece->spriteIds[3], -8, -8);


					piece->T0x -= 16;
					piece->T1x += 8;
					piece->T1y += 8;
					piece->T3x -= 8;
					piece->T3y -= 8;

					piece->orientation = 2;

					break;

				case 2:
					set_sprite_tile(piece->spriteIds[0], 1);
					set_sprite_tile(piece->spriteIds[1], 1);
					set_sprite_tile(piece->spriteIds[2], 1);
					set_sprite_tile(piece->spriteIds[3], 1);

					set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
					set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
					set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
					set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

					scroll_sprite(piece->spriteIds[0], 0,-16);
					scroll_sprite(piece->spriteIds[1], -8, 8);
					scroll_sprite(piece->spriteIds[2], 0, 0);
					scroll_sprite(piece->spriteIds[3], 8, -8);

					piece->T0y -= 16;
					piece->T1x -= 8;
					piece->T1y += 8;
					piece->T3x += 8;
					piece->T3y -= 8;

					piece->orientation = 3;

					break;

				case 3:
					set_sprite_tile(piece->spriteIds[0], 0);
					set_sprite_tile(piece->spriteIds[1], 0);
					set_sprite_tile(piece->spriteIds[2], 0);
					set_sprite_tile(piece->spriteIds[3], 0);

					set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
					set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
					set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
					set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

					scroll_sprite(piece->spriteIds[0], 16, 0);
					scroll_sprite(piece->spriteIds[1], -8, -8);
					scroll_sprite(piece->spriteIds[2], 0, 0);
					scroll_sprite(piece->spriteIds[3], 8, 8);

					piece->T0x += 16;
					piece->T1x -= 8;
					piece->T1y -= 8;
					piece->T3x += 8;
					piece->T3y += 8;

					piece->orientation = 0;

					break;
			}

			break;

		case 2:		//Z
			switch (piece->orientation)
			{
			case 0:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				scroll_sprite(piece->spriteIds[0], 16, 0);
				scroll_sprite(piece->spriteIds[1], 8, 8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], -8, 8);

				piece->T0x += 16;
				piece->T1x += 8;
				piece->T1y += 8;
				piece->T3x -= 8;
				piece->T3y += 8;

				piece->orientation = 1;

				break;

			case 1:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

				scroll_sprite(piece->spriteIds[0], 0, 16);
				scroll_sprite(piece->spriteIds[1], -8, 8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], -8, -8);

				piece->T0y += 16;
				piece->T1x -= 8;
				piece->T1y += 8;
				piece->T3x -= 8;
				piece->T3y -= 8;

				piece->orientation = 2;

				break;

			case 2:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

				scroll_sprite(piece->spriteIds[0], -16, 0);
				scroll_sprite(piece->spriteIds[1], -8, -8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], 8, -8);

				piece->T0x -= 16;
				piece->T1x -= 8;
				piece->T1y -= 8;
				piece->T3x += 8;
				piece->T3y -= 8;

				piece->orientation = 3;

				break;

			case 3:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

				scroll_sprite(piece->spriteIds[0], 0, -16);
				scroll_sprite(piece->spriteIds[1], 8, -8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], 8, 8);

				piece->T0y -= 16;
				piece->T1x += 8;
				piece->T1y -= 8;
				piece->T3x += 8;
				piece->T3y += 8;

				piece->orientation = 0;

				break;
			}

			break;

		case 3:		//J
			switch (piece->orientation)
			{
			case 0:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				scroll_sprite(piece->spriteIds[0], 16, 0);
				scroll_sprite(piece->spriteIds[1], 8, -8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], -8, 8);

				piece->T0x += 16;
				piece->T1x += 8;
				piece->T1y -= 8;
				piece->T3x -= 8;
				piece->T3y += 8;

				piece->orientation = 1;

				break;

			case 1:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

				scroll_sprite(piece->spriteIds[0], 0, 16);
				scroll_sprite(piece->spriteIds[1], 8, 8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], -8, -8);

				piece->T0y += 16;
				piece->T1x += 8;
				piece->T1y += 8;
				piece->T3x -= 8;
				piece->T3y -= 8;

				piece->orientation = 2;

				break;

			case 2:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

				scroll_sprite(piece->spriteIds[0], -16, 0);
				scroll_sprite(piece->spriteIds[1], -8, 8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], 8, -8);

				piece->T0x -= 16;
				piece->T1x -= 8;
				piece->T1y += 8;
				piece->T3x += 8;
				piece->T3y -= 8;

				piece->orientation = 3;

				break;

			case 3:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

				scroll_sprite(piece->spriteIds[0], 0, -16);
				scroll_sprite(piece->spriteIds[1], -8, -8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], 8, 8);

				piece->T0y -= 16;
				piece->T1x -= 8;
				piece->T1y -= 8;
				piece->T3x += 8;
				piece->T3y += 8;

				piece->orientation = 0;

				break;
			}

			break;

		case 4:		//I
			switch (piece->orientation)
			{
			case 0:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				scroll_sprite(piece->spriteIds[0], 16, -8);
				scroll_sprite(piece->spriteIds[1], 8, 0);
				scroll_sprite(piece->spriteIds[2], 0, 8);
				scroll_sprite(piece->spriteIds[3], -8, 16);

				piece->T0x += 16;
				piece->T0y -= 8;
				piece->T1x += 8;
				piece->T2y += 8;
				piece->T3x -= 8;
				piece->T3y += 16;

				piece->orientation = 1;

				break;

			case 1:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

				scroll_sprite(piece->spriteIds[0], 8, 16);
				scroll_sprite(piece->spriteIds[1], 0, 8);
				scroll_sprite(piece->spriteIds[2], -8, 0);
				scroll_sprite(piece->spriteIds[3], -16, -8);

				piece->T0x += 8;
				piece->T0y += 16;
				piece->T1y += 8;
				piece->T2x -= 8;
				piece->T3x -= 16;
				piece->T3y -= 8;

				piece->orientation = 2;

				break;

			case 2:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

				scroll_sprite(piece->spriteIds[0], -16, 8);
				scroll_sprite(piece->spriteIds[1], -8, 0);
				scroll_sprite(piece->spriteIds[2], 0, -8);
				scroll_sprite(piece->spriteIds[3], 8, -16);

				piece->T0x -= 16;
				piece->T0y += 8;
				piece->T1x -= 8;
				piece->T2y -= 8;
				piece->T3x += 8;
				piece->T3y -= 16;

				piece->orientation = 3;

				break;

			case 3:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

				scroll_sprite(piece->spriteIds[0], -8, -16);
				scroll_sprite(piece->spriteIds[1], 0, -8);
				scroll_sprite(piece->spriteIds[2], 8, 0);
				scroll_sprite(piece->spriteIds[3], 16, 8);

				piece->T0x -= 8;
				piece->T0y -= 16;
				piece->T1y -= 8;
				piece->T2x += 8;
				piece->T3x += 16;
				piece->T3y += 8;

				piece->orientation = 0;

				break;
			}

			break;

		case 5:		//S
			switch (piece->orientation)
			{
			case 0:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				scroll_sprite(piece->spriteIds[0], 8, 8);
				scroll_sprite(piece->spriteIds[1], 0, 16);
				scroll_sprite(piece->spriteIds[2], 8, -8);
				scroll_sprite(piece->spriteIds[3], 0, 0);

				piece->T0x += 8;
				piece->T0y += 8;
				piece->T1y += 16;
				piece->T2x += 8;
				piece->T2y -= 8;

				piece->orientation = 1;

				break;

			case 1:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

				scroll_sprite(piece->spriteIds[0], -8, 8);
				scroll_sprite(piece->spriteIds[1], -16, 0);
				scroll_sprite(piece->spriteIds[2], 8, 8);
				scroll_sprite(piece->spriteIds[3], 0, 0);

				piece->T0x -= 8;
				piece->T0y += 8;
				piece->T1x -= 16;
				piece->T2x += 8;
				piece->T2y += 8;

				piece->orientation = 2;

				break;

			case 2:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

				scroll_sprite(piece->spriteIds[0], -8, -8);
				scroll_sprite(piece->spriteIds[1], 0, -16);
				scroll_sprite(piece->spriteIds[2], -8, 8);
				scroll_sprite(piece->spriteIds[3], 0, 0);

				piece->T0x -= 8;
				piece->T0y -= 8;
				piece->T1y -= 16;
				piece->T2x -= 8;
				piece->T2y += 8;

				piece->orientation = 3;

				break;

			case 3:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

				scroll_sprite(piece->spriteIds[0], 8, -8);
				scroll_sprite(piece->spriteIds[1], 16, 0);
				scroll_sprite(piece->spriteIds[2], -8, -8);
				scroll_sprite(piece->spriteIds[3], 0, 0);

				piece->T0x += 8;
				piece->T0y -= 8;
				piece->T1x += 16;
				piece->T2x -= 8;
				piece->T2y -= 8;

				piece->orientation = 0;

				break;
			}

			break;

		case 6:		//T
			switch (piece->orientation)
			{
			case 0:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				scroll_sprite(piece->spriteIds[0], 8, 8);
				scroll_sprite(piece->spriteIds[1], 8, -8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], -8, 8);

				piece->T0x += 8;
				piece->T0y += 8;
				piece->T1x += 8;
				piece->T1y -= 8;
				piece->T3x -= 8;
				piece->T3y += 8;

				piece->orientation = 1;

				break;

			case 1:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) | S_FLIPY);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) | S_FLIPY);

				scroll_sprite(piece->spriteIds[0], -8, 8);
				scroll_sprite(piece->spriteIds[1], 8, 8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], -8, -8);

				piece->T0x -= 8;
				piece->T0y += 8;
				piece->T1x += 8;
				piece->T1y += 8;
				piece->T3x -= 8;
				piece->T3y -= 8;

				piece->orientation = 2;

				break;

			case 2:
				set_sprite_tile(piece->spriteIds[0], 1);
				set_sprite_tile(piece->spriteIds[1], 1);
				set_sprite_tile(piece->spriteIds[2], 1);
				set_sprite_tile(piece->spriteIds[3], 1);

				set_sprite_prop(piece->spriteIds[0], (get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], (get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], (get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPY) | S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], (get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPY) | S_FLIPX);

				scroll_sprite(piece->spriteIds[0], -8, -8);
				scroll_sprite(piece->spriteIds[1], -8, 8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], 8, -8);

				piece->T0x -= 8;
				piece->T0y -= 8;
				piece->T1x -= 8;
				piece->T1y += 8;
				piece->T3x += 8;
				piece->T3y -= 8;

				piece->orientation = 3;

				break;

			case 3:
				set_sprite_tile(piece->spriteIds[0], 0);
				set_sprite_tile(piece->spriteIds[1], 0);
				set_sprite_tile(piece->spriteIds[2], 0);
				set_sprite_tile(piece->spriteIds[3], 0);

				set_sprite_prop(piece->spriteIds[0], get_sprite_prop(piece->spriteIds[0]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[1], get_sprite_prop(piece->spriteIds[1]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[2], get_sprite_prop(piece->spriteIds[2]) & ~S_FLIPX);
				set_sprite_prop(piece->spriteIds[3], get_sprite_prop(piece->spriteIds[3]) & ~S_FLIPX);

				scroll_sprite(piece->spriteIds[0], 8, -8);
				scroll_sprite(piece->spriteIds[1], -8, -8);
				scroll_sprite(piece->spriteIds[2], 0, 0);
				scroll_sprite(piece->spriteIds[3], 8, 8);

				piece->T0x += 8;
				piece->T0y -= 8;
				piece->T1x -= 8;
				piece->T1y -= 8;
				piece->T3x += 8;
				piece->T3y += 8;

				piece->orientation = 0;

				break;
			}

			break;
	}
}
