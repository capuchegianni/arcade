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
    this->_tick = 0;
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

std::unordered_map<int, Input> keymap = {
    {27, ESC},
    {KEY_UP, CHANGE_GAME},
    {KEY_RIGHT, CHANGE_LIB},
    {9, MENU},
    {32, SPACE},
    {122, UP},
    {113, LEFT},
    {115, DOWN},
    {100, RIGHT},
    {114, RELOAD},
    {10, ENTER},
    {97, A},
    {98, B},
    {99, C},
    {101, E},
    {102, F},
    {103, G},
    {104, H},
    {105, I},
    {106, J},
    {107, K},
    {108, L},
    {109, M},
    {110, N},
    {111, O},
    {112, P},
    {116, T},
    {117, U},
    {118, V},
    {119, W},
    {120, X},
    {121, Y},
    {KEY_BACKSPACE, DELETE},
};

Input NcursesGraphicalModule::parseKeyboard() {
    int key = NcursesWrapper::n_getch();

    if (keymap.find(key) != keymap.end())
        return keymap[key];
    return NONE;
}

static void displayText(const std::string &text, const std::pair<int, int> &pos, const Color& color) {
    std::pair<int, int> newPos = std::make_pair(static_cast<int>(pos.second / 9), static_cast<int>(pos.first / 9));

    if (color.r > 200 && color.g > 200 && color.b > 200) {
        if (text == "<")
            NcursesWrapper::n_mvprintw(newPos.first, newPos.second + 10, text);
        else
            NcursesWrapper::n_mvprintw(newPos.first, newPos.second, text);
        return;
    }
    if (color.r > 200) {
        if (color.g > 200) {
            NcursesWrapper::n_attron(COLOR_PAIR(2));
            NcursesWrapper::n_mvprintw(newPos.first, newPos.second, text);
            NcursesWrapper::n_attroff(COLOR_PAIR(2));
        } else {
            NcursesWrapper::n_attron(COLOR_PAIR(3));
            NcursesWrapper::n_mvprintw(newPos.first, newPos.second, text);
            NcursesWrapper::n_attroff(COLOR_PAIR(3));
        }
        return;
    }
    if (color.b > 200) {
        NcursesWrapper::n_attron(COLOR_PAIR(1));
        NcursesWrapper::n_mvprintw(newPos.first, newPos.second, text);
        NcursesWrapper::n_attroff(COLOR_PAIR(1));
    }
}

void NcursesGraphicalModule::showMap(const std::vector<std::vector<Tiles>> &map) {
    if (this->_tick % 5 == 0) {
        NcursesWrapper::n_clear();
    }
    if (map.empty())
        return;
    for (int i = map.size() - 1; i >= 0; i--) {
        if (map[i].empty())
            continue;
        for (size_t j = 0; j < map[i].size(); j++) {
            if (map[i][j].getEntities().empty())
                continue;
            std::shared_ptr<AEntities> entity = map[i][j].getEntities()[map[i][j].getEntities().size() - 1];

            if (entity->getType() == BUTTON)
                displayText(entity->imageToDisplay().first, entity->getPos(), entity->imageToDisplay().second.getColor());
            else
                NcursesWrapper::n_mvprintw(i, j, std::string (1, entity->imageToDisplay().second.getAscii()));
        }
    }
    this->_tick++;
}

void NcursesGraphicalModule::initAssets(const std::vector<std::shared_ptr<AEntities>> &entities) {
    (void)entities;
    NcursesWrapper::n_init_pair(1, COLOR_BLACK, COLOR_BLUE);
    NcursesWrapper::n_init_pair(2, COLOR_BLACK, COLOR_YELLOW);
    NcursesWrapper::n_init_pair(3, COLOR_BLACK, COLOR_RED);
    return;
}
