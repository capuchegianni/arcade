/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** Snake
*/

#include "../../../include/Games/Snake/Snake.hpp"

extern "C" std::shared_ptr<AGameModule> createGame()
{
    return std::make_shared<Snake>();
}

Snake::Snake() : AGameModule("Snake")
{
    this->_player = Player();
    this->_mapNb = 1;
    this->_direction = STOP;
    this->_lastDirection = EAST;
    this->_score = 0;
    this->_map.resize(19);
    this->_gameStatus = GameStatus::RUNNING;
    this->_loadingMap = true;
    this->_gameName = "snake";
}

std::vector<std::shared_ptr<AEntities>> Snake::initAllEntities() const
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
    std::cout << "Snake entities initialized" << std::endl;
    std::cout << "There are " << entities.size() << " entities" << std::endl;
    return entities;
}

void Snake::catchInput(Input input)
{
    this->loadMap();
    this->speedBoost(input);
    this->changeDirection(input);
    this->playerLose();
    if (this->_gameStatus == GameStatus::OVER)
        return;
    this->clearPlayer();
    this->movePlayer();
    this->eatFruit();
    this->placePlayer();
}

void Snake::playerLose()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();

    switch(this->_direction) {
        case NORTH:
            if (this->_map[headPos.second][headPos.first].getEntities().size() > 2 || this->_map[headPos.second][headPos.first].getEntities()[0]->getType() == BLOCK)
                this->_gameStatus = GameStatus::OVER;
            break;
        case SOUTH:
            if (this->_map[headPos.second][headPos.first].getEntities().size() > 2 || this->_map[headPos.second][headPos.first].getEntities()[0]->getType() == BLOCK)
                this->_gameStatus = GameStatus::OVER;
            break;
        case EAST:
            if (this->_map[headPos.second][headPos.first].getEntities().size() > 2 || this->_map[headPos.second][headPos.first].getEntities()[0]->getType() == BLOCK)
                this->_gameStatus = GameStatus::OVER;
            break;
        case WEST:
            if (this->_map[headPos.second][headPos.first].getEntities().size() > 2 || this->_map[headPos.second][headPos.first].getEntities()[0]->getType() == BLOCK)
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
        this->_loadingMap = true;
    }
}

void Snake::loadMap()
{
    if (this->_loadingMap != true)
        return;

    std::vector<std::string> mapPath = {
        "./src/Games/Snake/maps/map1.txt"
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

void Snake::clearPlayer()
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

void Snake::placePlayer()
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
        this->_map[bodyPos.second][bodyPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(0, std::make_pair(bodyPos.first, bodyPos.second), "", ASCII(' ', Color()), "Empty"), this->_map[bodyPos.second][bodyPos.first].getEntities()[0], std::make_shared<PlayerBody>(1, std::make_pair(bodyPos.first, bodyPos.second), "", ASCII('B', Color()), "PlayerBody")});
    }
    this->_map[tailPos.second][tailPos.first].setEntities(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Empty>(0, std::make_pair(bodyPos.first, bodyPos.second), "", ASCII(' ', Color()), "Empty"), this->_map[tailPos.second][tailPos.first].getEntities()[0], std::make_shared<PlayerTail>(1, std::make_pair(tailPos.first, tailPos.second), "", ASCII('T', Color()), "PlayerTail")});
}

void Snake::movePlayer()
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

void Snake::changeDirection(Input key)
{
    switch (key) {
        case UP:
            if (this->_direction == SOUTH)
                break;
            this->_lastDirection = this->_direction;
            this->_direction = NORTH;
            break;
        case DOWN:
            if (this->_direction == NORTH)
                break;
            this->_lastDirection = this->_direction;
            this->_direction = SOUTH;
            break;
        case LEFT:
            if (this->_direction == EAST)
                break;
            this->_lastDirection = this->_direction;
            this->_direction = WEST;
            break;
        case RIGHT:
            if (this->_direction == WEST)
                break;
            this->_lastDirection = this->_direction;
            this->_direction = EAST;
            break;
        default:
            break;
    }
}

void Snake::spawnFruit()
{
    int randomNumber = rand() % 10 + 1;
    int fruitCount = (randomNumber <= 7) ? 1 : (randomNumber <= 9) ? 2 : 3;

    for (int i = 0; i < fruitCount; ++i) {
        int x = 0;
        int y = 0;

        do {
            x = rand() % (this->_map[0].size() - 3) + 1;
            y = rand() % (this->_map.size() - 3) + 1;
        } while (this->_map[y][x].getEntities()[0]->getType() != EMPTY);
        this->_map[y][x].setEntities(std::vector<std::shared_ptr<AEntities>>{std::make_shared<Fruit>(1, std::make_pair(x, y), "", ASCII('@', Color()), "Fruit")});
    }
}

void Snake::eatFruit()
{
    std::pair<int, int> headPos = this->_player.getHead().getPos();
    std::vector<PlayerBody> bodyPos = this->_player.getBody();

    if (this->_map[headPos.second][headPos.first].getEntities()[0]->getType() == ITEM) {
        this->_score += 10;
        this->_lastChronoRefresh = this->_chronoRefresh;
        this->_chronoRefresh -= 5;
        if (this->_chronoRefresh < 100)
            this->_chronoRefresh = 100;
        this->spawnFruit();
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

void Snake::speedBoost(Input key)
{
    if (key == SPACE && this->_speedBoost == false) {
        this->_chronoRefresh -= 100;
        if (this->_chronoRefresh < 100)
            this->_chronoRefresh = 100;
        this->_speedBoost = true;
    } else if (key == SPACE && this->_speedBoost == true) {
        this->_chronoRefresh = this->_lastChronoRefresh;
        this->_speedBoost = false;
    }
}

void Snake::updateGame()
{
    return;
}
