cmake_minimum_required(VERSION 3.10)
project(arcade)

set(CMAKE_CXX_STANDARD 20)

set(WARNING_FLAGS -Wall -W -g -g3 -std=c++20 -fno-gnu-unique)
set(LDL_FLAGS -ldl)
set(NCURSES_FLAGS -lncurses)
set(SFML_FLAGS -lsfml-graphics -lsfml-window -lsfml-system)
set(SDL_FLAGS -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer)

add_custom_target(create_lib_dir ALL
    COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}/lib
)

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})

include_directories(include)


# Core executable
set(core_src
    src/Errors/Errors.cpp
    src/GlobalClasses/Tiles.cpp
    src/GlobalClasses/Ascii.cpp
    src/Core/Main.cpp
    src/Core/CoreModule.cpp
    src/Core/LdlWrapper.cpp
    src/Entities/AEntities.cpp
    src/Entities/Entities.cpp
    src/Core/Menu.cpp
)

add_executable(arcade ${core_src})
target_compile_options(arcade PRIVATE ${WARNING_FLAGS})
target_link_libraries(arcade ${LDL_FLAGS})

# Graphical libraries
set(ncurses_src
    src/Errors/Errors.cpp
    src/GlobalClasses/Tiles.cpp
    src/GlobalClasses/Ascii.cpp
    src/Graphics/AGraphicalModule.cpp
    src/Graphics/Ncurses/NcursesWrapper.cpp
    src/Graphics/Ncurses/NcursesGraphicalModule.cpp
    src/Entities/AEntities.cpp
)

set(sdl2_src
    src/Errors/Errors.cpp
    src/GlobalClasses/Tiles.cpp
    src/GlobalClasses/Ascii.cpp
    src/Graphics/AGraphicalModule.cpp
    src/Graphics/SDL2/SDL2Wrapper.cpp
    src/Graphics/SDL2/Sdl2GraphicalModule.cpp
    src/Entities/AEntities.cpp
)

set(sfml_src
    src/Errors/Errors.cpp
    src/GlobalClasses/Tiles.cpp
    src/GlobalClasses/Ascii.cpp
    src/Graphics/AGraphicalModule.cpp
    src/Graphics/SFML/SfmlGraphicalModule.cpp
    src/Entities/AEntities.cpp
)

add_library(arcade_ncurses SHARED ${ncurses_src})
add_library(arcade_sdl2 SHARED ${sdl2_src})
add_library(arcade_sfml SHARED ${sfml_src})

target_compile_options(arcade_ncurses PRIVATE ${WARNING_FLAGS})
target_compile_options(arcade_sdl2 PRIVATE ${WARNING_FLAGS})
target_compile_options(arcade_sfml PRIVATE ${WARNING_FLAGS})

target_link_libraries(arcade_ncurses ${NCURSES_FLAGS})
target_link_libraries(arcade_sdl2 ${SDL_FLAGS})
target_link_libraries(arcade_sfml ${SFML_FLAGS})

set_target_properties(arcade_ncurses PROPERTIES PREFIX "")
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")
set_target_properties(arcade_sfml PROPERTIES PREFIX "")

# Games libraries
set(nibbler_src
    src/Errors/Errors.cpp
    src/GlobalClasses/Tiles.cpp
    src/GlobalClasses/Ascii.cpp
    src/Games/Nibbler/Nibbler.cpp
    src/Games/AGameModule.cpp
    src/Entities/AEntities.cpp
    src/Entities/Entities.cpp
    src/Entities/Player.cpp
)

set(snake_src
    src/Errors/Errors.cpp
    src/GlobalClasses/Tiles.cpp
    src/GlobalClasses/Ascii.cpp
    src/Games/Snake/Snake.cpp
    src/Games/AGameModule.cpp
    src/Entities/AEntities.cpp
    src/Entities/Entities.cpp
    src/Entities/Player.cpp
)

add_library(arcade_nibbler SHARED ${nibbler_src})
add_library(arcade_snake SHARED ${snake_src})

target_compile_options(arcade_nibbler PRIVATE ${WARNING_FLAGS})
target_compile_options(arcade_snake PRIVATE ${WARNING_FLAGS})

set_target_properties(arcade_nibbler PROPERTIES PREFIX "")
set_target_properties(arcade_snake PROPERTIES PREFIX "")
