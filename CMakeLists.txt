cmake_minimum_required(VERSION 3.10)
project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(WARNING_FLAGS -Wall -Wextra -W -g -g3 -ggdb -std=c++20)
set(LDL_FLAGS -ldl -fno-gnu-unique)
set(NCURSES_FLAGS -lncurses)
set(SFML_FLAGS -lsfml-graphics -lsfml-window -lsfml-system)
set(SDL_FLAGS -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

include_directories(include)

# Core executable
set(core_src
    src/Core/Main.cpp
    src/Errors/Errors.cpp
    src/Core/CoreModule.cpp
    src/Core/LdlWrapper.cpp
)

add_executable(arcade ${core_src})
set_target_properties(arcade PROPERTIES RUNTIME_OUTPUT_DIRECTORY ../)
target_compile_options(arcade PUBLIC ${WARNING_FLAGS})
target_link_libraries(arcade ${LDL_FLAGS} ${NCURSES_FLAGS} ${SDL_FLAGS} ${SFML_FLAGS})

# Graphical libraries
set(ncurses_src
    src/Graphics/Ncurses/Main.cpp
    src/Errors/Errors.cpp
    src/Graphics/AGraphicalModule.cpp
    src/Graphics/Ncurses/NcursesWrapper.cpp
    src/Graphics/Ncurses/NcursesGraphicalModule.cpp
)

set(sdl2_src
    src/Graphics/SDL2/Main.cpp
    src/Errors/Errors.cpp
    src/Graphics/AGraphicalModule.cpp
    src/Graphics/SDL2/SDL2Wrapper.cpp
    src/Graphics/SDL2/Sdl2GraphicalModule.cpp
)

set(sfml_src
    src/Graphics/SFML/Main.cpp
    src/Errors/Errors.cpp
    src/Graphics/AGraphicalModule.cpp
    src/Graphics/SFML/SfmlGraphicalModule.cpp
)

add_library(arcade_ncurses SHARED ${ncurses_src})
add_library(arcade_sdl2 SHARED ${sdl2_src})
add_library(arcade_sfml SHARED ${sfml_src})

target_compile_options(arcade_ncurses PUBLIC ${WARNING_FLAGS})
target_compile_options(arcade_sdl2 PUBLIC ${WARNING_FLAGS})
target_compile_options(arcade_sfml PUBLIC ${WARNING_FLAGS})

target_link_libraries(arcade_ncurses ${NCURSES_FLAGS})
target_link_libraries(arcade_sdl2 ${SDL_FLAGS})
target_link_libraries(arcade_sfml ${SFML_FLAGS})

set_target_properties(arcade_ncurses PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../lib PREFIX "")
set_target_properties(arcade_sdl2 PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../lib PREFIX "")
set_target_properties(arcade_sfml PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../lib PREFIX "")

# Games libraries
set(nibbler_src
    src/Games/Nibbler/Main.cpp
    src/Errors/Errors.cpp
)

set(centipede_src
    src/Games/Centipede/Main.cpp
    src/Errors/Errors.cpp
)

add_library(arcade_nibbler SHARED ${nibbler_src})
add_library(arcade_centipede SHARED ${centipede_src})

set_target_properties(arcade_nibbler PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../lib PREFIX "")
set_target_properties(arcade_centipede PROPERTIES LIBRARY_OUTPUT_DIRECTORY ../lib PREFIX "")

target_link_libraries(arcade arcade_ncurses ${NCURSES_FLAGS})
target_link_libraries(arcade arcade_sdl2 ${SDL_FLAGS})
target_link_libraries(arcade arcade_sfml ${SFML_FLAGS})
target_link_libraries(arcade arcade_nibbler)
target_link_libraries(arcade arcade_centipede)
