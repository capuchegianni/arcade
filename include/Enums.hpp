/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** enums
*/

#ifndef ENUMS_HPP_
#define ENUMS_HPP_

enum Input {
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ESC,
    ENTER,
    SPACE,
    NONE
};

enum Direction {
    NORTH,
    SOUTH,
    EAST,
    WEST,
    STOP
};

enum GameStatus {
    GAME_OVER,
    GAME_WIN,
    GAME_PAUSE,
    GAME_RESTART,
    GAME_RUNNING
};

#endif /* !ENUMS_HPP_ */
