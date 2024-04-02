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
    }
    return NONE;
}

void NcursesGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map) {
    NcursesWrapper::n_clear();
    if (map.empty())
        return;
    for (int i = map.size() - 1; i >= 0; i--) {
        if (map[i].empty())
            continue;
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j].getEntities().empty())
                continue;
            std::shared_ptr<AEntities> entity = map[i][j].getEntities()[map[i][j].getEntities().size() - 1];

            NcursesWrapper::n_mvprintw(i, j, std::string (1, entity->imageToDisplay().second.getAscii()));
        }
    }
}

void NcursesGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities) {
    (void)entities;
    return;
}
