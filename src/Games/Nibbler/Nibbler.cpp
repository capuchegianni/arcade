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
    this->_mapNb = 1;
    this->_direction = STOP;
    this->_lastDirection = EAST;
    this->_score = 0;
    this->_map.resize(19);
    this->_gameStatus = GameStatus::RUNNING;
    this->_fruitNb = 28;
    this->_gameName = "nibbler";
}

std::vector<std::shared_ptr<AEntities>> Nibbler::initAllEntities() const
{
    std::vector<std::shared_ptr<AEntities>> entities;

    entities.push_back(std::make_shared<Wall>(1, std::make_pair(0, 0), "assets/images/wall.png", ASCII('#', Color(105, 105, 105)), "Wall"));
    entities.push_back(std::make_shared<Empty>(1, std::make_pair(0, 0), "assets/images/empty.png", ASCII(' ', Color(255, 255, 255)), "Empty"));
    entities.push_back(std::make_shared<Fruit>(1, std::make_pair(0, 0), "assets/images/fruit.png", ASCII('@', Color(255, 0, 0)), "Fruit"));
    entities.push_back(std::make_shared<PlayerHead>(1, std::make_pair(0, 0), "assets/images/head_snake_north.png", ASCII('H', Color(77, 0, 255)), "PlayerHeadNorth"));
    entities.push_back(std::make_shared<PlayerHead>(1, std::make_pair(0, 0), "assets/images/head_snake_south.png", ASCII('H', Color(77, 0, 255)), "PlayerHeadSouth"));
    entities.push_back(std::make_shared<PlayerHead>(1, std::make_pair(0, 0), "assets/images/head_snake_east.png", ASCII('H', Color(77, 0, 255)), "PlayerHeadEast"));
    entities.push_back(std::make_shared<PlayerHead>(1, std::make_pair(0, 0), "assets/images/head_snake_west.png", ASCII('H', Color(77, 0, 255)), "PlayerHeadWest"));
    entities.push_back(std::make_shared<PlayerBody>(1, std::make_pair(0, 0), "assets/images/body_snake.png", ASCII('B', Color(119, 65, 245)), "PlayerBody"));
    entities.push_back(std::make_shared<PlayerTail>(1, std::make_pair(0, 0), "assets/images/tail_snake.png", ASCII('T', Color(144, 104, 239)), "PlayerTail"));
    std::cout << "Nibbler entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

void Nibbler::catchInput(Input input)
{
    this->playerWin();
    this->loadMap();
    this->speedBoost(input);
    this->changeDirection(input);
    this->autoTurn();
    this->playerLose();
    if (this->_gameStatus == GameStatus::OVER)
        return;
    this->clearPlayer();
    this->movePlayer();
    this->eatFruit();
    this->placePlayer();
}

void Nibbler::playerWin()
{
    if (this->_fruitNb == 0) {
        this->_score += 100;
        this->_chronoRefresh = this->_lastChronoRefresh;
        this->_chronoRefresh -= 10;
        this->_lastChronoRefresh = this->_chronoRefresh;
        this->_mapNb == 10 ? this->_mapNb = 1 : this->_mapNb++;
        this->_player.getBody().clear();
        this->_map.clear();
        this->_map.resize(19);
        this->_fruitNb = 28;
        this->_loadingMap = true;
    }
}

void Nibbler::playerLose()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();

    switch(this->_direction) {
        case NORTH:
            if (this->_map[headPos.second - 1][headPos.first].getEntities().size() != 1)
                this->_gameStatus = GameStatus::OVER;
            break;
        case SOUTH:
            if (this->_map[headPos.second + 1][headPos.first].getEntities().size() != 1)
                this->_gameStatus = GameStatus::OVER;
            break;
        case EAST:
            if (this->_map[headPos.second][headPos.first + 1].getEntities().size() != 1)
                this->_gameStatus = GameStatus::OVER;
            break;
        case WEST:
            if (this->_map[headPos.second][headPos.first - 1].getEntities().size() != 1)
                this->_gameStatus = GameStatus::OVER;
            break;
        default:
            break;
    }
    if (this->_gameStatus == GameStatus::OVER) {
        if (this->_highScores.find(this->_playerName) == this->_highScores.end())
            this->_highScores[this->_playerName] = this->_score;
        else if (this->_highScores[this->_playerName] < this->_score)
            this->_highScores[this->_playerName] = this->_score;
        this->_direction = STOP;
        this->_lastDirection = EAST;
        this->_chronoRefresh = 200;
        this->_lastChronoRefresh = 200;
        this->_score = 0;
        this->_mapNb = 1;
        this->clearPlayer();
        this->_player.getBody().clear();
        this->_map.clear();
        this->_map.resize(19);
        this->_fruitNb = 28;
        this->_loadingMap = true;
    }
}

void Nibbler::loadMap()
{
    if (this->_loadingMap != true)
        return;

    std::vector<std::string> mapPath = {
        "./src/Games/Nibbler/maps/map1.txt",
        "./src/Games/Nibbler/maps/map2.txt",
        "./src/Games/Nibbler/maps/map3.txt",
        "./src/Games/Nibbler/maps/map4.txt",
        "./src/Games/Nibbler/maps/map5.txt",
        "./src/Games/Nibbler/maps/map6.txt",
        "./src/Games/Nibbler/maps/map7.txt",
        "./src/Games/Nibbler/maps/map8.txt",
        "./src/Games/Nibbler/maps/map9.txt",
        "./src/Games/Nibbler/maps/map10.txt"
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
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(x, y), "", ASCII(' ', Color()), "Empty"), std::make_shared<PlayerHead>(1, std::make_pair(x, y), "", ASCII('H', Color()), "PlayerHead")}));
                    x++;
                    break;
                case 'B':
                    this->_player.setBody(PlayerBody(std::make_pair(x, y)));
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(x, y), "", ASCII(' ', Color()), "Empty"), std::make_shared<PlayerBody>(1, std::make_pair(x, y), "", ASCII('B', Color()), "PlayerBody")}));
                    x++;
                    break;
                case 'T':
                    this->_player.setTail(PlayerTail(std::make_pair(x, y)));
                    this->_map[y].push_back(Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(x, y), "", ASCII(' ', Color()), "Empty"), std::make_shared<PlayerTail>(1, std::make_pair(x, y), "", ASCII('T', Color()), "PlayerTail")}));
                    x++;
                    break;
                case '\n':
                    y++;
                    x = 0;
                    break;
                case '|':
                    file.close();
                    this->_loadingMap = false;
                    return;
            }
        }
    } else {
        throw Error("could not open file");
    }
}

void Nibbler::clearPlayer()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::pair<int, int> bodyPos;
    std::pair<int, int> tailPos = this->_player.getTail().getPos();

    this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0]});
    for (size_t i = 0; i < this->_player.getBody().size(); i++) {
        bodyPos = this->_player.getBody()[i].getPos();
        this->_map[bodyPos.second][bodyPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[bodyPos.second][bodyPos.first].getEntities()[0]});
    }
    this->_map[tailPos.second][tailPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[tailPos.second][tailPos.first].getEntities()[0]});
}

void Nibbler::placePlayer()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::pair<int, int> bodyPos;
    std::pair<int, int> tailPos = this->_player.getTail().getPos();

    switch (this->_direction) {
        case NORTH:
            this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadNorth")});
            break;
        case SOUTH:
            this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadSouth")});
            break;
        case EAST:
            this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadEast")});
            break;
        case WEST:
            this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadWest")});
            break;
        case STOP:
            if (this->_lastDirection == NORTH)
                this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadNorth")});
            else if (this->_lastDirection == SOUTH)
                this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadSouth")});
            else if (this->_lastDirection == EAST)
                this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadEast")});
            else if (this->_lastDirection == WEST)
                this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHeadWest")});
            break;
    }
    for (size_t i = 0; i < this->_player.getBody().size(); i++) {
        bodyPos = this->_player.getBody()[i].getPos();
        this->_map[bodyPos.second][bodyPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[bodyPos.second][bodyPos.first].getEntities()[0], std::make_shared<PlayerBody>(1, std::make_pair(bodyPos.first, bodyPos.second), "", ASCII('B', Color()), "PlayerBody")});
    }
    this->_map[tailPos.second][tailPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[tailPos.second][tailPos.first].getEntities()[0], std::make_shared<PlayerTail>(1, std::make_pair(tailPos.first, tailPos.second), "", ASCII('T', Color()), "PlayerTail")});
}

void Nibbler::movePlayer()
{
    static auto next_time = std::chrono::steady_clock::now();
    auto current_time = std::chrono::steady_clock::now();
    std::vector<std::pair<int, int>> playerPos;

    for (size_t i = 0; i < this->_player.getBody().size(); i++)
        playerPos.push_back(this->_player.getBody()[i].getPos());
    playerPos.push_back(this->_player.getHead().getPos());
    if (current_time >= next_time) {
        switch (this->_direction) {
            case NORTH:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first, this->_player.getHead().getPos().second - 1));
                for (size_t i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setLastPos(this->_player.getTail().getPos());
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case SOUTH:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first, this->_player.getHead().getPos().second + 1));
                for (size_t i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setLastPos(this->_player.getTail().getPos());
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case EAST:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first + 1, this->_player.getHead().getPos().second));
                for (size_t i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setLastPos(this->_player.getTail().getPos());
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case WEST:
                this->_player.getHead().setPos(std::make_pair(this->_player.getHead().getPos().first - 1, this->_player.getHead().getPos().second));
                for (size_t i = 1, z = 0; z < this->_player.getBody().size(); i++, z++)
                    this->_player.getBody()[z].setPos(playerPos[i]);
                this->_player.getTail().setLastPos(this->_player.getTail().getPos());
                this->_player.getTail().setPos(playerPos[0]);
                break;
            case STOP:
                break;
        }
        next_time = current_time + std::chrono::milliseconds(this->_chronoRefresh);
    }
}

void Nibbler::changeDirection(Input key)
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    EntityType radar;

    switch (key) {
        case UP:
            radar = this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType();
            if ((radar == EMPTY || radar == ITEM) && this->_map[headPos.second - 1][headPos.first].getEntities().size() == 1) {
                this->_lastDirection = this->_direction;
                this->_direction = NORTH;
            }
            break;
        case DOWN:
            radar = this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType();
            if ((radar == EMPTY || radar == ITEM) && this->_map[headPos.second + 1][headPos.first].getEntities().size() == 1) {
                this->_lastDirection = this->_direction;
                this->_direction = SOUTH;
            }
            break;
        case LEFT:
            radar = this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType();
            if ((radar == EMPTY || radar == ITEM) && this->_map[headPos.second][headPos.first - 1].getEntities().size() == 1) {
                this->_lastDirection = this->_direction;
                this->_direction = WEST;
            }
            break;
        case RIGHT:
            radar = this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType();
            if ((radar == EMPTY || radar == ITEM) && this->_map[headPos.second][headPos.first + 1].getEntities().size() == 1) {
                this->_lastDirection = this->_direction;
                this->_direction = EAST;
            }
            break;
        default:
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
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM) && this->_direction == NORTH) {
                this->_lastDirection = this->_direction;
                this->_direction = STOP;
            } else if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && radar[2] == BLOCK) {
                this->_lastDirection = this->_direction;
                this->_direction = WEST;
            } else if (radar[0] == BLOCK && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM)) {
                this->_lastDirection = this->_direction;
                this->_direction = EAST;
            }
            break;
        case SOUTH:
            radar = {
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM) && this->_direction == SOUTH) {
                this->_lastDirection = this->_direction;
                this->_direction = STOP;
            } else if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && radar[2] == BLOCK) {
                this->_lastDirection = this->_direction;
                this->_direction = WEST;
            } else if (radar[0] == BLOCK && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM)) {
                this->_lastDirection = this->_direction;
                this->_direction = EAST;
            }
            break;
        case EAST:
            radar = {
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM) && this->_direction == EAST) {
                this->_lastDirection = this->_direction;
                this->_direction = STOP;
            } else if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && radar[2] == BLOCK) {
                this->_lastDirection = this->_direction;
                this->_direction = NORTH;
            } else if (radar[0] == BLOCK && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM)) {
                this->_lastDirection = this->_direction;
                this->_direction = SOUTH;
            }
            break;
        case WEST:
            radar = {
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM) && this->_direction == WEST) {
                this->_lastDirection = this->_direction;
                this->_direction = STOP;
            } else if ((radar[0] == EMPTY || radar[0] == ITEM) && radar[1] == BLOCK && radar[2] == BLOCK) {
                this->_lastDirection = this->_direction;
                this->_direction = NORTH;
            } else if (radar[0] == BLOCK && radar[1] == BLOCK && (radar[2] == EMPTY || radar[2] == ITEM)) {
                this->_lastDirection = this->_direction;
                this->_direction = SOUTH;
            }
            break;
        default:
            break;
    }
}

void Nibbler::eatFruit()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::vector<PlayerBody> bodyPos = this->_player.getBody();

    if (this->_map[headPos.second][headPos.first].getEntities()[0]->getType() == ITEM) {
        this->_score += 10;
        this->_fruitNb--;
        this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(headPos.first, headPos.second), "", ASCII(' ', Color()), "Empty")});
        this->_player.getBody().clear();
        for (size_t i = 0; i < bodyPos.size() + 1; i++) {
            if (i == 0) {
                this->_player.setBody(this->_player.getTail().getPos());
                continue;
            }
            this->_player.setBody(bodyPos[i - 1].getPos());
        }
        this->_player.getTail().setPos(this->_player.getTail().getLastPos());
        this->_player.getTail().setLastPos(this->_player.getTail().getPos());
    }
}

void Nibbler::speedBoost(Input key)
{
    if (key == SPACE && this->_speedBoost == false) {
        this->_chronoRefresh -= 100;
        this->_speedBoost = true;
    } else if (key == SPACE && this->_speedBoost == true) {
        this->_chronoRefresh = this->_lastChronoRefresh;
        this->_speedBoost = false;
    }
}
