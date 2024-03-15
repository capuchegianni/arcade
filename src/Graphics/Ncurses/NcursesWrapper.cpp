/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesWrapper
*/

#include "../../../include/Graphics/Ncurses/NcursesWrapper.hpp"

WINDOW *NcursesWrapper::n_initscr()
{
    return ::initscr();
}

int NcursesWrapper::n_refresh()
{
    return ::refresh();
}

int NcursesWrapper::n_wrefresh(WINDOW *win)
{
    return ::wrefresh(win);
}

int NcursesWrapper::n_endwin()
{
    return ::endwin();
}

int NcursesWrapper::n_echo()
{
    return ::echo();
}

int NcursesWrapper::n_noecho()
{
    return ::noecho();
}

int NcursesWrapper::n_keypad(WINDOW *win, bool bf)
{
    return ::keypad(win, bf);
}

int NcursesWrapper::n_halfdelay(int tenths)
{
    return ::halfdelay(tenths);
}

int NcursesWrapper::n_clear()
{
    return ::clear();
}

int NcursesWrapper::n_wclear(WINDOW *win)
{
    return ::wclear(win);
}

int NcursesWrapper::n_wmove(WINDOW *win, int y, int x)
{
    return ::wmove(win, y, x);
}

void NcursesWrapper::n_getmaxyx(WINDOW *win, int& y, int& x)
{
    getmaxyx(win, y, x);
}

void NcursesWrapper::n_getyx(WINDOW *win, int& y, int& x)
{
    getyx(win, y, x);
}

int NcursesWrapper::n_mvprintw(int y, int x, std::string fmt)
{
    return ::mvprintw(y, x, "%s", fmt.c_str());
}

int NcursesWrapper::n_start_color()
{
    return ::start_color();
}

int NcursesWrapper::n_init_pair(short pair, short f, short b)
{
    return ::init_pair(pair, f, b);
}

int NcursesWrapper::n_init_color(short color, short r, short g, short b)
{
    return ::init_color(color, r, g, b);
}

int NcursesWrapper::n_getch()
{
    return ::getch();
}
