/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Centipede
*/

#include "../../../include/Games/Centipede/Centipede.hpp"


Centipede::Centipede() :
    AGameModule("Centipede") {}

extern "C" std::shared_ptr<AGameModule> createGame() {
    return std::make_shared<Centipede>();
}

void Centipede::reset()
{
    // this->score = 0;
    // this->velocity = 0.1;
    // this->wave = 1;
    // this->direction = EAST;
}

void Centipede::changeDirection(Input key)
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

void Centipede::movePlayer()
{
    static auto next_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    if (current_time >= next_time) {
        printf("Moving player\n");
        next_time = current_time + std::chrono::milliseconds(200);
    }
}

void Centipede::autoTurn()
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

void Centipede::parseInput(Input input) {
    return;
}

std::vector<std::shared_ptr<AEntities>> Centipede::getAllEntities() const {
    return std::vector<std::shared_ptr<AEntities>>();
}
