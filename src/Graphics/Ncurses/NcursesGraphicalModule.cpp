/*
** EPITECH PROJECT, 2024
** arcade
** File description:
** NcursesGraphicalModule
*/

#include "../../../include/Graphics/Ncurses/NcursesGraphicalModule.hpp"

NcursesGraphicalModule::NcursesGraphicalModule() :
    AGraphicalModule("Ncurses") { }

extern "C" std::shared_ptr<AGraphicalModule> createLib() {
    return std::make_shared<NcursesGraphicalModule>();
}

void NcursesGraphicalModule::destroyWindow() {
    this->_isOpen = false;
    NcursesWrapper::n_endwin();
    return;
}

void NcursesGraphicalModule::createWindow(const std::string &name, const std::vector<int> &size) {
    (void)name;
    (void)size;
    this->_isOpen = true;
    NcursesWrapper::n_initscr();
    NcursesWrapper::n_noecho();
    NcursesWrapper::n_keypad(stdscr, TRUE);
    NcursesWrapper::n_nodelay(stdscr, TRUE);
    NcursesWrapper::n_curs_set(0);
    NcursesWrapper::n_start_color();
    return;
}

void NcursesGraphicalModule::setWindowSize(const std::vector<int> &size) {
    (void)size;
    return;
}

void NcursesGraphicalModule::setWindowTitle(const std::string &title) {
    (void)title;
    return;
}

void NcursesGraphicalModule::displayWindow() {
    NcursesWrapper::n_refresh();
}

bool NcursesGraphicalModule::isWindowOpen() {
    return this->_isOpen;
}

Input NcursesGraphicalModule::parseKeyboard() {
    int key = NcursesWrapper::n_getch();

    switch (key) {
        case 27:
            return ESC;

        case KEY_UP:
            return CHANGE_GAME;

        case KEY_RIGHT:
            return CHANGE_LIB;

        case 114:
            return RELOAD;

        case 9:
            return MENU;

        case 122:
            return UP;

        case 113:
            return LEFT;

        case 115:
            return DOWN;

        case 100:
            return RIGHT;

        case 32:
            return SPACE;
    }
    return NONE;
}

static void displayText(const std::string &text, const std::pair<int, int> &pos, const Color& color) {
    std::pair<int, int> newPos = std::make_pair((int)pos.first / 100, (int)pos.second);

    if (color.r == 0 && color.g == 162 && color.b == 255) {
        NcursesWrapper::n_attron(COLOR_PAIR(1));
        NcursesWrapper::n_mvprintw(newPos.first, newPos.second, text);
        NcursesWrapper::n_attroff(COLOR_PAIR(1));
    }
    if (color.r == 239 && color.g == 255 && color.b == 0) {
        NcursesWrapper::n_attron(COLOR_PAIR(2));
        NcursesWrapper::n_mvprintw(newPos.first, newPos.second, text);
        NcursesWrapper::n_attroff(COLOR_PAIR(2));
    }
}

void NcursesGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map) {
    NcursesWrapper::n_clear();
    if (map.empty())
        return;
    for (int i = map.size() - 1; i >= 0; i--) {
        if (map[i].empty())
            continue;
        for (int j = map[i].size() - 1; j >= 0; j--) {
            if (map[i][j].getEntities().empty())
                continue;

            std::shared_ptr<AEntities> entity = map[i][j].getEntities()[0];

            if (entity->getType() == BUTTON)
                displayText(entity->imageToDisplay().first, entity->getPos(), entity->imageToDisplay().second.getColor());
            else
                NcursesWrapper::n_mvprintw(i, j, std::string (1, entity->imageToDisplay().second.getAscii()));
        }
    }
}

void NcursesGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities) {
    (void)entities;
    NcursesWrapper::n_init_pair(1, COLOR_BLACK, COLOR_BLUE);
    NcursesWrapper::n_init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    return;
}
