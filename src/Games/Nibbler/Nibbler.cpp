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

Nibbler::Nibbler() : AGameModule("Nibbler")
{
    this->_mapNb = 0;
    this->_direction = NORTH;
    this->_score = 0;
    this->_map.resize(20);
    this->_gameStatus = GameStatus::WIN;
}

std::vector<std::shared_ptr<AEntities>> Nibbler::initAllEntities() const
{
    std::vector<std::shared_ptr<AEntities>> entities;

    entities.push_back(std::make_shared<Wall>(1, std::make_pair(0, 0), "assets/images/wall.png", ASCII('#', Color(105, 105, 105)), "Wall"));
    entities.push_back(std::make_shared<Empty>(1, std::make_pair(0, 0), "assets/images/empty.png", ASCII(' ', Color(255, 255, 255)), "Empty"));
    entities.push_back(std::make_shared<Fruit>(1, std::make_pair(0, 0), "assets/images/fruit.png", ASCII('@', Color(255, 0, 0)), "Fruit"));
    entities.push_back(std::make_shared<PlayerHead>(1, std::make_pair(0, 0), "assets/images/head.png", ASCII('H', Color(77, 0, 255)), "PlayerHead"));
    entities.push_back(std::make_shared<PlayerBody>(1, std::make_pair(0, 0), "assets/images/body.png", ASCII('B', Color(119, 65, 245)), "PlayerBody"));
    entities.push_back(std::make_shared<PlayerTail>(1, std::make_pair(0, 0), "assets/images/tail.png", ASCII('T', Color(144, 104, 239)), "PlayerTail"));
    std::cout << "Nibbler entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

void Nibbler::playerWin()
{
    if (this->_gameStatus == GameStatus::WIN) {
        this->_mapNb == 3 ? this->_mapNb = 1 : this->_mapNb++;
    }
}

void Nibbler::loadMap()
{
    if (this->_gameStatus != GameStatus::WIN)
        return;

    std::vector<std::string> mapPath = {
        "./src/Games/Nibbler/maps/map1.txt",
        "./src/Games/Nibbler/maps/map2.txt",
        "./src/Games/Nibbler/maps/map3.txt",
    };
    std::ifstream file(mapPath[this->_mapNb - 1]);
    char c;
    int y = 0;
    int x = 0;

    this->_gameStatus = GameStatus::RUNNING;
    if (file.is_open()) {
        while (file.get(c)) {
            switch (c) {
                case '#':
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Wall>(1, std::make_pair(x, y), "", ASCII('#', Color()), "Wall")}));
                    x++;
                    break;
                case ' ':
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(x, y), "", ASCII(' ', Color()), "Empty")}));
                    x++;
                    break;
                case 'F':
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Fruit>(1, std::make_pair(x, y), "", ASCII('@', Color()), "Fruit")}));
                    x++;
                    break;
                case 'H':
                    this->_player.setHead(PlayerHead(std::make_pair(x, y)));
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<PlayerHead>(1, std::make_pair(x, y), "", ASCII('H', Color()), "PlayerHead")}));
                    x++;
                    break;
                case 'B':
                    this->_player.setBody(PlayerBody(std::make_pair(x, y)));
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<PlayerBody>(1, std::make_pair(x, y), "", ASCII('B', Color()), "PlayerBody")}));
                    x++;
                    break;
                case 'T':
                    this->_player.setTail(PlayerTail(std::make_pair(x, y)));
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<PlayerTail>(1, std::make_pair(x, y), "", ASCII('T', Color()), "PlayerTail")}));
                    x++;
                    break;
                case '\n':
                    y++;
                    x = 0;
                    break;
                case '|':
                    file.close();
                    return;
            }
        }
    } else {
        throw Error("could not open file");
    }
}

void Nibbler::catchInput(Input input)
{
    this->playerWin();
    this->loadMap();
    this->autoTurn();
    this->movePlayer();
    sleep(1);
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
    std::vector<std::pair<int, int>> playerPos;

    for (int i = 0; i < this->_player.getBody().size(); i++)
        playerPos.push_back(this->_player.getBody()[i].getPos());
    playerPos.push_back(this->_player.getHead().getPos());
    if (current_time >= next_time) {
        switch (this->_direction) {
            case NORTH:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first, this->_player.getHead().getPos().second - 1));
                for (int i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case SOUTH:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first, this->_player.getHead().getPos().second + 1));
                for (int i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case EAST:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first + 1, this->_player.getHead().getPos().second));
                for (int i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case WEST:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first - 1, this->_player.getHead().getPos().second));
                for (int i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case STOP:
                break;
        }
        printf("---\nHead pos: %d, %d\n", this->_player.getHead().getPos().first, this->_player.getHead().getPos().second);
        for (int i = this->_player.getBody().size() - 1; i >= 0; i--) {
            printf("Body pos: %d, %d\n", this->_player.getBody()[i].getPos().first, this->_player.getBody()[i].getPos().second);
        }
        printf("Tail pos: %d, %d\n---\n", this->_player.getTail().getPos().first, this->_player.getTail().getPos().second);
        printf("Direction: %d\n---\n", this->_direction);
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
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType()
            };
            if (key == LEFT && radar[0] == EMPTY)
                this->_direction = WEST;
            else if (key == RIGHT && radar[1] == EMPTY)
                this->_direction = EAST;
            break;
        case SOUTH:
            radar = {
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if (key == LEFT && radar[0] == EMPTY)
                this->_direction = WEST;
            else if (key == RIGHT && radar[1] == EMPTY)
                this->_direction = EAST;
            break;
        case EAST:
            radar = {
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
            };
            if (key == UP && radar[0] == EMPTY)
                this->_direction = NORTH;
            else if (key == DOWN && radar[1] == EMPTY)
                this->_direction = SOUTH;
            break;
        case WEST:
            radar = {
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
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
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = WEST;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = EAST;
            break;
        case SOUTH:
            radar = {
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = WEST;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = EAST;
            break;
        case EAST:
            radar = {
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = NORTH;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = SOUTH;
            break;
        case WEST:
            radar = {
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = NORTH;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = SOUTH;
            break;
    }
}
