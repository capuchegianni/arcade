/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-elouan.rigomont
** File description:
** Tiles
*/

#ifndef TILES_HPP_
#define TILES_HPP_

enum Type {
    EMPTY,
    WALL,
    PLAYER,
    ENEMY,
    ITEM
};
class Tiles {
    public:
        bool isType(Type type);
        void setType(Type type);
        Type getType() const;

    private:
        Type _type = EMPTY;
};

#endif /* !TILES_HPP_ */
