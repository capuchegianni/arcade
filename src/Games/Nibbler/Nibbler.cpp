/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Nibbler
*/

#include "../../../include/Games/Nibbler/Nibbler.hpp"

extern "C" std::shared_ptr<AGameModule> createGame()
{
    return std::make_shared<Nibbler>();
}

Nibbler::Nibbler() :
    AGameModule("Nibbler") {}

std::vector<std::shared_ptr<AEntities>> Nibbler::initAllEntities() const
{
    return std::vector<std::shared_ptr<AEntities>>();
}

void Nibbler::parseInput(Input input)
{
    this->autoTurn();
    this->movePlayer();
    return;
}

void Nibbler::reset()
{
    this->_score = 0;
}

void Nibbler::movePlayer()
{
    static auto next_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();

    if (current_time >= next_time) {
        switch (this->_direction) {
            case NORTH:
                printf("Moving player north\n");
                break;
            case SOUTH:
                printf("Moving player south\n");
                break;
            case EAST:
                printf("Moving player east\n");
                break;
            case WEST:
                printf("Moving player west\n");
                break;
            case STOP:
                break;
        }
        next_time = current_time + std::chrono::milliseconds(200);
    }
}

void Nibbler::changeDirection(Input key)
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::vector<EntityType> radar;

    switch(this->_direction) {
        case NORTH:
            radar = {
                this->_map[headPos.first - 1][headPos.second].getEntities()[0]->getType(),
                this->_map[headPos.first + 1][headPos.second].getEntities()[0]->getType()
            };
            if (key == LEFT && radar[0] == EMPTY)
                this->_direction = WEST;
            else if (key == RIGHT && radar[1] == EMPTY)
                this->_direction = EAST;
            break;
        case SOUTH:
            radar = {
                this->_map[headPos.first - 1][headPos.second].getEntities()[0]->getType(),
                this->_map[headPos.first + 1][headPos.second].getEntities()[0]->getType(),
            };
            if (key == LEFT && radar[0] == EMPTY)
                this->_direction = WEST;
            else if (key == RIGHT && radar[1] == EMPTY)
                this->_direction = EAST;
            break;
        case EAST:
            radar = {
                this->_map[headPos.first][headPos.second - 1].getEntities()[0]->getType(),
                this->_map[headPos.first][headPos.second + 1].getEntities()[0]->getType(),
            };
            if (key == UP && radar[0] == EMPTY)
                this->_direction = NORTH;
            else if (key == DOWN && radar[1] == EMPTY)
                this->_direction = SOUTH;
            break;
        case WEST:
            radar = {
                this->_map[headPos.first][headPos.second - 1].getEntities()[0]->getType(),
                this->_map[headPos.first][headPos.second + 1].getEntities()[0]->getType(),
            };
            if (key == UP && radar[0] == EMPTY)
                this->_direction = NORTH;
            else if (key == DOWN && radar[1] == EMPTY)
                this->_direction = SOUTH;
            break;
    }
}

void Nibbler::autoTurn()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::vector<EntityType> radar;

    switch(this->_direction) {
        case NORTH:
            radar = {
                this->_map[headPos.first - 1][headPos.second].getEntities()[0]->getType(),
                this->_map[headPos.first][headPos.second - 1].getEntities()[0]->getType(),
                this->_map[headPos.first + 1][headPos.second].getEntities()[0]->getType(),
            };
            if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = STOP;
            else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
                this->_direction = WEST;
            else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = EAST;
            break;
        case SOUTH:
            radar = {
                this->_map[headPos.first - 1][headPos.second].getEntities()[0]->getType(),
                this->_map[headPos.first][headPos.second + 1].getEntities()[0]->getType(),
                this->_map[headPos.first + 1][headPos.second].getEntities()[0]->getType(),
            };
            if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = STOP;
            else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
                this->_direction = WEST;
            else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = EAST;
            break;
        case EAST:
            radar = {
                this->_map[headPos.first][headPos.second - 1].getEntities()[0]->getType(),
                this->_map[headPos.first + 1][headPos.second].getEntities()[0]->getType(),
                this->_map[headPos.first][headPos.second + 1].getEntities()[0]->getType(),
            };
            if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = STOP;
            else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
                this->_direction = NORTH;
            else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = SOUTH;
            break;
        case WEST:
            radar = {
                this->_map[headPos.first][headPos.second - 1].getEntities()[0]->getType(),
                this->_map[headPos.first - 1][headPos.second].getEntities()[0]->getType(),
                this->_map[headPos.first][headPos.second + 1].getEntities()[0]->getType(),
            };
            if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = STOP;
            else if (radar[0] == EMPTY && radar[1] == WALL && radar[2] == WALL)
                this->_direction = NORTH;
            else if (radar[0] == WALL && radar[1] == WALL && radar[2] == EMPTY)
                this->_direction = SOUTH;
            break;
    }
}
