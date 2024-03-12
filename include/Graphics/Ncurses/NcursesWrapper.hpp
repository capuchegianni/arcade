/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesWrapper
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <ncurses.h>

class NcursesWrapper {
    public:
        NcursesWrapper() = default;
        ~NcursesWrapper() = default;

        WINDOW *n_initscr();
        int n_refresh();
        int n_wrefresh(WINDOW *win);
        int n_endwin();
        int n_echo();
        int n_noecho();
        int n_keypad(WINDOW *win, bool bf);
        int n_halfdelay(int tenths);
        int n_clear();
        int n_wclear(WINDOW *win);
        int n_wmove(WINDOW *win, int y, int x);
        void n_getmaxyx(WINDOW *win, int y, int x);
        void n_getyx(WINDOW *win, int y, int x);
        int n_mvprintw(WINDOW *win, int y, int x, const char *fmt);
        int n_start_color();
        int n_init_pair(short pair, short f, short b);
        int n_init_color(short color, short r, short g, short b);
        int delwin(WINDOW *win);
};

#endif /* !NCURSES_HPP_ */
