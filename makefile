all:
	gcc main.c menu.c load.c perso.c background.c time.c minimap.c collision.c ennemi.c enigme.c enigmee.c -o prog -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lm; ./prog
