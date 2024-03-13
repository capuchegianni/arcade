/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesWrapper
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>
#include <memory>
#include <string>

class NcursesWrapper {
    public:
        NcursesWrapper() = default;
        ~NcursesWrapper() = default;

    std::shared_ptr<WINDOW> n_initscr();
    int n_refresh();
    int n_wrefresh(std::shared_ptr<WINDOW> win);
    int n_endwin();
    int n_echo();
    int n_noecho();
    int n_keypad(std::shared_ptr<WINDOW> win, bool bf);
    int n_halfdelay(int tenths);
    int n_clear();
    int n_wclear(std::shared_ptr<WINDOW> win);
    int n_wmove(std::shared_ptr<WINDOW> win, int y, int x);
    void n_getmaxyx(std::shared_ptr<WINDOW> win, int& y, int& x);
    void n_getyx(std::shared_ptr<WINDOW> win, int& y, int& x);
    int n_mvprintw(int y, int x, std::string fmt);
    int n_start_color();
    int n_init_pair(short pair, short f, short b);
    int n_init_color(short color, short r, short g, short b);
};

#endif /* !NCURSES_HPP_ */
