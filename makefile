##RPG-FPS by Gedas The Evil
CC=gcc
CFLAGS= -c -Wall
# LDFLAGS= -lX11 -lGLU -lGL -lglut -L/usr/X11R6/lib -I/usr/include/SDL -D_GNU_SOURCE=1 -D_REENTRANT -L/usr/lib -lSDL -lSDL_mixer

LDFLAGS= -lGL -lm -lglut -lSDL -lSDL_mixer -lGLU

SOURCES=src/AI.c src/building_inside.c src/conf.c src/credits.c src/events.c src/Exit.c src/game.c src/inventory.c src/items.c src/keyboard.c src/loading.c src/menu_conf.c  src/menu_game.c src/menu_main.c src/mouse.c src/passage.c src/player.c src/quests.c src/scene.c src/sceneSetup.c src/shoot.c src/sounds.c src/stats.c src/text.c src/TextInput.c src/textures.c src/vars.c ./Models/anubitas.c ./Models/anubitas_w1.c ./Models/anubitas_w2.c ./Models/spider2.c ./Models/spider2w1.c ./Models/spider2a1.c ./Maps/land1.c ./Models/temple.c src/game_over.c ./Maps/Dungeon0.c ./Maps/Dungeon0Pass.c ./Maps/Dungeon0Mobs.c ./Maps/Dungeon0Items.c src/game_win.c src/shapes.c

HEADERS= src/AI.h src/building_inside.h src/conf.h src/credits.h src/events.h src/Exit.h src/game.h src/inventory.h src/items.h src/keyboard.h src/loading.h src/menu_conf.h  src/menu_game.h src/menu_main.h src/mouse.h src/passage.h src/player.h src/quests.h src/scene.h src/sceneSetup.h src/shoot.h src/sounds.h src/stats.h src/text.h src/TextInput.h src/textures.h vars.h ./Models/anubitas.h ./Models/anubitas_w1.h ./Models/anubitas_w2.h ./Models/spider2.h ./Models/spider2w1.h ./Models/spider2a1.h ./Maps/land1.h ./Models/temple.h game_over.h ./Maps/Dungeon0.h ./Maps/Dungeon0Pass.h ./Maps/Dungeon0Mobs.h ./Maps/Dungeon0Items.h game_win.h ./Maps/atmo.h  ./Maps/dungeon1.h ./Maps/water.h ./Models/arrow.h  ./Models/bezier.h  ./Models/fountain1.h  ./Models/house1.h  ./Models/padestal.h  ./Models/ship.h  ./Models/signpost.h  ./Models/tavern.h  ./Models/tree1.h  ./Models/tree2.h ./Models/tree.h  ./Models/well.h

OBJECTS=$(SOURCES:.c=.o)

EXECUTABLE=play.exe

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) $(LDFLAGS) -o $@

.c.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJECTS) play.exe
