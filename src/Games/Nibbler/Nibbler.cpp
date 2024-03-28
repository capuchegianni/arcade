/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "../../../include/Games/Nibbler/Nibbler.hpp"

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Nibbler>();
}

Nibbler::Nibbler() :
    AGameModule("Nibbler") {}

void Nibbler::parseInput(Input input) {
    return;
}

std::vector<std::shared_ptr<AEntities>> Nibbler::initAllEntities() const {
    return std::vector<std::shared_ptr<AEntities>>();
}

void Nibbler::reset()
{
    // this->score = 0;
    // this->velocity = 0.1;
    // this->wave = 1;
    // this->direction = EAST;
}

void Nibbler::changeDirection(Input key)
{
    // std::pair<int, int> headPos = this->playerPos[0];
    // std::vector<TilesType> radar;

    // switch(this->direction) {
    //     case NORTH:
    //         radar = {
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType()
    //         };
    //         if (key == LEFT && radar[0] == EMPTY)
    //             direction = WEST;
    //         else if (key == RIGHT && radar[1] == EMPTY)
    //             direction = EAST;
    //         break;
    //     case SOUTH:
    //         radar = {
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType()
    //         };
    //         if (key == LEFT && radar[0] == EMPTY)
    //             direction = WEST;
    //         else if (key == RIGHT && radar[1] == EMPTY)
    //             direction = EAST;
    //         break;
    //     case EAST:
    //         radar = {
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType()
    //         };
    //         if (key == UP && radar[0] == EMPTY)
    //             direction = NORTH;
    //         else if (key == DOWN && radar[1] == EMPTY)
    //             direction = SOUTH;
    //         break;
    //     case WEST:
    //         radar = {
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType()
    //         };
    //         if (key == UP && radar[0] == EMPTY)
    //             direction = NORTH;
    //         else if (key == DOWN && radar[1] == EMPTY)
    //             direction = SOUTH;
    //         break;
    // }
}

void Nibbler::movePlayer()
{
    static auto next_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    if (current_time >= next_time) {
        printf("Moving player\n");
        next_time = current_time + std::chrono::milliseconds(200);
    }
}

void Nibbler::changeDirection(Input key)
{
    // std::pair<int, int> headPos = this->playerPos[0];
    // std::vector<TilesType> radar;

    // switch(this->direction) {
    //     case NORTH:
    //         radar = {
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType()
    //         };
    //         if (key == LEFT && radar[0] == EMPTY)
    //             direction = WEST;
    //         else if (key == RIGHT && radar[1] == EMPTY)
    //             direction = EAST;
    //         break;
    //     case SOUTH:
    //         radar = {
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType()
    //         };
    //         if (key == LEFT && radar[0] == EMPTY)
    //             direction = WEST;
    //         else if (key == RIGHT && radar[1] == EMPTY)
    //             direction = EAST;
    //         break;
    //     case EAST:
    //         radar = {
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType()
    //         };
    //         if (key == UP && radar[0] == EMPTY)
    //             direction = NORTH;
    //         else if (key == DOWN && radar[1] == EMPTY)
    //             direction = SOUTH;
    //         break;
    //     case WEST:
    //         radar = {
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType()
    //         };
    //         if (key == UP && radar[0] == EMPTY)
    //             direction = NORTH;
    //         else if (key == DOWN && radar[1] == EMPTY)
    //             direction = SOUTH;
    //         break;
    // }
}

void Nibbler::autoTurn()
{
    // std::pair<int, int> headPos = this->playerPos[0];
    // std::vector<TilesType> radar;

    // switch(this->direction) {
    //     case NORTH:
    //         radar = {
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType()
    //         };
    //         if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = STOP;
    //         else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
    //             direction = WEST;
    //         else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = EAST;
    //         break;
    //     case SOUTH:
    //         radar = {
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType()
    //         };
    //         if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = STOP;
    //         else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
    //             direction = WEST;
    //         else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = EAST;
    //         break;
    //     case EAST:
    //         radar = {
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first + 1][headPos.second].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType()
    //         };
    //         if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = STOP;
    //         else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
    //             direction = NORTH;
    //         else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = SOUTH;
    //         break;
    //     case WEST:
    //         radar = {
    //             this->map[headPos.first][headPos.second - 1].getType(),
    //             this->map[headPos.first - 1][headPos.second].getType(),
    //             this->map[headPos.first][headPos.second + 1].getType()
    //         };
    //         if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = STOP;
    //         else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
    //             direction = NORTH;
    //         else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
    //             direction = SOUTH;
    //         break;
    // }
}
