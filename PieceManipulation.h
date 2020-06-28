struct Tetromino
{
	UINT8 tetrominoType;
	UINT8 orientation;
	UBYTE spriteIds[4];
	UINT8 T0x;
	UINT8 T0y;
	UINT8 T1x;
	UINT8 T1y;
	UINT8 T2x;
	UINT8 T2y;
	UINT8 T3x;
	UINT8 T3y;
};

void spawnTetromino(struct Tetromino* piece, UINT8 pieceType, UINT8 spawnPositionx, UINT8 spawnPositiony);

void moveTetromino(struct Tetromino* piece, INT8 x, INT8 y);

void rotateClockwise(struct Tetromino* piece);