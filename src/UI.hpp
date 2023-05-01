#pragma once

#include <ncurses.h>
#include <exception>
#include <cstring>
#include "tab.hpp"
#include <string>

namespace YAExplorer
{

#define curs_invisible 0
#define curs_normal 1
#define curs_visible 2

#define APP_NAME "Yet Another Explorer"

class UI            //singleton
{
    protected:

    UI();

    static UI* instance;

    static WINDOW* up_bar;             //in-fact all if them are static, its not marked by static cause their initialization should be after UI constructor;
    static WINDOW* status_bar;

    static dirPanel* left;
    static dirPanel* right;

    static std::string status;

    public:

    UI(UI &other) = delete;
    void operator=(const UI&) = delete;

    static UI* GetInstance();
    static void CloseInstance();

    static WINDOW* create_newwin(int height, int width, int starty, int startx, chtype lu_corner = ACS_ULCORNER, chtype ru_corner = ACS_URCORNER, chtype ll_corner = ACS_LLCORNER, chtype rl_corner = ACS_LRCORNER);
    static void destroy_win(WINDOW *local_win);

    static void setStatus(std::string message);
    static std::string getStatus();

    static bool changeSide(); // 0 - left, 1 - right;


    private:

    ~UI();
};




}