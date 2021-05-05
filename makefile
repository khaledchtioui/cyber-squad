all:
	gcc main.c menu.c load.c perso.c background.c time.c minimap.c collision.c ennemi.c enigme.c enigmee.c sss.c game.c gfxutils.c menuu.c score.c snake.c  -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; ./prog
