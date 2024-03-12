/*
** EPITECH PROJECT, 2024
** Arcade
** File description:
** NcursesWrapper
*/

#include "../../../include/Graphics/Ncurses/NcursesWrapper.hpp"

std::shared_ptr<WINDOW> NcursesWrapper::n_initscr()
{
    return std::shared_ptr<WINDOW>(::initscr(), ::delwin);
}

int NcursesWrapper::n_refresh()
{
    return ::refresh();
}

int NcursesWrapper::n_wrefresh(std::shared_ptr<WINDOW> win)
{
    return ::wrefresh(win.get());
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

int NcursesWrapper::n_keypad(std::shared_ptr<WINDOW> win, bool bf)
{
    return ::keypad(win.get(), bf);
}

int NcursesWrapper::n_halfdelay(int tenths)
{
    return ::halfdelay(tenths);
}

int NcursesWrapper::n_clear()
{
    return ::clear();
}

int NcursesWrapper::n_wclear(std::shared_ptr<WINDOW> win)
{
    return ::wclear(win.get());
}

int NcursesWrapper::n_wmove(std::shared_ptr<WINDOW> win, int y, int x)
{
    return ::wmove(win.get(), y, x);
}

void NcursesWrapper::n_getmaxyx(std::shared_ptr<WINDOW> win, int y, int x)
{
    getmaxyx(win.get(), y, x);
}

void NcursesWrapper::n_getyx(std::shared_ptr<WINDOW> win, int y, int x)
{
    getyx(win.get(), y, x);
}

int NcursesWrapper::n_mvprintw(std::shared_ptr<WINDOW> win, int y, int x, std::string fmt)
{
    return ::mvprintw(y, x, "%s", fmt);
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
