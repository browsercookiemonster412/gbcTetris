c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o BackgroundTiles.o BackgroundTiles.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o BackgroundMap.o BackgroundMap.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o Tetrominos.o Tetrominos.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -c -o PieceManipulation.o PieceManipulation.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j  -c -o main.o main.c
c:\gbdk\bin\lcc -Wa-l -Wl-m -Wl-j -Wl-yp0x143=0x80 -o Tetris.gbc BackgroundTiles.o BackgroundMap.o Tetrominos.o PieceManipulation.o main.o