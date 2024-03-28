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
    MENU,
    CHANGE_LIB,
    CHANGE_GAME,
    RELOAD,
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
    OVER,
    WIN,
    PAUSE,
    RESTART,
    RUNNING
};

enum EntityType {
    PLAYER_HEAD,
    PLAYER_BODY,
    PLAYER_TAIL,
    ENEMY,
    PROJECTILE,
    WALL,
    FRUIT,
    EMPTY
};

#endif /* !ENUMS_HPP_ */
