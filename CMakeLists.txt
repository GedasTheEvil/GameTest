project(Rpg-FPS C)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(SDL REQUIRED)
find_package(SDL_mixer REQUIRED)

cmake_minimum_required(VERSION 3.8)

set(
        GAME_SOURCES
        src/AI.c
        src/building_inside.c
        src/conf.c
        src/credits.c
        src/events.c
        src/Exit.c
        src/game.c
        src/inventory.c
        src/items.c
        src/keyboard.c
        src/loading.c
        src/menu_conf.c
        src/menu_game.c
        src/menu_main.c
        src/mouse.c
        src/passage.c
        src/player.c
        src/quests.c
        src/scene.c
        src/sceneSetup.c
        src/shoot.c
        src/sounds.c
        src/stats.c
        src/text.c
        src/TextInput.c
        src/textures.c
        src/vars.c
        ./Models/anubitas.c
        ./Models/anubitas_w1.c
        ./Models/anubitas_w2.c
        ./Models/spider2.c
        ./Models/spider2w1.c
        ./Models/spider2a1.c
        ./Maps/land1.c
        ./Models/temple.c
        src/game_over.c
        ./Maps/Dungeon0.c
        ./Maps/Dungeon0Pass.c
        ./Maps/Dungeon0Mobs.c
        ./Maps/Dungeon0Items.c
        src/game_win.c
)

add_executable(play.exe ${GAME_SOURCES})
target_link_libraries(
        play.exe
        m
        OpenGL
        GLU
        glut
        SDL
        SDL_mixer
)
