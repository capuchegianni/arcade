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
    this->_direction = EAST;
    this->_score = 0;
    this->_map.resize(20);
    this->_gameStatus = GameStatus::WIN;
    this->_fruitNb = 28;
}

std::vector<std::shared_ptr<AEntities>> Nibbler::initAllEntities() const
{
    std::vector<std::shared_ptr<AEntities>> entities;

    entities.push_back(std::make_shared<Wall>(1, std::make_pair(0, 0), "assets/images/wall.png", ASCII('#', Color(105, 105, 105)), "Wall"));
    entities.push_back(std::make_shared<Empty>(1, std::make_pair(0, 0), "assets/images/empty.png", ASCII(' ', Color(255, 255, 255)), "Empty"));
    entities.push_back(std::make_shared<Fruit>(1, std::make_pair(0, 0), "assets/images/fruit.png", ASCII('@', Color(255, 0, 0)), "Fruit"));
    entities.push_back(std::make_shared<Enemy>(1, std::make_pair(0, 0), "assets/images/enemy.png", ASCII('E', Color(255, 0, 0)), "Enemy"));
    entities.push_back(std::make_shared<Projectile>(1, std::make_pair(0, 0), "assets/images/projectile.png", ASCII('P', Color(255, 0, 0)), "Projectile"));
    entities.push_back(std::make_shared<PlayerHead>(1, std::make_pair(0, 0), "assets/images/head.png", ASCII('H', Color(77, 0, 255)), "PlayerHead"));
    entities.push_back(std::make_shared<PlayerBody>(1, std::make_pair(0, 0), "assets/images/body.png", ASCII('B', Color(119, 65, 245)), "PlayerBody"));
    entities.push_back(std::make_shared<PlayerTail>(1, std::make_pair(0, 0), "assets/images/tail.png", ASCII('T', Color(144, 104, 239)), "PlayerTail"));
    std::cout << "Nibbler entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

void printMap(std::vector<std::vector<Tiles>> map)
{
    for (int i = 0; i < map.size(); i++) {
        for (int j = 0; j < map[i].size(); j++) {
            std::cout << map[i][j].getEntities()[map[i][j].getEntities().size() - 1]->imageToDisplay().second.getAscii();
        }
        std::cout << std::endl;
    }
}

void Nibbler::catchInput(Input input)
{
    this->playerWin();
    this->loadMap();
    this->changeDirection(input);
    this->autoTurn();
    this->clearPlayer();
    this->movePlayer();
    this->eatFruit();
    this->placePlayer();
    return;
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
                    return;
            }
        }
    } else {
        throw Error("could not open file");
    }
}

void Nibbler::reset()
{
    this->_score = 0;
}

void Nibbler::clearPlayer()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::pair<int, int> bodyPos;
    std::pair<int, int> tailPos = this->_player.getTail().getPos();

    this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0]});
    for (int i = 0; i < this->_player.getBody().size(); i++) {
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

    this->_map[headPos.second][headPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{this->_map[headPos.second][headPos.first].getEntities()[0], std::make_shared<PlayerHead>(1, std::make_pair(headPos.first, headPos.second), "", ASCII('H', Color()), "PlayerHead")});
    for (int i = 0; i < this->_player.getBody().size(); i++) {
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
        next_time = current_time + std::chrono::milliseconds(200);
    }
}

void Nibbler::changeDirection(Input key)
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    EntityType radar;

    switch (key) {
        case UP:
            radar = this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType();
            if (radar == EMPTY || radar == FRUIT)
                this->_direction = NORTH;
            break;
        case DOWN:
            radar = this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType();
            if (radar == EMPTY || radar == FRUIT)
                this->_direction = SOUTH;
            break;
        case LEFT:
            radar = this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType();
            if (radar == EMPTY || radar == FRUIT)
                this->_direction = WEST;
            break;
        case RIGHT:
            radar = this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType();
            if (radar == EMPTY || radar == FRUIT)
                this->_direction = EAST;
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
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT) && this->_direction == NORTH)
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = WEST;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = EAST;
            break;
        case SOUTH:
            radar = {
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT) && this->_direction == SOUTH)
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = WEST;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = EAST;
            break;
        case EAST:
            radar = {
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT) && this->_direction == EAST)
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = NORTH;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = SOUTH;
            break;
        case WEST:
            radar = {
                this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType(),
                this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType(),
                this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType(),
            };
            if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT) && this->_direction == WEST)
                this->_direction = STOP;
            else if ((radar[0] == EMPTY || radar[0] == FRUIT) && radar[1] == WALL && radar[2] == WALL)
                this->_direction = NORTH;
            else if (radar[0] == WALL && radar[1] == WALL && (radar[2] == EMPTY || radar[2] == FRUIT))
                this->_direction = SOUTH;
            break;
    }
}

void Nibbler::eatFruit()
{
    // EntityType radar;
    // std::pair<int, int> headPos = this->_player.getHead().getPos();

    // switch (this->_direction) {
    //     case NORTH:
    //         radar = this->_map[headPos.second - 1][headPos.first].getEntities()[0]->getType();
    //         if (radar == FRUIT) {
    //             this->_fruitNb--;
    //             this->_score += 10;
    //             //this->_map[headPos.second - 1][headPos.first] = Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(headPos.first, headPos.second - 1), "", ASCII(' ', Color()), "Empty")});;
    //         }
    //         break;
    //     case SOUTH:
    //         radar = this->_map[headPos.second + 1][headPos.first].getEntities()[0]->getType();
    //         if (radar == FRUIT) {
    //             this->_fruitNb--;
    //             this->_score += 10;
    //             //this->_map[headPos.second + 1][headPos.first] = Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(headPos.first, headPos.second + 1), "", ASCII(' ', Color()), "Empty")});;
    //         }
    //         break;
    //     case EAST:
    //         radar = this->_map[headPos.second][headPos.first + 1].getEntities()[0]->getType();
    //         if (radar == FRUIT) {
    //             this->_fruitNb--;
    //             this->_score += 10;
    //             //this->_map[headPos.second][headPos.first + 1] = Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(headPos.first + 1, headPos.second), "", ASCII(' ', Color()), "Empty")});;
    //         }
    //         break;
    //     case WEST:
    //         radar = this->_map[headPos.second][headPos.first - 1].getEntities()[0]->getType();
    //         if (radar == FRUIT) {
    //             this->_fruitNb--;
    //             this->_score += 10;
    //             //this->_map[headPos.second][headPos.first - 1] = Tiles(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(1, std::make_pair(headPos.first - 1, headPos.second), "", ASCII(' ', Color()), "Empty")});;
    //         }
    //         break;
    // }
    // printf("Fruit left: %d\n", this->_fruitNb);
}
