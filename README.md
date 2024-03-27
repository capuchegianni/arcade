# Arcade

## Table of Contents

- [Arcade](#arcade)
  - [Table of Contents](#table-of-contents)
  - [About](#about)
  - [Common Group](#common-group)
    - [Prerequisites](#prerequisites)
    - [Installing](#installing)
  - [Usage](#usage)

## About<a name = "about"></a>

Arcade is the second project of the OOP module at Epitech (Oriented Object Programming). The goal of this project is to create a gaming platform that will allow the user to play games in a graphical interface. The user will be able to switch between games and graphical libraries at runtime. The project is divided into three parts:
  - The core: The core is the main part of the project. It is the part that will manage the games and the graphical libraries. It will also be the part that will manage the user inputs.
  - The games: The games are the games that the user will be able to play. The games will be loaded at runtime by the core.
  - The graphical libraries: The graphical libraries are the libraries that will be used to display the games. The libraries will be loaded at runtime by the core.

## Common Group

We decided to work along with the following groups:
  - [sacha.polerowicz@epitech.eu](https://github.com/Sachaplr)
  - [jules.weishaus@epitech.eu](https://github.com/ImPoulpitos)
  - [isaac.levy-piquet@epitech.eu](https://www.youtube.com/watch?v=dQw4w9WgXcQ)
  - [hugos.denis@epitech.eu]()
  - [robin.caboche@epitech.eu]()
  - [nicolas.nguyen@epitech.eu]()

### Prerequisites

To compile the project you will need to have the following libraries installed:
  - [CMake](https://cmake.org/)
  - [Make](https://www.gnu.org/software/make/)

To run the project you will need to have at least the following libraries installed:
  - [SFML](https://www.sfml-dev.org/)
  - [SDL2](https://www.libsdl.org/)
  - [NCURSES](https://invisible-island.net/ncurses/)

### Installing

First, you need to clone the repository:
```bash
git clone git@github.com:EpitechPromo2027/B-OOP-400-LIL-4-1-arcade-elouan.rigomont.git
```

Next, you can compile the project by running the following commands:
```bash
mkdir build
cd build
cmake ..
make
```

## Usage<a name = "usage"></a>

Then, to run the arcade project, you can execute the following command to start a SFML window for example:
```bash
./arcade ./lib/arcade_sfml.so
```

To play a game, the following keybinds are available:
  - ZQSD: Move the player
  - R: Restart the game
  - TAB: Go back to the menu
  - ARROW RIGHT: Go to the next graphical library
  - ARROW UP: Go to the next game
  - ESCAPE: Close the window
