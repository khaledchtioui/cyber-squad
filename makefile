all:
	gcc main.c animation.c  -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; ./prog
